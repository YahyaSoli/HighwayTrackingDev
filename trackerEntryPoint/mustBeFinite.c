/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mustBeFinite.c
 *
 * Code generation for function 'mustBeFinite'
 *
 */

/* Include files */
#include "mustBeFinite.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "mwmathutil.h"

/* Function Definitions */
void mustBeFinite(const emlrtStack *sp, const real_T A[2])
{
  int32_T k;
  boolean_T p;
  p = true;
  for (k = 0; k < 2; k++) {
    if (p) {
      real_T d;
      d = A[k];
      if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
                                  "MATLAB:validators:mustBeFinite",
                                  "MATLAB:validators:mustBeFinite", 0);
  }
}

/* End of code generation (mustBeFinite.c) */
