/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * UniformPoissonClutterModel.c
 *
 * Code generation for function 'UniformPoissonClutterModel'
 *
 */

/* Include files */
#include "UniformPoissonClutterModel.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = {
    13,                                                    /* lineNo */
    "UniformPoissonClutterModel/%validate.ClutterDensity", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+clutter\\UniformPoissonClutterM"
    "odel.m" /* pathName */
};

/* Function Definitions */
void c_UniformPoissonClutterModel_se(const emlrtStack *sp, real_T val)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = NULL;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &eb_emlrtRSI;
  if (muDoubleScalarIsInf(val) || muDoubleScalarIsNaN(val)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
                                  "MATLAB:validators:mustBeFinite",
                                  "MATLAB:validators:mustBeFinite", 0);
  }
  b_st.site = &eb_emlrtRSI;
  if (!(val > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "MATLAB:validators:mustBePositive",
                                  "MATLAB:validators:mustBePositive", 0);
  }
}

/* End of code generation (UniformPoissonClutterModel.c) */
