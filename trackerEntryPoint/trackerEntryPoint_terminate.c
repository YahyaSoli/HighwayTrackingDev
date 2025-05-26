/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackerEntryPoint_terminate.c
 *
 * Code generation for function 'trackerEntryPoint_terminate'
 *
 */

/* Include files */
#include "trackerEntryPoint_terminate.h"
#include "_coder_trackerEntryPoint_mex.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint.h"
#include "trackerEntryPoint_data.h"

/* Function Declarations */
static void c_trackerEntryPoint_emx_free_dt(const emlrtStack *sp,
                                            const void *r);

static void emlrtExitTimeCleanupDtorFcn(const void *r);

/* Function Definitions */
static void c_trackerEntryPoint_emx_free_dt(const emlrtStack *sp, const void *r)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = NULL;
  trackerEntryPoint_emx_free(&st);
}

static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void trackerEntryPoint_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(
      &st, false, NULL, (void *)&emlrtExitTimeCleanupDtorFcn, NULL, NULL, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, NULL,
                                    (void *)&c_trackerEntryPoint_emx_free_dt,
                                    NULL, NULL, NULL);
  trackerEntryPoint_emx_free(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void trackerEntryPoint_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (trackerEntryPoint_terminate.c) */
