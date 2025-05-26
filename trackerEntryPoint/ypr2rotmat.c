/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ypr2rotmat.c
 *
 * Code generation for function 'ypr2rotmat'
 *
 */

/* Include files */
#include "ypr2rotmat.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = {
    10,                         /* lineNo */
    "quaternionBase/normalize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\rotations\\rotationslib\\+"
    "matlabshared\\+rotations\\+internal\\@quaternionBa"
    "se\\normalize.m" /* pathName */
};

static emlrtRSInfo dr_emlrtRSI = {
    126,          /* lineNo */
    "ypr2rotmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\radarfusion\\+fusion\\+internal\\+"
    "frames\\ypr2rotmat.m" /* pathName */
};

static emlrtRSInfo er_emlrtRSI = {
    101,           /* lineNo */
    "quat2rotmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\radarfusion\\+fusion\\+internal\\+"
    "frames\\quat2rotmat.m" /* pathName */
};

static emlrtRSInfo fr_emlrtRSI = {
    19,                      /* lineNo */
    "quaternionBase/rotmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\rotations\\rotationslib\\+"
    "matlabshared\\+rotations\\+internal\\@quaternionBa"
    "se\\rotmat.m" /* pathName */
};

/* Function Definitions */
void ypr2rotmat(const emlrtStack *sp, const real_T ypr[3], real_T rot[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_ypr[3];
  real_T cosa;
  real_T cosb;
  real_T cosc;
  real_T n;
  real_T q_a;
  real_T q_b;
  real_T q_c;
  real_T q_d;
  real_T sina;
  real_T sinb;
  real_T sinc;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  _mm_storeu_pd(
      &b_ypr[0],
      _mm_div_pd(_mm_div_pd(_mm_mul_pd(_mm_loadu_pd(&ypr[0]),
                                       _mm_set1_pd(3.1415926535897931)),
                            _mm_set1_pd(180.0)),
                 _mm_set1_pd(2.0)));
  b_ypr[2] = ypr[2] * 3.1415926535897931 / 180.0 / 2.0;
  sina = muDoubleScalarSin(b_ypr[0]);
  sinb = muDoubleScalarSin(b_ypr[1]);
  sinc = muDoubleScalarSin(b_ypr[2]);
  cosa = muDoubleScalarCos(b_ypr[0]);
  cosb = muDoubleScalarCos(b_ypr[1]);
  cosc = muDoubleScalarCos(b_ypr[2]);
  n = cosa * cosb;
  q_a = n * cosc + sina * sinb * sinc;
  q_b = n * sinc - cosc * sina * sinb;
  q_c = cosa * cosc * sinb + cosb * sina * sinc;
  q_d = cosb * cosc * sina - cosa * sinb * sinc;
  st.site = &dr_emlrtRSI;
  b_st.site = &er_emlrtRSI;
  c_st.site = &fr_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  n = ((q_a * q_a + q_b * q_b) + q_c * q_c) + q_d * q_d;
  if (n < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  n = muDoubleScalarSqrt(n);
  q_a /= n;
  q_b /= n;
  q_c /= n;
  q_d /= n;
  sina = q_a * q_b * 2.0;
  sinb = q_a * q_c * 2.0;
  sinc = q_a * q_d * 2.0;
  cosa = q_b * q_c * 2.0;
  cosb = q_b * q_d * 2.0;
  cosc = q_c * q_d * 2.0;
  n = q_a * q_a * 2.0 - 1.0;
  rot[0] = n + q_b * q_b * 2.0;
  rot[3] = cosa + sinc;
  rot[6] = cosb - sinb;
  rot[1] = cosa - sinc;
  rot[4] = n + q_c * q_c * 2.0;
  rot[7] = cosc + sina;
  rot[2] = cosb + sinb;
  rot[5] = cosc - sina;
  rot[8] = n + q_d * q_d * 2.0;
}

/* End of code generation (ypr2rotmat.c) */
