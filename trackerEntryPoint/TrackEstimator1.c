/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TrackEstimator1.c
 *
 * Code generation for function 'TrackEstimator1'
 *
 */

/* Include files */
#include "TrackEstimator1.h"
#include "ExtendedKalmanFilter.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_types.h"

/* Function Definitions */
real_T c_TrackEstimator_sampleDistribu(
    f_fusion_tracker_internal_estim *estimator_StateEstimator,
    uint32_T *pdf_TrackID, uint32_T *pdf_Age, boolean_T *pdf_IsConfirmed,
    boolean_T *pdf_IsCoasted, struct_T pdf_Hypothesis[2],
    real_T pdf_LogWeights[2], boolean_T pdf_IsValid[2],
    real_T *pdf_ExistenceProbability)
{
  real_T pdf_Time;
  int32_T i;
  for (i = 0; i < 10; i++) {
    pdf_Hypothesis[0].State[i] = estimator_StateEstimator->StateEstimator
                                     .Estimators.f1.TrackingFilter->pState[i];
  }
  c_ExtendedKalmanFilter_get_Stat(
      estimator_StateEstimator->StateEstimator.Estimators.f1.TrackingFilter,
      pdf_Hypothesis[0].StateCovariance);
  for (i = 0; i < 10; i++) {
    pdf_Hypothesis[1].State[i] = estimator_StateEstimator->StateEstimator
                                     .Estimators.f2.TrackingFilter->pState[i];
  }
  c_ExtendedKalmanFilter_get_Stat(
      estimator_StateEstimator->StateEstimator.Estimators.f2.TrackingFilter,
      pdf_Hypothesis[1].StateCovariance);
  pdf_Time = 0.0;
  *pdf_TrackID = 0U;
  *pdf_Age = 0U;
  *pdf_IsConfirmed = false;
  *pdf_IsCoasted = false;
  pdf_LogWeights[0] = -0.69314718055994529;
  pdf_IsValid[0] = true;
  pdf_LogWeights[1] = -0.69314718055994529;
  pdf_IsValid[1] = true;
  *pdf_ExistenceProbability = 0.0;
  return pdf_Time;
}

/* End of code generation (TrackEstimator1.c) */
