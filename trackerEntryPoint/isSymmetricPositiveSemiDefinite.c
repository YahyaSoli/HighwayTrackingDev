/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * isSymmetricPositiveSemiDefinite.c
 *
 * Code generation for function 'isSymmetricPositiveSemiDefinite'
 *
 */

/* Include files */
#include "isSymmetricPositiveSemiDefinite.h"
#include "anyNonFinite.h"
#include "eigStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "warning.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xhseqr.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void isSymmetricPositiveSemiDefinite(const emlrtStack *sp,
                                     const real_T b_value[9])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  creal_T b_d[3];
  real_T A[9];
  real_T y[9];
  real_T work[3];
  real_T dv[2];
  real_T tau[2];
  real_T absx;
  real_T d;
  real_T tol;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T rowleft;
  boolean_T x_data[10];
  boolean_T b_y[3];
  boolean_T c_y;
  boolean_T exitg1;
  boolean_T p;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  work[0] = muDoubleScalarAbs(b_value[0]);
  work[1] = muDoubleScalarAbs(b_value[4]);
  work[2] = muDoubleScalarAbs(b_value[8]);
  if (!muDoubleScalarIsNaN(work[0])) {
    idx = 1;
  } else {
    idx = 0;
    i1 = 2;
    exitg1 = false;
    while ((!exitg1) && (i1 < 4)) {
      if (!muDoubleScalarIsNaN(work[i1 - 1])) {
        idx = i1;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
  if (idx == 0) {
    absx = work[0];
  } else {
    absx = work[idx - 1];
    idx++;
    for (i1 = idx; i1 < 4; i1++) {
      d = work[i1 - 1];
      if (absx < d) {
        absx = d;
      }
    }
  }
  if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
    absx = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    absx = 4.94065645841247E-324;
  } else {
    frexp(absx, &rowleft);
    absx = ldexp(1.0, rowleft - 53);
  }
  tol = 100.0 * absx;
  for (idx = 0; idx < 3; idx++) {
    A[3 * idx] = b_value[idx];
    A[3 * idx + 1] = b_value[idx + 3];
    A[3 * idx + 2] = b_value[idx + 6];
  }
  r = _mm_loadu_pd(&A[0]);
  _mm_storeu_pd(&tau[0], _mm_sub_pd(_mm_loadu_pd(&b_value[0]), r));
  dv[0] = muDoubleScalarAbs(tau[0]);
  dv[1] = muDoubleScalarAbs(tau[1]);
  r = _mm_loadu_pd(&dv[0]);
  _mm_storeu_pd(&y[0], r);
  r = _mm_loadu_pd(&A[2]);
  _mm_storeu_pd(&tau[0], _mm_sub_pd(_mm_loadu_pd(&b_value[2]), r));
  dv[0] = muDoubleScalarAbs(tau[0]);
  dv[1] = muDoubleScalarAbs(tau[1]);
  r = _mm_loadu_pd(&dv[0]);
  _mm_storeu_pd(&y[2], r);
  r = _mm_loadu_pd(&A[4]);
  _mm_storeu_pd(&tau[0], _mm_sub_pd(_mm_loadu_pd(&b_value[4]), r));
  dv[0] = muDoubleScalarAbs(tau[0]);
  dv[1] = muDoubleScalarAbs(tau[1]);
  r = _mm_loadu_pd(&dv[0]);
  _mm_storeu_pd(&y[4], r);
  r = _mm_loadu_pd(&A[6]);
  _mm_storeu_pd(&tau[0], _mm_sub_pd(_mm_loadu_pd(&b_value[6]), r));
  dv[0] = muDoubleScalarAbs(tau[0]);
  dv[1] = muDoubleScalarAbs(tau[1]);
  r = _mm_loadu_pd(&dv[0]);
  _mm_storeu_pd(&y[6], r);
  y[8] = muDoubleScalarAbs(b_value[8] - A[8]);
  st.site = &tf_emlrtRSI;
  absx = muDoubleScalarSqrt(tol);
  st.site = &tf_emlrtRSI;
  b_st.site = &vf_emlrtRSI;
  b_y[0] = true;
  b_y[1] = true;
  b_y[2] = true;
  idx = 3;
  for (i = 0; i < 3; i++) {
    rowleft = idx;
    i1 = idx - 2;
    idx += 3;
    c_st.site = &wf_emlrtRSI;
    if ((i1 <= rowleft) && (rowleft > 2147483646)) {
      d_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    exitg1 = false;
    while ((!exitg1) && (i1 <= rowleft)) {
      if (!(y[i1 - 1] < absx)) {
        b_y[i] = false;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
  c_y = true;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 <= 2)) {
    if (!b_y[i1]) {
      c_y = false;
      exitg1 = true;
    } else {
      i1++;
    }
  }
  __m128d r1;
  st.site = &uf_emlrtRSI;
  r = _mm_loadu_pd(&A[0]);
  r1 = _mm_set1_pd(2.0);
  _mm_storeu_pd(&A[0],
                _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[0]), r), r1));
  r = _mm_loadu_pd(&A[2]);
  _mm_storeu_pd(&A[2],
                _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[2]), r), r1));
  r = _mm_loadu_pd(&A[4]);
  _mm_storeu_pd(&A[4],
                _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[4]), r), r1));
  r = _mm_loadu_pd(&A[6]);
  _mm_storeu_pd(&A[6],
                _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[6]), r), r1));
  A[8] = (b_value[8] + A[8]) / 2.0;
  b_st.site = &xf_emlrtRSI;
  if (anyNonFinite(A)) {
    b_d[0].re = rtNaN;
    b_d[1].re = rtNaN;
    b_d[2].re = rtNaN;
  } else {
    int32_T exitg2;
    p = true;
    i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (i1 < 3)) {
      i = 0;
      do {
        exitg2 = 0;
        if (i <= i1) {
          if (!(A[i + 3 * i1] == A[i1 + 3 * i])) {
            p = false;
            exitg2 = 1;
          } else {
            i++;
          }
        } else {
          i1++;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    if (p) {
      ptrdiff_t n_t;
      b_st.site = &yf_emlrtRSI;
      c_st.site = &fg_emlrtRSI;
      d_st.site = &hg_emlrtRSI;
      n_t = (ptrdiff_t)3;
      n_t = LAPACKE_dsyev(102, 'N', 'L', n_t, &A[0], n_t, &work[0]);
      e_st.site = &ye_emlrtRSI;
      if ((int32_T)n_t < 0) {
        if ((int32_T)n_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&e_st, &e_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&e_st, &d_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 13, &cv[0], 12, (int32_T)n_t);
        }
      }
      b_d[0].re = work[0];
      b_d[1].re = work[1];
      b_d[2].re = work[2];
      if ((int32_T)n_t != 0) {
        c_st.site = &gg_emlrtRSI;
        warning(&c_st);
      }
    } else {
      p = true;
      i1 = 0;
      exitg1 = false;
      while ((!exitg1) && (i1 < 3)) {
        i = 0;
        do {
          exitg2 = 0;
          if (i <= i1) {
            if (!(A[i + 3 * i1] == -A[i1 + 3 * i])) {
              p = false;
              exitg2 = 1;
            } else {
              i++;
            }
          } else {
            i1++;
            exitg2 = 2;
          }
        } while (exitg2 == 0);
        if (exitg2 == 1) {
          exitg1 = true;
        }
      }
      if (p) {
        b_st.site = &ag_emlrtRSI;
        c_st.site = &ig_emlrtRSI;
        d_st.site = &jg_emlrtRSI;
        e_st.site = &kg_emlrtRSI;
        if (anyNonFinite(A)) {
          for (idx = 0; idx < 9; idx++) {
            A[idx] = rtNaN;
          }
          idx = 2;
          for (i1 = 0; i1 < 2; i1++) {
            if (idx <= 3) {
              memset(&A[(i1 * 3 + idx) + -1], 0,
                     (uint32_T)(-idx + 4) * sizeof(real_T));
            }
            idx++;
          }
        } else {
          e_st.site = &lg_emlrtRSI;
          f_st.site = &og_emlrtRSI;
          work[0] = 0.0;
          work[1] = 0.0;
          work[2] = 0.0;
          for (i = 0; i < 2; i++) {
            int32_T alpha1_tmp_tmp;
            int32_T in;
            int32_T lastv;
            in = (i + 1) * 3;
            alpha1_tmp_tmp = i + 3 * i;
            absx = A[alpha1_tmp_tmp + 1];
            g_st.site = &pg_emlrtRSI;
            d = xzlarfg(&g_st, 2 - i, &absx, A, i * 3 + 3);
            tau[i] = d;
            A[alpha1_tmp_tmp + 1] = 1.0;
            g_st.site = &qg_emlrtRSI;
            if (d != 0.0) {
              lastv = 2 - i;
              idx = (alpha1_tmp_tmp - i) + 2;
              while ((lastv > 0) && (A[idx] == 0.0)) {
                lastv--;
                idx--;
              }
              idx = 3;
              exitg1 = false;
              while ((!exitg1) && (idx > 0)) {
                rowleft = in + idx;
                i1 = rowleft;
                do {
                  exitg2 = 0;
                  if (i1 <= rowleft + (lastv - 1) * 3) {
                    if (A[i1 - 1] != 0.0) {
                      exitg2 = 1;
                    } else {
                      i1 += 3;
                    }
                  } else {
                    idx--;
                    exitg2 = 2;
                  }
                } while (exitg2 == 0);
                if (exitg2 == 1) {
                  exitg1 = true;
                }
              }
            } else {
              lastv = 0;
              idx = 0;
            }
            if (lastv > 0) {
              h_st.site = &sg_emlrtRSI;
              xgemv(&h_st, idx, lastv, A, in + 1, A, alpha1_tmp_tmp + 2, work);
              h_st.site = &tg_emlrtRSI;
              xgerc(&h_st, idx, lastv, -tau[i], work, alpha1_tmp_tmp + 2, A,
                    in + 1);
            }
            g_st.site = &rg_emlrtRSI;
            xzlarf(&g_st, 2 - i, 2 - i, alpha1_tmp_tmp + 2, tau[i], A,
                   (i + in) + 2, work);
            A[alpha1_tmp_tmp + 1] = absx;
          }
          e_st.site = &mg_emlrtRSI;
          idx = xhseqr(&e_st, A);
          if (idx != 0) {
            e_st.site = &ng_emlrtRSI;
            b_warning(&e_st);
          }
        }
        i = 1;
        do {
          exitg2 = 0;
          if (i <= 3) {
            boolean_T guard1;
            guard1 = false;
            if (i != 3) {
              d = A[i + 3 * (i - 1)];
              if (d != 0.0) {
                absx = muDoubleScalarAbs(d);
                b_d[i - 1].re = 0.0;
                b_d[i - 1].im = absx;
                b_d[i].re = 0.0;
                b_d[i].im = -absx;
                i += 2;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }
            if (guard1) {
              b_d[i - 1].re = 0.0;
              b_d[i - 1].im = 0.0;
              i++;
            }
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      } else {
        b_st.site = &bg_emlrtRSI;
        eigStandard(&b_st, A, b_d);
      }
    }
  }
  x_data[0] = (b_d[0].re < -tol);
  x_data[1] = (b_d[1].re < -tol);
  x_data[2] = (b_d[2].re < -tol);
  p = false;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 <= 2)) {
    if (x_data[i1]) {
      p = true;
      exitg1 = true;
    } else {
      i1++;
    }
  }
  if (p || (!c_y)) {
    emlrtErrorWithMessageIdR2018a(
        sp, &f_emlrtRTEI,
        "shared_tracking:KalmanFilter:invalidCovarianceValues",
        "shared_tracking:KalmanFilter:invalidCovarianceValues", 3, 4, 12,
        "ProcessNoise");
  }
}

/* End of code generation (isSymmetricPositiveSemiDefinite.c) */
