/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * AutomotiveCameraBoxes.c
 *
 * Code generation for function 'AutomotiveCameraBoxes'
 *
 */

/* Include files */
#include "AutomotiveCameraBoxes.h"
#include "UniformPoissonBirthModel.h"
#include "UniformPoissonClutterModel.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_types.h"

/* Variable Definitions */
static emlrtRSInfo jb_emlrtRSI = {
    199,                                   /* lineNo */
    "AutomotiveCameraBoxes/set.ImageSize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    200,                                   /* lineNo */
    "AutomotiveCameraBoxes/set.ImageSize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    201,                                   /* lineNo */
    "AutomotiveCameraBoxes/set.ImageSize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    202,                                   /* lineNo */
    "AutomotiveCameraBoxes/set.ImageSize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    203,                                   /* lineNo */
    "AutomotiveCameraBoxes/set.ImageSize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    204,                                   /* lineNo */
    "AutomotiveCameraBoxes/set.ImageSize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "sensorspecs\\AutomotiveCameraBoxes.m" /* pathName */
};

/* Function Definitions */
real_T AutomotiveCameraBoxes_getVolume(void)
{
  return 6.18475290624E+13;
}

void c_AutomotiveCameraBoxes_set_Ima(const emlrtStack *sp,
                                     c_fusion_tracker_sensorspecs_Au *obj)
{
  static const int16_T b_iv[9] = {800, 0, 0, 0, 600, 0, 320, 240, 1};
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 9; i++) {
    obj->MeasurementModel.Intrinsics[i] = b_iv[i];
  }
  obj->MeasurementModel.ImageSize[0] = 768.0;
  obj->MeasurementModel.ImageSize[1] = 1024.0;
  st.site = &jb_emlrtRSI;
  obj->DetectabilityModel.RangeLimits[0] = 0.0;
  obj->DetectabilityModel.RangeRateLimits[0] = -1.7976931348623157E+308;
  obj->DetectabilityModel.RangeLimits[1] = 100.0;
  obj->DetectabilityModel.RangeRateLimits[1] = 1.7976931348623157E+308;
  obj->DetectabilityModel.AzimuthLimits[0] = -32.619243071192827;
  obj->DetectabilityModel.AzimuthLimits[1] = 32.619243071192827;
  st.site = &kb_emlrtRSI;
  obj->DetectabilityModel.ElevationLimits[0] = -32.619243071192827;
  obj->DetectabilityModel.ElevationLimits[1] = 32.619243071192827;
  st.site = &lb_emlrtRSI;
  obj->NumFalsePositivesPerImage = 1.0;
  obj->NumNewTargetsPerImage = 1.0;
  st.site = &mb_emlrtRSI;
  st.site = &nb_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  c_UniformPoissonClutterModel_se(&b_st, 1.6168794698185391E-14);
  st.site = &ob_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  c_UniformPoissonBirthModel_set_(&b_st, 1.6168794698185391E-14);
}

/* End of code generation (AutomotiveCameraBoxes.c) */
