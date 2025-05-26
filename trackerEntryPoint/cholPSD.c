/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cholPSD.c
 *
 * Code generation for function 'cholPSD'
 *
 */

/* Include files */
#include "cholPSD.h"
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "xpotrf.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kj_emlrtRSI = {
    15,        /* lineNo */
    "cholPSD", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\cholPSD.m" /* pathName */
};

static emlrtRSInfo lj_emlrtRSI = {
    18,        /* lineNo */
    "cholPSD", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\cholPSD.m" /* pathName */
};

static emlrtRSInfo mj_emlrtRSI = {
    20,        /* lineNo */
    "cholPSD", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\cholPSD.m" /* pathName */
};

static emlrtRSInfo nj_emlrtRSI = {
    15,     /* lineNo */
    "chol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m" /* pathName
                                                                        */
};

static emlrtRSInfo oj_emlrtRSI = {
    84,     /* lineNo */
    "chol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\chol.m" /* pathName
                                                                           */
};

static emlrtRSInfo pj_emlrtRSI = {
    100,    /* lineNo */
    "chol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\chol.m" /* pathName
                                                                           */
};

static emlrtRSInfo qj_emlrtRSI = {
    101,    /* lineNo */
    "chol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\chol.m" /* pathName
                                                                           */
};

static emlrtRSInfo bk_emlrtRSI = {
    12,     /* lineNo */
    "chol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m" /* pathName
                                                                        */
};

static emlrtRSInfo ck_emlrtRSI = {
    15,       /* lineNo */
    "svdPSD", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\svdPSD.m" /* pathName */
};

static emlrtRSInfo dk_emlrtRSI = {
    17,       /* lineNo */
    "svdPSD", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\svdPSD.m" /* pathName */
};

static emlrtRSInfo ek_emlrtRSI = {
    14,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo fk_emlrtRSI = {
    36,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo gk_emlrtRSI = {
    52,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo hk_emlrtRSI = {
    107,          /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo ik_emlrtRSI = {
    34,       /* lineNo */
    "xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    109,    /* lineNo */
    27,     /* colNo */
    "chol", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\chol.m" /* pName
                                                                           */
};

/* Function Definitions */
void cholPSD(const emlrtStack *sp, const real_T A[9], real_T b_value[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T Ss[9];
  real_T b_A[9];
  int32_T b;
  int32_T info;
  int32_T j;
  int32_T jmax;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kj_emlrtRSI;
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
  b_st.site = &nj_emlrtRSI;
  memcpy(&Ss[0], &A[0], 9U * sizeof(real_T));
  c_st.site = &oj_emlrtRSI;
  info = xpotrf(&c_st, Ss);
  if (info == 0) {
    jmax = 2;
  } else {
    jmax = info - 2;
  }
  c_st.site = &pj_emlrtRSI;
  if (jmax > 2147483646) {
    d_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (j = 0; j < jmax; j++) {
    c_st.site = &qj_emlrtRSI;
    if ((j + 2 <= jmax + 1) && (jmax + 1 > 2147483646)) {
      d_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }
  if (info == 0) {
    st.site = &lj_emlrtRSI;
    b_st.site = &bk_emlrtRSI;
    memcpy(&Ss[0], &A[0], 9U * sizeof(real_T));
    c_st.site = &oj_emlrtRSI;
    info = xpotrf(&c_st, Ss);
    if (info == 0) {
      jmax = 3;
    } else {
      jmax = info - 1;
    }
    b = jmax - 2;
    c_st.site = &pj_emlrtRSI;
    if (jmax - 1 > 2147483646) {
      d_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= b; j++) {
      int32_T a;
      a = j + 2;
      c_st.site = &qj_emlrtRSI;
      if ((j + 2 <= jmax) && (jmax > 2147483646)) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      if (a <= jmax) {
        memset(&Ss[(j * 3 + a) + -1], 0,
               (uint32_T)((jmax - a) + 1) * sizeof(real_T));
      }
    }
    if (info != 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:posdef",
                                    "MATLAB:posdef", 0);
    }
    for (jmax = 0; jmax < 3; jmax++) {
      b_value[3 * jmax] = Ss[jmax];
      b_value[3 * jmax + 1] = Ss[jmax + 3];
      b_value[3 * jmax + 2] = Ss[jmax + 6];
    }
  } else {
    __m128d r;
    real_T V[9];
    real_T s[3];
    boolean_T allFiniteA;
    st.site = &mj_emlrtRSI;
    b_st.site = &ck_emlrtRSI;
    c_st.site = &ek_emlrtRSI;
    allFiniteA = !anyNonFinite(A);
    if (allFiniteA) {
      c_st.site = &fk_emlrtRSI;
      d_st.site = &gk_emlrtRSI;
      e_st.site = &hk_emlrtRSI;
      memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
      f_st.site = &ik_emlrtRSI;
      xzsvdc(&f_st, b_A, Ss, s, V);
    } else {
      s[0] = rtNaN;
      s[1] = rtNaN;
      s[2] = rtNaN;
      for (jmax = 0; jmax < 9; jmax++) {
        V[jmax] = rtNaN;
      }
    }
    memset(&Ss[0], 0, 9U * sizeof(real_T));
    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    b_st.site = &dk_emlrtRSI;
    allFiniteA = false;
    for (jmax = 0; jmax < 9; jmax++) {
      if (allFiniteA || (Ss[jmax] < 0.0)) {
        allFiniteA = true;
      }
    }
    if (allFiniteA) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    r = _mm_loadu_pd(&Ss[0]);
    _mm_storeu_pd(&Ss[0], _mm_sqrt_pd(r));
    r = _mm_loadu_pd(&Ss[2]);
    _mm_storeu_pd(&Ss[2], _mm_sqrt_pd(r));
    r = _mm_loadu_pd(&Ss[4]);
    _mm_storeu_pd(&Ss[4], _mm_sqrt_pd(r));
    r = _mm_loadu_pd(&Ss[6]);
    _mm_storeu_pd(&Ss[6], _mm_sqrt_pd(r));
    Ss[8] = muDoubleScalarSqrt(Ss[8]);
    for (jmax = 0; jmax < 3; jmax++) {
      real_T d;
      real_T d1;
      real_T d2;
      d = V[jmax];
      d1 = V[jmax + 3];
      d2 = V[jmax + 6];
      for (b = 0; b < 3; b++) {
        b_value[jmax + 3 * b] =
            (d * Ss[3 * b] + d1 * Ss[3 * b + 1]) + d2 * Ss[3 * b + 2];
      }
    }
  }
}

/* End of code generation (cholPSD.c) */
