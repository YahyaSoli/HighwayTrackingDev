#include "../include/ego_motion.h"
#include <math.h>
#include <stddef.h>

static void update_displacement(double s, double w, double dT, double* dx, double* dy, double* dtheta_deg) {
    if (fabs(w) > YAW_RATE_EPSILON) {
        *dx = s / w * sin(w * dT);
        *dy = s / w * (1 - cos(w * dT));
    } else {
        *dx = s * dT;
        *dy = 0;
    }
    *dtheta_deg = rad2deg(w * dT);
}

void estimate_ego_motion(EgoMotion* ego_motion, LastOdometry* last_odometry, const OdometryFrame* current_odometry) {
    if (!ego_motion || !last_odometry || !current_odometry) return;
    if (ego_motion->count >= MAX_EGO_MOTION_HISTORY) return;

    double t_last = ego_motion->count > 0 ? ego_motion->time[ego_motion->count - 1] : last_odometry->timestamp;
    double t_current = current_odometry->timestamp;

    if (t_current > t_last) {
        double dT = t_current - t_last;
        double s = last_odometry->vehicle.speed;
        double w = last_odometry->vehicle.yaw_rate;
        double dx, dy, dtheta_deg;

        update_displacement(s, w, dT, &dx, &dy, &dtheta_deg);

        size_t idx = ego_motion->count;
        ego_motion->time[idx] = t_current;
        ego_motion->positional_displacement[idx][0] = dx;
        ego_motion->positional_displacement[idx][1] = dy;
        ego_motion->positional_displacement[idx][2] = 0;
        ego_motion->rotational_displacement[idx][0] = dtheta_deg;
        ego_motion->rotational_displacement[idx][1] = 0;
        ego_motion->rotational_displacement[idx][2] = 0;
        ego_motion->count++;

        // Update cumulative pose
        double theta_rad = ego_motion->cumulative_pose.theta_deg * M_PI / 180.0;
        ego_motion->cumulative_pose.x += dx * cos(theta_rad) - dy * sin(theta_rad);
        ego_motion->cumulative_pose.y += dx * sin(theta_rad) + dy * cos(theta_rad);
        ego_motion->cumulative_pose.theta_deg += dtheta_deg;
    }

    // Update last odometry
    last_odometry->vehicle = *current_odometry;
    last_odometry->timestamp = current_odometry->timestamp;
}

void reset_ego_motion(EgoMotion* ego_motion, const OdometryData* odometry_data) {
    if (!ego_motion) return;
    ego_motion->count = 0;
    ego_motion->cumulative_pose = (EgoPose){0, 0, 0};
    if (!odometry_data || odometry_data->num_frames == 0) return;

    ego_motion->time[0] = odometry_data->frames[0].timestamp;
    ego_motion->positional_displacement[0][0] = 0;
    ego_motion->positional_displacement[0][1] = 0;
    ego_motion->positional_displacement[0][2] = 0;
    ego_motion->rotational_displacement[0][0] = 0;
    ego_motion->rotational_displacement[0][1] = 0;
    ego_motion->rotational_displacement[0][2] = 0;
    ego_motion->count = 1;
}

void reset_ego_motion_to_time(EgoMotion* ego_motion, double t_reset) {
    if (!ego_motion) return;
    ego_motion->count = 0;
    ego_motion->cumulative_pose = (EgoPose){0, 0, 0};
    ego_motion->time[0] = t_reset;
    ego_motion->positional_displacement[0][0] = 0;
    ego_motion->positional_displacement[0][1] = 0;
    ego_motion->positional_displacement[0][2] = 0;
    ego_motion->rotational_displacement[0][0] = 0;
    ego_motion->rotational_displacement[0][1] = 0;
    ego_motion->rotational_displacement[0][2] = 0;
    ego_motion->count = 1;
}
