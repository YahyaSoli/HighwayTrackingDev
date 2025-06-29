#ifndef MOTION_TYPES_H
#define MOTION_TYPES_H

#include "sensor_data.h"

#define MAX_EGO_MOTION_HISTORY 2000

typedef struct {
    double x;
    double y;
    double theta_deg;  // orientation in degrees
} EgoPose;

// Structure to hold ego motion data
typedef struct {
    double time[MAX_EGO_MOTION_HISTORY];
    double positional_displacement[MAX_EGO_MOTION_HISTORY][3];
    double rotational_displacement[MAX_EGO_MOTION_HISTORY][3];
    size_t count;
    EgoPose cumulative_pose;
} EgoMotion;

// Structure to hold last odometry data
typedef struct {
    OdometryFrame vehicle;
    double timestamp;
} LastOdometry;

#endif // MOTION_TYPES_H
