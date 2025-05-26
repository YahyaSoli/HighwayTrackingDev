/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackerEntryPoint_emxutil.h
 *
 * Code generation for function 'trackerEntryPoint_emxutil'
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
void c_emxCopyStruct_fusion_tracker_(const emlrtStack *sp,
                                     m_fusion_tracker_internal_compo *dst,
                                     const m_fusion_tracker_internal_compo *src,
                                     const emlrtRTEInfo *srcLocation);

void c_emxFreeStruct_fusion_tracker_(const emlrtStack *sp,
                                     m_fusion_tracker_internal_compo *pStruct);

void c_emxInitStruct_fusion_tracker_(const emlrtStack *sp,
                                     m_fusion_tracker_internal_compo *pStruct,
                                     const emlrtRTEInfo *srcLocation,
                                     boolean_T doPush);

void d_emxFreeStruct_fusion_tracker_(const emlrtStack *sp,
                                     fusion_tracker_JIPDATracker *pStruct);

void d_emxInitStruct_fusion_tracker_(const emlrtStack *sp,
                                     fusion_tracker_JIPDATracker *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void e_emxFreeStruct_fusion_tracker_(const emlrtStack *sp,
                                     c_fusion_tracker_internal_compo *pStruct);

void e_emxInitStruct_fusion_tracker_(const emlrtStack *sp,
                                     c_fusion_tracker_internal_compo *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void emxCopy_struct_T(const emlrtStack *sp, emxArray_struct_T **dst,
                      emxArray_struct_T *const *src,
                      const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct4_T(const emlrtStack *sp,
                                 emxArray_struct4_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct_T(const emlrtStack *sp,
                                emxArray_struct_T *emxArray, int32_T oldNumel,
                                const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_uint32_T(const emlrtStack *sp,
                                emxArray_uint32_T *emxArray, int32_T oldNumel,
                                const emlrtRTEInfo *srcLocation);

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray);

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxFree_struct4_T(const emlrtStack *sp, emxArray_struct4_T **pEmxArray);

void emxFree_struct_T(const emlrtStack *sp, emxArray_struct_T **pEmxArray);

void emxFree_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray);

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation, boolean_T doPush);

void emxInit_struct4_T(const emlrtStack *sp, emxArray_struct4_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_struct_T(const emlrtStack *sp, emxArray_struct_T **pEmxArray,
                      const emlrtRTEInfo *srcLocation, boolean_T doPush);

void emxInit_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray,
                      const emlrtRTEInfo *srcLocation);

/* End of code generation (trackerEntryPoint_emxutil.h) */
