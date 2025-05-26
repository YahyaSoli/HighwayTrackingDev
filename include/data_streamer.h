#ifndef DATA_STREAMER_H
#define DATA_STREAMER_H

#include "sensor_data.h"
#include "motion_types.h"

// Structure to hold streamed data
typedef struct {
    RadarData* radar;
    LidarData* lidar;
    CameraData* camera;
    OdometryData* odometry;
} StreamedData;

// Function to stream data between two timestamps
StreamedData* stream_data(RadarData* radar_data, 
                         LidarData* lidar_data, 
                         CameraData* camera_data, 
                         OdometryData* odometry_data,
                         double t1, 
                         double t2);

// Function to free streamed data
void free_streamed_data(StreamedData* data);

#endif // DATA_STREAMER_H 