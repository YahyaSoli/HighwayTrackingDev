/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eigStandard.c
 *
 * Code generation for function 'eigStandard'
 *
 */

/* Include files */
#include "eigStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "warning.h"
#include "xdlahqr.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xzgebal.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "xzlascl.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo fi_emlrtRSI = {
    54,      /* lineNo */
    "xgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeev.m" /* pathName */
};

static emlrtRSInfo gi_emlrtRSI = {
    49,       /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo hi_emlrtRSI = {
    67,       /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo ii_emlrtRSI = {
    73,       /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo ji_emlrtRSI = {
    130,      /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo ki_emlrtRSI = {
    131,      /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo li_emlrtRSI = {
    133,      /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo mi_emlrtRSI = {
    134,      /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo ni_emlrtRSI = {
    139,      /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo ej_emlrtRSI = {
    28,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo fj_emlrtRSI = {
    37,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

/* Function Definitions */
void eigStandard(const emlrtStack *sp, const real_T A[9], creal_T V[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T a[9];
  real_T tau[2];
  real_T absxk;
  real_T alpha1;
  real_T anrm;
  int32_T b_i;
  int32_T i;
  int32_T ihi;
  int32_T lastc;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &di_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &fi_emlrtRSI;
  memcpy(&a[0], &A[0], 9U * sizeof(real_T));
  lastc = 0;
  anrm = 0.0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 9)) {
    absxk = muDoubleScalarAbs(A[i]);
    if (muDoubleScalarIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }
      i++;
    }
  }
  if (muDoubleScalarIsInf(anrm) || muDoubleScalarIsNaN(anrm)) {
    V[0].re = rtNaN;
    V[0].im = 0.0;
    V[1].re = rtNaN;
    V[1].im = 0.0;
    V[2].re = rtNaN;
    V[2].im = 0.0;
  } else {
    real_T wi[3];
    real_T work[3];
    int32_T ilo;
    boolean_T scalea;
    absxk = anrm;
    scalea = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      scalea = true;
      absxk = 6.7178761075670888E-139;
      d_xzlascl(anrm, absxk, a);
    } else if (anrm > 1.4885657073574029E+138) {
      scalea = true;
      absxk = 1.4885657073574029E+138;
      d_xzlascl(anrm, absxk, a);
    }
    c_st.site = &gi_emlrtRSI;
    ilo = xzgebal(&c_st, a, &ihi, work);
    c_st.site = &hi_emlrtRSI;
    if ((ihi - ilo) + 1 > 1) {
      d_st.site = &ej_emlrtRSI;
      if (ilo - 1 > 2147483646) {
        e_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      i = (uint8_T)(ilo - 1);
      if (i - 1 >= 0) {
        memset(&tau[0], 0, (uint32_T)i * sizeof(real_T));
      }
      for (b_i = ihi; b_i < 3; b_i++) {
        tau[b_i - 1] = 0.0;
      }
      work[0] = 0.0;
      work[1] = 0.0;
      work[2] = 0.0;
      d_st.site = &fj_emlrtRSI;
      if ((ilo <= ihi - 1) && (ihi - 1 > 2147483646)) {
        e_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (b_i = ilo; b_i < ihi; b_i++) {
        real_T d;
        int32_T alpha1_tmp;
        int32_T in;
        int32_T lastv;
        int32_T n;
        i = (b_i - 1) * 3;
        in = b_i * 3 + 1;
        n = ihi - b_i;
        alpha1_tmp = b_i + i;
        alpha1 = a[alpha1_tmp];
        d_st.site = &pg_emlrtRSI;
        d = xzlarfg(&d_st, n, &alpha1, a, i + 3);
        tau[b_i - 1] = d;
        a[alpha1_tmp] = 1.0;
        d_st.site = &qg_emlrtRSI;
        if (d != 0.0) {
          lastv = n;
          i = (alpha1_tmp + n) + 1;
          while ((lastv > 0) && (a[i - 2] == 0.0)) {
            lastv--;
            i--;
          }
          lastc = ihi;
          exitg1 = false;
          while ((!exitg1) && (lastc > 0)) {
            int32_T exitg2;
            int32_T ia;
            i = (in + lastc) - 1;
            ia = i;
            do {
              exitg2 = 0;
              if (ia <= i + (lastv - 1) * 3) {
                if (a[ia - 1] != 0.0) {
                  exitg2 = 1;
                } else {
                  ia += 3;
                }
              } else {
                lastc--;
                exitg2 = 2;
              }
            } while (exitg2 == 0);
            if (exitg2 == 1) {
              exitg1 = true;
            }
          }
        } else {
          lastv = 0;
          lastc = 0;
        }
        if (lastv > 0) {
          e_st.site = &sg_emlrtRSI;
          xgemv(&e_st, lastc, lastv, a, in, a, alpha1_tmp + 1, work);
          e_st.site = &tg_emlrtRSI;
          xgerc(&e_st, lastc, lastv, -tau[b_i - 1], work, alpha1_tmp + 1, a,
                in);
        }
        d_st.site = &rg_emlrtRSI;
        xzlarf(&d_st, n, 3 - b_i, alpha1_tmp + 1, tau[b_i - 1], a, b_i + in,
               work);
        a[alpha1_tmp] = alpha1;
      }
    }
    c_st.site = &ii_emlrtRSI;
    lastc = xdlahqr(&c_st, ilo, ihi, a, work, wi);
    if (scalea) {
      c_st.site = &ji_emlrtRSI;
      xzlascl(&c_st, absxk, anrm, 3 - lastc, work, lastc + 1);
      c_st.site = &ki_emlrtRSI;
      xzlascl(&c_st, absxk, anrm, 3 - lastc, wi, lastc + 1);
      if (lastc != 0) {
        c_st.site = &li_emlrtRSI;
        b_xzlascl(&c_st, absxk, anrm, ilo - 1, work);
        c_st.site = &mi_emlrtRSI;
        b_xzlascl(&c_st, absxk, anrm, ilo - 1, wi);
      }
    }
    if (lastc != 0) {
      c_st.site = &ni_emlrtRSI;
      if ((ilo <= lastc) && (lastc > 2147483646)) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (b_i = ilo; b_i <= lastc; b_i++) {
        work[b_i - 1] = rtNaN;
        wi[b_i - 1] = 0.0;
      }
    }
    V[0].re = work[0];
    V[0].im = wi[0];
    V[1].re = work[1];
    V[1].im = wi[1];
    V[2].re = work[2];
    V[2].im = wi[2];
  }
  if (lastc != 0) {
    st.site = &ei_emlrtRSI;
    warning(&st);
  }
}

/* End of code generation (eigStandard.c) */
