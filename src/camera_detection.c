#include "cJSON.h"
#include "camera_detection.h"
#include <stdio.h>
#include <stdlib.h>

int load_detections_from_json(const char* filename, CameraDetectionData* out, double timestamp) {
    FILE* f = fopen(filename, "r");
    if (!f) return -1;
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* data = malloc(len + 1);
    fread(data, 1, len, f);
    data[len] = 0;
    fclose(f);

    cJSON* root = cJSON_Parse(data);
    if (!root) { free(data); return -2; }
    int num = cJSON_GetArraySize(root);
    out->detections = malloc(num * sizeof(Detection));
    out->num_detections = num;
    out->timestamp = timestamp;

    for (int i = 0; i < num; ++i) {
        cJSON* det = cJSON_GetArrayItem(root, i);
        out->detections[i].x1 = cJSON_GetObjectItem(det, "x1")->valueint;
        out->detections[i].y1 = cJSON_GetObjectItem(det, "y1")->valueint;
        out->detections[i].x2 = cJSON_GetObjectItem(det, "x2")->valueint;
        out->detections[i].y2 = cJSON_GetObjectItem(det, "y2")->valueint;
        out->detections[i].conf = (float)cJSON_GetObjectItem(det, "conf")->valuedouble;
        out->detections[i].cls = cJSON_GetObjectItem(det, "cls")->valueint;
    }
    cJSON_Delete(root);
    free(data);
    return 0;
}