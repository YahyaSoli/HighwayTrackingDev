#ifndef EGO_MOTION_H
#define EGO_MOTION_H

#include <math.h>
#include "motion_types.h"

// Main function to estimate ego motion
void estimate_ego_motion(EgoMotion* ego_motion, LastOdometry* last_odometry, const OdometryFrame* current_odometry);

// Reset ego motion using odometry data
void reset_ego_motion(EgoMotion* ego_motion, const OdometryData* odometry_data);

// Reset ego motion using a specific timestamp
void reset_ego_motion_to_time(EgoMotion* ego_motion, double t_reset);

// Helper: Convert radians to degrees
static inline double rad2deg(double rad) {
    return rad * 180.0 / M_PI;
}

// Threshold for considering yaw rate zero
#define YAW_RATE_EPSILON 1e-6

#endif // EGO_MOTION_H
