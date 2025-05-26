#include "../include/ego_motion.h"
#include <math.h>

void estimate_ego_motion(EgoMotion* ego_motion, LastOdometry* last_odometry, const OdometryFrame* current_odometry) {
    if (!ego_motion || !last_odometry || !current_odometry) return;
    if (ego_motion->count >= MAX_EGO_MOTION_HISTORY) return;

    double t_last = ego_motion->count > 0 ? ego_motion->time[ego_motion->count - 1] : last_odometry->timestamp;
    double t_current = current_odometry->timestamp;
    
    if (t_current > t_last) {
        double dT = t_current - t_last;
        double s = last_odometry->vehicle.speed;
        double w = last_odometry->vehicle.yaw_rate;
        double dx, dy;
        if (fabs(w) > 0) {
            // Circular motion
            dx = s/w * sin(w * dT);
            dy = s/w * (1 - cos(w * dT));
        } else {
            // Linear motion
            dx = s * dT;
            dy = 0;
        }
        size_t idx = ego_motion->count;
        ego_motion->time[idx] = t_current;
        ego_motion->positional_displacement[idx][0] = dx;
        ego_motion->positional_displacement[idx][1] = dy;
        ego_motion->positional_displacement[idx][2] = 0;
        ego_motion->rotational_displacement[idx][0] = rad2deg(w * dT);
        ego_motion->rotational_displacement[idx][1] = 0;
        ego_motion->rotational_displacement[idx][2] = 0;
        ego_motion->count++;
    }
    
    // Update last odometry
    last_odometry->vehicle = *current_odometry;
    last_odometry->timestamp = current_odometry->timestamp;
}

void reset_ego_motion(EgoMotion* ego_motion, const OdometryData* odometry_data) {
    if (!ego_motion) return;
    ego_motion->count = 0;
    if (!odometry_data || odometry_data->num_frames == 0) {
        return;
    }
    // Initialize with the first timestamp
    ego_motion->time[0] = odometry_data->frames[0].timestamp;
    ego_motion->positional_displacement[0][0] = 0;
    ego_motion->positional_displacement[0][1] = 0;
    ego_motion->positional_displacement[0][2] = 0;
    ego_motion->rotational_displacement[0][0] = 0;
    ego_motion->rotational_displacement[0][1] = 0;
    ego_motion->rotational_displacement[0][2] = 0;
    ego_motion->count = 1;
} 