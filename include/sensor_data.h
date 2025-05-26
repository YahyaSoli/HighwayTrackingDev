#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <stddef.h>

//_____________LIDAR _____________

// Define a struct for Lidar point cloud data
typedef struct {
    float* location;       // [N x 3] flattened array (x1,y1,z1,x2,y2,z2,...)
    float* intensity;      // [N x 1]
    float count;           // scalar
    float x_limits[2];     // [1 x 2]
    float y_limits[2];     // [1 x 2]
    float z_limits[2];     // [1 x 2]
    int color[2];          // [1 x 2] (fixed size int array)
    int normal[2];         // [1 x 2] (fixed size int array)
    size_t num_points;     // derived from intensity/location
} LidarPointCloud;

// Define a struct for Lidar sensor data including timestamps and pointclouds
typedef struct {
    double* timestamps;         // array of timestamps
    LidarPointCloud* frames;    // array of Lidar point clouds
    size_t num_frames;          // number of point cloud frames
} LidarData;

//_____________RADAR _____________

// Define a struct for Radar data
// Define a struct for Radar point cloud data
typedef struct {
    float* x;
    float* y;
    float* z;
    float* snr;
    float* radial_speed;
    float* noise;
    float* rcs;
    float* power;
    float* timestamp;
    size_t num_points;
} RadarPointCloud;

// Define a struct for Radar sensor data including timestamps and pointclouds
typedef struct {
    double* timestamps;         // array of global timestamps for each frame
    RadarPointCloud* frames;    // array of Radar point clouds
    size_t num_frames;          // number of point cloud frames
} RadarData;

//_____________ODOMETRY_____________
// Define a struct for Odometry measurements (per frame)
typedef struct {
    double speed;       // scalar speed
    double yaw_rate;    // scalar yaw rate
    double timestamp;   // scalar timestamp
} OdometryFrame;

// Define a struct for Odometry sensor data
typedef struct {
    OdometryFrame* frames; // array of odometry frames
    size_t num_frames;     // number of frames
} OdometryData;

//_____________CAMERA_____________
typedef struct {
    unsigned char* data;  // RGB image (after CHW→HWC if needed)
    int width;
    int height;
    int channels;         // should be 3
} CameraImage;

typedef struct {
    double* timestamps;     // [2019]
    CameraImage* frames;    // [2019]
    size_t num_frames;
} CameraData;

#endif // SENSOR_DATA_H 