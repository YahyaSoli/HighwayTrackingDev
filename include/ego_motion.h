#ifndef EGO_MOTION_H
#define EGO_MOTION_H

#include <math.h>
#include "motion_types.h"

// Function to estimate ego motion between two timestamps
void estimate_ego_motion(EgoMotion* ego_motion, LastOdometry* last_odometry, const OdometryFrame* current_odometry);

// Function to reset ego motion data
void reset_ego_motion(EgoMotion* ego_motion, const OdometryData* odometry_data);

// Helper function to convert radians to degrees
static inline double rad2deg(double rad) {
    return rad * 180.0 / M_PI;
}

#endif // EGO_MOTION_H 