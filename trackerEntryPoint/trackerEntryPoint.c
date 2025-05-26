/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackerEntryPoint.c
 *
 * Code generation for function 'trackerEntryPoint'
 *
 */

/* Include files */
#include "trackerEntryPoint.h"
#include "AutomotiveCameraBoxes.h"
#include "SystemCore.h"
#include "UniformPoissonBirthModel.h"
#include "UniformPoissonClutterModel.h"
#include "mustBeFinite.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_emxutil.h"
#include "trackerEntryPoint_types.h"
#include <string.h>

/* Variable Definitions */
static fusion_tracker_JIPDATracker tracker;

static boolean_T tracker_not_empty;

static emlrtRSInfo emlrtRSI = {
    16,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    17,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    18,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    19,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    21,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    22,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    30,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    32,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    40,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    44,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    39,                  /* lineNo */
    "trackerEntryPoint", /* fcnName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    161,                                                   /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MountingLocation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    162,                                                   /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MountingLocation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    177,                                                 /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MountingAngles", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    178,                                                 /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MountingAngles", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    205,                                           /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MaxRange", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    209,                                           /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MaxRange", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    210,                                           /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MaxRange", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    531,                                                   /* lineNo */
    "AutomotiveRadarClusteredPoints/setDefaultProperties", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    250,                                                           /* lineNo */
    "AutomotiveRadarClusteredPoints/set.NumFalsePositivesPerScan", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    259,                                                       /* lineNo */
    "AutomotiveRadarClusteredPoints/set.NumNewTargetsPerScan", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    224,                                               /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MaxRangeRate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    225,                                               /* lineNo */
    "AutomotiveRadarClusteredPoints/set.MaxRangeRate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveRadarClusteredPoint"
    "s.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    16,                                              /* lineNo */
    "FieldOfViewPointModel/%validate.AzimuthLimits", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+detectability\\FieldOfViewPoint"
    "Model.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    17,                                                /* lineNo */
    "FieldOfViewPointModel/%validate.ElevationLimits", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+detectability\\FieldOfViewPoint"
    "Model.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    187,                                    /* lineNo */
    "AutomotiveCameraBoxes/set.Intrinsics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    188,                                    /* lineNo */
    "AutomotiveCameraBoxes/set.Intrinsics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    190,                                    /* lineNo */
    "AutomotiveCameraBoxes/set.Intrinsics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    191,                                    /* lineNo */
    "AutomotiveCameraBoxes/set.Intrinsics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo hc_emlrtRSI = {
    192,                                    /* lineNo */
    "AutomotiveCameraBoxes/set.Intrinsics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    34,                         /* lineNo */
    "multiSensorTargetTracker", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\multiSensorTargetTra"
    "cker.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    50,                         /* lineNo */
    "multiSensorTargetTracker", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\multiSensorTargetTra"
    "cker.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    51,                         /* lineNo */
    "multiSensorTargetTracker", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\multiSensorTargetTra"
    "cker.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    103,                         /* lineNo */
    "JIPDATracker/JIPDATracker", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    1,               /* lineNo */
    "System/System", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\System.p" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    1,                                       /* lineNo */
    "SystemProp/matlabCodegenNotifyAnyProp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemProp.p" /* pathName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    4,                   /* lineNo */
    16,                  /* colNo */
    "trackerEntryPoint", /* fName */
    "C:\\Users\\20200866\\OneDrive - TU "
    "Eindhoven\\Documents\\MATLAB\\Examples\\R2024b\\fusion\\HighwayVehicleTrac"
    "kingForAutomotiveAp"
    "plicationsExample\\trackerEntryPoint.m" /* pName */
};

/* Function Definitions */
void trackerEntryPoint(const emlrtStack *sp, const struct0_T *radarDet,
                       const struct1_T *lidarDet, const struct2_T *cameraDet,
                       const struct3_T *egoMotion, emxArray_struct4_T *tracks)
{
  static const real_T dv[9] = {1176.29501, 0.0,       0.0, 0.0, 1176.28913, 0.0,
                               520.32287,  389.60511, 1.0};
  static const real_T rmat[9] = {0.99984769515639138,   -6.0920267229363468E-5,
                                 -0.017452300111251116, 0.0,
                                 0.9999939076577905,    -0.0034906514152237326,
                                 0.017452406437283512,  0.003490119772105844,
                                 0.999841603742075};
  static const int8_T b_iv[18] = {1, 0, 0, 0, 1, 0, 0, 0, 1,
                                  1, 0, 0, 0, 1, 0, 0, 0, 1};
  c_fusion_tracker_sensorspecs_Au cameraSpec;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T d_sensorSpecifications_f1_Measu[18];
  int32_T i;
  (void)radarDet;
  (void)lidarDet;
  (void)cameraDet;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (!tracker_not_empty) {
    real_T c_sensorSpecifications_f1_Measu[6];
    boolean_T flag;
    /*  Define target specifications */
    /*  Define sensor specifications */
    st.site = &emlrtRSI;
    for (i = 0; i < 6; i++) {
      c_sensorSpecifications_f1_Measu[i] = 0.0;
    }
    c_sensorSpecifications_f1_Measu[0] = 4.68465;
    c_sensorSpecifications_f1_Measu[1] = 0.0127;
    c_sensorSpecifications_f1_Measu[2] = -0.1143;
    b_st.site = &n_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = NULL;
    b_st.site = &o_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = NULL;
    st.site = &b_emlrtRSI;
    for (i = 0; i < 18; i++) {
      d_sensorSpecifications_f1_Measu[i] = b_iv[i];
    }
    for (i = 0; i < 3; i++) {
      int32_T e_sensorSpecifications_f1_Measu;
      d_sensorSpecifications_f1_Measu[3 * i] = rmat[3 * i];
      e_sensorSpecifications_f1_Measu = 3 * i + 1;
      d_sensorSpecifications_f1_Measu[e_sensorSpecifications_f1_Measu] =
          rmat[e_sensorSpecifications_f1_Measu];
      e_sensorSpecifications_f1_Measu = 3 * i + 2;
      d_sensorSpecifications_f1_Measu[e_sensorSpecifications_f1_Measu] =
          rmat[e_sensorSpecifications_f1_Measu];
    }
    real_T dv1[2];
    b_st.site = &t_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = NULL;
    b_st.site = &u_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = NULL;
    st.site = &c_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    c_st.site = &cb_emlrtRSI;
    d_st.site = &fb_emlrtRSI;
    b_st.site = &ab_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    c_UniformPoissonClutterModel_se(&c_st, 1.1574074074074074E-7);
    b_st.site = &bb_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    c_UniformPoissonBirthModel_set_(&c_st, 1.1574074074074074E-7);
    st.site = &d_emlrtRSI;
    b_st.site = &hb_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    c_UniformPoissonClutterModel_se(&c_st, 4.0849673202614381E-8);
    b_st.site = &ib_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    c_UniformPoissonBirthModel_set_(&c_st, 4.0849673202614381E-8);
    st.site = &e_emlrtRSI;
    b_st.site = &db_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    c_UniformPoissonClutterModel_se(&c_st, 2.4509803921568627E-7);
    st.site = &f_emlrtRSI;
    b_st.site = &fb_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    c_UniformPoissonBirthModel_set_(&c_st, 8.1699346405228761E-8);
    st.site = &g_emlrtRSI;
    c_AutomotiveCameraBoxes_set_Ima(&st, &cameraSpec);
    st.site = &h_emlrtRSI;
    memcpy(&cameraSpec.MeasurementModel.Intrinsics[0], &dv[0],
           9U * sizeof(real_T));
    b_st.site = &dc_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = NULL;
    dv1[0] = -23.521804499357511;
    dv1[1] = 23.521804499357511;
    e_st.site = &ub_emlrtRSI;
    mustBeFinite(&e_st, dv1);
    cameraSpec.DetectabilityModel.AzimuthLimits[0] = -23.521804499357511;
    cameraSpec.DetectabilityModel.AzimuthLimits[1] = 23.521804499357511;
    b_st.site = &ec_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = NULL;
    dv1[0] = -18.079289756638421;
    dv1[1] = 18.079289756638421;
    e_st.site = &vb_emlrtRSI;
    mustBeFinite(&e_st, dv1);
    cameraSpec.DetectabilityModel.ElevationLimits[0] = -18.079289756638421;
    cameraSpec.DetectabilityModel.ElevationLimits[1] = 18.079289756638421;
    b_st.site = &fc_emlrtRSI;
    AutomotiveCameraBoxes_getVolume();
    b_st.site = &gc_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    c_UniformPoissonClutterModel_se(&c_st, 1.6168794698185391E-14);
    b_st.site = &hc_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    c_UniformPoissonBirthModel_set_(&c_st, 1.6168794698185391E-14);
    /*  Create JIPDA tracker */
    st.site = &k_emlrtRSI;
    b_st.site = &ic_emlrtRSI;
    tracker.c_ConfirmationExistenceProbabil = 0.9;
    tracker.DeletionExistenceProbability = 0.1;
    tracker.MaxNumEvents = rtInf;
    c_st.site = &lc_emlrtRSI;
    d_st.site = &mc_emlrtRSI;
    d_st.site = &mc_emlrtRSI;
    tracker.isInitialized = 0;
    for (i = 0; i < 7; i++) {
      tracker.tunablePropertyChanged[i] = false;
    }
    b_st.site = &jc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    flag = (tracker.isInitialized == 1);
    if (flag) {
      tracker.TunablePropsChanged = true;
      tracker.tunablePropertyChanged[0] = true;
    }
    b_st.site = &jc_emlrtRSI;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .LengthLimits[0] = 3.6;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .LengthLimits[1] = 5.6;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .WidthLimits[0] = 1.7;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .WidthLimits[1] = 2.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .HeightLimits[0] = 1.4;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .HeightLimits[1] = 2.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.SpeedLimits[0] = -30.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.SpeedLimits[1] = 30.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawLimits[0] = -10.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawLimits[1] = 10.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawRateLimits[0] = -5.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawRateLimits[1] = 5.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.HorizontalAccelerationVariance = 5.333333333333333;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.AngularAccelerationVariance = 133.33333333333334;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalVelocityLimits[0] = -3.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalVelocityLimits[1] = 3.0;
    tracker.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalAccelerationVariance = 0.0192;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .LengthLimits[0] = 16.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .LengthLimits[1] = 22.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .WidthLimits[0] = 2.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .WidthLimits[1] = 2.6;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .HeightLimits[0] = 3.5;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .HeightLimits[1] = 4.2;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.SpeedLimits[0] = -20.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.SpeedLimits[1] = 20.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawLimits[0] = -10.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawLimits[1] = 10.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawRateLimits[0] = -4.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawRateLimits[1] = 4.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.HorizontalAccelerationVariance = 3.0;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.AngularAccelerationVariance = 33.333333333333336;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalVelocityLimits[0] = -2.4;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalVelocityLimits[1] = 2.4;
    tracker.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalAccelerationVariance = 0.010799999999999999;
    b_st.site = &kc_emlrtRSI;
    c_st.site = &pc_emlrtRSI;
    flag = (tracker.isInitialized == 1);
    if (flag) {
      tracker.TunablePropsChanged = true;
      tracker.tunablePropertyChanged[1] = true;
    }
    for (i = 0; i < 6; i++) {
      tracker.SensorSpecifications.f1.MeasurementModel.OriginPosition[i] =
          c_sensorSpecifications_f1_Measu[i];
    }
    memcpy(&tracker.SensorSpecifications.f1.MeasurementModel.Orientation[0],
           &d_sensorSpecifications_f1_Measu[0], 18U * sizeof(real_T));
    tracker.SensorSpecifications.f1.DetectabilityModel.AzimuthLimits[0] = -30.0;
    tracker.SensorSpecifications.f1.DetectabilityModel.AzimuthLimits[1] = 30.0;
    tracker.SensorSpecifications.f1.DetectabilityModel.ElevationLimits[0] =
        -10.0;
    tracker.SensorSpecifications.f1.DetectabilityModel.ElevationLimits[1] =
        10.0;
    tracker.SensorSpecifications.f1.DetectabilityModel.RangeLimits[0] = 0.0;
    tracker.SensorSpecifications.f1.DetectabilityModel.RangeLimits[1] = 120.0;
    tracker.SensorSpecifications.f1.DetectabilityModel.RangeRateLimits[0] =
        -85.0;
    tracker.SensorSpecifications.f1.DetectabilityModel.RangeRateLimits[1] =
        85.0;
    tracker.SensorSpecifications.f1.NumFalsePositivesPerScan = 6.0;
    tracker.SensorSpecifications.f1.NumNewTargetsPerScan = 2.0;
    tracker.SensorSpecifications.f3 = cameraSpec;
    tracker_not_empty = true;
    st.site = &i_emlrtRSI;
    b_st.site = &pc_emlrtRSI;
    flag = (tracker.isInitialized == 1);
    if (flag) {
      tracker.TunablePropsChanged = true;
      tracker.tunablePropertyChanged[2] = true;
    }
    st.site = &i_emlrtRSI;
    tracker.MaxMahalanobisDistance = 7.0;
  }
  /*  ✅ CORRECT WAY TO CALL WITH MULTIPLE SENSORS */
  st.site = &j_emlrtRSI;
  b_st.site = &oc_emlrtRSI;
  SystemCore_step(&b_st, &tracker, egoMotion->Time,
                  egoMotion->EgoRotationalDisplacement, tracks);
}

void trackerEntryPoint_emx_free(const emlrtStack *sp)
{
  d_emxFreeStruct_fusion_tracker_(sp, &tracker);
}

void trackerEntryPoint_emx_init(const emlrtStack *sp)
{
  d_emxInitStruct_fusion_tracker_(sp, &tracker, &t_emlrtRTEI);
}

void trackerEntryPoint_init(void)
{
  tracker_not_empty = false;
}

/* End of code generation (trackerEntryPoint.c) */
