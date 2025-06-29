#include <stdio.h>
#include <stdlib.h>
#include "../include/sensor_loader.h"
#include "../include/tracker_specs.h"
#include "../include/data_streamer.h"
#include "../include/motion_types.h"
#include "../include/ego_motion.h"
#include "../include/camera_detection.h"
#include "../include/darknet_detector.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdatomic.h>
#include <string.h>

// Helper function to print target specification
void printTargetSpec(const TargetSpec* spec) {
    if (!spec) return;
    printf("Target Specification:\n");
    printf("  Type: %s\n", spec->type == TARGET_TYPE_CAR ? "Car" : "Truck");
    printf("  Reference Frame: %s\n", spec->referenceFrame ? spec->referenceFrame : "(null)");
    printf("  Max Speed: %.2f m/s\n", spec->maxSpeed);
    printf("  Max Acceleration: %.2f\n", spec->maxAcceleration);
    printf("  Max Yaw Rate: %.2f\n", spec->maxYawRate);
    printf("  Max Yaw Acceleration: %.2f\n", spec->maxYawAcceleration);
    printf("  Yaw Limits: [%.2f, %.2f]\n", spec->yawLimits[0], spec->yawLimits[1]);
    printf("  Length Limits: [%.2f, %.2f]\n", spec->lengthLimits[0], spec->lengthLimits[1]);
    printf("  Width Limits: [%.2f, %.2f]\n", spec->widthLimits[0], spec->widthLimits[1]);
    printf("  Height Limits: [%.2f, %.2f]\n", spec->heightLimits[0], spec->heightLimits[1]);
    printf("  Environment: %s\n", spec->environment ? spec->environment : "(null)");
    printf("\n");
}

// Helper function to print sensor mounting
void printSensorMounting(const SensorMounting* mounting) {
    printf("  Mounting Location: [%.5f, %.5f, %.5f] meters\n", 
           mounting->location[0], mounting->location[1], mounting->location[2]);
    printf("  Mounting Angles: [%.2f, %.2f, %.2f] degrees\n",
           mounting->angles[0], mounting->angles[1], mounting->angles[2]);
}

// Helper function to print radar specification
void printRadarSpec(const RadarSpec* spec) {
    printf("Radar Specification:\n");
    printSensorMounting(&spec->mounting);
    printf("  Max Measurements: %d\n", spec->maxNumMeasurements);
    printf("  Field of View: [%.2f, %.2f] degrees\n", 
           spec->fieldOfView[0], spec->fieldOfView[1]);
    printf("  Max Range: %.2f meters\n", spec->maxRange);
    printf("  Max Range Rate: %.2f m/s\n", spec->maxRangeRate);
    printf("  Detection Probability: %.2f\n", spec->detectionProbability);
    printf("  False Positives per Scan: %.2f\n", spec->numFalsePositivesPerScan);
    printf("  New Targets per Scan: %.2f\n", spec->numNewTargetsPerScan);
    printf("\n");
}

// Helper function to print camera specification
void printCameraSpec(const CameraSpec* spec) {
    printf("Camera Specification:\n");
    printSensorMounting(&spec->mounting);
    printf("  Max Measurements: %d\n", spec->maxNumMeasurements);
    printf("  Width Accuracy: %.2f\n", spec->widthAccuracy);
    printf("  Center Accuracy: %.2f\n", spec->centerAccuracy);
    printf("  Height Accuracy: %.2f\n", spec->heightAccuracy);
    printf("  Max Range: %.2f meters\n", spec->maxRange);
    printf("  Detection Probability: %.2f\n", spec->detectionProbability);
    printf("  Ego Origin Height: %.4f meters\n", spec->egoOriginHeight);
    printf("  Image Size: %dx%d\n", spec->imageSize[1], spec->imageSize[0]);
    printf("  Camera Intrinsics:\n");
    for (int i = 0; i < 3; i++) {
        printf("    [%.5f, %.5f, %.5f]\n", 
               spec->intrinsics[i][0], spec->intrinsics[i][1], spec->intrinsics[i][2]);
    }
    printf("  False Positives per Image: %.2e\n", spec->numFalsePositivesPerImage);
    printf("  New Targets per Image: %.2e\n", spec->numNewTargetsPerImage);
    printf("\n");
}

// Helper function to print lidar specification
void printLidarSpec(const LidarSpec* spec) {
    printf("Lidar Specification:\n");
    printSensorMounting(&spec->mounting);
    printf("  Max Measurements: %d\n", spec->maxNumMeasurements);
    printf("  Elevation Limits: [%.2f, %.2f] degrees\n", 
           spec->elevationLimits[0], spec->elevationLimits[1]);
    printf("  Azimuth Limits: [%.2f, %.2f] degrees\n", 
           spec->azimuthLimits[0], spec->azimuthLimits[1]);
    printf("  Max Range: %.2f meters\n", spec->maxRange);
    printf("  Detection Probability: %.2f\n", spec->detectionProbability);
    printf("  Dimension Accuracy: %.2f\n", spec->dimensionAccuracy);
    printf("  Center Accuracy: %.2f\n", spec->centerAccuracy);
    printf("  Orientation Accuracy: %.2f\n", spec->orientationAccuracy);
    printf("  False Positives per Scan: %.2f\n", spec->numFalsePositivesPerScan);
    printf("  New Targets per Scan: %.2f\n", spec->numNewTargetsPerScan);
    printf("\n");
}

// Helper function to delete all files in a directory
int delete_all_files_in_directory(const char* dir_path) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        printf("Could not open directory: %s\n", dir_path);
        return -1;
    }
    
    struct dirent *entry;
    char filepath[512];
    int deleted = 0;
    int errors = 0;
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Only delete regular files, not directories
        if (entry->d_type == DT_REG) {
            snprintf(filepath, sizeof(filepath), "%s/%s", dir_path, entry->d_name);
            if (remove(filepath) == 0) {
                deleted++;
            } else {
                printf("Failed to delete: %s\n", filepath);
                errors++;
            }
        }
    }
    
    closedir(dir);
    
    if (errors > 0) {
        printf("Deleted %d files, %d errors occurred\n", deleted, errors);
        return -1;
    } else {
        printf("Successfully deleted %d files\n", deleted);
        return 0;
    }
}

int main() {
    const char* filename = "data/rawdata_flat.mat";
    
    // Load all sensor data
    printf("Loading sensor data...\n");
    
    printf("    Loading odometry data...\n");
    OdometryData* odometry_data = load_odometry_data(filename);
    if (!odometry_data) {
        fprintf(stderr, "Error: Failed to load odometry data\n");
        return 1;
    }
    printf("    ✅ Odometry data loaded.\n");

    printf("    Loading radar data...\n");
    RadarData* radar_data = load_radar_data(filename);
    if (!radar_data) {
        fprintf(stderr, "Error: Failed to load radar data\n");
        free_odometry_data(odometry_data);
        return 1;
    }
    printf("    ✅ Radar data loaded.\n");

    printf("    Loading lidar data...\n");
    LidarData* lidar_data = load_lidar_data(filename);
    if (!lidar_data) {
        fprintf(stderr, "Error: Failed to load lidar data\n");
        free_odometry_data(odometry_data);
        free_radar_data(radar_data);
        return 1;
    }
    printf("    ✅ Lidar data loaded.\n");

    printf("    Loading camera data...\n");
    CameraData* camera_data = load_camera_data(filename);
    if (!camera_data) {
        fprintf(stderr, "Error: Failed to load camera data\n");
        free_odometry_data(odometry_data);
        free_radar_data(radar_data);
        free_lidar_data(lidar_data);
        return 1;
    }
    printf("    ✅ Camera data loaded.\n");

    // Print summary of loaded data
    printf("\nData Summary:\n");
    printf("Odometry frames: %zu\n", odometry_data->num_frames);
    printf("Radar frames: %zu\n", radar_data->num_frames);
    printf("Lidar frames: %zu\n", lidar_data->num_frames);
    printf("Camera frames: %zu\n", camera_data->num_frames);

    // Create target specifications array
    TargetSpec* targets[2];
    size_t num_targets = 2;
    targets[0] = createCarSpec();
    targets[1] = createTruckSpec();

    // Create sensor specifications array
    RadarSpec* radarSpec = createRadarSpec();
    LidarSpec* lidarSpec = createLidarSpec();
    CameraSpec* cameraSpec = createCameraSpec();
    size_t num_sensors = 3;

    // Print summary to confirm setup
    printf("\nTarget and Sensor Arrays Setup:\n");
    printf("Number of targets: %zu\n", num_targets);
    for (size_t i = 0; i < num_targets; ++i) {
        printf("  Target %zu: %s\n", i, targets[i]->type == TARGET_TYPE_CAR ? "Car" : "Truck");
    }
    printf("Number of sensors: %zu\n", num_sensors);
    printf("  Sensor 0: Radar\n");
    printf("  Sensor 1: Lidar\n");
    printf("  Sensor 2: Camera\n");

    CameraDetectionData* all_detections = calloc(camera_data->num_frames, sizeof(CameraDetectionData));

    while (1) {
        printf("\nSelect data type to inspect:\n");
        printf("1. Odometry Data\n");
        printf("2. Radar Data\n");
        printf("3. Lidar Data\n");
        printf("4. Camera Data\n");
        printf("5. Test Target and Sensor Specifications\n");
        printf("6. Test Data Streaming\n");
        printf("7. Test Ego Motion Estimation for user-selected frame\n");
        printf("8. Run Darknet YOLO Detection (Clean Wrapper Functions)\n");
        printf("9. Delete all files in detections directory\n");
        printf("10. Exit\n");
        printf("Enter your choice (1-10): ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: { // Odometry Data
                printf("\nOdometry Data Options:\n");
                printf("1. View frame details\n");
                printf("2. Back to main menu\n");
                printf("Enter your choice (1-2): ");
                
                int odom_choice;
                if (scanf("%d", &odom_choice) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (odom_choice == 1) {
                    printf("Enter frame index (0-%zu): ", odometry_data->num_frames - 1);
                    size_t index;
                    if (scanf("%zu", &index) != 1 || index >= odometry_data->num_frames) {
                        printf("Invalid frame index\n");
                        while (getchar() != '\n');
                        break;
                    }

                    printf("\nOdometry Frame %zu details:\n", index);
                    printf("Speed: %.2f m/s\n", odometry_data->frames[index].speed);
                    printf("Yaw Rate: %.2f rad/s\n", odometry_data->frames[index].yaw_rate);
                    printf("Timestamp: %.6f\n", odometry_data->frames[index].timestamp);
                }
                break;
            }
            case 2: { // Radar Data
                printf("\nRadar Data Options:\n");
                printf("1. View frame details\n");
                printf("2. Back to main menu\n");
                printf("Enter your choice (1-2): ");
                
                int radar_choice;
                if (scanf("%d", &radar_choice) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (radar_choice == 1) {
                    printf("Enter frame index (0-%zu): ", radar_data->num_frames - 1);
                    size_t index;
                    if (scanf("%zu", &index) != 1 || index >= radar_data->num_frames) {
                        printf("Invalid frame index\n");
                        while (getchar() != '\n');
                        break;
                    }

                    printf("\nRadar Frame %zu details:\n", index);
                    printf("Number of points: %zu\n", radar_data->frames[index].num_points);
                    printf("Timestamp: %.6f\n", radar_data->timestamps[index]);
                    
                    if (radar_data->frames[index].num_points > 0) {
                        size_t point_index = 0;
                        printf("Enter point index to inspect (0 to %zu): ", radar_data->frames[index].num_points - 1);
                        scanf("%zu", &point_index);

                        if (point_index >= radar_data->frames[index].num_points) {
                            printf("❌ Invalid point index.\n");
                        } else {
                            printf("\nPoint %zu details:\n", point_index);
                            printf("Location: (%.2f, %.2f, %.2f)\n",
                                radar_data->frames[index].x[point_index],
                                radar_data->frames[index].y[point_index],
                                radar_data->frames[index].z[point_index]);
                            printf("SNR: %.2f\n", radar_data->frames[index].snr[point_index]);
                            printf("Radial Speed: %.2f\n", radar_data->frames[index].radial_speed[point_index]);
                            printf("RCS: %.2f\n", radar_data->frames[index].rcs[point_index]);
                            printf("Power: %.2f\n", radar_data->frames[index].power[point_index]);
                            printf("Timestamp: %.6f\n", radar_data->timestamps[index]);
                        }
                    }
                }
                break;
            }
            case 3: { // Lidar Data
                printf("\nLidar Data Options:\n");
                printf("1. View frame details\n");
                printf("2. Back to main menu\n");
                printf("Enter your choice (1-2): ");
                
                int lidar_choice;
                if (scanf("%d", &lidar_choice) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (lidar_choice == 1) {
                    printf("Enter frame index (0-%zu): ", lidar_data->num_frames - 1);
                    size_t index;
                    if (scanf("%zu", &index) != 1 || index >= lidar_data->num_frames) {
                        printf("Invalid frame index\n");
                        while (getchar() != '\n');
                        break;
                    }

                    printf("\nLidar Frame %zu details:\n", index);
                    printf("Number of points: %zu\n", lidar_data->frames[index].num_points);
                    printf("Timestamp: %.6f\n", lidar_data->timestamps[index]);
                    
                    if (lidar_data->frames[index].num_points > 0) {
                        size_t point_index = 0;
                        printf("Enter point index to inspect (0 to %zu): ", lidar_data->frames[index].num_points - 1);
                        scanf("%zu", &point_index);

                        if (point_index >= lidar_data->frames[index].num_points) {
                            printf("❌ Invalid point index.\n");
                        } else {
                            printf("\nPoint %zu details:\n", point_index);
                            printf("Location: (%.2f, %.2f, %.2f)\n",
                                lidar_data->frames[index].location[point_index * 3],
                                lidar_data->frames[index].location[point_index * 3 + 1],
                                lidar_data->frames[index].location[point_index * 3 + 2]);
                            printf("Intensity: %.2f\n", lidar_data->frames[index].intensity[point_index]);
                            printf("X Limits: [%.2f, %.2f]\n", 
                                lidar_data->frames[index].x_limits[0],
                                lidar_data->frames[index].x_limits[1]);
                            printf("Y Limits: [%.2f, %.2f]\n",
                                lidar_data->frames[index].y_limits[0],
                                lidar_data->frames[index].y_limits[1]);
                            printf("Z Limits: [%.2f, %.2f]\n",
                                lidar_data->frames[index].z_limits[0],
                                lidar_data->frames[index].z_limits[1]);
                            printf("Color: [%d, %d]\n",
                                lidar_data->frames[index].color[0],
                                lidar_data->frames[index].color[1]);
                            printf("Normal: [%d, %d]\n",
                                lidar_data->frames[index].normal[0],
                                lidar_data->frames[index].normal[1]);
                        }
                    }
                }
                break;
            }
            case 4: { // Camera Data
                printf("\nCamera Data Options:\n");
                printf("1. View frame details\n");
                printf("2. Save frame as PNG\n");
                printf("3. Back to main menu\n");
                printf("Enter your choice (1-3): ");
                
                int cam_choice;
                if (scanf("%d", &cam_choice) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (cam_choice == 1 || cam_choice == 2) {
                    printf("Enter frame index (0-%zu): ", camera_data->num_frames - 1);
                    size_t index;
                    if (scanf("%zu", &index) != 1 || index >= camera_data->num_frames) {
                        printf("Invalid frame index\n");
                        while (getchar() != '\n');
                        break;
                    }

                    if (cam_choice == 1) {
                        printf("\nCamera Frame %zu details:\n", index);
                        printf("Dimensions: %dx%dx%d\n",
                               camera_data->frames[index].width,
                               camera_data->frames[index].height,
                               camera_data->frames[index].channels);
                        printf("Timestamp: %.6f\n", camera_data->timestamps[index]);
                    } else {
                        char out_filename[64];
                        snprintf(out_filename, sizeof(out_filename), "camera_frame_%zu.png", index);
                        save_camera_image(&camera_data->frames[index], out_filename);
                    }
                }
                break;
            }
            case 5: { // Test Target and Sensor Specifications
                printf("Testing Target and Sensor Specifications\n");
                printf("=======================================\n\n");

                // Test target specifications
                TargetSpec* carSpec = createCarSpec();
                TargetSpec* truckSpec = createTruckSpec();
                
                printf("Testing Car Specification:\n");
                printTargetSpec(carSpec);
                
                printf("Testing Truck Specification:\n");
                printTargetSpec(truckSpec);

                // Test sensor specifications
                RadarSpec* radarSpec = createRadarSpec();
                CameraSpec* cameraSpec = createCameraSpec();
                LidarSpec* lidarSpec = createLidarSpec();

                printRadarSpec(radarSpec);
                printCameraSpec(cameraSpec);
                printLidarSpec(lidarSpec);

                // Clean up
                freeTargetSpec(carSpec);
                freeTargetSpec(truckSpec);
                freeRadarSpec(radarSpec);
                freeCameraSpec(cameraSpec);
                freeLidarSpec(lidarSpec);
                break;
            }
            case 6: { // Test Data Streaming
                printf("\nTesting Data Streaming:\n");
                printf("Enter number of timestamps to process (max 2000): ");
                size_t num_timestamps;
                if (scanf("%zu", &num_timestamps) != 1 || num_timestamps > 2000) {
                    printf("Invalid number of timestamps\n");
                    while (getchar() != '\n');
                    break;
                }

                // Initialize last odometry
                LastOdometry last_odometry;
                last_odometry.vehicle = odometry_data->frames[0];
                last_odometry.timestamp = odometry_data->frames[0].timestamp;

                // Initialize ego motion
                EgoMotion ego_motion;
                reset_ego_motion(&ego_motion, odometry_data);

                printf("\nProcessing %zu timestamps...\n", num_timestamps);
                
                // Process each timestamp
                for (size_t i = 1; i < num_timestamps; i++) {
                    double t1 = odometry_data->frames[i-1].timestamp;
                    double t2 = odometry_data->frames[i].timestamp;
                    
                    printf("\nStreaming data between timestamps %.6f and %.6f\n", t1, t2);
                    
                    // Stream data between timestamps
                    StreamedData* sensor_data = stream_data(radar_data, lidar_data, camera_data, odometry_data, t1, t2);
                    
                    if (sensor_data) {
                        // Print summary of streamed data
                        printf("Streamed Data Summary at index %zu:\n", i);
                        
                        if (sensor_data->radar) {
                            printf("Radar frames: %zu\n", sensor_data->radar->num_frames);
                            printf("Radar timestamp: %.6f\n", sensor_data->radar->timestamps[0]);
                        }
                        
                        if (sensor_data->lidar) {
                            printf("Lidar frames: %zu\n", sensor_data->lidar->num_frames);
                            printf("Lidar timestamp: %.6f\n", sensor_data->lidar->timestamps[0]);
                        }
                        
                        if (sensor_data->camera) {
                            printf("Camera frames: %zu\n", sensor_data->camera->num_frames);
                            printf("Camera timestamp: %.6f\n", sensor_data->camera->timestamps[0]);
                        }
                        
                        if (sensor_data->odometry) {
                            printf("Odometry frames: %zu\n", sensor_data->odometry->num_frames);
                            printf("Odometry timestamp: %.6f\n", sensor_data->odometry->frames->timestamp);
                        }

                        // Free the streamed data
                        free_streamed_data(sensor_data);
                    }
                }
                break;
            }
            case 7: { // Test Ego Motion Estimation for user-selected frame
                printf("\nTesting Ego Motion Estimation for a selected frame:\n");
                printf("Enter frame index to test (1 to %zu): ", odometry_data->num_frames - 1);
                size_t idx;
                if (scanf("%zu", &idx) != 1 || idx < 1 || idx >= odometry_data->num_frames) {
                    printf("Invalid frame index.\n");
                    while (getchar() != '\n');
                    break;
                }

                // Initialize ego motion with time aligned to the previous frame
                EgoMotion ego_motion;
                reset_ego_motion_to_time(&ego_motion, odometry_data->frames[idx - 1].timestamp);

                // Initialize last odometry with frame[idx - 1]
                LastOdometry last_odometry;
                last_odometry.vehicle = odometry_data->frames[idx - 1];
                last_odometry.timestamp = odometry_data->frames[idx - 1].timestamp;

                const OdometryFrame* current_odometry = &odometry_data->frames[idx];

                printf("\nInitial State:\n");
                printf("Last Odometry (frame %zu):\n", idx - 1);
                printf("  Timestamp: %.6f\n", last_odometry.timestamp);
                printf("  Speed: %.2f m/s\n", last_odometry.vehicle.speed);
                printf("  Yaw Rate: %.2f rad/s\n", last_odometry.vehicle.yaw_rate);

                printf("\nCurrent Odometry (frame %zu):\n", idx);
                printf("  Timestamp: %.6f\n", current_odometry->timestamp);
                printf("  Speed: %.2f m/s\n", current_odometry->speed);
                printf("  Yaw Rate: %.2f rad/s\n", current_odometry->yaw_rate);

                // Estimate ego motion
                estimate_ego_motion(&ego_motion, &last_odometry, current_odometry);

                // Display results (all accumulated values)
                printf("\nEgo Motion History (count = %zu):\n", ego_motion.count);
                for (size_t i = 0; i < ego_motion.count; ++i) {
                    printf("  [%zu] Time: %.6f\n", i, ego_motion.time[i]);
                    printf("      Positional Displacement: [%.6f, %.6f, %.6f] meters\n",
                        ego_motion.positional_displacement[i][0],
                        ego_motion.positional_displacement[i][1],
                        ego_motion.positional_displacement[i][2]);
                    printf("      Rotational Displacement: [%.6f, %.6f, %.6f] degrees\n",
                        ego_motion.rotational_displacement[i][0],
                        ego_motion.rotational_displacement[i][1],
                        ego_motion.rotational_displacement[i][2]);
                }

                // Print cumulative pose to match MATLAB
                printf("\nCumulative Ego Pose:\n");
                printf("  X: %.6f m\n", ego_motion.cumulative_pose.x);
                printf("  Y: %.6f m\n", ego_motion.cumulative_pose.y);
                printf("  Theta: %.6f degrees\n", ego_motion.cumulative_pose.theta_deg);

                break;
            }
            case 8: { // Run Darknet YOLO Detection (Clean Wrapper Functions)
                printf("Running Darknet YOLO detection using clean wrapper functions.\n");
                printf("This demonstrates the clean separation between model loading and image detection.\n");
                
                // Step 1: Initialize the detector (loads model once)
                printf("\n=== STEP 1: INITIALIZING DETECTOR ===\n");
                DirectDarknetDetector* detector = direct_darknet_init(
                    "darknet/cfg/coco.data",    // Data configuration
                    "darknet/yolov4.cfg",       // Network configuration
                    "darknet/yolov4.weights",   // Pre-trained weights
                    0.25f,                      // Detection threshold
                    0.5f                        // Hierarchical threshold
                );
                
                if (!detector) {
                    printf("ERROR: Failed to initialize detector\n");
                    break;
                }
                
                // Step 2: Detect on image file
                printf("\n=== STEP 2: DETECTING ON IMAGE FILE ===\n");
                int result1 = direct_darknet_detect_image(
                    detector,
                    "camera_frame_0.png",           // Input image
                    "detections/detections_test_image.json",  // Output JSON
                    "detections/detection_test_image"     // Output image
                );
                
                if (result1 != 0) {
                    printf("ERROR: Detection on image file failed\n");
                    direct_darknet_cleanup(detector);
                    break;
                }
                
                // Step 3: Detect on camera frame data (pixels)
                printf("\n=== STEP 3: DETECTING ON CAMERA FRAME DATA ===\n");
                printf("Enter frame index (0-%zu): ", camera_data->num_frames - 1);
                size_t frame_idx;
                if (scanf("%zu", &frame_idx) != 1 || frame_idx >= camera_data->num_frames) {
                    printf("Invalid frame index.\n");
                    while (getchar() != '\n');
                    direct_darknet_cleanup(detector);
                    break;
                }
                
                const CameraImage* img = &camera_data->frames[frame_idx];
                printf("Processing camera frame %zu: %dx%dx%d\n", frame_idx, img->width, img->height, img->channels);
                
                // Generate filenames with frame index
                char json_filename[256];
                char img_filename[256];
                snprintf(json_filename, sizeof(json_filename), "detections/detections_pixels_frame_%zu.json", frame_idx);
                snprintf(img_filename, sizeof(img_filename), "detections/detection_pixels_frame_%zu", frame_idx);
                              
                int result2 = direct_darknet_detect_pixels(
                    detector,
                    img->data,                                    // Pixel data
                    img->width,                                   // Width
                    img->height,                                  // Height
                    img->channels,                                // Channels
                    json_filename,                                // Output JSON
                    img_filename                                  // Output image
                );
                
                if (result2 != 0) {
                    printf("ERROR: Detection on pixel data failed\n");
                    direct_darknet_cleanup(detector);
                    break;
                }
                
                // Step 4: Cleanup
                printf("\n=== STEP 4: CLEANUP ===\n");
                direct_darknet_cleanup(detector);
                
                break;
            }
            case 9: { // Delete all files in detections directory
                printf("Deleting all files in detections directory...\n");
                if (delete_all_files_in_directory("detections") != 0) {
                    printf("Error: Failed to delete files in detections directory\n");
                } else {
                    printf("Success: All files in detections directory deleted\n");
                }
                break;
            }
            case 10: { // Exit
                // Clean up
                for (size_t i = 0; i < num_targets; ++i) {
                    free(targets[i]);
                }
                free(radarSpec);
                free(lidarSpec);
                free(cameraSpec);
                
                free_odometry_data(odometry_data);
                free_radar_data(radar_data);
                free_lidar_data(lidar_data);
                free_camera_data(camera_data);
                
                free(all_detections);
                
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}