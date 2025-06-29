#ifndef CAMERA_DETECTION_H
#define CAMERA_DETECTION_H

#include "sensor_data.h"
#include <unistd.h>     // for pipe(), fork(), dup2(), read(), write(), execlp()
#include <sys/types.h>  // for pid_t
#include <sys/wait.h>   // for waitpid()
#include <fcntl.h> 

typedef struct {
    int x1, y1, x2, y2;
    float conf;
    int cls;
} Detection;

typedef struct {
    Detection* detections; // dynamically allocated array
    int num_detections;
    double timestamp;      // from camera_data->timestamps[frame_idx]
} CameraDetectionData;

typedef struct {
    size_t frame_idx;
    char json_filename[128];
    char img_filename[128];
} YoloTask;

int load_detections_from_json(const char* filename, CameraDetectionData* out, double timestamp);	

#endif // CAMERA_DETECTION_H