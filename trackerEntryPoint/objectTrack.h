/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * objectTrack.h
 *
 * Code generation for function 'objectTrack'
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
void objectTrack_set_StateCovariance(const emlrtStack *sp, objectTrack *obj,
                                     const real_T b_value[100]);

/* End of code generation (objectTrack.h) */
