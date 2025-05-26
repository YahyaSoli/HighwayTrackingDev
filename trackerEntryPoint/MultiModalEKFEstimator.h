/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MultiModalEKFEstimator.h
 *
 * Code generation for function 'MultiModalEKFEstimator'
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
int32_T c_MultiModalEKFEstimator_toObje(
    const struct_T pdf_Hypothesis[2], const real_T pdf_LogWeights[2],
    real_T objectTrackPdf_State[10], real_T objectTrackPdf_StateCovariance[100],
    real_T c_objectTrackPdf_ObjectClassPro[2]);

/* End of code generation (MultiModalEKFEstimator.h) */
