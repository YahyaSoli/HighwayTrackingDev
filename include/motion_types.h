#ifndef MOTION_TYPES_H
#define MOTION_TYPES_H

#include "sensor_data.h"

#define MAX_EGO_MOTION_HISTORY 2000

// Structure to hold ego motion data
typedef struct {
    double time[MAX_EGO_MOTION_HISTORY];
    double positional_displacement[MAX_EGO_MOTION_HISTORY][3];
    double rotational_displacement[MAX_EGO_MOTION_HISTORY][3];
    size_t count;
} EgoMotion;

// Structure to hold last odometry data
typedef struct {
    OdometryFrame vehicle;
    double timestamp;
} LastOdometry;

#endif // MOTION_TYPES_H 