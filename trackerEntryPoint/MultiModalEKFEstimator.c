/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MultiModalEKFEstimator.c
 *
 * Code generation for function 'MultiModalEKFEstimator'
 *
 */

/* Include files */
#include "MultiModalEKFEstimator.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_types.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
int32_T c_MultiModalEKFEstimator_toObje(
    const struct_T pdf_Hypothesis[2], const real_T pdf_LogWeights[2],
    real_T objectTrackPdf_State[10], real_T objectTrackPdf_StateCovariance[100],
    real_T c_objectTrackPdf_ObjectClassPro[2])
{
  int32_T objectTrackPdf_ObjectClassID;
  if ((pdf_LogWeights[0] < pdf_LogWeights[1]) ||
      (muDoubleScalarIsNaN(pdf_LogWeights[0]) &&
       (!muDoubleScalarIsNaN(pdf_LogWeights[1])))) {
    objectTrackPdf_ObjectClassID = 2;
  } else {
    objectTrackPdf_ObjectClassID = 1;
  }
  memcpy(&objectTrackPdf_State[0], &pdf_Hypothesis[1].State[0],
         10U * sizeof(real_T));
  memcpy(&objectTrackPdf_StateCovariance[0],
         &pdf_Hypothesis[1].StateCovariance[0], 100U * sizeof(real_T));
  if (objectTrackPdf_ObjectClassID == 1) {
    memcpy(&objectTrackPdf_State[0], &pdf_Hypothesis[0].State[0],
           10U * sizeof(real_T));
    memcpy(&objectTrackPdf_StateCovariance[0],
           &pdf_Hypothesis[0].StateCovariance[0], 100U * sizeof(real_T));
  }
  if (objectTrackPdf_ObjectClassID == 2) {
    memcpy(&objectTrackPdf_State[0], &pdf_Hypothesis[1].State[0],
           10U * sizeof(real_T));
    memcpy(&objectTrackPdf_StateCovariance[0],
           &pdf_Hypothesis[1].StateCovariance[0], 100U * sizeof(real_T));
  }
  c_objectTrackPdf_ObjectClassPro[0] = muDoubleScalarExp(pdf_LogWeights[0]);
  c_objectTrackPdf_ObjectClassPro[1] = muDoubleScalarExp(pdf_LogWeights[1]);
  return objectTrackPdf_ObjectClassID;
}

/* End of code generation (MultiModalEKFEstimator.c) */
