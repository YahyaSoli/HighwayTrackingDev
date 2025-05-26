/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eigSkewHermitianStandard.c
 *
 * Code generation for function 'eigSkewHermitianStandard'
 *
 */

/* Include files */
#include "eigSkewHermitianStandard.h"
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "warning.h"
#include "xhseqr.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
void eigSkewHermitianStandard(const emlrtStack *sp, const real_T A[100],
                              creal_T V[10])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack st;
  real_T T[100];
  real_T work[10];
  real_T xnorm;
  int32_T b_i;
  int32_T exitg1;
  int32_T ia;
  int32_T j;
  int32_T k;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ig_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  b_st.site = &jg_emlrtRSI;
  memcpy(&T[0], &A[0], 100U * sizeof(real_T));
  c_st.site = &kg_emlrtRSI;
  if (b_anyNonFinite(A)) {
    int32_T i;
    for (j = 0; j < 100; j++) {
      T[j] = rtNaN;
    }
    i = 2;
    for (j = 0; j < 9; j++) {
      if (i <= 10) {
        memset(&T[(j * 10 + i) + -1], 0, (uint32_T)(-i + 11) * sizeof(real_T));
      }
      i++;
    }
  } else {
    real_T tau[9];
    int32_T i;
    c_st.site = &lg_emlrtRSI;
    d_st.site = &og_emlrtRSI;
    memset(&work[0], 0, 10U * sizeof(real_T));
    for (b_i = 0; b_i < 9; b_i++) {
      __m128d r;
      real_T alpha1_tmp;
      int32_T alpha1_tmp_tmp;
      int32_T in;
      int32_T knt;
      int32_T lastc;
      int32_T lastv;
      int32_T scalarLB;
      in = (b_i + 1) * 10;
      alpha1_tmp_tmp = (b_i + 10 * b_i) + 1;
      alpha1_tmp = T[alpha1_tmp_tmp];
      i = b_i + 3;
      i = muIntScalarMin_sint32(i, 10) + b_i * 10;
      e_st.site = &pg_emlrtRSI;
      tau[b_i] = 0.0;
      f_st.site = &af_emlrtRSI;
      xnorm = xnrm2(&f_st, 8 - b_i, T, i);
      if (xnorm != 0.0) {
        xnorm = muDoubleScalarHypot(alpha1_tmp, xnorm);
        if (alpha1_tmp >= 0.0) {
          xnorm = -xnorm;
        }
        if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          j = (i - b_i) + 7;
          do {
            knt++;
            f_st.site = &bf_emlrtRSI;
            g_st.site = &if_emlrtRSI;
            h_st.site = &jf_emlrtRSI;
            scalarLB = ((((j - i) + 1) / 2) << 1) + i;
            vectorUB = scalarLB - 2;
            for (k = i; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&T[k - 1]);
              _mm_storeu_pd(&T[k - 1],
                            _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r));
            }
            for (k = scalarLB; k <= j; k++) {
              T[k - 1] *= 9.9792015476736E+291;
            }
            xnorm *= 9.9792015476736E+291;
            alpha1_tmp *= 9.9792015476736E+291;
          } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                   (knt < 20));
          f_st.site = &cf_emlrtRSI;
          xnorm = xnrm2(&f_st, 8 - b_i, T, i);
          xnorm = muDoubleScalarHypot(alpha1_tmp, xnorm);
          if (alpha1_tmp >= 0.0) {
            xnorm = -xnorm;
          }
          tau[b_i] = (xnorm - alpha1_tmp) / xnorm;
          f_st.site = &df_emlrtRSI;
          xscal(&f_st, 8 - b_i, 1.0 / (alpha1_tmp - xnorm), T, i);
          f_st.site = &ef_emlrtRSI;
          for (k = 0; k < knt; k++) {
            xnorm *= 1.0020841800044864E-292;
          }
          alpha1_tmp = xnorm;
        } else {
          tau[b_i] = (xnorm - alpha1_tmp) / xnorm;
          f_st.site = &ff_emlrtRSI;
          xscal(&f_st, 8 - b_i, 1.0 / (alpha1_tmp - xnorm), T, i);
          alpha1_tmp = xnorm;
        }
      }
      T[alpha1_tmp_tmp] = 1.0;
      scalarLB = in + 1;
      e_st.site = &qg_emlrtRSI;
      if (tau[b_i] != 0.0) {
        boolean_T exitg2;
        lastv = 8 - b_i;
        i = (alpha1_tmp_tmp - b_i) + 8;
        while ((lastv + 1 > 0) && (T[i] == 0.0)) {
          lastv--;
          i--;
        }
        lastc = 10;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          i = in + lastc;
          ia = i;
          do {
            exitg1 = 0;
            if (ia <= i + lastv * 10) {
              if (T[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia += 10;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = -1;
        lastc = 0;
      }
      if (lastv + 1 > 0) {
        f_st.site = &sg_emlrtRSI;
        g_st.site = &ug_emlrtRSI;
        if (lastc != 0) {
          h_st.site = &wg_emlrtRSI;
          memset(&work[0], 0, (uint32_T)lastc * sizeof(real_T));
          i = alpha1_tmp_tmp;
          j = (in + 10 * lastv) + 1;
          for (vectorUB = scalarLB; vectorUB <= j; vectorUB += 10) {
            knt = vectorUB + lastc;
            h_st.site = &vg_emlrtRSI;
            for (ia = vectorUB; ia < knt; ia++) {
              k = ia - vectorUB;
              work[k] += T[ia - 1] * T[i];
            }
            i++;
          }
        }
        f_st.site = &tg_emlrtRSI;
        g_st.site = &xg_emlrtRSI;
        h_st.site = &yg_emlrtRSI;
        i_st.site = &ah_emlrtRSI;
        if (!(-tau[b_i] == 0.0)) {
          i = in;
          j_st.site = &bh_emlrtRSI;
          for (j = 0; j <= lastv; j++) {
            xnorm = T[alpha1_tmp_tmp + j];
            if (xnorm != 0.0) {
              xnorm *= -tau[b_i];
              knt = i + 1;
              k = lastc + i;
              j_st.site = &ch_emlrtRSI;
              if ((i + 1 <= k) && (k > 2147483646)) {
                k_st.site = &p_emlrtRSI;
                check_forloop_overflow_error(&k_st);
              }
              scalarLB = ((((k - i) / 2) << 1) + i) + 1;
              vectorUB = scalarLB - 2;
              for (ia = knt; ia <= vectorUB; ia += 2) {
                __m128d r1;
                r = _mm_loadu_pd(&work[(ia - i) - 1]);
                r1 = _mm_loadu_pd(&T[ia - 1]);
                _mm_storeu_pd(
                    &T[ia - 1],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xnorm))));
              }
              for (ia = scalarLB; ia <= k; ia++) {
                T[ia - 1] += work[(ia - i) - 1] * xnorm;
              }
            }
            i += 10;
          }
        }
      }
      e_st.site = &rg_emlrtRSI;
      b_xzlarf(&e_st, 9 - b_i, 9 - b_i, alpha1_tmp_tmp + 1, tau[b_i], T,
               (b_i + in) + 2, work);
      T[alpha1_tmp_tmp] = alpha1_tmp;
    }
    c_st.site = &mg_emlrtRSI;
    i = b_xhseqr(&c_st, T);
    if (i != 0) {
      c_st.site = &ng_emlrtRSI;
      b_warning(&c_st);
    }
  }
  b_i = 1;
  do {
    exitg1 = 0;
    if (b_i <= 10) {
      boolean_T guard1;
      guard1 = false;
      if (b_i != 10) {
        xnorm = T[b_i + 10 * (b_i - 1)];
        if (xnorm != 0.0) {
          xnorm = muDoubleScalarAbs(xnorm);
          V[b_i - 1].re = 0.0;
          V[b_i - 1].im = xnorm;
          V[b_i].re = 0.0;
          V[b_i].im = -xnorm;
          b_i += 2;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        V[b_i - 1].re = 0.0;
        V[b_i - 1].im = 0.0;
        b_i++;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (eigSkewHermitianStandard.c) */
