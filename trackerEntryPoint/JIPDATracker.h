/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * JIPDATracker.h
 *
 * Code generation for function 'JIPDATracker'
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
void JIPDATracker_stepImpl(const emlrtStack *sp,
                           fusion_tracker_JIPDATracker *b_tracker,
                           real_T varargin_4_Time,
                           const real_T c_varargin_4_EgoRotationalDispl[3],
                           emxArray_struct4_T *varargout_1);

void c_JIPDATracker_updateTargetSpec(const emlrtStack *sp,
                                     fusion_tracker_JIPDATracker *obj);

/* End of code generation (JIPDATracker.h) */
