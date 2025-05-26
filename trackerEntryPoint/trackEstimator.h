/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackEstimator.h
 *
 * Code generation for function 'trackEstimator'
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
void b_trackEstimator(
    const emlrtStack *sp, const real_T c_tgtSpecs_f1_StateTransitionMo[2],
    const real_T d_tgtSpecs_f1_StateTransitionMo[2],
    const real_T e_tgtSpecs_f1_StateTransitionMo[2],
    const real_T f_tgtSpecs_f1_StateTransitionMo[2],
    const real_T g_tgtSpecs_f1_StateTransitionMo[2],
    const real_T h_tgtSpecs_f1_StateTransitionMo[2],
    real_T i_tgtSpecs_f1_StateTransitionMo,
    real_T j_tgtSpecs_f1_StateTransitionMo,
    const real_T k_tgtSpecs_f1_StateTransitionMo[2],
    real_T l_tgtSpecs_f1_StateTransitionMo,
    const real_T c_tgtSpecs_f2_StateTransitionMo[2],
    const real_T d_tgtSpecs_f2_StateTransitionMo[2],
    const real_T e_tgtSpecs_f2_StateTransitionMo[2],
    const c_fusion_tracker_internal_motio *f_tgtSpecs_f2_StateTransitionMo,
    k_fusion_tracker_internal_estim *trkEstimator_StateEstimator);

void c_trackEstimator(
    const emlrtStack *sp, const real_T c_tgtSpecs_f1_StateTransitionMo[2],
    const real_T d_tgtSpecs_f1_StateTransitionMo[2],
    const real_T e_tgtSpecs_f1_StateTransitionMo[2],
    const real_T f_tgtSpecs_f1_StateTransitionMo[2],
    const real_T g_tgtSpecs_f1_StateTransitionMo[2],
    const real_T h_tgtSpecs_f1_StateTransitionMo[2],
    real_T i_tgtSpecs_f1_StateTransitionMo,
    real_T j_tgtSpecs_f1_StateTransitionMo,
    const real_T k_tgtSpecs_f1_StateTransitionMo[2],
    real_T l_tgtSpecs_f1_StateTransitionMo,
    const real_T c_tgtSpecs_f2_StateTransitionMo[2],
    const real_T d_tgtSpecs_f2_StateTransitionMo[2],
    const real_T e_tgtSpecs_f2_StateTransitionMo[2],
    const c_fusion_tracker_internal_motio *f_tgtSpecs_f2_StateTransitionMo,
    const c_fusion_tracker_sensorspecs_Au *sensorSpecs,
    o_fusion_tracker_internal_estim *trkEstimator_StateEstimator);

void trackEstimator(
    const emlrtStack *sp, const c_fusion_tracker_targetspecs_Hi *tgtSpecs_f1,
    const d_fusion_tracker_targetspecs_Hi *tgtSpecs_f2,
    const d_fusion_tracker_sensorspecs_Au *sensorSpecs, trackingEKF *iobj_0,
    f_fusion_tracker_internal_estim *trkEstimator_StateEstimator);

/* End of code generation (trackEstimator.h) */
