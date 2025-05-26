/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackerEntryPoint.h
 *
 * Code generation for function 'trackerEntryPoint'
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
void trackerEntryPoint(const emlrtStack *sp, const struct0_T *radarDet,
                       const struct1_T *lidarDet, const struct2_T *cameraDet,
                       const struct3_T *egoMotion, emxArray_struct4_T *tracks);

void trackerEntryPoint_emx_free(const emlrtStack *sp);

void trackerEntryPoint_emx_init(const emlrtStack *sp);

void trackerEntryPoint_init(void);

/* End of code generation (trackerEntryPoint.h) */
