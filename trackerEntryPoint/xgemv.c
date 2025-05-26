/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.c
 *
 * Code generation for function 'xgemv'
 *
 */

/* Include files */
#include "xgemv.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include <string.h>

/* Function Definitions */
void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[9],
           int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ug_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != 0) {
    int32_T i;
    int32_T ix;
    b_st.site = &wg_emlrtRSI;
    if (m > 2147483646) {
      c_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)m;
    memset(&y[0], 0, (uint32_T)i * sizeof(real_T));
    ix = ix0;
    i = ia0 + 3 * (n - 1);
    for (iac = ia0; iac <= i; iac += 3) {
      int32_T b;
      b = (iac + m) - 1;
      b_st.site = &vg_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        c_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b; ia++) {
        int32_T i1;
        i1 = ia - iac;
        y[i1] += A[ia - 1] * x[ix - 1];
      }
      ix++;
    }
  }
}

/* End of code generation (xgemv.c) */
