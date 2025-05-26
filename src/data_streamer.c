#include <stdlib.h>
#include <string.h>
#include "../include/data_streamer.h"

// Helper function to count valid frames between timestamps
static size_t count_valid_frames(double* timestamps, size_t num_frames, double t1, double t2) {
    size_t count = 0;
    for (size_t i = 0; i < num_frames; i++) {
        if (timestamps[i] > t1 && timestamps[i] <= t2) {
            count++;
        }
    }
    return count;
}

// Helper function to count valid odometry frames between timestamps
static size_t count_valid_odometry_frames(OdometryFrame* frames, size_t num_frames, double t1, double t2) {
    size_t count = 0;
    for (size_t i = 0; i < num_frames; i++) {
        if (frames[i].timestamp > t1 && frames[i].timestamp <= t2) {
            count++;
        }
    }
    return count;
}

// Helper function to copy radar frame
static void copy_radar_frame(RadarPointCloud* dest, const RadarPointCloud* src) {
    dest->num_points = src->num_points;
    
    // Allocate memory for arrays
    dest->x = (float*)malloc(src->num_points * sizeof(float));
    dest->y = (float*)malloc(src->num_points * sizeof(float));
    dest->z = (float*)malloc(src->num_points * sizeof(float));
    dest->snr = (float*)malloc(src->num_points * sizeof(float));
    dest->radial_speed = (float*)malloc(src->num_points * sizeof(float));
    dest->noise = (float*)malloc(src->num_points * sizeof(float));
    dest->rcs = (float*)malloc(src->num_points * sizeof(float));
    dest->power = (float*)malloc(src->num_points * sizeof(float));
    dest->timestamp = (float*)malloc(src->num_points * sizeof(float));

    // Copy data
    memcpy(dest->x, src->x, src->num_points * sizeof(float));
    memcpy(dest->y, src->y, src->num_points * sizeof(float));
    memcpy(dest->z, src->z, src->num_points * sizeof(float));
    memcpy(dest->snr, src->snr, src->num_points * sizeof(float));
    memcpy(dest->radial_speed, src->radial_speed, src->num_points * sizeof(float));
    memcpy(dest->noise, src->noise, src->num_points * sizeof(float));
    memcpy(dest->rcs, src->rcs, src->num_points * sizeof(float));
    memcpy(dest->power, src->power, src->num_points * sizeof(float));
    memcpy(dest->timestamp, src->timestamp, src->num_points * sizeof(float));
}

// Helper function to copy lidar frame
static void copy_lidar_frame(LidarPointCloud* dest, const LidarPointCloud* src) {
    dest->num_points = src->num_points;
    
    // Allocate and copy arrays
    dest->location = (float*)malloc(src->num_points * 3 * sizeof(float));
    dest->intensity = (float*)malloc(src->num_points * sizeof(float));
    
    memcpy(dest->location, src->location, src->num_points * 3 * sizeof(float));
    memcpy(dest->intensity, src->intensity, src->num_points * sizeof(float));
    
    // Copy other fields
    dest->count = src->count;
    memcpy(dest->x_limits, src->x_limits, 2 * sizeof(float));
    memcpy(dest->y_limits, src->y_limits, 2 * sizeof(float));
    memcpy(dest->z_limits, src->z_limits, 2 * sizeof(float));
    memcpy(dest->color, src->color, 2 * sizeof(int));
    memcpy(dest->normal, src->normal, 2 * sizeof(int));
}

// Helper function to copy camera frame
static void copy_camera_frame(CameraImage* dest, const CameraImage* src) {
    dest->width = src->width;
    dest->height = src->height;
    dest->channels = src->channels;
    
    size_t data_size = src->width * src->height * src->channels;
    dest->data = (unsigned char*)malloc(data_size);
    memcpy(dest->data, src->data, data_size);
}

StreamedData* stream_data(RadarData* radar_data, 
                         LidarData* lidar_data, 
                         CameraData* camera_data, 
                         OdometryData* odometry_data,
                         double t1, 
                         double t2) {
    StreamedData* current_data = (StreamedData*)malloc(sizeof(StreamedData));
    if (!current_data) return NULL;

    // Initialize all pointers to NULL
    current_data->radar = NULL;
    current_data->lidar = NULL;
    current_data->camera = NULL;
    current_data->odometry = NULL;

    // Process Radar data
    if (radar_data) {
        size_t valid_frames = count_valid_frames(radar_data->timestamps, radar_data->num_frames, t1, t2);
        if (valid_frames > 0) {
            current_data->radar = (RadarData*)malloc(sizeof(RadarData));
            current_data->radar->num_frames = valid_frames;
            current_data->radar->timestamps = (double*)malloc(valid_frames * sizeof(double));
            current_data->radar->frames = (RadarPointCloud*)malloc(valid_frames * sizeof(RadarPointCloud));

            size_t current_idx = 0;
            for (size_t i = 0; i < radar_data->num_frames; i++) {
                if (radar_data->timestamps[i] > t1 && radar_data->timestamps[i] <= t2) {
                    current_data->radar->timestamps[current_idx] = radar_data->timestamps[i];
                    copy_radar_frame(&current_data->radar->frames[current_idx], &radar_data->frames[i]);
                    current_idx++;
                }
            }
        }
    }

    // Process Lidar data
    if (lidar_data) {
        size_t valid_frames = count_valid_frames(lidar_data->timestamps, lidar_data->num_frames, t1, t2);
        if (valid_frames > 0) {
            current_data->lidar = (LidarData*)malloc(sizeof(LidarData));
            current_data->lidar->num_frames = valid_frames;
            current_data->lidar->timestamps = (double*)malloc(valid_frames * sizeof(double));
            current_data->lidar->frames = (LidarPointCloud*)malloc(valid_frames * sizeof(LidarPointCloud));

            size_t current_idx = 0;
            for (size_t i = 0; i < lidar_data->num_frames; i++) {
                if (lidar_data->timestamps[i] > t1 && lidar_data->timestamps[i] <= t2) {
                    current_data->lidar->timestamps[current_idx] = lidar_data->timestamps[i];
                    copy_lidar_frame(&current_data->lidar->frames[current_idx], &lidar_data->frames[i]);
                    current_idx++;
                }
            }
        }
    }

    // Process Camera data
    if (camera_data) {
        size_t valid_frames = count_valid_frames(camera_data->timestamps, camera_data->num_frames, t1, t2);
        if (valid_frames > 0) {
            current_data->camera = (CameraData*)malloc(sizeof(CameraData));
            current_data->camera->num_frames = valid_frames;
            current_data->camera->timestamps = (double*)malloc(valid_frames * sizeof(double));
            current_data->camera->frames = (CameraImage*)malloc(valid_frames * sizeof(CameraImage));

            size_t current_idx = 0;
            for (size_t i = 0; i < camera_data->num_frames; i++) {
                if (camera_data->timestamps[i] > t1 && camera_data->timestamps[i] <= t2) {
                    current_data->camera->timestamps[current_idx] = camera_data->timestamps[i];
                    copy_camera_frame(&current_data->camera->frames[current_idx], &camera_data->frames[i]);
                    current_idx++;
                }
            }
        }
    }

    // Process Odometry data
    if (odometry_data) {
        size_t valid_frames = count_valid_odometry_frames(odometry_data->frames, odometry_data->num_frames, t1, t2);
        if (valid_frames > 0) {
            current_data->odometry = (OdometryData*)malloc(sizeof(OdometryData));
            current_data->odometry->num_frames = valid_frames;
            current_data->odometry->frames = (OdometryFrame*)malloc(valid_frames * sizeof(OdometryFrame));

            size_t current_idx = 0;
            for (size_t i = 0; i < odometry_data->num_frames; i++) {
                if (odometry_data->frames[i].timestamp > t1 && odometry_data->frames[i].timestamp <= t2) {
                    current_data->odometry->frames[current_idx] = odometry_data->frames[i];
                    current_idx++;
                }
            }
        }
    }

    return current_data;
}

void free_streamed_data(StreamedData* data) {
    if (!data) return;

    // Free Radar data
    if (data->radar) {
        for (size_t i = 0; i < data->radar->num_frames; i++) {
            RadarPointCloud* frame = &data->radar->frames[i];
            free(frame->x);
            free(frame->y);
            free(frame->z);
            free(frame->snr);
            free(frame->radial_speed);
            free(frame->noise);
            free(frame->rcs);
            free(frame->power);
            free(frame->timestamp);
        }
        free(data->radar->timestamps);
        free(data->radar->frames);
        free(data->radar);
    }

    // Free Lidar data
    if (data->lidar) {
        for (size_t i = 0; i < data->lidar->num_frames; i++) {
            LidarPointCloud* frame = &data->lidar->frames[i];
            free(frame->location);
            free(frame->intensity);
        }
        free(data->lidar->timestamps);
        free(data->lidar->frames);
        free(data->lidar);
    }

    // Free Camera data
    if (data->camera) {
        for (size_t i = 0; i < data->camera->num_frames; i++) {
            free(data->camera->frames[i].data);
        }
        free(data->camera->timestamps);
        free(data->camera->frames);
        free(data->camera);
    }

    // Free Odometry data
    if (data->odometry) {
        free(data->odometry->frames);
        free(data->odometry);
    }

    free(data);
} 