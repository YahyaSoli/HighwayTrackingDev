/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackerEntryPoint_initialize.c
 *
 * Code generation for function 'trackerEntryPoint_initialize'
 *
 */

/* Include files */
#include "trackerEntryPoint_initialize.h"
#include "_coder_trackerEntryPoint_mex.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint.h"
#include "trackerEntryPoint_data.h"

/* Function Declarations */
static void trackerEntryPoint_once(const emlrtStack *sp);

/* Function Definitions */
static void trackerEntryPoint_once(const emlrtStack *sp)
{
  emlrtStack st;
  mex_InitInfAndNan();
  st.prev = sp;
  st.tls = sp->tls;
  st.site = NULL;
  trackerEntryPoint_emx_init(&st);
  trackerEntryPoint_init();
}

void trackerEntryPoint_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "sensor_fusion_and_tracking", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    trackerEntryPoint_once(&st);
  }
}

/* End of code generation (trackerEntryPoint_initialize.c) */
