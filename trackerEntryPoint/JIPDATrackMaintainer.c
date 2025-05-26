/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * JIPDATrackMaintainer.c
 *
 * Code generation for function 'JIPDATrackMaintainer'
 *
 */

/* Include files */
#include "JIPDATrackMaintainer.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_types.h"

/* Variable Definitions */
static emlrtRSInfo en_emlrtRSI = {
    16,                                                     /* lineNo */
    "JIPDATrackMaintainer/%validate.ConfirmationThreshold", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m" /* pathName */
};

static emlrtRSInfo fn_emlrtRSI = {
    8,                /* lineNo */
    "mustBeLessThan", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\validators\\mustBeLessTh"
    "an.m" /* pathName */
};

static emlrtRSInfo gn_emlrtRSI = {
    17,                                                 /* lineNo */
    "JIPDATrackMaintainer/%validate.DeletionThreshold", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m" /* pathName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    18,                     /* lineNo */
    5,                      /* colNo */
    "binaryRelopValidator", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\validators\\private\\bin"
    "aryRelopValidator.m" /* pName */
};

/* Function Definitions */
void c_JIPDATrackMaintainer_set_Conf(const emlrtStack *sp,
                                     n_fusion_tracker_internal_compo *obj,
                                     real_T val)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = NULL;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &en_emlrtRSI;
  if (!(val > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "MATLAB:validators:mustBePositive",
                                  "MATLAB:validators:mustBePositive", 0);
  }
  b_st.site = &en_emlrtRSI;
  c_st.site = &fn_emlrtRSI;
  if (!(val < 1.0)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &s_emlrtRTEI, "MATLAB:validators:mustBeLessThan",
        "MATLAB:validators:mustBeLessThan", 3, 4, 1, "1");
  }
  obj->ConfirmationThreshold = val;
}

void c_JIPDATrackMaintainer_set_Dele(const emlrtStack *sp,
                                     n_fusion_tracker_internal_compo *obj,
                                     real_T val)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = NULL;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &gn_emlrtRSI;
  if (!(val > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "MATLAB:validators:mustBePositive",
                                  "MATLAB:validators:mustBePositive", 0);
  }
  obj->DeletionThreshold = val;
}

/* End of code generation (JIPDATrackMaintainer.c) */
