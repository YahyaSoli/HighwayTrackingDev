/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xhseqr.c
 *
 * Code generation for function 'xhseqr'
 *
 */

/* Include files */
#include "xhseqr.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "xdlanv2.h"
#include "xzlarfg.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo ih_emlrtRSI = {
    32,       /* lineNo */
    "xhseqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xhseqr.m" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    22,        /* lineNo */
    "xdhseqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdhseqr.m" /* pathName */
};

/* Function Definitions */
int32_T b_xhseqr(const emlrtStack *sp, real_T h[100])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v[3];
  real_T aa;
  real_T d;
  real_T h12;
  real_T h21;
  real_T h22;
  real_T rt2r;
  real_T s;
  real_T tst;
  int32_T b_i;
  int32_T b_k;
  int32_T i;
  int32_T i1;
  int32_T info;
  int32_T k;
  int32_T kdefl;
  int32_T v_tmp;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ih_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &jh_emlrtRSI;
  info = 0;
  for (i = 0; i < 7; i++) {
    i1 = i + 10 * i;
    h[i1 + 2] = 0.0;
    h[i1 + 3] = 0.0;
  }
  h[79] = 0.0;
  kdefl = 0;
  b_i = 9;
  exitg1 = false;
  while ((!exitg1) && (b_i + 1 >= 1)) {
    int32_T i2;
    int32_T its;
    int32_T l;
    int32_T nr;
    int32_T tst_tmp_tmp;
    boolean_T converged;
    boolean_T exitg2;
    l = 1;
    converged = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      boolean_T exitg3;
      k = b_i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > l)) {
        i1 = k + 10 * (k - 1);
        d = muDoubleScalarAbs(h[i1]);
        if (d <= 1.0020841800044864E-291) {
          exitg3 = true;
        } else {
          tst_tmp_tmp = k + 10 * k;
          h21 = muDoubleScalarAbs(h[tst_tmp_tmp]);
          tst = muDoubleScalarAbs(h[i1 - 1]) + h21;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h[(k + 10 * (k - 2)) - 1]);
            }
            if (k + 2 <= 10) {
              tst += muDoubleScalarAbs(h[tst_tmp_tmp + 1]);
            }
          }
          if (d <= 2.2204460492503131E-16 * tst) {
            h12 = muDoubleScalarAbs(h[tst_tmp_tmp - 1]);
            tst = muDoubleScalarAbs(h[i1 - 1] - h[tst_tmp_tmp]);
            aa = muDoubleScalarMax(h21, tst);
            tst = muDoubleScalarMin(h21, tst);
            s = aa + tst;
            if (muDoubleScalarMin(d, h12) * (muDoubleScalarMax(d, h12) / s) <=
                muDoubleScalarMax(1.0020841800044864E-291,
                                  2.2204460492503131E-16 * (tst * (aa / s)))) {
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
      if (k + 1 > 1) {
        h[k + 10 * (k - 1)] = 0.0;
      }
      if (k + 1 >= b_i) {
        converged = true;
        exitg2 = true;
      } else {
        __m128d r;
        real_T rt1r;
        int32_T m;
        kdefl++;
        if (kdefl - kdefl / 20 * 20 == 0) {
          s = muDoubleScalarAbs(h[b_i + 10 * (b_i - 1)]) +
              muDoubleScalarAbs(h[(b_i + 10 * (b_i - 2)) - 1]);
          tst = 0.75 * s + h[b_i + 10 * b_i];
          h12 = -0.4375 * s;
          h21 = s;
          h22 = tst;
        } else if (kdefl - kdefl / 10 * 10 == 0) {
          tst_tmp_tmp = k + 10 * k;
          s = muDoubleScalarAbs(h[tst_tmp_tmp + 1]) +
              muDoubleScalarAbs(h[(k + 10 * (k + 1)) + 2]);
          tst = 0.75 * s + h[tst_tmp_tmp];
          h12 = -0.4375 * s;
          h21 = s;
          h22 = tst;
        } else {
          tst_tmp_tmp = b_i + 10 * (b_i - 1);
          tst = h[tst_tmp_tmp - 1];
          h21 = h[tst_tmp_tmp];
          tst_tmp_tmp = b_i + 10 * b_i;
          h12 = h[tst_tmp_tmp - 1];
          h22 = h[tst_tmp_tmp];
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
          h21 = muDoubleScalarSqrt(muDoubleScalarAbs(tst));
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
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          tst_tmp_tmp = m + 10 * (m - 1);
          h12 = h[tst_tmp_tmp - 1];
          aa = h12 - rt2r;
          s = (muDoubleScalarAbs(aa) + muDoubleScalarAbs(h21)) +
              muDoubleScalarAbs(h[tst_tmp_tmp]);
          h22 = h[tst_tmp_tmp] / s;
          v_tmp = m + 10 * m;
          v[0] = (h22 * h[v_tmp - 1] + aa * (aa / s)) - tst * (h21 / s);
          v[1] = h22 * (((h12 + h[v_tmp]) - rt1r) - rt2r);
          v[2] = h22 * h[v_tmp + 1];
          s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
              muDoubleScalarAbs(v[2]);
          r = _mm_loadu_pd(&v[0]);
          _mm_storeu_pd(&v[0], _mm_div_pd(r, _mm_set1_pd(s)));
          v[2] /= s;
          if (m == k + 1) {
            exitg3 = true;
          } else {
            i1 = m + 10 * (m - 2);
            if (muDoubleScalarAbs(h[i1 - 1]) *
                    (muDoubleScalarAbs(v[1]) + muDoubleScalarAbs(v[2])) <=
                2.2204460492503131E-16 * muDoubleScalarAbs(v[0]) *
                    ((muDoubleScalarAbs(h[i1 - 2]) +
                      muDoubleScalarAbs(h[tst_tmp_tmp - 1])) +
                     muDoubleScalarAbs(h[v_tmp]))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
        }
        for (b_k = m; b_k <= b_i; b_k++) {
          i = (b_i - b_k) + 2;
          nr = muIntScalarMin_sint32(3, i);
          if (b_k > m) {
            tst_tmp_tmp = ((b_k - 2) * 10 + b_k) - 1;
            for (v_tmp = 0; v_tmp < nr; v_tmp++) {
              v[v_tmp] = h[tst_tmp_tmp + v_tmp];
            }
          }
          tst = v[0];
          c_st.site = &ph_emlrtRSI;
          aa = b_xzlarfg(&c_st, nr, &tst, v);
          if (b_k > m) {
            i1 = b_k + 10 * (b_k - 2);
            h[i1 - 1] = tst;
            h[i1] = 0.0;
            if (b_k < b_i) {
              h[i1 + 1] = 0.0;
            }
          } else if (m > k + 1) {
            i1 = (b_k + 10 * (b_k - 2)) - 1;
            h[i1] *= 1.0 - aa;
          }
          d = v[1];
          tst = aa * v[1];
          if (nr == 3) {
            int32_T i3;
            h22 = v[2];
            h12 = aa * v[2];
            for (i = b_k; i < 11; i++) {
              i1 = b_k + 10 * (i - 1);
              rt2r = h[i1 - 1];
              rt1r = h[i1];
              s = h[i1 + 1];
              h21 = (rt2r + d * rt1r) + h22 * s;
              rt2r -= h21 * aa;
              h[i1 - 1] = rt2r;
              rt1r -= h21 * tst;
              h[i1] = rt1r;
              s -= h21 * h12;
              h[i1 + 1] = s;
            }
            i = b_k + 3;
            i1 = b_i + 1;
            i1 = muIntScalarMin_sint32(i, i1);
            tst_tmp_tmp = (i1 / 2) << 1;
            v_tmp = tst_tmp_tmp - 2;
            for (i = 0; i <= v_tmp; i += 2) {
              __m128d r1;
              __m128d r2;
              __m128d r3;
              i2 = i + 10 * b_k;
              r = _mm_loadu_pd(&h[i2]);
              nr = i + 10 * (b_k + 1);
              r1 = _mm_loadu_pd(&h[nr]);
              i3 = i + 10 * (b_k - 1);
              r2 = _mm_loadu_pd(&h[i3]);
              r3 = _mm_add_pd(_mm_add_pd(r2, _mm_mul_pd(_mm_set1_pd(d), r)),
                              _mm_mul_pd(_mm_set1_pd(h22), r1));
              _mm_storeu_pd(&h[i3],
                            _mm_sub_pd(r2, _mm_mul_pd(r3, _mm_set1_pd(aa))));
              _mm_storeu_pd(&h[i2],
                            _mm_sub_pd(r, _mm_mul_pd(r3, _mm_set1_pd(tst))));
              _mm_storeu_pd(&h[nr],
                            _mm_sub_pd(r1, _mm_mul_pd(r3, _mm_set1_pd(h12))));
            }
            for (i = tst_tmp_tmp; i < i1; i++) {
              i2 = i + 10 * (b_k - 1);
              rt2r = h[i2];
              nr = i + 10 * b_k;
              rt1r = h[nr];
              i3 = i + 10 * (b_k + 1);
              s = h[i3];
              h21 = (rt2r + d * rt1r) + h22 * s;
              rt2r -= h21 * aa;
              h[i2] = rt2r;
              rt1r -= h21 * tst;
              h[nr] = rt1r;
              s -= h21 * h12;
              h[i3] = s;
            }
          } else if (nr == 2) {
            for (i = b_k; i < 11; i++) {
              i1 = b_k + 10 * (i - 1);
              h22 = h[i1 - 1];
              rt2r = h[i1];
              h21 = h22 + d * rt2r;
              h22 -= h21 * aa;
              h[i1 - 1] = h22;
              rt2r -= h21 * tst;
              h[i1] = rt2r;
            }
            tst_tmp_tmp = ((b_i + 1) / 2) << 1;
            v_tmp = tst_tmp_tmp - 2;
            for (i = 0; i <= v_tmp; i += 2) {
              __m128d r1;
              __m128d r2;
              i1 = i + 10 * b_k;
              r = _mm_loadu_pd(&h[i1]);
              i2 = i + 10 * (b_k - 1);
              r1 = _mm_loadu_pd(&h[i2]);
              r2 = _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r));
              _mm_storeu_pd(&h[i2],
                            _mm_sub_pd(r1, _mm_mul_pd(r2, _mm_set1_pd(aa))));
              _mm_storeu_pd(&h[i1],
                            _mm_sub_pd(r, _mm_mul_pd(r2, _mm_set1_pd(tst))));
            }
            for (i = tst_tmp_tmp; i <= b_i; i++) {
              i1 = i + 10 * (b_k - 1);
              h22 = h[i1];
              i2 = i + 10 * b_k;
              rt2r = h[i2];
              h21 = h22 + d * rt2r;
              h22 -= h21 * aa;
              h[i1] = h22;
              rt2r -= h21 * tst;
              h[i2] = rt2r;
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
      if ((l != b_i + 1) && (l == b_i)) {
        i1 = b_i + 10 * b_i;
        d = h[i1 - 1];
        i2 = 10 * (b_i - 1);
        nr = b_i + i2;
        h22 = h[nr];
        rt2r = h[i1];
        xdlanv2(&h[nr - 1], &d, &h22, &rt2r, &s, &tst, &h21, &h12, &aa);
        h[i1 - 1] = d;
        h[nr] = h22;
        h[i1] = rt2r;
        if (b_i + 1 < 10) {
          tst_tmp_tmp = (b_i + 1) * 10 + b_i;
          i1 = 8 - b_i;
          for (k = 0; k <= i1; k++) {
            v_tmp = tst_tmp_tmp + k * 10;
            tst = h[v_tmp];
            h21 = h[v_tmp - 1];
            h[v_tmp] = h12 * tst - aa * h21;
            h[v_tmp - 1] = h12 * h21 + aa * tst;
          }
        }
        if (b_i - 1 >= 1) {
          nr = b_i * 10;
          i1 = (uint8_T)(b_i - 1);
          for (k = 0; k < i1; k++) {
            tst_tmp_tmp = nr + k;
            tst = h[tst_tmp_tmp];
            v_tmp = i2 + k;
            h21 = h[v_tmp];
            h[tst_tmp_tmp] = h12 * tst - aa * h21;
            h[v_tmp] = h12 * h21 + aa * tst;
          }
        }
      }
      kdefl = 0;
      b_i = l - 2;
    }
  }
  for (i = 0; i < 8; i++) {
    for (b_i = i + 3; b_i < 11; b_i++) {
      h[(b_i + 10 * i) - 1] = 0.0;
    }
  }
  return info;
}

int32_T xhseqr(const emlrtStack *sp, real_T h[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v[3];
  real_T aa;
  real_T d;
  real_T d1;
  real_T h12;
  real_T h21;
  real_T h22;
  real_T rt1r;
  real_T s;
  real_T tst;
  int32_T b_k;
  int32_T c_k;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T kdefl;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ih_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &jh_emlrtRSI;
  info = 0;
  h[2] = 0.0;
  kdefl = 0;
  i = 2;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    int32_T b_i;
    int32_T i1;
    int32_T its;
    int32_T k;
    int32_T nr;
    int32_T tst_tmp_tmp;
    boolean_T converged;
    boolean_T exitg2;
    k = -1;
    converged = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      boolean_T exitg3;
      k = i - 1;
      exitg3 = false;
      while ((!exitg3) && (k + 2 > 1)) {
        b_i = k + 3 * k;
        d = muDoubleScalarAbs(h[b_i + 1]);
        if (d <= 3.0062525400134592E-292) {
          exitg3 = true;
        } else {
          nr = 3 * (k + 1);
          tst_tmp_tmp = k + nr;
          h21 = muDoubleScalarAbs(h[tst_tmp_tmp + 1]);
          tst = muDoubleScalarAbs(h[b_i]) + h21;
          if (tst == 0.0) {
            if (k >= 1) {
              tst = muDoubleScalarAbs(h[k]);
            }
            if (k + 3 <= 3) {
              tst += muDoubleScalarAbs(h[nr + 2]);
            }
          }
          if (d <= 2.2204460492503131E-16 * tst) {
            h12 = muDoubleScalarAbs(h[tst_tmp_tmp]);
            tst = muDoubleScalarAbs(h[b_i] - h[tst_tmp_tmp + 1]);
            aa = muDoubleScalarMax(h21, tst);
            tst = muDoubleScalarMin(h21, tst);
            s = aa + tst;
            if (muDoubleScalarMin(d, h12) * (muDoubleScalarMax(d, h12) / s) <=
                muDoubleScalarMax(3.0062525400134592E-292,
                                  2.2204460492503131E-16 * (tst * (aa / s)))) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }
      if (k + 2 > 1) {
        h[(k + 3 * k) + 1] = 0.0;
      }
      if (k + 2 >= i) {
        converged = true;
        exitg2 = true;
      } else {
        __m128d r;
        int32_T m;
        kdefl++;
        if (kdefl - kdefl / 20 * 20 == 0) {
          s = muDoubleScalarAbs(h[i + 3 * (i - 1)]) +
              muDoubleScalarAbs(h[i - 1]);
          tst = 0.75 * s + h[i + 3 * i];
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
          nr = i + 3 * (i - 1);
          tst = h[nr - 1];
          h21 = h[nr];
          nr = i + 3 * i;
          h12 = h[nr - 1];
          h22 = h[nr];
        }
        s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(h12)) +
             muDoubleScalarAbs(h21)) +
            muDoubleScalarAbs(h22);
        if (s == 0.0) {
          rt1r = 0.0;
          tst = 0.0;
          aa = 0.0;
          h21 = 0.0;
        } else {
          tst /= s;
          h21 /= s;
          h12 /= s;
          h22 /= s;
          aa = (tst + h22) / 2.0;
          tst = (tst - aa) * (h22 - aa) - h12 * h21;
          h21 = muDoubleScalarSqrt(muDoubleScalarAbs(tst));
          if (tst >= 0.0) {
            rt1r = aa * s;
            aa = rt1r;
            tst = h21 * s;
            h21 = -tst;
          } else {
            rt1r = aa + h21;
            aa -= h21;
            if (muDoubleScalarAbs(rt1r - h22) <= muDoubleScalarAbs(aa - h22)) {
              rt1r *= s;
              aa = rt1r;
            } else {
              aa *= s;
              rt1r = aa;
            }
            tst = 0.0;
            h21 = 0.0;
          }
        }
        m = i - 1;
        if (i - 1 >= 1) {
          s = (muDoubleScalarAbs(h[0] - aa) + muDoubleScalarAbs(h21)) +
              muDoubleScalarAbs(h[1]);
          h12 = h[1] / s;
          v[0] = (h12 * h[3] + (h[0] - rt1r) * ((h[0] - aa) / s)) -
                 tst * (h21 / s);
          v[1] = h12 * (((h[0] + h[4]) - rt1r) - aa);
          v[2] = h12 * h[5];
          s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
              muDoubleScalarAbs(v[2]);
          r = _mm_loadu_pd(&v[0]);
          _mm_storeu_pd(&v[0], _mm_div_pd(r, _mm_set1_pd(s)));
          v[2] /= s;
        }
        for (b_k = m; b_k <= i; b_k++) {
          b_i = (i - b_k) + 2;
          nr = muIntScalarMin_sint32(3, b_i);
          if (b_k > i - 1) {
            tst_tmp_tmp = ((b_k - 2) * 3 + b_k) - 1;
            for (c_k = 0; c_k < nr; c_k++) {
              v[c_k] = h[tst_tmp_tmp + c_k];
            }
          }
          tst = v[0];
          c_st.site = &ph_emlrtRSI;
          rt1r = b_xzlarfg(&c_st, nr, &tst, v);
          if (b_k > i - 1) {
            h[b_k - 1] = tst;
            h[b_k] = 0.0;
            if (b_k < i) {
              /* Check node always fails. would cause program termination and
               * was eliminated */
            }
          }
          d = v[1];
          h12 = rt1r * v[1];
          if (nr == 3) {
            d1 = v[2];
            tst = rt1r * v[2];
            for (j = b_k; j < 4; j++) {
              tst_tmp_tmp = 3 * (j - 1);
              nr = b_k + tst_tmp_tmp;
              h21 = h[nr - 1];
              aa = (h21 + d * h[nr]) + d1 * h[tst_tmp_tmp + 2];
              h[nr - 1] = h21 - aa * rt1r;
              h[nr] -= aa * h12;
              h[tst_tmp_tmp + 2] -= aa * tst;
            }
            b_i = b_k + 3;
            i1 = i + 1;
            b_i = muIntScalarMin_sint32(b_i, i1);
            c_k = (b_i / 2) << 1;
            tst_tmp_tmp = c_k - 2;
            for (j = 0; j <= tst_tmp_tmp; j += 2) {
              __m128d r1;
              __m128d r2;
              i1 = j + 3 * b_k;
              r = _mm_loadu_pd(&h[i1]);
              nr = j + 3 * (b_k - 1);
              r1 = _mm_loadu_pd(&h[nr]);
              r2 = _mm_loadu_pd(&h[j + 6]);
              r = _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r)),
                             _mm_mul_pd(_mm_set1_pd(d1), r2));
              r1 = _mm_loadu_pd(&h[nr]);
              _mm_storeu_pd(&h[nr],
                            _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(rt1r))));
              r1 = _mm_loadu_pd(&h[i1]);
              _mm_storeu_pd(&h[i1],
                            _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(h12))));
              r1 = _mm_loadu_pd(&h[j + 6]);
              _mm_storeu_pd(&h[j + 6],
                            _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(tst))));
            }
            for (j = c_k; j < b_i; j++) {
              tst_tmp_tmp = j + 3 * (b_k - 1);
              h21 = h[tst_tmp_tmp];
              nr = j + 3 * b_k;
              aa = (h21 + d * h[nr]) + d1 * h[j + 6];
              h[tst_tmp_tmp] = h21 - aa * rt1r;
              h[nr] -= aa * h12;
              h[j + 6] -= aa * tst;
            }
          } else if (nr == 2) {
            for (j = b_k; j < 4; j++) {
              b_i = b_k + 3 * (j - 1);
              d1 = h[b_i - 1];
              h22 = h[b_i];
              aa = d1 + d * h22;
              d1 -= aa * rt1r;
              h[b_i - 1] = d1;
              h22 -= aa * h12;
              h[b_i] = h22;
            }
            c_k = ((i + 1) / 2) << 1;
            tst_tmp_tmp = c_k - 2;
            for (j = 0; j <= tst_tmp_tmp; j += 2) {
              __m128d r1;
              __m128d r2;
              b_i = j + 3 * b_k;
              r = _mm_loadu_pd(&h[b_i]);
              i1 = j + 3 * (b_k - 1);
              r1 = _mm_loadu_pd(&h[i1]);
              r2 = _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r));
              _mm_storeu_pd(&h[i1],
                            _mm_sub_pd(r1, _mm_mul_pd(r2, _mm_set1_pd(rt1r))));
              _mm_storeu_pd(&h[b_i],
                            _mm_sub_pd(r, _mm_mul_pd(r2, _mm_set1_pd(h12))));
            }
            for (j = c_k; j <= i; j++) {
              b_i = j + 3 * (b_k - 1);
              d1 = h[b_i];
              i1 = j + 3 * b_k;
              h22 = h[i1];
              aa = d1 + d * h22;
              d1 -= aa * rt1r;
              h[b_i] = d1;
              h22 -= aa * h12;
              h[i1] = h22;
            }
          }
        }
        its++;
      }
    }
    if (!converged) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((k + 2 != i + 1) && (k + 2 == i)) {
        b_i = i + 3 * i;
        d = h[b_i - 1];
        i1 = 3 * (i - 1);
        nr = i + i1;
        d1 = h[nr];
        h22 = h[b_i];
        xdlanv2(&h[nr - 1], &d, &d1, &h22, &h21, &h12, &aa, &rt1r, &s);
        h[b_i - 1] = d;
        h[nr] = d1;
        h[b_i] = h22;
        if (i + 1 < 3) {
          b_i = 1 - i;
          nr = (i + 1) * 3 + i;
          for (b_k = 0; b_k <= b_i; b_k++) {
            tst_tmp_tmp = nr + b_k * 3;
            tst = h[tst_tmp_tmp];
            h21 = h[tst_tmp_tmp - 1];
            h[tst_tmp_tmp] = rt1r * tst - s * h21;
            h[tst_tmp_tmp - 1] = rt1r * h21 + s * tst;
          }
        }
        if (i - 1 >= 1) {
          nr = i * 3;
          tst = rt1r * h[i1] + s * h[nr];
          h[nr] = rt1r * h[nr] - s * h[i1];
          h[i1] = tst;
        }
      }
      kdefl = 0;
      i = k;
    }
  }
  h[2] = 0.0;
  return info;
}

/* End of code generation (xhseqr.c) */
