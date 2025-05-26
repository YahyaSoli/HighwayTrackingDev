/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackEstimator.c
 *
 * Code generation for function 'trackEstimator'
 *
 */

/* Include files */
#include "trackEstimator.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_types.h"
#include "trackingEKF.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = {
    33,                                              /* lineNo */
    "MultiModalEKFEstimator/MultiModalEKFEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\MultiModalEKFEstima"
    "tor.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    19,               /* lineNo */
    "trackEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+utils\\trackEstimator.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    20,               /* lineNo */
    "trackEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+utils\\trackEstimator.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    15,               /* lineNo */
    "trackEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+utils\\trackEstimator.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    17,               /* lineNo */
    "trackEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+utils\\trackEstimator.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    18,               /* lineNo */
    "trackEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+utils\\trackEstimator.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    21,               /* lineNo */
    "trackEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+utils\\trackEstimator.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    56,                            /* lineNo */
    "IPDAEstimator/IPDAEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    55,                            /* lineNo */
    "IPDAEstimator/IPDAEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    59,                            /* lineNo */
    "IPDAEstimator/IPDAEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    216,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    227,                /* lineNo */
    "parseCoderInputs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    40,                          /* lineNo */
    "stickyStruct/dotReference", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stickyStruct.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    46,                              /* lineNo */
    "TrackEstimator/TrackEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\TrackEstimator.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    49,                              /* lineNo */
    "TrackEstimator/TrackEstimator", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\TrackEstimator.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    151,           /* lineNo */
    "parseInputs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\TrackEstimator.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    162,                /* lineNo */
    "parseCoderInputs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\TrackEstimator.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    23,                                        /* lineNo */
    "TrackEstimator/set.TargetSpecifications", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\TrackEstimator.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    32,                                       /* lineNo */
    "IPDAEstimator/set.TargetSpecifications", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    45,                                                /* lineNo */
    "MultiModalEKFEstimator/set.TargetSpecifications", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\MultiModalEKFEstima"
    "tor.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    31,                                        /* lineNo */
    "TrackEstimator/set.SensorSpecifications", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\TrackEstimator.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    41,                                       /* lineNo */
    "IPDAEstimator/set.SensorSpecifications", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    50,                                                /* lineNo */
    "MultiModalEKFEstimator/set.SensorSpecifications", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\MultiModalEKFEstima"
    "tor.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    56,                     /* lineNo */
    "TrackEstimator/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\TrackEstimator.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    71,                    /* lineNo */
    "IPDAEstimator/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    72,                    /* lineNo */
    "IPDAEstimator/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo je_emlrtRSI = {
    67,                    /* lineNo */
    "IPDAEstimator/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\IPDAEstimator.m" /* pathName */
};

static emlrtRSInfo ke_emlrtRSI = {
    90,                             /* lineNo */
    "MultiModalEKFEstimator/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\MultiModalEKFEstima"
    "tor.m" /* pathName */
};

static emlrtRSInfo le_emlrtRSI = {
    93,                             /* lineNo */
    "MultiModalEKFEstimator/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\MultiModalEKFEstima"
    "tor.m" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI = {
    58,                        /* lineNo */
    "EKFStateEstimator/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+estimators\\EKFStateEstimator.m" /* pathName */
};

/* Function Definitions */
void b_trackEstimator(
    const emlrtStack *sp, const real_T c_tgtSpecs_f1_StateTransitionMo[2],
    const real_T d_tgtSpecs_f1_StateTransitionMo[2],
    const real_T e_tgtSpecs_f1_StateTransitionMo[2],
    const real_T f_tgtSpecs_f1_StateTransitionMo[2],
    const real_T g_tgtSpecs_f1_StateTransitionMo[2],
    const real_T h_tgtSpecs_f1_StateTransitionMo[2],
    real_T i_tgtSpecs_f1_StateTransitionMo,
    real_T j_tgtSpecs_f1_StateTransitionMo,
    const real_T k_tgtSpecs_f1_StateTransitionMo[2],
    real_T l_tgtSpecs_f1_StateTransitionMo,
    const real_T c_tgtSpecs_f2_StateTransitionMo[2],
    const real_T d_tgtSpecs_f2_StateTransitionMo[2],
    const real_T e_tgtSpecs_f2_StateTransitionMo[2],
    const c_fusion_tracker_internal_motio *f_tgtSpecs_f2_StateTransitionMo,
    k_fusion_tracker_internal_estim *trkEstimator_StateEstimator)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T Q[9];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &bd_emlrtRSI;
  st.site = &hd_emlrtRSI;
  b_st.site = &kd_emlrtRSI;
  c_st.site = &nd_emlrtRSI;
  d_st.site = &od_emlrtRSI;
  b_st.site = &ld_emlrtRSI;
  b_st.site = &md_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  st.site = &id_emlrtRSI;
  b_st.site = &vd_emlrtRSI;
  c_st.site = &xd_emlrtRSI;
  d_st.site = &yd_emlrtRSI;
  b_st.site = &wd_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  st.site = &ed_emlrtRSI;
  b_st.site = &ae_emlrtRSI;
  c_st.site = &be_emlrtRSI;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance = i_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance = j_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance = l_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      d_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      e_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      f_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      g_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      h_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] = k_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      d_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      e_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      d_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      e_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      f_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      g_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      h_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] = k_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      d_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      e_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel =
      *f_tgtSpecs_f2_StateTransitionMo;
  d_st.site = &ce_emlrtRSI;
  st.site = &fd_emlrtRSI;
  b_st.site = &de_emlrtRSI;
  c_st.site = &ee_emlrtRSI;
  d_st.site = &fe_emlrtRSI;
  st.site = &jd_emlrtRSI;
  b_st.site = &ge_emlrtRSI;
  c_st.site = &je_emlrtRSI;
  d_st.site = &ke_emlrtRSI;
  d_st.site = &le_emlrtRSI;
  memset(&Q[0], 0, 9U * sizeof(real_T));
  Q[0] = i_tgtSpecs_f1_StateTransitionMo;
  Q[4] = j_tgtSpecs_f1_StateTransitionMo;
  Q[8] = l_tgtSpecs_f1_StateTransitionMo;
  e_st.site = &oe_emlrtRSI;
  b_trackingEKF_trackingEKF(&e_st, Q);
  d_st.site = &ke_emlrtRSI;
  d_st.site = &le_emlrtRSI;
  memset(&Q[0], 0, 9U * sizeof(real_T));
  Q[0] = f_tgtSpecs_f2_StateTransitionMo->HorizontalAccelerationVariance;
  Q[4] = f_tgtSpecs_f2_StateTransitionMo->AngularAccelerationVariance;
  Q[8] = f_tgtSpecs_f2_StateTransitionMo->VerticalAccelerationVariance;
  e_st.site = &oe_emlrtRSI;
  b_trackingEKF_trackingEKF(&e_st, Q);
  c_st.site = &he_emlrtRSI;
  c_st.site = &ie_emlrtRSI;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance = i_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance = j_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance = l_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      f_tgtSpecs_f2_StateTransitionMo->HorizontalAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      f_tgtSpecs_f2_StateTransitionMo->AngularAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      d_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      e_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      f_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      g_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      h_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] = k_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      d_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      e_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      f_tgtSpecs_f2_StateTransitionMo->SpeedLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      f_tgtSpecs_f2_StateTransitionMo->YawLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      f_tgtSpecs_f2_StateTransitionMo->YawRateLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      f_tgtSpecs_f2_StateTransitionMo->VerticalVelocityLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      d_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      e_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      f_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      g_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      h_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] = k_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      d_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      e_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      f_tgtSpecs_f2_StateTransitionMo->SpeedLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      f_tgtSpecs_f2_StateTransitionMo->YawLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      f_tgtSpecs_f2_StateTransitionMo->YawRateLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      f_tgtSpecs_f2_StateTransitionMo->VerticalVelocityLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      f_tgtSpecs_f2_StateTransitionMo->VerticalAccelerationVariance;
}

void c_trackEstimator(
    const emlrtStack *sp, const real_T c_tgtSpecs_f1_StateTransitionMo[2],
    const real_T d_tgtSpecs_f1_StateTransitionMo[2],
    const real_T e_tgtSpecs_f1_StateTransitionMo[2],
    const real_T f_tgtSpecs_f1_StateTransitionMo[2],
    const real_T g_tgtSpecs_f1_StateTransitionMo[2],
    const real_T h_tgtSpecs_f1_StateTransitionMo[2],
    real_T i_tgtSpecs_f1_StateTransitionMo,
    real_T j_tgtSpecs_f1_StateTransitionMo,
    const real_T k_tgtSpecs_f1_StateTransitionMo[2],
    real_T l_tgtSpecs_f1_StateTransitionMo,
    const real_T c_tgtSpecs_f2_StateTransitionMo[2],
    const real_T d_tgtSpecs_f2_StateTransitionMo[2],
    const real_T e_tgtSpecs_f2_StateTransitionMo[2],
    const c_fusion_tracker_internal_motio *f_tgtSpecs_f2_StateTransitionMo,
    const c_fusion_tracker_sensorspecs_Au *sensorSpecs,
    o_fusion_tracker_internal_estim *trkEstimator_StateEstimator)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T Q[9];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &bd_emlrtRSI;
  st.site = &hd_emlrtRSI;
  b_st.site = &kd_emlrtRSI;
  c_st.site = &nd_emlrtRSI;
  d_st.site = &od_emlrtRSI;
  b_st.site = &ld_emlrtRSI;
  b_st.site = &md_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  st.site = &id_emlrtRSI;
  b_st.site = &vd_emlrtRSI;
  c_st.site = &xd_emlrtRSI;
  d_st.site = &yd_emlrtRSI;
  b_st.site = &wd_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  st.site = &ed_emlrtRSI;
  b_st.site = &ae_emlrtRSI;
  c_st.site = &be_emlrtRSI;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance = i_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance = j_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance = l_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      d_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      e_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      f_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      g_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      h_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] = k_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      d_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      e_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      d_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      e_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      f_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      g_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      h_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] = k_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      d_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      e_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0]
      .StateTransitionModel.StationaryMotionModel.MotionModel =
      *f_tgtSpecs_f2_StateTransitionMo;
  d_st.site = &ce_emlrtRSI;
  st.site = &fd_emlrtRSI;
  b_st.site = &de_emlrtRSI;
  c_st.site = &ee_emlrtRSI;
  d_st.site = &fe_emlrtRSI;
  st.site = &jd_emlrtRSI;
  b_st.site = &ge_emlrtRSI;
  c_st.site = &je_emlrtRSI;
  d_st.site = &ke_emlrtRSI;
  d_st.site = &le_emlrtRSI;
  memset(&Q[0], 0, 9U * sizeof(real_T));
  Q[0] = i_tgtSpecs_f1_StateTransitionMo;
  Q[4] = j_tgtSpecs_f1_StateTransitionMo;
  Q[8] = l_tgtSpecs_f1_StateTransitionMo;
  e_st.site = &oe_emlrtRSI;
  b_trackingEKF_trackingEKF(&e_st, Q);
  d_st.site = &ke_emlrtRSI;
  d_st.site = &le_emlrtRSI;
  memset(&Q[0], 0, 9U * sizeof(real_T));
  Q[0] = f_tgtSpecs_f2_StateTransitionMo->HorizontalAccelerationVariance;
  Q[4] = f_tgtSpecs_f2_StateTransitionMo->AngularAccelerationVariance;
  Q[8] = f_tgtSpecs_f2_StateTransitionMo->VerticalAccelerationVariance;
  e_st.site = &oe_emlrtRSI;
  b_trackingEKF_trackingEKF(&e_st, Q);
  c_st.site = &he_emlrtRSI;
  c_st.site = &ie_emlrtRSI;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance = i_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance = j_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance = l_tgtSpecs_f1_StateTransitionMo;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      f_tgtSpecs_f2_StateTransitionMo->HorizontalAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      f_tgtSpecs_f2_StateTransitionMo->AngularAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      d_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      e_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      f_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      g_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      h_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] = k_tgtSpecs_f1_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      d_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      e_tgtSpecs_f2_StateTransitionMo[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      f_tgtSpecs_f2_StateTransitionMo->SpeedLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      f_tgtSpecs_f2_StateTransitionMo->YawLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      f_tgtSpecs_f2_StateTransitionMo->YawRateLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      f_tgtSpecs_f2_StateTransitionMo->VerticalVelocityLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      d_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      e_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      f_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      g_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      h_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] = k_tgtSpecs_f1_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      d_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      e_tgtSpecs_f2_StateTransitionMo[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      f_tgtSpecs_f2_StateTransitionMo->SpeedLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      f_tgtSpecs_f2_StateTransitionMo->YawLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      f_tgtSpecs_f2_StateTransitionMo->YawRateLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      f_tgtSpecs_f2_StateTransitionMo->VerticalVelocityLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      f_tgtSpecs_f2_StateTransitionMo->VerticalAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.SensorSpecifications[0] =
      *sensorSpecs;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .SensorSpecifications[0] = *sensorSpecs;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .SensorSpecifications[0] = *sensorSpecs;
}

void trackEstimator(
    const emlrtStack *sp, const c_fusion_tracker_targetspecs_Hi *tgtSpecs_f1,
    const d_fusion_tracker_targetspecs_Hi *tgtSpecs_f2,
    const d_fusion_tracker_sensorspecs_Au *sensorSpecs, trackingEKF *iobj_0,
    f_fusion_tracker_internal_estim *trkEstimator_StateEstimator)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  trackingEKF *b_obj_TrackingFilter;
  trackingEKF *obj_TrackingFilter;
  real_T Q[9];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &bd_emlrtRSI;
  st.site = &hd_emlrtRSI;
  b_st.site = &kd_emlrtRSI;
  c_st.site = &nd_emlrtRSI;
  d_st.site = &od_emlrtRSI;
  b_st.site = &ld_emlrtRSI;
  b_st.site = &md_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  st.site = &id_emlrtRSI;
  b_st.site = &vd_emlrtRSI;
  c_st.site = &xd_emlrtRSI;
  d_st.site = &yd_emlrtRSI;
  b_st.site = &wd_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  st.site = &ed_emlrtRSI;
  b_st.site = &ae_emlrtRSI;
  c_st.site = &be_emlrtRSI;
  d_st.site = &ce_emlrtRSI;
  st.site = &fd_emlrtRSI;
  b_st.site = &de_emlrtRSI;
  c_st.site = &ee_emlrtRSI;
  d_st.site = &fe_emlrtRSI;
  st.site = &jd_emlrtRSI;
  b_st.site = &ge_emlrtRSI;
  c_st.site = &je_emlrtRSI;
  d_st.site = &ke_emlrtRSI;
  d_st.site = &le_emlrtRSI;
  memset(&Q[0], 0, 9U * sizeof(real_T));
  Q[0] = tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
             .HorizontalAccelerationVariance;
  Q[4] = tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
             .AngularAccelerationVariance;
  Q[8] = tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
             .VerticalAccelerationVariance;
  e_st.site = &oe_emlrtRSI;
  obj_TrackingFilter = trackingEKF_trackingEKF(&e_st, &iobj_0[0], Q);
  d_st.site = &ke_emlrtRSI;
  d_st.site = &le_emlrtRSI;
  memset(&Q[0], 0, 9U * sizeof(real_T));
  Q[0] = tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
             .HorizontalAccelerationVariance;
  Q[4] = tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
             .AngularAccelerationVariance;
  Q[8] = tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
             .VerticalAccelerationVariance;
  e_st.site = &oe_emlrtRSI;
  b_obj_TrackingFilter = trackingEKF_trackingEKF(&e_st, &iobj_0[1], Q);
  c_st.site = &he_emlrtRSI;
  c_st.site = &ie_emlrtRSI;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.LengthLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.LengthLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .HorizontalAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .AngularAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .VerticalAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .HorizontalAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .AngularAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.WidthLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.HeightLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .SpeedLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .YawLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .YawRateLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .VerticalVelocityLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.LengthLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.WidthLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.HeightLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .SpeedLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .YawLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .YawRateLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .VerticalVelocityLimits[0];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.WidthLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.HeightLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .SpeedLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .YawLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .YawRateLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      tgtSpecs_f1->StateTransitionModel.StationaryMotionModel.MotionModel
          .VerticalVelocityLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.LengthLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.WidthLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.HeightLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .SpeedLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .YawLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .YawRateLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .VerticalVelocityLimits[1];
  trkEstimator_StateEstimator->StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      tgtSpecs_f2->StateTransitionModel.StationaryMotionModel.MotionModel
          .VerticalAccelerationVariance;
  trkEstimator_StateEstimator->StateEstimator.SensorSpecifications[0] =
      *sensorSpecs;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .TargetSpecifications[0] = *tgtSpecs_f1;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1
      .SensorSpecifications[0] = *sensorSpecs;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f1.TrackingFilter =
      obj_TrackingFilter;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .TargetSpecifications[0] = *tgtSpecs_f2;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2
      .SensorSpecifications[0] = *sensorSpecs;
  trkEstimator_StateEstimator->StateEstimator.Estimators.f2.TrackingFilter =
      b_obj_TrackingFilter;
}

/* End of code generation (trackEstimator.c) */
