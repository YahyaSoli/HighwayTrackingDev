/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_trackerEntryPoint_mex.c
 *
 * Code generation for function '_coder_trackerEntryPoint_mex'
 *
 */

/* Include files */
#include "_coder_trackerEntryPoint_mex.h"
#include "_coder_trackerEntryPoint_api.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_initialize.h"
#include "trackerEntryPoint_terminate.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&trackerEntryPoint_atexit);
  trackerEntryPoint_initialize();
  trackerEntryPoint_mexFunction(nlhs, plhs, nrhs, prhs);
  trackerEntryPoint_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void trackerEntryPoint_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                   const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        17, "trackerEntryPoint");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "trackerEntryPoint");
  }
  /* Call the function. */
  trackerEntryPoint_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_trackerEntryPoint_mex.c) */
