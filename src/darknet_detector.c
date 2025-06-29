#include "darknet_detector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

// Darknet includes
#include "darknet.h"
#include "../darknet/src/network.h"
#include "../darknet/src/region_layer.h"
#include "../darknet/src/cost_layer.h"
#include "../darknet/src/utils.h"
#include "../darknet/src/parser.h"
#include "../darknet/src/box.h"
#include "../darknet/src/demo.h"
#include "../darknet/src/option_list.h"

// ============================================================================
// NEW: Direct Darknet Wrapper Functions (based on case 19 implementation)
// ============================================================================

DirectDarknetDetector* direct_darknet_init(const char* datacfg, const char* cfgfile, const char* weightfile, float thresh, float hier_thresh) {
    if (!datacfg || !cfgfile || !weightfile) {
        printf("ERROR: Invalid parameters - datacfg, cfgfile, and weightfile must not be NULL\n");
        return NULL;
    }
    
    // Allocate detector structure
    DirectDarknetDetector* detector = malloc(sizeof(DirectDarknetDetector));
    if (!detector) {
        printf("ERROR: Failed to allocate detector memory\n");
        return NULL;
    }
    
    // Initialize structure
    memset(detector, 0, sizeof(DirectDarknetDetector));
    detector->initialized = false;
    
    // Load data configuration
    list *options = read_data_cfg((char*)datacfg);
    if (!options) {
        printf("ERROR: Failed to read data configuration: %s\n", datacfg);
        free(detector);
        return NULL;
    }
    
    // Get class names
    char *name_list = option_find_str(options, "names", "data/names.list");
    int names_size = 0;
    detector->names = get_labels_custom(name_list, &names_size);
    if (!detector->names) {
        printf("ERROR: Failed to load class names from: %s\n", name_list);
        free_list_contents_kvp(options);
        free_list(options);
        free(detector);
        return NULL;
    }
    
    // Load alphabet for drawing
    detector->alphabet = load_alphabet();
    if (!detector->alphabet) {
        printf("ERROR: Failed to load alphabet\n");
        free_ptrs((void**)detector->names, names_size);
        free_list_contents_kvp(options);
        free_list(options);
        free(detector);
        return NULL;
    }
    
    // Parse network configuration
    detector->net = malloc(sizeof(network));
    if (!detector->net) {
        printf("ERROR: Failed to allocate network memory\n");
        free_alphabet(detector->alphabet);
        free_ptrs((void**)detector->names, names_size);
        free_list_contents_kvp(options);
        free_list(options);
        free(detector);
        return NULL;
    }
    
    *detector->net = parse_network_cfg_custom((char*)cfgfile, 1, 1);
    if (detector->net->layers == NULL) {
        printf("ERROR: Failed to parse network configuration: %s\n", cfgfile);
        free(detector->net);
        free_alphabet(detector->alphabet);
        free_ptrs((void**)detector->names, names_size);
        free_list_contents_kvp(options);
        free_list(options);
        free(detector);
        return NULL;
    }
    
    // Load weights
    load_weights(detector->net, (char*)weightfile);
    if (detector->net->layers[detector->net->n - 1].classes != names_size) {
        printf("ERROR: Number of classes in config (%d) doesn't match number of names (%d)\n",
               detector->net->layers[detector->net->n - 1].classes, names_size);
        free_network(*detector->net);
        free(detector->net);
        free_alphabet(detector->alphabet);
        free_ptrs((void**)detector->names, names_size);
        free_list_contents_kvp(options);
        free_list(options);
        free(detector);
        return NULL;
    }
    
    // Set network properties
    detector->letter_box = detector->net->letter_box;
    detector->thresh = thresh;
    detector->hier_thresh = hier_thresh;
    
    // Optimize network
    fuse_conv_batchnorm(*detector->net);
    calculate_binary_weights(*detector->net);
    
    // Set random seed for reproducibility
    srand(2222222);
    
    // Clean up options
    free_list_contents_kvp(options);
    free_list(options);
    
    // Mark as initialized
    detector->initialized = true;
    
    return detector;
}

void direct_darknet_cleanup(DirectDarknetDetector* detector) {
    if (!detector) {
        return;
    }
    
    if (detector->initialized) {
        // Store number of classes before freeing network
        int num_classes = 0;
        if (detector->net) {
            num_classes = detector->net->layers[detector->net->n - 1].classes;
            free_network(*detector->net);
            free(detector->net);
        }
        
        if (detector->alphabet) {
            free_alphabet(detector->alphabet);
        }
        
        if (detector->names) {
            free_ptrs((void**)detector->names, num_classes);
        }
    }
    
    free(detector);
}

int direct_darknet_detect_image(DirectDarknetDetector* detector, const char* input_image, const char* output_json, const char* output_image) {
    if (!detector || !detector->initialized) {
        printf("ERROR: Detector not initialized\n");
        return -1;
    }
    
    if (!input_image) {
        printf("ERROR: Input image path is NULL\n");
        return -1;
    }
    
    // Step 1: Load image
    image im = load_image(input_image, 0, 0, detector->net->c);
    if (im.data == NULL) {
        printf("ERROR: Failed to load image: %s\n", input_image);
        return -1;
    }
    
    // Step 2: Resize image for network
    image sized;
    if(detector->letter_box) {
        sized = letterbox_image(im, detector->net->w, detector->net->h);
    } else {
        sized = resize_image(im, detector->net->w, detector->net->h);
    }

    // Step 3: Find detection layer
    layer l = detector->net->layers[detector->net->n - 1];
    int k;
    for (k = 0; k < detector->net->n; ++k) {
        layer lk = detector->net->layers[k];
        if (lk.type == YOLO || lk.type == GAUSSIAN_YOLO || lk.type == REGION) {
            l = lk;
            break;
        }
    }

    // Step 4: Run network prediction
    float *X = sized.data;
    network_predict(*detector->net, X);

    // Step 5: Get detection boxes
    int nboxes = 0;
    detection *dets = get_network_boxes(detector->net, im.w, im.h, detector->thresh, detector->hier_thresh, 0, 1, &nboxes, detector->letter_box);

    // Step 6: Apply Non-Maximum Suppression
    float nms = 0.45f;
    if (nms) {
        if (l.nms_kind == DEFAULT_NMS) {
            do_nms_sort(dets, nboxes, l.classes, nms);
        } else {
            diounms_sort(dets, nboxes, l.classes, nms, l.nms_kind, l.beta_nms);
        }
    }

    // Step 7: Draw detections and save image
    int ext_output = 1;
    draw_detections_v3(im, dets, nboxes, detector->thresh, detector->names, detector->alphabet, l.classes, ext_output);
    
    if (output_image) {
        save_image(im, output_image);
    } else {
        save_image(im, "predictions");
    }

    // Step 8: Save results to JSON
    if (output_json) {
        FILE* json_file = fopen(output_json, "wb");
        if (json_file) {
            fprintf(json_file, "[\n");
            for (int i = 0; i < nboxes; ++i) {
                int class_id = -1;
                float best_prob = 0;
                for (int j = 0; j < l.classes; ++j) {
                    if (dets[i].prob[j] > best_prob) {
                        best_prob = dets[i].prob[j];
                        class_id = j;
                    }
                }
                
                if (class_id >= 0) {
                    box b = dets[i].bbox;
                    int left   = (b.x - b.w / 2.0) * im.w;
                    int right  = (b.x + b.w / 2.0) * im.w;
                    int top    = (b.y - b.h / 2.0) * im.h;
                    int bottom = (b.y + b.h / 2.0) * im.h;
                    
                    if (left < 0) left = 0;
                    if (right > im.w - 1) right = im.w - 1;
                    if (top < 0) top = 0;
                    if (bottom > im.h - 1) bottom = im.h - 1;
                    
                    fprintf(json_file, "%s{\n", (i > 0) ? ",\n" : "");
                    fprintf(json_file, "  \"detection_id\": %d,\n", i);
                    fprintf(json_file, "  \"class_id\": %d,\n", class_id);
                    fprintf(json_file, "  \"class_name\": \"%s\",\n", detector->names[class_id]);
                    fprintf(json_file, "  \"confidence\": %.6f,\n", best_prob);
                    fprintf(json_file, "  \"bbox\": {\n");
                    fprintf(json_file, "    \"x1\": %d,\n", left);
                    fprintf(json_file, "    \"y1\": %d,\n", top);
                    fprintf(json_file, "    \"x2\": %d,\n", right);
                    fprintf(json_file, "    \"y2\": %d\n", bottom);
                    fprintf(json_file, "  }\n");
                    fprintf(json_file, "}");
                }
            }
            fprintf(json_file, "\n]\n");
            fclose(json_file);
        }
    }

    // Step 9: Cleanup
    free_detections(dets, nboxes);
    free_image(im);
    free_image(sized);
    
    return 0;
}

int direct_darknet_detect_pixels(DirectDarknetDetector* detector, const unsigned char* pixels, int width, int height, int channels, const char* output_json, const char* output_image) {
    if (!detector || !detector->initialized) {
        printf("ERROR: Detector not initialized\n");
        return -1;
    }
    
    if (!pixels) {
        printf("ERROR: Pixel data is NULL\n");
        return -1;
    }
    
    // Step 1: Create image from pixel data
    image im = make_image(height, width, channels);
    
    // Copy pixel data to image
    for (int c = 0; c < channels; ++c) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int pixel_idx = (y * width + x) * channels + c;
                int image_idx = c * width * height + y * width + x;
                im.data[image_idx] = pixels[pixel_idx] / 255.0f;
            }
        }
    }
    
    // Step 2: Resize image for network
    image sized;
    if(detector->letter_box) {
        sized = letterbox_image(im, detector->net->w, detector->net->h);
    } else {
        sized = resize_image(im, detector->net->w, detector->net->h);
    }

    // Step 3: Find detection layer
    layer l = detector->net->layers[detector->net->n - 1];
    int k;
    for (k = 0; k < detector->net->n; ++k) {
        layer lk = detector->net->layers[k];
        if (lk.type == YOLO || lk.type == GAUSSIAN_YOLO || lk.type == REGION) {
            l = lk;
            break;
        }
    }

    // Step 4: Run network prediction
    float *X = sized.data;
    network_predict(*detector->net, X);

    // Step 5: Get detection boxes
    int nboxes = 0;
    detection *dets = get_network_boxes(detector->net, im.w, im.h, detector->thresh, detector->hier_thresh, 0, 1, &nboxes, detector->letter_box);

    // Step 6: Apply Non-Maximum Suppression
    float nms = 0.45f;
    if (nms) {
        if (l.nms_kind == DEFAULT_NMS) {
            do_nms_sort(dets, nboxes, l.classes, nms);
        } else {
            diounms_sort(dets, nboxes, l.classes, nms, l.nms_kind, l.beta_nms);
        }
    }

    // Step 7: Draw detections and save image
    int ext_output = 1;
    draw_detections_v3(im, dets, nboxes, detector->thresh, detector->names, detector->alphabet, l.classes, ext_output);
    
    if (output_image) {
        save_image(im, output_image);
    } else {
        save_image(im, "predictions");
    }

    // Step 8: Save results to JSON
    if (output_json) {
        FILE* json_file = fopen(output_json, "wb");
        if (json_file) {
            fprintf(json_file, "[\n");
            for (int i = 0; i < nboxes; ++i) {
                int class_id = -1;
                float best_prob = 0;
                for (int j = 0; j < l.classes; ++j) {
                    if (dets[i].prob[j] > best_prob) {
                        best_prob = dets[i].prob[j];
                        class_id = j;
                    }
                }
                
                if (class_id >= 0) {
                    box b = dets[i].bbox;
                    int left   = (b.x - b.w / 2.0) * im.w;
                    int right  = (b.x + b.w / 2.0) * im.w;
                    int top    = (b.y - b.h / 2.0) * im.h;
                    int bottom = (b.y + b.h / 2.0) * im.h;
                    
                    if (left < 0) left = 0;
                    if (right > im.w - 1) right = im.w - 1;
                    if (top < 0) top = 0;
                    if (bottom > im.h - 1) bottom = im.h - 1;
                    
                    fprintf(json_file, "%s{\n", (i > 0) ? ",\n" : "");
                    fprintf(json_file, "  \"detection_id\": %d,\n", i);
                    fprintf(json_file, "  \"class_id\": %d,\n", class_id);
                    fprintf(json_file, "  \"class_name\": \"%s\",\n", detector->names[class_id]);
                    fprintf(json_file, "  \"confidence\": %.6f,\n", best_prob);
                    fprintf(json_file, "  \"bbox\": {\n");
                    fprintf(json_file, "    \"x1\": %d,\n", left);
                    fprintf(json_file, "    \"y1\": %d,\n", top);
                    fprintf(json_file, "    \"x2\": %d,\n", right);
                    fprintf(json_file, "    \"y2\": %d\n", bottom);
                    fprintf(json_file, "  }\n");
                    fprintf(json_file, "}");
                }
            }
            fprintf(json_file, "\n]\n");
            fclose(json_file);
        }
    }

    // Step 9: Cleanup
    free_detections(dets, nboxes);
    free_image(im);
    free_image(sized);
    
    return 0;
}

// ============================================================================
// Existing Interface Functions (stubs for now)
// ============================================================================

DarknetDetector* darknet_detector_init(const char* cfg_file, const char* weights_file, const char* names_file, float thresh) {
    // This is a stub - you can implement the old interface if needed
    printf("WARNING: Using old interface. Consider using direct_darknet_init() instead.\n");
    return NULL;
}

void darknet_detector_cleanup(DarknetDetector* detector) {
    // This is a stub
    printf("WARNING: Using old interface cleanup.\n");
}

int darknet_detect_pixels(DarknetDetector* detector, const unsigned char* pixels, int width, int height, int channels, const char* output_json, double timestamp) {
    // This is a stub
    printf("WARNING: Using old interface. Consider using direct_darknet_detect_pixels() instead.\n");
    return -1;
}

int darknet_save_detections_to_json(const DarknetDetectionData* detections, const char* filename) {
    // This is a stub
    printf("WARNING: Using old interface.\n");
    return -1;
}

int darknet_load_detections_from_json(const char* filename, DarknetDetectionData* detections, double timestamp) {
    // This is a stub
    printf("WARNING: Using old interface.\n");
    return -1;
}

void darknet_free_detections(DarknetDetectionData* detections) {
    // This is a stub
    printf("WARNING: Using old interface.\n");
}

// ============================================================================
// Helper Functions (stubs for now)
// ============================================================================

void load_class_names(const char* names_file, char*** class_names, int* num_classes) {
    // This is a stub
    printf("WARNING: Using old helper function.\n");
}

struct image make_image_from_pixels(const unsigned char* pixels, int width, int height, int channels) {
    // This is a stub
    printf("WARNING: Using old helper function.\n");
    struct image im = {0};
    return im;
}

void convert_darknet_detections_to_our_format(struct detection* darknet_dets, int num_detections, 
                                            DarknetDetection* our_dets, char** class_names, int num_classes,
                                            int orig_width, int orig_height) {
    // This is a stub
    printf("WARNING: Using old helper function.\n");
}
