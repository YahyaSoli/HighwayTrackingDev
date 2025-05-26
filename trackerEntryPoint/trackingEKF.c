/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackingEKF.c
 *
 * Code generation for function 'trackingEKF'
 *
 */

/* Include files */
#include "trackingEKF.h"
#include "cholPSD.h"
#include "isSymmetricPositiveSemiDefinite.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_types.h"
#include "validateattributes.h"

/* Variable Definitions */
static emlrtRSInfo pe_emlrtRSI =
    {
        142,                       /* lineNo */
        "trackingEKF/trackingEKF", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\trackingE"
        "KF.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI =
    {
        143,                       /* lineNo */
        "trackingEKF/trackingEKF", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\trackingE"
        "KF.m" /* pathName */
};

static emlrtRSInfo re_emlrtRSI =
    {
        135,                       /* lineNo */
        "trackingEKF/trackingEKF", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\trackingE"
        "KF.m" /* pathName */
};

static emlrtRSInfo se_emlrtRSI =
    {
        144,                       /* lineNo */
        "trackingEKF/trackingEKF", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\trackingE"
        "KF.m" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    425,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\ExtendedKalmanFi"
    "lter.m" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    487,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\ExtendedKalmanFi"
    "lter.m" /* pathName */
};

static emlrtRSInfo ve_emlrtRSI = {
    495,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\ExtendedKalmanFi"
    "lter.m" /* pathName */
};

static emlrtRSInfo we_emlrtRSI = {
    535,                                         /* lineNo */
    "ExtendedKalmanFilter/ExtendedKalmanFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\ExtendedKalmanFi"
    "lter.m" /* pathName */
};

static emlrtRSInfo pf_emlrtRSI = {
    1067,                                    /* lineNo */
    "ExtendedKalmanFilter/set.ProcessNoise", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\ExtendedKalmanFi"
    "lter.m" /* pathName */
};

static emlrtRSInfo qf_emlrtRSI = {
    1074,                                    /* lineNo */
    "ExtendedKalmanFilter/set.ProcessNoise", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\ExtendedKalmanFi"
    "lter.m" /* pathName */
};

static emlrtRSInfo rf_emlrtRSI = {
    1084,                                    /* lineNo */
    "ExtendedKalmanFilter/set.ProcessNoise", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\ExtendedKalmanFi"
    "lter.m" /* pathName */
};

static emlrtRSInfo gl_emlrtRSI = {
    1,                                       /* lineNo */
    "RetrodictionFilter/RetrodictionFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\RetrodictionFilt"
    "er.m" /* pathName */
};

static emlrtRSInfo il_emlrtRSI = {
    1,                                               /* lineNo */
    "AbstractTrackingFilter/AbstractTrackingFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\AbstractTracking"
    "Filter.m" /* pathName */
};

static emlrtRSInfo jl_emlrtRSI = {
    1,                                       /* lineNo */
    "AbstractJPDAFilter/AbstractJPDAFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\trackinglib\\+"
    "matlabshared\\+tracking\\+internal\\AbstractJPDAFilt"
    "er.m" /* pathName */
};

static emlrtRSInfo kl_emlrtRSI = {
    1,                                             /* lineNo */
    "AbstractTunableFilter/AbstractTunableFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\+"
    "matlabshared\\+tracking\\+internal\\+fusion\\AbstractT"
    "unableFilter.m" /* pathName */
};

static emlrtRSInfo ll_emlrtRSI = {
    1,                                                         /* lineNo */
    "GaussianSmootherJIPDAFilter/GaussianSmootherJIPDAFilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\tracking\\fusionlib\\+"
    "matlabshared\\+tracking\\+internal\\+fusion\\GaussianS"
    "mootherJIPDAFilter.m" /* pathName */
};

static emlrtRSInfo nl_emlrtRSI = {
    55,                        /* lineNo */
    "EKFSmoother/EKFSmoother", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\smoothers\\+matlabshared\\+"
    "smoothers\\+internal\\EKFSmoother.m" /* pathName */
};

/* Function Definitions */
void b_trackingEKF_trackingEKF(const emlrtStack *sp,
                               const real_T varargin_22[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T unusedExpr[9];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &te_emlrtRSI;
  b_st.site = &we_emlrtRSI;
  c_st.site = &pf_emlrtRSI;
  validateattributes(&c_st, varargin_22);
  c_st.site = &qf_emlrtRSI;
  isSymmetricPositiveSemiDefinite(&c_st, varargin_22);
  c_st.site = &rf_emlrtRSI;
  cholPSD(&c_st, varargin_22, unusedExpr);
  st.site = &qe_emlrtRSI;
  b_st.site = &gl_emlrtRSI;
  st.site = &re_emlrtRSI;
  b_st.site = &il_emlrtRSI;
  st.site = &re_emlrtRSI;
  b_st.site = &jl_emlrtRSI;
  st.site = &re_emlrtRSI;
  b_st.site = &kl_emlrtRSI;
  st.site = &re_emlrtRSI;
  b_st.site = &ll_emlrtRSI;
  st.site = &se_emlrtRSI;
  b_st.site = &nl_emlrtRSI;
}

trackingEKF *trackingEKF_trackingEKF(const emlrtStack *sp, trackingEKF *EKF,
                                     const real_T varargin_22[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  trackingEKF *b_EKF;
  real_T unusedExpr[9];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_EKF = EKF;
  st.site = &pe_emlrtRSI;
  b_st.site = &te_emlrtRSI;
  b_st.site = &ue_emlrtRSI;
  for (i = 0; i < 10; i++) {
    b_EKF->pState[i] = 0.0;
  }
  b_EKF->pSqrtStateCovarianceScalar = 1.0;
  b_st.site = &ve_emlrtRSI;
  for (i = 0; i < 100; i++) {
    b_EKF->pSqrtStateCovariance[i] = iv[i];
  }
  b_EKF->pIsSetStateCovariance = true;
  b_EKF->pSqrtStateCovarianceScalar = -1.0;
  b_st.site = &we_emlrtRSI;
  c_st.site = &pf_emlrtRSI;
  validateattributes(&c_st, varargin_22);
  c_st.site = &qf_emlrtRSI;
  isSymmetricPositiveSemiDefinite(&c_st, varargin_22);
  c_st.site = &rf_emlrtRSI;
  cholPSD(&c_st, varargin_22, unusedExpr);
  st.site = &qe_emlrtRSI;
  b_st.site = &gl_emlrtRSI;
  st.site = &re_emlrtRSI;
  b_st.site = &il_emlrtRSI;
  st.site = &re_emlrtRSI;
  b_st.site = &jl_emlrtRSI;
  st.site = &re_emlrtRSI;
  b_st.site = &kl_emlrtRSI;
  st.site = &re_emlrtRSI;
  b_st.site = &ll_emlrtRSI;
  st.site = &se_emlrtRSI;
  b_st.site = &nl_emlrtRSI;
  return b_EKF;
}

/* End of code generation (trackingEKF.c) */
