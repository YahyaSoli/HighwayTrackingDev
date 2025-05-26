#include "../include/tracker_specs.h"
#include <stdlib.h>
#include <string.h>

// Helper function to create a new target specification
static TargetSpec* createTargetSpec(
    TargetType type,
    const char* referenceFrame,
    double maxSpeed,
    double maxAcceleration,
    double maxYawRate,
    double maxYawAcceleration,
    const double yawLimits[2],
    const double lengthLimits[2],
    const double widthLimits[2],
    const double heightLimits[2],
    const char* environment
) {
    TargetSpec* spec = (TargetSpec*)malloc(sizeof(TargetSpec));
    if (spec == NULL) return NULL;

    spec->type = type;
    spec->referenceFrame = strdup(referenceFrame);
    spec->maxSpeed = maxSpeed;
    spec->maxAcceleration = maxAcceleration;
    spec->maxYawRate = maxYawRate;
    spec->maxYawAcceleration = maxYawAcceleration;
    spec->yawLimits[0] = yawLimits[0];
    spec->yawLimits[1] = yawLimits[1];
    spec->lengthLimits[0] = lengthLimits[0];
    spec->lengthLimits[1] = lengthLimits[1];
    spec->widthLimits[0] = widthLimits[0];
    spec->widthLimits[1] = widthLimits[1];
    spec->heightLimits[0] = heightLimits[0];
    spec->heightLimits[1] = heightLimits[1];
    spec->environment = strdup(environment);
    return spec;
}

TargetSpec* createCarSpec(void) {
    double yawLimits[2] = {-10, 10};
    double lengthLimits[2] = {3.6, 5.6};
    double widthLimits[2] = {1.7, 2.0};
    double heightLimits[2] = {1.4, 2.0};
    return createTargetSpec(
        TARGET_TYPE_CAR,
        "ego",
        30.0,   // MaxSpeed
        4.0,    // MaxAcceleration
        5.0,    // MaxYawRate
        20.0,   // MaxYawAcceleration
        yawLimits,
        lengthLimits,
        widthLimits,
        heightLimits,
        "highway-driving"
    );
}

TargetSpec* createTruckSpec(void) {
    double yawLimits[2] = {-10, 10};
    double lengthLimits[2] = {16.0, 22.0};
    double widthLimits[2] = {2.0, 2.6};
    double heightLimits[2] = {3.5, 4.2};
    return createTargetSpec(
        TARGET_TYPE_TRUCK,
        "ego",
        20.0,   // MaxSpeed
        3.0,    // MaxAcceleration
        4.0,    // MaxYawRate
        10.0,   // MaxYawAcceleration
        yawLimits,
        lengthLimits,
        widthLimits,
        heightLimits,
        "highway-driving"
    );
}

RadarSpec* createRadarSpec(void) {
    RadarSpec* spec = (RadarSpec*)malloc(sizeof(RadarSpec));
    if (spec == NULL) return NULL;

    spec->type = SENSOR_TYPE_RADAR;
    
    // Set mounting location and angles from MATLAB code
    spec->mounting.location[0] = 4.68465;
    spec->mounting.location[1] = 0.01270;
    spec->mounting.location[2] = -0.11430;
    
    spec->mounting.angles[0] = 0.0;
    spec->mounting.angles[1] = -1.0;
    spec->mounting.angles[2] = 0.2;

    // Set other parameters from MATLAB code
    spec->maxNumMeasurements = 30;
    spec->fieldOfView[0] = 100.0;  // azimuth
    spec->fieldOfView[1] = 15.0;   // elevation
    spec->maxRange = 120.0;
    spec->maxRangeRate = 85.0;
    spec->detectionProbability = 0.9;
    spec->numFalsePositivesPerScan = 6.0;
    spec->numNewTargetsPerScan = 2.0;

    return spec;
}

CameraSpec* createCameraSpec(void) {
    CameraSpec* spec = (CameraSpec*)malloc(sizeof(CameraSpec));
    if (spec == NULL) return NULL;

    spec->type = SENSOR_TYPE_CAMERA;
    
    // Set mounting location and angles from MATLAB code
    spec->mounting.location[0] = 2.1398;
    spec->mounting.location[1] = -0.3180;
    spec->mounting.location[2] = 1.2014;
    
    spec->mounting.angles[0] = 0.0;
    spec->mounting.angles[1] = 2.0;
    spec->mounting.angles[2] = 0.2;

    // Set other parameters from MATLAB code
    spec->maxNumMeasurements = 20;
    spec->widthAccuracy = 10.0;
    spec->centerAccuracy = 10.0;
    spec->heightAccuracy = 5.0;
    spec->maxRange = 120.0;
    spec->detectionProbability = 0.95;
    spec->egoOriginHeight = 0.4826;

    // Set camera intrinsics matrix
    double intrinsics[3][3] = {
        {1176.29501, 0.0, 520.32287},
        {0.0, 1176.28913, 389.60511},
        {0.0, 0.0, 1.0}
    };
    memcpy(spec->intrinsics, intrinsics, sizeof(intrinsics));

    spec->imageSize[0] = 768;   // height
    spec->imageSize[1] = 1024;  // width
    spec->numFalsePositivesPerImage = 0.01;
    spec->numNewTargetsPerImage = 0.01;

    return spec;
}

LidarSpec* createLidarSpec(void) {
    LidarSpec* spec = (LidarSpec*)malloc(sizeof(LidarSpec));
    if (spec == NULL) return NULL;

    spec->type = SENSOR_TYPE_LIDAR;
    
    // Set mounting location and angles from MATLAB code
    spec->mounting.location[0] = 2.12090;
    spec->mounting.location[1] = 0.01270;
    spec->mounting.location[2] = 1.10712;
    
    spec->mounting.angles[0] = 0.0;
    spec->mounting.angles[1] = 2.0;
    spec->mounting.angles[2] = 0.2;

    // Set other parameters from MATLAB code
    spec->maxNumMeasurements = 20;
    spec->elevationLimits[0] = -25.0;
    spec->elevationLimits[1] = 25.0;
    spec->azimuthLimits[0] = -90.0;
    spec->azimuthLimits[1] = 90.0;
    spec->maxRange = 150.0;
    spec->detectionProbability = 0.9;
    spec->dimensionAccuracy = 0.25;
    spec->centerAccuracy = 0.25;
    spec->orientationAccuracy = 5.0;
    spec->numFalsePositivesPerScan = 2.0;
    spec->numNewTargetsPerScan = 1.0;

    return spec;
}

// Free functions
void freeTargetSpec(TargetSpec* spec) {
    if (spec != NULL) {
        free(spec->referenceFrame);
        free(spec->environment);
        free(spec);
    }
}

void freeRadarSpec(RadarSpec* spec) {
    free(spec);
}

void freeCameraSpec(CameraSpec* spec) {
    free(spec);
}

void freeLidarSpec(LidarSpec* spec) {
    free(spec);
} 