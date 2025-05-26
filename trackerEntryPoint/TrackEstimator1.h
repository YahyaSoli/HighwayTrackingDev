/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TrackEstimator1.h
 *
 * Code generation for function 'TrackEstimator1'
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
real_T c_TrackEstimator_sampleDistribu(
    f_fusion_tracker_internal_estim *estimator_StateEstimator,
    uint32_T *pdf_TrackID, uint32_T *pdf_Age, boolean_T *pdf_IsConfirmed,
    boolean_T *pdf_IsCoasted, struct_T pdf_Hypothesis[2],
    real_T pdf_LogWeights[2], boolean_T pdf_IsValid[2],
    real_T *pdf_ExistenceProbability);

/* End of code generation (TrackEstimator1.h) */
