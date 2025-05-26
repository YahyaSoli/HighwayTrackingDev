#ifndef SENSOR_LOADER_H
#define SENSOR_LOADER_H

#include "sensor_data.h"

// Odometry data functions
OdometryData* load_odometry_data(const char* filename);
void free_odometry_data(OdometryData* odometry_data);

// Radar data functions
RadarData* load_radar_data(const char* filename);
void free_radar_data(RadarData* radar_data);

// Lidar data functions
LidarData* load_lidar_data(const char* filename);
void free_lidar_data(LidarData* lidar_data);

// Camera data functions
CameraData* load_camera_data(const char* filename);
void free_camera_data(CameraData* camera_data);

// Utility functions
void save_camera_image(const CameraImage* image, const char* filename);

#endif // SENSOR_LOADER_H 