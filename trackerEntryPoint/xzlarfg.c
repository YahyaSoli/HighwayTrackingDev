/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarfg.c
 *
 * Code generation for function 'xzlarfg'
 *
 */

/* Include files */
#include "xzlarfg.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "xnrm2.h"
#include "xscal.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Function Definitions */
real_T b_xzlarfg(const emlrtStack *sp, int32_T n, real_T *alpha1, real_T x[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T tau;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  tau = 0.0;
  if (n > 0) {
    real_T xnorm;
    st.site = &af_emlrtRSI;
    xnorm = c_xnrm2(n - 1, x);
    if (xnorm != 0.0) {
      xnorm = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }
      if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
        int32_T knt;
        boolean_T overflow;
        knt = 0;
        overflow = (n > 2147483646);
        do {
          int32_T scalarLB;
          int32_T vectorUB;
          knt++;
          st.site = &bf_emlrtRSI;
          b_st.site = &if_emlrtRSI;
          c_st.site = &jf_emlrtRSI;
          if (overflow) {
            d_st.site = &p_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }
          scalarLB = (((n - 1) / 2) << 1) + 2;
          vectorUB = scalarLB - 2;
          for (k = 2; k <= vectorUB; k += 2) {
            __m128d r;
            r = _mm_loadu_pd(&x[k - 1]);
            _mm_storeu_pd(&x[k - 1],
                          _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r));
          }
          for (k = scalarLB; k <= n; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                 (knt < 20));
        st.site = &cf_emlrtRSI;
        xnorm = c_xnrm2(n - 1, x);
        xnorm = muDoubleScalarHypot(*alpha1, xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &df_emlrtRSI;
        c_xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x);
        st.site = &ef_emlrtRSI;
        for (k = 0; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }
        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &ff_emlrtRSI;
        c_xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x);
        *alpha1 = xnorm;
      }
    }
  }
  return tau;
}

real_T xzlarfg(const emlrtStack *sp, int32_T n, real_T *alpha1, real_T x[9],
               int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T tau;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  tau = 0.0;
  if (n > 0) {
    real_T xnorm;
    st.site = &af_emlrtRSI;
    xnorm = b_xnrm2(&st, n - 1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }
      if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
        int32_T b;
        int32_T knt;
        boolean_T overflow;
        knt = 0;
        b = (ix0 + n) - 2;
        overflow = ((ix0 <= b) && (b > 2147483646));
        do {
          int32_T scalarLB;
          int32_T vectorUB;
          knt++;
          st.site = &bf_emlrtRSI;
          b_st.site = &if_emlrtRSI;
          c_st.site = &jf_emlrtRSI;
          if (overflow) {
            d_st.site = &p_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }
          scalarLB = ((b - ix0) + 1) / 2 * 2 + ix0;
          vectorUB = scalarLB - 2;
          for (k = ix0; k <= vectorUB; k += 2) {
            __m128d r;
            r = _mm_loadu_pd(&x[k - 1]);
            r = _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r);
            _mm_storeu_pd(&x[k - 1], r);
          }
          for (k = scalarLB; k <= b; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                 (knt < 20));
        st.site = &cf_emlrtRSI;
        xnorm = b_xnrm2(&st, n - 1, x, ix0);
        xnorm = muDoubleScalarHypot(*alpha1, xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &df_emlrtRSI;
        b_xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x, ix0);
        st.site = &ef_emlrtRSI;
        for (k = 0; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }
        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &ff_emlrtRSI;
        b_xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x, ix0);
        *alpha1 = xnorm;
      }
    }
  }
  return tau;
}

/* End of code generation (xzlarfg.c) */
