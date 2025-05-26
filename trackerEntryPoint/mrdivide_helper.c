/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "blas.h"
#include "lapacke.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo oq_emlrtRSI = {
    42,      /* lineNo */
    "mrdiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo
    pq_emlrtRSI =
        {
            67,        /* lineNo */
            "lusolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    qq_emlrtRSI =
        {
            107,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    rq_emlrtRSI =
        {
            135,          /* lineNo */
            "XtimesInvA", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    sq_emlrtRSI =
        {
            140,          /* lineNo */
            "XtimesInvA", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    tq_emlrtRSI =
        {
            142,          /* lineNo */
            "XtimesInvA", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo uq_emlrtRSI = {
    27,       /* lineNo */
    "xgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" /* pathName */
};

static emlrtRSInfo vq_emlrtRSI = {
    91,             /* lineNo */
    "ceval_xgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" /* pathName */
};

static emlrtRSInfo yq_emlrtRSI = {
    67,      /* lineNo */
    "xtrsm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm."
    "m" /* pathName */
};

/* Function Definitions */
void mrdiv(const emlrtStack *sp, real_T A_data[], int32_T A_size[2],
           const real_T B_data[], const int32_T B_size[2])
{
  static const char_T fname[19] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 't', 'r', 'f',
                                   '_', 'w', 'o', 'r', 'k'};
  ptrdiff_t info_t;
  ptrdiff_t ipiv_t_data;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T alpha1;
  real_T b_A_data;
  int32_T loop_ub;
  char_T DIAGA1;
  char_T SIDE1;
  char_T TRANSA1;
  char_T UPLO1;
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
  if ((A_size[0] == 0) || (A_size[1] == 0) ||
      ((B_size[0] == 0) || (B_size[1] == 0))) {
    int32_T unnamed_idx_0;
    unnamed_idx_0 = A_size[0];
    loop_ub = B_size[0];
    A_size[1] = B_size[0];
    if (loop_ub - 1 >= 0) {
      for (loop_ub = 0; loop_ub < unnamed_idx_0; loop_ub++) {
        A_data[0] = 0.0;
      }
    }
  } else {
    st.site = &oq_emlrtRSI;
    b_st.site = &pq_emlrtRSI;
    c_st.site = &qq_emlrtRSI;
    d_st.site = &rq_emlrtRSI;
    b_A_data = B_data[0];
    e_st.site = &uq_emlrtRSI;
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)1, (ptrdiff_t)1, &b_A_data,
                                 (ptrdiff_t)1, &ipiv_t_data);
    f_st.site = &vq_emlrtRSI;
    if ((int32_T)info_t < 0) {
      if ((int32_T)info_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&f_st, &e_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&f_st, &d_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      19, &fname[0], 12, (int32_T)info_t);
      }
    }
    d_st.site = &sq_emlrtRSI;
    if (A_size[0] >= 1) {
      e_st.site = &yq_emlrtRSI;
      alpha1 = 1.0;
      DIAGA1 = 'N';
      TRANSA1 = 'N';
      UPLO1 = 'U';
      SIDE1 = 'R';
      info_t = (ptrdiff_t)1;
      ipiv_t_data = (ptrdiff_t)1;
      lda_t = (ptrdiff_t)1;
      ldb_t = (ptrdiff_t)A_size[0];
      dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &info_t, &ipiv_t_data, &alpha1,
            &b_A_data, &lda_t, &A_data[0], &ldb_t);
    }
    d_st.site = &tq_emlrtRSI;
    if (A_size[0] >= 1) {
      e_st.site = &yq_emlrtRSI;
      alpha1 = 1.0;
      DIAGA1 = 'U';
      TRANSA1 = 'N';
      UPLO1 = 'L';
      SIDE1 = 'R';
      info_t = (ptrdiff_t)1;
      ipiv_t_data = (ptrdiff_t)1;
      lda_t = (ptrdiff_t)1;
      ldb_t = (ptrdiff_t)A_size[0];
      dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &info_t, &ipiv_t_data, &alpha1,
            &b_A_data, &lda_t, &A_data[0], &ldb_t);
    }
  }
}

/* End of code generation (mrdivide_helper.c) */
