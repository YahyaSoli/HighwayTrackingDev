/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * uniquetolcg.h
 *
 * Code generation for function 'uniquetolcg'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "trackerEntryPoint_types.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void uniquetolcg(const emlrtStack *sp, const emxArray_real_T *in, real_T tol,
                 emxArray_real_T *out);

/* End of code generation (uniquetolcg.h) */
