#ifndef DARKNET_DETECTOR_H
#define DARKNET_DETECTOR_H

#include <stddef.h>

// Forward declarations of Darknet types
struct network;
struct detection;
struct image;

// Structure to hold detection results compatible with your existing code
typedef struct {
    int x1, y1, x2, y2;  // Bounding box coordinates
    float confidence;    // Detection confidence
    int class_id;        // Class ID
    char class_name[64]; // Class name
} DarknetDetection;

// Structure to hold all detections for a frame
typedef struct {
    DarknetDetection* detections;
    int num_detections;
    double timestamp;
} DarknetDetectionData;

// Darknet detector context using the actual library
typedef struct {
    struct network* net;     // Darknet network
    char** class_names;      // Class names array
    int num_classes;         // Number of classes
    float thresh;           // Detection threshold
    int initialized;        // Initialization flag
} DarknetDetector;

// NEW: Direct Darknet wrapper functions (based on case 19 implementation)
typedef struct {
    struct network* net;     // Darknet network (pointer to avoid incomplete type)
    char** names;           // Class names
    int names_size;         // Number of classes
    struct image** alphabet; // Drawing alphabet
    float thresh;           // Detection threshold
    float hier_thresh;      // Hierarchical threshold
    int letter_box;         // Letterbox flag
    int initialized;        // Initialization flag
} DirectDarknetDetector;

// Function prototypes for existing interface
DarknetDetector* darknet_detector_init(const char* cfg_file, const char* weights_file, const char* names_file, float thresh);
void darknet_detector_cleanup(DarknetDetector* detector);
int darknet_detect_pixels(DarknetDetector* detector, const unsigned char* pixels, int width, int height, int channels, const char* output_json, double timestamp);
int darknet_save_detections_to_json(const DarknetDetectionData* detections, const char* filename);
int darknet_load_detections_from_json(const char* filename, DarknetDetectionData* detections, double timestamp);
void darknet_free_detections(DarknetDetectionData* detections);

// NEW: Direct Darknet wrapper function prototypes
DirectDarknetDetector* direct_darknet_init(const char* datacfg, const char* cfgfile, const char* weightfile, float thresh, float hier_thresh);
void direct_darknet_cleanup(DirectDarknetDetector* detector);
int direct_darknet_detect_image(DirectDarknetDetector* detector, const char* image_path, const char* output_json, const char* output_image);
int direct_darknet_detect_pixels(DirectDarknetDetector* detector, const unsigned char* pixels, int width, int height, int channels, const char* output_json, const char* output_image);

// Helper functions (internal use)
void load_class_names(const char* names_file, char*** class_names, int* num_classes);
struct image make_image_from_pixels(const unsigned char* pixels, int width, int height, int channels);
void convert_darknet_detections_to_our_format(struct detection* darknet_dets, int num_detections, 
                                            DarknetDetection* our_dets, char** class_names, int num_classes,
                                            int orig_width, int orig_height);

#endif // DARKNET_DETECTOR_H 