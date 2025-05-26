/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * objectTrack.c
 *
 * Code generation for function 'objectTrack'
 *
 */

/* Include files */
#include "objectTrack.h"
#include "anyNonFinite.h"
#include "eigSkewHermitianStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_types.h"
#include "warning.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo um_emlrtRSI =
    {
        293,                               /* lineNo */
        "objectTrack/set.StateCovariance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo vm_emlrtRSI =
    {
        295,                               /* lineNo */
        "objectTrack/set.StateCovariance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\objectTra"
        "ck.m" /* pathName */
};

static emlrtRSInfo wm_emlrtRSI = {
    159,           /* lineNo */
    "ceval_xgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeev.m" /* pathName */
};

static emlrtRSInfo xm_emlrtRSI = {
    42,      /* lineNo */
    "xgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeev.m" /* pathName */
};

/* Function Definitions */
void objectTrack_set_StateCovariance(const emlrtStack *sp, objectTrack *obj,
                                     const real_T b_value[100])
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 'e', 'v', 'x'};
  __m128d r;
  ptrdiff_t ihi_t;
  ptrdiff_t ilo_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  creal_T d[10];
  real_T A[100];
  real_T y[100];
  real_T scale[10];
  real_T wimag[10];
  real_T wreal[10];
  real_T dv[2];
  real_T dv1[2];
  real_T abnrm;
  real_T absx;
  real_T rconde;
  real_T rcondv;
  real_T tol;
  real_T vleft;
  int32_T exponent;
  int32_T i;
  int32_T i1;
  int32_T idx;
  boolean_T b_y[10];
  boolean_T c_y;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &um_emlrtRSI;
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
  b_st.site = &sf_emlrtRSI;
  p = true;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 < 100)) {
    if ((!muDoubleScalarIsInf(b_value[i1])) &&
        (!muDoubleScalarIsNaN(b_value[i1]))) {
      i1++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:objectTrack:expectedFinite", 3, 4, 15, "StateCovariance");
  }
  st.site = &vm_emlrtRSI;
  for (i1 = 0; i1 < 10; i1++) {
    wreal[i1] = muDoubleScalarAbs(b_value[i1 + 10 * i1]);
  }
  if (!muDoubleScalarIsNaN(wreal[0])) {
    idx = 1;
  } else {
    idx = 0;
    i1 = 2;
    exitg1 = false;
    while ((!exitg1) && (i1 < 11)) {
      if (!muDoubleScalarIsNaN(wreal[i1 - 1])) {
        idx = i1;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
  if (idx == 0) {
    absx = wreal[0];
  } else {
    absx = wreal[idx - 1];
    i = idx + 1;
    for (i1 = i; i1 < 11; i1++) {
      vleft = wreal[i1 - 1];
      if (absx < vleft) {
        absx = vleft;
      }
    }
  }
  if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
    vleft = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    vleft = 4.94065645841247E-324;
  } else {
    frexp(absx, &exponent);
    vleft = ldexp(1.0, exponent - 53);
  }
  tol = 100.0 * vleft;
  for (i = 0; i < 10; i++) {
    for (idx = 0; idx < 10; idx++) {
      A[idx + 10 * i] = b_value[i + 10 * idx];
    }
  }
  for (i1 = 0; i1 <= 98; i1 += 2) {
    r = _mm_loadu_pd(&A[i1]);
    _mm_storeu_pd(&dv[0], _mm_sub_pd(_mm_loadu_pd(&b_value[i1]), r));
    dv1[0] = muDoubleScalarAbs(dv[0]);
    dv1[1] = muDoubleScalarAbs(dv[1]);
    r = _mm_loadu_pd(&dv1[0]);
    _mm_storeu_pd(&y[i1], r);
  }
  b_st.site = &tf_emlrtRSI;
  vleft = muDoubleScalarSqrt(tol);
  b_st.site = &tf_emlrtRSI;
  c_st.site = &vf_emlrtRSI;
  for (i = 0; i < 10; i++) {
    b_y[i] = true;
  }
  idx = 10;
  for (i = 0; i < 10; i++) {
    exponent = idx;
    i1 = idx - 9;
    idx += 10;
    d_st.site = &wf_emlrtRSI;
    if ((i1 <= exponent) && (exponent > 2147483646)) {
      e_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    exitg1 = false;
    while ((!exitg1) && (i1 <= exponent)) {
      if (!(y[i1 - 1] < vleft)) {
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
  while ((!exitg1) && (i1 <= 9)) {
    if (!b_y[i1]) {
      c_y = false;
      exitg1 = true;
    } else {
      i1++;
    }
  }
  b_st.site = &uf_emlrtRSI;
  for (i = 0; i <= 98; i += 2) {
    r = _mm_loadu_pd(&A[i]);
    _mm_storeu_pd(&A[i], _mm_div_pd(_mm_add_pd(_mm_loadu_pd(&b_value[i]), r),
                                    _mm_set1_pd(2.0)));
  }
  c_st.site = &xf_emlrtRSI;
  if (b_anyNonFinite(A)) {
    for (i = 0; i < 10; i++) {
      d[i].re = rtNaN;
      d[i].im = 0.0;
    }
  } else {
    int32_T exitg2;
    p = true;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx < 10)) {
      i = 0;
      do {
        exitg2 = 0;
        if (i <= idx) {
          if (!(A[i + 10 * idx] == A[idx + 10 * i])) {
            p = false;
            exitg2 = 1;
          } else {
            i++;
          }
        } else {
          idx++;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    if (p) {
      ptrdiff_t info_t;
      c_st.site = &yf_emlrtRSI;
      d_st.site = &fg_emlrtRSI;
      e_st.site = &hg_emlrtRSI;
      ilo_t = (ptrdiff_t)10;
      info_t = LAPACKE_dsyev(102, 'N', 'L', ilo_t, &A[0], ilo_t, &scale[0]);
      f_st.site = &ye_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &e_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&f_st, &d_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 13, &cv[0], 12, (int32_T)info_t);
        }
      }
      for (i = 0; i < 10; i++) {
        d[i].re = scale[i];
        d[i].im = 0.0;
      }
      if ((int32_T)info_t != 0) {
        d_st.site = &gg_emlrtRSI;
        warning(&d_st);
      }
    } else {
      p = true;
      idx = 0;
      exitg1 = false;
      while ((!exitg1) && (idx < 10)) {
        i = 0;
        do {
          exitg2 = 0;
          if (i <= idx) {
            if (!(A[i + 10 * idx] == -A[idx + 10 * i])) {
              p = false;
              exitg2 = 1;
            } else {
              i++;
            }
          } else {
            idx++;
            exitg2 = 2;
          }
        } while (exitg2 == 0);
        if (exitg2 == 1) {
          exitg1 = true;
        }
      }
      if (p) {
        c_st.site = &ag_emlrtRSI;
        eigSkewHermitianStandard(&c_st, A, d);
      } else {
        ptrdiff_t info_t;
        c_st.site = &bg_emlrtRSI;
        d_st.site = &di_emlrtRSI;
        e_st.site = &xm_emlrtRSI;
        info_t = LAPACKE_dgeevx(102, 'B', 'N', 'N', 'N', (ptrdiff_t)10, &A[0],
                                (ptrdiff_t)10, &wreal[0], &wimag[0], &vleft,
                                (ptrdiff_t)1, &absx, (ptrdiff_t)1, &ilo_t,
                                &ihi_t, &scale[0], &abnrm, &rconde, &rcondv);
        f_st.site = &wm_emlrtRSI;
        if ((int32_T)info_t < 0) {
          if ((int32_T)info_t == -1010) {
            emlrtErrorWithMessageIdR2018a(&f_st, &e_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(
                &f_st, &d_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &fname[0], 12,
                (int32_T)info_t);
          }
        }
        for (i = 0; i < 10; i++) {
          d[i].re = wreal[i];
          d[i].im = wimag[i];
        }
        if ((int32_T)info_t != 0) {
          d_st.site = &ei_emlrtRSI;
          warning(&d_st);
        }
      }
    }
  }
  for (i = 0; i < 10; i++) {
    b_y[i] = (d[i].re < -tol);
  }
  p = false;
  i1 = 0;
  exitg1 = false;
  while ((!exitg1) && (i1 <= 9)) {
    if (b_y[i1]) {
      p = true;
      exitg1 = true;
    } else {
      i1++;
    }
  }
  if (p || (!c_y)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI,
        "shared_tracking:KalmanFilter:invalidCovarianceValues",
        "shared_tracking:KalmanFilter:invalidCovarianceValues", 3, 4, 15,
        "StateCovariance");
  }
  memcpy(&obj->pStateCovariance[0], &b_value[0], 100U * sizeof(real_T));
}

/* End of code generation (objectTrack.c) */
