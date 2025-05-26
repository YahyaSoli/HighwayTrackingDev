/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackingEKF.h
 *
 * Code generation for function 'trackingEKF'
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
void b_trackingEKF_trackingEKF(const emlrtStack *sp,
                               const real_T varargin_22[9]);

trackingEKF *trackingEKF_trackingEKF(const emlrtStack *sp, trackingEKF *EKF,
                                     const real_T varargin_22[9]);

/* End of code generation (trackingEKF.h) */
