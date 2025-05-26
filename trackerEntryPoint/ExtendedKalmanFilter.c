/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ExtendedKalmanFilter.c
 *
 * Code generation for function 'ExtendedKalmanFilter'
 *
 */

/* Include files */
#include "ExtendedKalmanFilter.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_types.h"
#include "blas.h"
#include <stddef.h>

/* Function Definitions */
void c_ExtendedKalmanFilter_get_Stat(trackingEKF *obj, real_T b_value[100])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((!obj->pIsSetStateCovariance) ||
      (obj->pSqrtStateCovarianceScalar != -1.0)) {
    alpha1 = obj->pSqrtStateCovarianceScalar;
    for (i = 0; i < 100; i++) {
      obj->pSqrtStateCovariance[i] = alpha1 * (real_T)iv[i];
    }
    obj->pIsSetStateCovariance = true;
    obj->pSqrtStateCovarianceScalar = -1.0;
  }
  TRANSB1 = 'T';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)10;
  n_t = (ptrdiff_t)10;
  k_t = (ptrdiff_t)10;
  lda_t = (ptrdiff_t)10;
  ldb_t = (ptrdiff_t)10;
  ldc_t = (ptrdiff_t)10;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
        &obj->pSqrtStateCovariance[0], &lda_t, &obj->pSqrtStateCovariance[0],
        &ldb_t, &beta1, &b_value[0], &ldc_t);
}

/* End of code generation (ExtendedKalmanFilter.c) */
