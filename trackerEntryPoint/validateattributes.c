/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * validateattributes.c
 *
 * Code generation for function 'validateattributes'
 *
 */

/* Include files */
#include "validateattributes.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "mwmathutil.h"

/* Function Definitions */
void validateattributes(const emlrtStack *sp, const real_T a[9])
{
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sf_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(a[k])) && (!muDoubleScalarIsNaN(a[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:ExtendedKalmanFilter:expectedFinite", 3, 4, 12, "ProcessNoise");
  }
}

/* End of code generation (validateattributes.c) */
