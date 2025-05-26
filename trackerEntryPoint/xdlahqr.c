/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdlahqr.c
 *
 * Code generation for function 'xdlahqr'
 *
 */

/* Include files */
#include "xdlahqr.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "xdlanv2.h"
#include "xzlarfg.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo mh_emlrtRSI = {
    337,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo nh_emlrtRSI = {
    301,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo oh_emlrtRSI = {
    273,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    240,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    226,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    172,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo gj_emlrtRSI = {
    292,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo hj_emlrtRSI = {
    264,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo ij_emlrtRSI = {
    33,        /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo jj_emlrtRSI = {
    16,        /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

/* Function Definitions */
int32_T xdlahqr(const emlrtStack *sp, int32_T ilo, int32_T ihi, real_T h[9],
                real_T wr[3], real_T wi[3])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T v[3];
  real_T aa;
  real_T d;
  real_T h12;
  real_T h21;
  real_T h22;
  real_T rt1r;
  real_T tst;
  int32_T b_i;
  int32_T b_k;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info = 0;
  st.site = &jj_emlrtRSI;
  if (ilo - 1 > 2147483646) {
    b_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)(ilo - 1);
  for (b_i = 0; b_i < i; b_i++) {
    wr[b_i] = h[b_i + 3 * b_i];
    wi[b_i] = 0.0;
  }
  i = ihi + 1;
  for (b_i = i; b_i < 4; b_i++) {
    wr[b_i - 1] = h[(b_i + 3 * (b_i - 1)) - 1];
    wi[b_i - 1] = 0.0;
  }
  if (ilo == ihi) {
    wr[ilo - 1] = h[(ilo + 3 * (ilo - 1)) - 1];
    wi[ilo - 1] = 0.0;
  } else {
    real_T smlnum;
    int32_T kdefl;
    boolean_T exitg1;
    st.site = &ij_emlrtRSI;
    if ((ilo <= ihi - 3) && (ihi - 3 > 2147483646)) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    if (ilo <= ihi - 2) {
      h[ihi - 1] = 0.0;
    }
    smlnum = 2.2250738585072014E-308 *
             ((real_T)((ihi - ilo) + 1) / 2.2204460492503131E-16);
    kdefl = 0;
    b_i = ihi - 1;
    exitg1 = false;
    while ((!exitg1) && (b_i + 1 >= ilo)) {
      int32_T i1;
      int32_T its;
      int32_T l;
      boolean_T converged;
      boolean_T exitg2;
      l = ilo;
      converged = false;
      its = 0;
      exitg2 = false;
      while ((!exitg2) && (its < 301)) {
        real_T s;
        int32_T nr;
        boolean_T exitg3;
        k = b_i;
        exitg3 = false;
        while ((!exitg3) && (k + 1 > l)) {
          i = k + 3 * (k - 1);
          d = muDoubleScalarAbs(h[i]);
          if (d <= smlnum) {
            exitg3 = true;
          } else {
            nr = k + 3 * k;
            h21 = muDoubleScalarAbs(h[nr]);
            tst = muDoubleScalarAbs(h[i - 1]) + h21;
            if (tst == 0.0) {
              if (k - 1 >= ilo) {
                tst = muDoubleScalarAbs(h[k - 1]);
              }
              if (k + 2 <= ihi) {
                tst += muDoubleScalarAbs(h[3 * k + 2]);
              }
            }
            if (d <= 2.2204460492503131E-16 * tst) {
              h12 = muDoubleScalarAbs(h[nr - 1]);
              tst = muDoubleScalarAbs(h[i - 1] - h[nr]);
              aa = muDoubleScalarMax(h21, tst);
              tst = muDoubleScalarMin(h21, tst);
              s = aa + tst;
              if (muDoubleScalarMin(d, h12) * (muDoubleScalarMax(d, h12) / s) <=
                  muDoubleScalarMax(smlnum, 2.2204460492503131E-16 *
                                                (tst * (aa / s)))) {
                exitg3 = true;
              } else {
                k--;
              }
            } else {
              k--;
            }
          }
        }
        l = k + 1;
        if (k + 1 > ilo) {
          h[k + 3 * (k - 1)] = 0.0;
        }
        if (k + 1 >= b_i) {
          converged = true;
          exitg2 = true;
        } else {
          __m128d r;
          real_T rt2r;
          int32_T m;
          kdefl++;
          if (kdefl - kdefl / 20 * 20 == 0) {
            s = muDoubleScalarAbs(h[b_i + 3 * (b_i - 1)]) +
                muDoubleScalarAbs(h[b_i - 1]);
            tst = 0.75 * s + h[b_i + 3 * b_i];
            h12 = -0.4375 * s;
            h21 = s;
            h22 = tst;
          } else if (kdefl - kdefl / 10 * 10 == 0) {
            s = muDoubleScalarAbs(h[1]) + muDoubleScalarAbs(h[5]);
            tst = 0.75 * s + h[0];
            h12 = -0.4375 * s;
            h21 = s;
            h22 = tst;
          } else {
            nr = b_i + 3 * (b_i - 1);
            tst = h[nr - 1];
            h21 = h[nr];
            nr = b_i + 3 * b_i;
            h12 = h[nr - 1];
            h22 = h[nr];
          }
          s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(h12)) +
               muDoubleScalarAbs(h21)) +
              muDoubleScalarAbs(h22);
          if (s == 0.0) {
            rt1r = 0.0;
            tst = 0.0;
            rt2r = 0.0;
            h21 = 0.0;
          } else {
            tst /= s;
            h21 /= s;
            h12 /= s;
            h22 /= s;
            aa = (tst + h22) / 2.0;
            tst = (tst - aa) * (h22 - aa) - h12 * h21;
            h21 = muDoubleScalarAbs(tst);
            st.site = &sh_emlrtRSI;
            if (h21 < 0.0) {
              emlrtErrorWithMessageIdR2018a(
                  &st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }
            h21 = muDoubleScalarSqrt(h21);
            if (tst >= 0.0) {
              rt1r = aa * s;
              rt2r = rt1r;
              tst = h21 * s;
              h21 = -tst;
            } else {
              rt1r = aa + h21;
              rt2r = aa - h21;
              if (muDoubleScalarAbs(rt1r - h22) <=
                  muDoubleScalarAbs(rt2r - h22)) {
                rt1r *= s;
                rt2r = rt1r;
              } else {
                rt2r *= s;
                rt1r = rt2r;
              }
              tst = 0.0;
              h21 = 0.0;
            }
          }
          m = b_i - 1;
          if (b_i - 1 >= 1) {
            h12 = h[0] - rt2r;
            s = (muDoubleScalarAbs(h12) + muDoubleScalarAbs(h21)) +
                muDoubleScalarAbs(h[1]);
            aa = h[1] / s;
            v[0] = (aa * h[3] + (h[0] - rt1r) * (h12 / s)) - tst * (h21 / s);
            v[1] = aa * (((h[0] + h[4]) - rt1r) - rt2r);
            v[2] = aa * h[5];
            s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
                muDoubleScalarAbs(v[2]);
            r = _mm_loadu_pd(&v[0]);
            _mm_storeu_pd(&v[0], _mm_div_pd(r, _mm_set1_pd(s)));
            v[2] /= s;
          }
          st.site = &rh_emlrtRSI;
          if ((b_i - 1 <= b_i) && (b_i > 2147483646)) {
            b_st.site = &p_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
          for (k = m; k <= b_i; k++) {
            i = (b_i - k) + 2;
            nr = muIntScalarMin_sint32(3, i);
            if (k > b_i - 1) {
              i1 = ((k - 2) * 3 + k) - 1;
              st.site = &qh_emlrtRSI;
              i = (uint8_T)nr;
              for (b_k = 0; b_k < i; b_k++) {
                v[b_k] = h[i1 + b_k];
              }
            }
            tst = v[0];
            st.site = &ph_emlrtRSI;
            rt2r = b_xzlarfg(&st, nr, &tst, v);
            if (k > b_i - 1) {
              h[k - 1] = tst;
              h[k] = 0.0;
              if (k < b_i) {
                /* Check node always fails. would cause program termination and
                 * was eliminated */
              }
            }
            d = v[1];
            h12 = rt2r * v[1];
            if (nr == 3) {
              int32_T b;
              rt1r = v[2];
              tst = rt2r * v[2];
              st.site = &hj_emlrtRSI;
              if ((k <= b_i + 1) && (b_i + 1 > 2147483646)) {
                b_st.site = &p_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
              for (j = k; j <= b_i + 1; j++) {
                nr = 3 * (j - 1);
                i1 = k + nr;
                h21 = h[i1 - 1];
                aa = (h21 + d * h[i1]) + rt1r * h[nr + 2];
                h[i1 - 1] = h21 - aa * rt2r;
                h[i1] -= aa * h12;
                h[nr + 2] -= aa * tst;
              }
              i = k + 3;
              i1 = b_i + 1;
              b = muIntScalarMin_sint32(i, i1);
              st.site = &oh_emlrtRSI;
              if (b > 2147483646) {
                b_st.site = &p_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
              b_k = ((b / 2) << 1) + 1;
              nr = b_k - 2;
              for (j = 1; j <= nr; j += 2) {
                __m128d r1;
                __m128d r2;
                i = (j + 3 * k) - 1;
                r = _mm_loadu_pd(&h[i]);
                i1 = (j + 3 * (k - 1)) - 1;
                r1 = _mm_loadu_pd(&h[i1]);
                r2 = _mm_loadu_pd(&h[j + 5]);
                r = _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r)),
                               _mm_mul_pd(_mm_set1_pd(rt1r), r2));
                r1 = _mm_loadu_pd(&h[i1]);
                _mm_storeu_pd(&h[i1],
                              _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(rt2r))));
                r1 = _mm_loadu_pd(&h[i]);
                _mm_storeu_pd(&h[i],
                              _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(h12))));
                r1 = _mm_loadu_pd(&h[j + 5]);
                _mm_storeu_pd(&h[j + 5],
                              _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(tst))));
              }
              for (j = b_k; j <= b; j++) {
                nr = (j + 3 * (k - 1)) - 1;
                h21 = h[nr];
                i1 = (j + 3 * k) - 1;
                aa = (h21 + d * h[i1]) + rt1r * h[j + 5];
                h[nr] = h21 - aa * rt2r;
                h[i1] -= aa * h12;
                h[j + 5] -= aa * tst;
              }
            } else if (nr == 2) {
              st.site = &gj_emlrtRSI;
              if ((k <= b_i + 1) && (b_i + 1 > 2147483646)) {
                b_st.site = &p_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
              for (j = k; j <= b_i + 1; j++) {
                i = k + 3 * (j - 1);
                rt1r = h[i - 1];
                h22 = h[i];
                aa = rt1r + d * h22;
                rt1r -= aa * rt2r;
                h[i - 1] = rt1r;
                h22 -= aa * h12;
                h[i] = h22;
              }
              st.site = &nh_emlrtRSI;
              if (b_i + 1 > 2147483646) {
                b_st.site = &p_emlrtRSI;
                check_forloop_overflow_error(&b_st);
              }
              b_k = (((b_i + 1) / 2) << 1) + 1;
              nr = b_k - 2;
              for (j = 1; j <= nr; j += 2) {
                __m128d r1;
                __m128d r2;
                i = (j + 3 * k) - 1;
                r = _mm_loadu_pd(&h[i]);
                i1 = (j + 3 * (k - 1)) - 1;
                r1 = _mm_loadu_pd(&h[i1]);
                r2 = _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r));
                _mm_storeu_pd(
                    &h[i1], _mm_sub_pd(r1, _mm_mul_pd(r2, _mm_set1_pd(rt2r))));
                _mm_storeu_pd(&h[i],
                              _mm_sub_pd(r, _mm_mul_pd(r2, _mm_set1_pd(h12))));
              }
              for (j = b_k; j <= b_i + 1; j++) {
                i = (j + 3 * (k - 1)) - 1;
                rt1r = h[i];
                i1 = (j + 3 * k) - 1;
                h22 = h[i1];
                aa = rt1r + d * h22;
                rt1r -= aa * rt2r;
                h[i] = rt1r;
                h22 -= aa * h12;
                h[i1] = h22;
              }
            }
          }
          its++;
        }
      }
      if (!converged) {
        info = b_i + 1;
        exitg1 = true;
      } else {
        if (l == b_i + 1) {
          wr[b_i] = h[b_i + 3 * b_i];
          wi[b_i] = 0.0;
        } else if (l == b_i) {
          i = b_i + 3 * b_i;
          d = h[i - 1];
          i1 = b_i + 3 * (b_i - 1);
          rt1r = h[i1];
          h22 = h[i];
          st.site = &mh_emlrtRSI;
          wr[b_i - 1] = xdlanv2(&h[i1 - 1], &d, &rt1r, &h22, &wi[b_i - 1], &tst,
                                &h21, &h12, &aa);
          wr[b_i] = tst;
          wi[b_i] = h21;
          h[i - 1] = d;
          h[i1] = rt1r;
          h[i] = h22;
        }
        kdefl = 0;
        b_i = l - 2;
      }
    }
    if (info != 0) {
      h[2] = 0.0;
    }
  }
  return info;
}

/* End of code generation (xdlahqr.c) */
