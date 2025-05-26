/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ObjectTrackOutputter.c
 *
 * Code generation for function 'ObjectTrackOutputter'
 *
 */

/* Include files */
#include "ObjectTrackOutputter.h"
#include "MultiModalEKFEstimator.h"
#include "TrackEstimator1.h"
#include "objectTrack.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "trackEstimator.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_types.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo jm_emlrtRSI = {
    36,                           /* lineNo */
    "ObjectTrackOutputter/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m" /* pathName */
};

static emlrtRSInfo km_emlrtRSI = {
    39,                           /* lineNo */
    "ObjectTrackOutputter/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m" /* pathName */
};

static emlrtRSInfo lm_emlrtRSI = {
    33,                           /* lineNo */
    "ObjectTrackOutputter/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m" /* pathName */
};

static emlrtRSInfo mm_emlrtRSI =
    {
        255,                       /* lineNo */
        "objectTrack/objectTrack", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo nm_emlrtRSI =
    {
        524,                         /* lineNo */
        "objectTrack/setProperties", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo om_emlrtRSI =
    {
        492,                         /* lineNo */
        "objectTrack/setProperties", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo pm_emlrtRSI =
    {
        488,                         /* lineNo */
        "objectTrack/setProperties", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo qm_emlrtRSI =
    {
        487,                         /* lineNo */
        "objectTrack/setProperties", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo rm_emlrtRSI =
    {
        485,                         /* lineNo */
        "objectTrack/setProperties", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo sm_emlrtRSI =
    {
        277,                          /* lineNo */
        "objectTrack/set.UpdateTime", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo tm_emlrtRSI =
    {
        287,                     /* lineNo */
        "objectTrack/set.State", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo ym_emlrtRSI =
    {
        355,                                        /* lineNo */
        "objectTrack/set.ObjectClassProbabilities", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo an_emlrtRSI =
    {
        358,                                        /* lineNo */
        "objectTrack/set.ObjectClassProbabilities", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo bn_emlrtRSI =
    {
        324,                               /* lineNo */
        "objectTrack/set.TrackLogicState", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    28,           /* lineNo */
    27,           /* colNo */
    "validatele", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatele.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnegative.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI =
    {
        359,                                        /* lineNo */
        17,                                         /* colNo */
        "objectTrack/set.ObjectClassProbabilities", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pName */
};

/* Function Definitions */
void ObjectTrackOutputter_setup(const emlrtStack *sp,
                                o_fusion_tracker_internal_compo *outputter,
                                trackingEKF *iobj_0)
{
  d_fusion_tracker_sensorspecs_Au b_outputter;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  f_fusion_tracker_internal_estim b_estimator_StateEstimator;
  f_fusion_tracker_internal_estim estimator_StateEstimator;
  objectTrack track;
  struct_T sampleTrackFromList_Hypothesis[2];
  real_T statePdf_StateCovariance[100];
  real_T sampleTrackFromList_LogWeights[2];
  real_T f_expl_temp;
  int32_T k;
  int32_T statePdf_ObjectClassID;
  uint32_T b_expl_temp;
  uint32_T c_expl_temp;
  boolean_T expl_temp[2];
  boolean_T d_expl_temp;
  boolean_T e_expl_temp;
  boolean_T exitg1;
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
  b_outputter = outputter->SensorSpecifications.f1;
  st.site = &lm_emlrtRSI;
  trackEstimator(&st, &outputter->TargetSpecifications.f1,
                 &outputter->TargetSpecifications.f2, &b_outputter, &iobj_0[0],
                 &estimator_StateEstimator);
  b_estimator_StateEstimator = estimator_StateEstimator;
  st.site = &jm_emlrtRSI;
  c_TrackEstimator_sampleDistribu(
      &b_estimator_StateEstimator, &b_expl_temp, &c_expl_temp, &d_expl_temp,
      &e_expl_temp, sampleTrackFromList_Hypothesis,
      sampleTrackFromList_LogWeights, expl_temp, &f_expl_temp);
  statePdf_ObjectClassID = c_MultiModalEKFEstimator_toObje(
      sampleTrackFromList_Hypothesis, sampleTrackFromList_LogWeights,
      track.pState, statePdf_StateCovariance, track.ObjectClassProbabilities);
  st.site = &km_emlrtRSI;
  b_st.site = &mm_emlrtRSI;
  track.TrackID = 0U;
  track.BranchID = 0U;
  track.SourceIndex = 1U;
  c_st.site = &rm_emlrtRSI;
  d_st.site = &sm_emlrtRSI;
  track.pUpdateTime = 0.0;
  track.Age = 0U;
  c_st.site = &qm_emlrtRSI;
  d_st.site = &tm_emlrtRSI;
  e_st.site = &sf_emlrtRSI;
  d_expl_temp = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 10)) {
    if ((!muDoubleScalarIsInf(track.pState[k])) &&
        (!muDoubleScalarIsNaN(track.pState[k]))) {
      k++;
    } else {
      d_expl_temp = false;
      exitg1 = true;
    }
  }
  if (!d_expl_temp) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:objectTrack:expectedFinite", 3, 4, 5, "State");
  }
  c_st.site = &pm_emlrtRSI;
  objectTrack_set_StateCovariance(&c_st, &track, statePdf_StateCovariance);
  track.IsConfirmed = false;
  track.IsCoasted = false;
  track.IsSelfReported = true;
  c_st.site = &om_emlrtRSI;
  d_st.site = &ym_emlrtRSI;
  e_st.site = &sf_emlrtRSI;
  d_expl_temp = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(track.ObjectClassProbabilities[k])) &&
        (!muDoubleScalarIsNaN(track.ObjectClassProbabilities[k]))) {
      k++;
    } else {
      d_expl_temp = false;
      exitg1 = true;
    }
  }
  if (!d_expl_temp) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:objectTrack:expectedFinite", 3, 4, 24,
        "ObjectClassProbabilities");
  }
  e_st.site = &sf_emlrtRSI;
  d_expl_temp = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(track.ObjectClassProbabilities[k] < 0.0)) {
      k++;
    } else {
      d_expl_temp = false;
      exitg1 = true;
    }
  }
  if (!d_expl_temp) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &q_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:objectTrack:expectedNonnegative", 3, 4, 24,
        "ObjectClassProbabilities");
  }
  e_st.site = &sf_emlrtRSI;
  d_expl_temp = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (track.ObjectClassProbabilities[k] <= 1.0) {
      k++;
    } else {
      d_expl_temp = false;
      exitg1 = true;
    }
  }
  if (!d_expl_temp) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &p_emlrtRTEI, "MATLAB:validateattributes:expectedArray",
        "MATLAB:objectTrack:notLessEqual", 9, 4, 24, "ObjectClassProbabilities",
        4, 2, "<=", 4, 1, "1");
  }
  d_st.site = &an_emlrtRSI;
  if (muDoubleScalarAbs(sumColumnB(track.ObjectClassProbabilities) - 1.0) >
      1.4901161193847656E-8) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &r_emlrtRTEI,
        "shared_tracking:objectTrack:invalidClassProbabilityVector",
        "shared_tracking:objectTrack:invalidClassProbabilityVector", 3, 4, 24,
        "ObjectClassProbabilities");
  }
  track.ObjectClassID = statePdf_ObjectClassID;
  c_st.site = &nm_emlrtRSI;
  d_st.site = &bn_emlrtRSI;
  track.pTrackLogicState = 0.0;
  outputter->SampleTrack = track;
  outputter->Estimator.StateEstimator = estimator_StateEstimator;
}

/* End of code generation (ObjectTrackOutputter.c) */
