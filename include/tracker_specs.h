#ifndef TRACKER_SPECS_H
#define TRACKER_SPECS_H

#include <stdbool.h>

// Target type enumeration
typedef enum {
    TARGET_TYPE_CAR,
    TARGET_TYPE_TRUCK
} TargetType;

// Target specification structure
typedef struct {
    TargetType type;
    char* referenceFrame; // e.g., "ego"
    double maxSpeed;
    double maxAcceleration;
    double maxYawRate;
    double maxYawAcceleration;
    double yawLimits[2];
    double lengthLimits[2];
    double widthLimits[2];
    double heightLimits[2];
    char* environment;  // e.g., "highway-driving"
} TargetSpec;

// Sensor type enumeration
typedef enum {
    SENSOR_TYPE_RADAR,
    SENSOR_TYPE_CAMERA,
    SENSOR_TYPE_LIDAR
} SensorType;

// Common sensor mounting parameters
typedef struct {
    double location[3];  // [x, y, z] in meters
    double angles[3];    // [roll, pitch, yaw] in degrees
} SensorMounting;

// Radar sensor specification
typedef struct {
    SensorType type;
    SensorMounting mounting;
    int maxNumMeasurements;
    double fieldOfView[2];  // [azimuth, elevation] in degrees
    double maxRange;        // in meters
    double maxRangeRate;    // in m/s
    double detectionProbability;
    double numFalsePositivesPerScan;
    double numNewTargetsPerScan;
} RadarSpec;

// Camera sensor specification
typedef struct {
    SensorType type;
    SensorMounting mounting;
    int maxNumMeasurements;
    double widthAccuracy;
    double centerAccuracy;
    double heightAccuracy;
    double maxRange;
    double detectionProbability;
    double egoOriginHeight;
    double intrinsics[3][3];  // Camera intrinsic matrix
    int imageSize[2];        // [height, width]
    double numFalsePositivesPerImage;
    double numNewTargetsPerImage;
} CameraSpec;

// Lidar sensor specification
typedef struct {
    SensorType type;
    SensorMounting mounting;
    int maxNumMeasurements;
    double elevationLimits[2];  // [min, max] in degrees
    double azimuthLimits[2];    // [min, max] in degrees
    double maxRange;
    double detectionProbability;
    double dimensionAccuracy;
    double centerAccuracy;
    double orientationAccuracy;
    double numFalsePositivesPerScan;
    double numNewTargetsPerScan;
} LidarSpec;

// Function declarations for creating specifications
TargetSpec* createCarSpec(void);
TargetSpec* createTruckSpec(void);
RadarSpec* createRadarSpec(void);
CameraSpec* createCameraSpec(void);
LidarSpec* createLidarSpec(void);

// Function declarations for freeing specifications
void freeTargetSpec(TargetSpec* spec);
void freeRadarSpec(RadarSpec* spec);
void freeCameraSpec(CameraSpec* spec);
void freeLidarSpec(LidarSpec* spec);

#endif // TRACKER_SPECS_H 