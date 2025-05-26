/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackerEntryPoint_types.h
 *
 * Code generation for function 'trackerEntryPoint'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef c_typedef_c_fusion_tracker_inte
#define c_typedef_c_fusion_tracker_inte
typedef struct {
  real_T SpeedLimits[2];
  real_T YawLimits[2];
  real_T YawRateLimits[2];
  real_T HorizontalAccelerationVariance;
  real_T AngularAccelerationVariance;
  real_T VerticalVelocityLimits[2];
  real_T VerticalAccelerationVariance;
} c_fusion_tracker_internal_motio;
#endif /* c_typedef_c_fusion_tracker_inte */

#ifndef c_typedef_d_fusion_tracker_inte
#define c_typedef_d_fusion_tracker_inte
typedef struct {
  real_T LengthLimits[2];
  real_T WidthLimits[2];
  real_T HeightLimits[2];
  c_fusion_tracker_internal_motio MotionModel;
} d_fusion_tracker_internal_motio;
#endif /* c_typedef_d_fusion_tracker_inte */

#ifndef c_typedef_e_fusion_tracker_inte
#define c_typedef_e_fusion_tracker_inte
typedef struct {
  d_fusion_tracker_internal_motio StationaryMotionModel;
} e_fusion_tracker_internal_motio;
#endif /* c_typedef_e_fusion_tracker_inte */

#ifndef c_typedef_c_fusion_tracker_targ
#define c_typedef_c_fusion_tracker_targ
typedef struct {
  e_fusion_tracker_internal_motio StateTransitionModel;
} c_fusion_tracker_targetspecs_Hi;
#endif /* c_typedef_c_fusion_tracker_targ */

#ifndef c_typedef_d_fusion_tracker_targ
#define c_typedef_d_fusion_tracker_targ
typedef struct {
  e_fusion_tracker_internal_motio StateTransitionModel;
} d_fusion_tracker_targetspecs_Hi;
#endif /* c_typedef_d_fusion_tracker_targ */

#ifndef typedef_cell_4
#define typedef_cell_4
typedef struct {
  c_fusion_tracker_targetspecs_Hi f1;
  d_fusion_tracker_targetspecs_Hi f2;
} cell_4;
#endif /* typedef_cell_4 */

#ifndef d_typedef_c_fusion_tracker_inte
#define d_typedef_c_fusion_tracker_inte
typedef struct {
  real_T OriginPosition[6];
  real_T Orientation[18];
} c_fusion_tracker_internal_measu;
#endif /* d_typedef_c_fusion_tracker_inte */

#ifndef e_typedef_c_fusion_tracker_inte
#define e_typedef_c_fusion_tracker_inte
typedef struct {
  real_T AzimuthLimits[2];
  real_T ElevationLimits[2];
  real_T RangeLimits[2];
  real_T RangeRateLimits[2];
} c_fusion_tracker_internal_detec;
#endif /* e_typedef_c_fusion_tracker_inte */

#ifndef d_typedef_d_fusion_tracker_inte
#define d_typedef_d_fusion_tracker_inte
typedef struct {
  real_T Intrinsics[9];
  real_T ImageSize[2];
} d_fusion_tracker_internal_measu;
#endif /* d_typedef_d_fusion_tracker_inte */

#ifndef typedef_trackingEKF
#define typedef_trackingEKF
typedef struct {
  real_T pState[10];
  real_T pSqrtStateCovariance[100];
  real_T pSqrtStateCovarianceScalar;
  boolean_T pIsSetStateCovariance;
} trackingEKF;
#endif /* typedef_trackingEKF */

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  real_T State[10];
  real_T StateCovariance[100];
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  real_T Time;
  uint32_T TrackID;
  uint32_T Age;
  boolean_T IsConfirmed;
  boolean_T IsCoasted;
  struct_T Hypothesis[2];
  real_T LogWeights[2];
  boolean_T IsValid[2];
  real_T ExistenceProbability;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct {
  real_T Time;
  real_T EgoPositionalDisplacement[3];
  real_T EgoRotationalDisplacement[3];
} struct3_T;
#endif /* typedef_struct3_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T
typedef struct {
  b_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;
#endif /* typedef_emxArray_struct_T */

#ifndef f_typedef_c_fusion_tracker_inte
#define f_typedef_c_fusion_tracker_inte
typedef struct {
  real_T TimeTolerance;
  real_T CurrentIndex;
  emxArray_real_T *ProcessingTimestamps;
} c_fusion_tracker_internal_compo;
#endif /* f_typedef_c_fusion_tracker_inte */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T
struct emxArray_uint32_T {
  uint32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint32_T */
#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T
typedef struct emxArray_uint32_T emxArray_uint32_T;
#endif /* typedef_emxArray_uint32_T */

#ifndef typedef_struct4_T
#define typedef_struct4_T
typedef struct {
  uint32_T TrackID;
  uint32_T BranchID;
  uint32_T SourceIndex;
  real_T UpdateTime;
  uint32_T Age;
  real_T State[10];
  real_T StateCovariance[100];
  int32_T ObjectClassID;
  real_T ObjectClassProbabilities[2];
  char_T TrackLogic[10];
  real_T TrackLogicState;
  boolean_T IsConfirmed;
  boolean_T IsCoasted;
  boolean_T IsSelfReported;
} struct4_T;
#endif /* typedef_struct4_T */

#ifndef typedef_emxArray_struct4_T
#define typedef_emxArray_struct4_T
typedef struct {
  struct4_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct4_T;
#endif /* typedef_emxArray_struct4_T */

#ifndef c_typedef_c_fusion_tracker_sens
#define c_typedef_c_fusion_tracker_sens
typedef struct {
  d_fusion_tracker_internal_measu MeasurementModel;
  c_fusion_tracker_internal_detec DetectabilityModel;
  real_T NumFalsePositivesPerImage;
  real_T NumNewTargetsPerImage;
} c_fusion_tracker_sensorspecs_Au;
#endif /* c_typedef_c_fusion_tracker_sens */

#ifndef c_typedef_d_fusion_tracker_sens
#define c_typedef_d_fusion_tracker_sens
typedef struct {
  c_fusion_tracker_internal_measu MeasurementModel;
  c_fusion_tracker_internal_detec DetectabilityModel;
  real_T NumFalsePositivesPerScan;
  real_T NumNewTargetsPerScan;
} d_fusion_tracker_sensorspecs_Au;
#endif /* c_typedef_d_fusion_tracker_sens */

#ifndef g_typedef_c_fusion_tracker_inte
#define g_typedef_c_fusion_tracker_inte
typedef struct {
  c_fusion_tracker_targetspecs_Hi TargetSpecifications[1];
  d_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  trackingEKF *TrackingFilter;
} c_fusion_tracker_internal_estim;
#endif /* g_typedef_c_fusion_tracker_inte */

#ifndef e_typedef_d_fusion_tracker_inte
#define e_typedef_d_fusion_tracker_inte
typedef struct {
  d_fusion_tracker_targetspecs_Hi TargetSpecifications[1];
  d_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  trackingEKF *TrackingFilter;
} d_fusion_tracker_internal_estim;
#endif /* e_typedef_d_fusion_tracker_inte */

#ifndef typedef_cell_6
#define typedef_cell_6
typedef struct {
  c_fusion_tracker_internal_estim f1;
  d_fusion_tracker_internal_estim f2;
} cell_6;
#endif /* typedef_cell_6 */

#ifndef d_typedef_e_fusion_tracker_inte
#define d_typedef_e_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  d_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  cell_6 Estimators;
} e_fusion_tracker_internal_estim;
#endif /* d_typedef_e_fusion_tracker_inte */

#ifndef c_typedef_f_fusion_tracker_inte
#define c_typedef_f_fusion_tracker_inte
typedef struct {
  e_fusion_tracker_internal_estim StateEstimator;
} f_fusion_tracker_internal_estim;
#endif /* c_typedef_f_fusion_tracker_inte */

#ifndef c_typedef_g_fusion_tracker_inte
#define c_typedef_g_fusion_tracker_inte
typedef struct {
  f_fusion_tracker_internal_estim StateEstimator;
} g_fusion_tracker_internal_estim;
#endif /* c_typedef_g_fusion_tracker_inte */

#ifndef f_typedef_d_fusion_tracker_inte
#define f_typedef_d_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  d_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  g_fusion_tracker_internal_estim Estimator;
} d_fusion_tracker_internal_compo;
#endif /* f_typedef_d_fusion_tracker_inte */

#ifndef c_typedef_h_fusion_tracker_inte
#define c_typedef_h_fusion_tracker_inte
typedef struct {
  c_fusion_tracker_targetspecs_Hi TargetSpecifications[1];
} h_fusion_tracker_internal_estim;
#endif /* c_typedef_h_fusion_tracker_inte */

#ifndef c_typedef_i_fusion_tracker_inte
#define c_typedef_i_fusion_tracker_inte
typedef struct {
  d_fusion_tracker_targetspecs_Hi TargetSpecifications[1];
} i_fusion_tracker_internal_estim;
#endif /* c_typedef_i_fusion_tracker_inte */

#ifndef typedef_cell_7
#define typedef_cell_7
typedef struct {
  h_fusion_tracker_internal_estim f1;
  i_fusion_tracker_internal_estim f2;
} cell_7;
#endif /* typedef_cell_7 */

#ifndef c_typedef_j_fusion_tracker_inte
#define c_typedef_j_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  cell_7 Estimators;
} j_fusion_tracker_internal_estim;
#endif /* c_typedef_j_fusion_tracker_inte */

#ifndef c_typedef_k_fusion_tracker_inte
#define c_typedef_k_fusion_tracker_inte
typedef struct {
  j_fusion_tracker_internal_estim StateEstimator;
} k_fusion_tracker_internal_estim;
#endif /* c_typedef_k_fusion_tracker_inte */

#ifndef c_typedef_l_fusion_tracker_inte
#define c_typedef_l_fusion_tracker_inte
typedef struct {
  c_fusion_tracker_targetspecs_Hi TargetSpecifications[1];
  c_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
} l_fusion_tracker_internal_estim;
#endif /* c_typedef_l_fusion_tracker_inte */

#ifndef c_typedef_m_fusion_tracker_inte
#define c_typedef_m_fusion_tracker_inte
typedef struct {
  d_fusion_tracker_targetspecs_Hi TargetSpecifications[1];
  c_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
} m_fusion_tracker_internal_estim;
#endif /* c_typedef_m_fusion_tracker_inte */

#ifndef typedef_cell_8
#define typedef_cell_8
typedef struct {
  l_fusion_tracker_internal_estim f1;
  m_fusion_tracker_internal_estim f2;
} cell_8;
#endif /* typedef_cell_8 */

#ifndef c_typedef_n_fusion_tracker_inte
#define c_typedef_n_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  c_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  cell_8 Estimators;
} n_fusion_tracker_internal_estim;
#endif /* c_typedef_n_fusion_tracker_inte */

#ifndef c_typedef_o_fusion_tracker_inte
#define c_typedef_o_fusion_tracker_inte
typedef struct {
  n_fusion_tracker_internal_estim StateEstimator;
} o_fusion_tracker_internal_estim;
#endif /* c_typedef_o_fusion_tracker_inte */

#ifndef e_typedef_e_fusion_tracker_inte
#define e_typedef_e_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  d_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  g_fusion_tracker_internal_estim Estimator;
} e_fusion_tracker_internal_compo;
#endif /* e_typedef_e_fusion_tracker_inte */

#ifndef d_typedef_f_fusion_tracker_inte
#define d_typedef_f_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  d_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  g_fusion_tracker_internal_estim Estimator;
} f_fusion_tracker_internal_compo;
#endif /* d_typedef_f_fusion_tracker_inte */

#ifndef typedef_cell_5
#define typedef_cell_5
typedef struct {
  d_fusion_tracker_sensorspecs_Au f1;
  c_fusion_tracker_sensorspecs_Au f3;
} cell_5;
#endif /* typedef_cell_5 */

#ifndef c_typedef_p_fusion_tracker_inte
#define c_typedef_p_fusion_tracker_inte
typedef struct {
  k_fusion_tracker_internal_estim StateEstimator;
} p_fusion_tracker_internal_estim;
#endif /* c_typedef_p_fusion_tracker_inte */

#ifndef d_typedef_g_fusion_tracker_inte
#define d_typedef_g_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  p_fusion_tracker_internal_estim Estimator;
} g_fusion_tracker_internal_compo;
#endif /* d_typedef_g_fusion_tracker_inte */

#ifndef c_typedef_q_fusion_tracker_inte
#define c_typedef_q_fusion_tracker_inte
typedef struct {
  o_fusion_tracker_internal_estim StateEstimator;
} q_fusion_tracker_internal_estim;
#endif /* c_typedef_q_fusion_tracker_inte */

#ifndef d_typedef_h_fusion_tracker_inte
#define d_typedef_h_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  c_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  q_fusion_tracker_internal_estim Estimator;
} h_fusion_tracker_internal_compo;
#endif /* d_typedef_h_fusion_tracker_inte */

#ifndef typedef_cell_9
#define typedef_cell_9
typedef struct {
  d_fusion_tracker_internal_compo f1;
  g_fusion_tracker_internal_compo f2;
  h_fusion_tracker_internal_compo f3;
} cell_9;
#endif /* typedef_cell_9 */

#ifndef d_typedef_i_fusion_tracker_inte
#define d_typedef_i_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  p_fusion_tracker_internal_estim Estimator;
} i_fusion_tracker_internal_compo;
#endif /* d_typedef_i_fusion_tracker_inte */

#ifndef d_typedef_j_fusion_tracker_inte
#define d_typedef_j_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  c_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  q_fusion_tracker_internal_estim Estimator;
} j_fusion_tracker_internal_compo;
#endif /* d_typedef_j_fusion_tracker_inte */

#ifndef typedef_cell_10
#define typedef_cell_10
typedef struct {
  e_fusion_tracker_internal_compo f1;
  i_fusion_tracker_internal_compo f2;
  j_fusion_tracker_internal_compo f3;
} cell_10;
#endif /* typedef_cell_10 */

#ifndef d_typedef_k_fusion_tracker_inte
#define d_typedef_k_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  p_fusion_tracker_internal_estim Estimator;
} k_fusion_tracker_internal_compo;
#endif /* d_typedef_k_fusion_tracker_inte */

#ifndef d_typedef_l_fusion_tracker_inte
#define d_typedef_l_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  c_fusion_tracker_sensorspecs_Au SensorSpecifications[1];
  q_fusion_tracker_internal_estim Estimator;
} l_fusion_tracker_internal_compo;
#endif /* d_typedef_l_fusion_tracker_inte */

#ifndef typedef_cell_11
#define typedef_cell_11
typedef struct {
  f_fusion_tracker_internal_compo f1;
  k_fusion_tracker_internal_compo f2;
  l_fusion_tracker_internal_compo f3;
} cell_11;
#endif /* typedef_cell_11 */

#ifndef d_typedef_m_fusion_tracker_inte
#define d_typedef_m_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  cell_5 SensorSpecifications;
  emxArray_struct_T *InternalTrackList;
} m_fusion_tracker_internal_compo;
#endif /* d_typedef_m_fusion_tracker_inte */

#ifndef d_typedef_n_fusion_tracker_inte
#define d_typedef_n_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  cell_5 SensorSpecifications;
  real_T ConfirmationThreshold;
  real_T DeletionThreshold;
  g_fusion_tracker_internal_estim Estimator;
} n_fusion_tracker_internal_compo;
#endif /* d_typedef_n_fusion_tracker_inte */

#ifndef typedef_objectTrack
#define typedef_objectTrack
typedef struct {
  uint32_T TrackID;
  uint32_T BranchID;
  uint32_T SourceIndex;
  uint32_T Age;
  int32_T ObjectClassID;
  real_T ObjectClassProbabilities[2];
  boolean_T IsConfirmed;
  boolean_T IsCoasted;
  boolean_T IsSelfReported;
  real_T pState[10];
  real_T pStateCovariance[100];
  real_T pUpdateTime;
  real_T pTrackLogicState;
} objectTrack;
#endif /* typedef_objectTrack */

#ifndef d_typedef_o_fusion_tracker_inte
#define d_typedef_o_fusion_tracker_inte
typedef struct {
  cell_4 TargetSpecifications;
  cell_5 SensorSpecifications;
  g_fusion_tracker_internal_estim Estimator;
  objectTrack SampleTrack;
} o_fusion_tracker_internal_compo;
#endif /* d_typedef_o_fusion_tracker_inte */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T Azimuth[4];
  real_T Elevation[4];
  real_T Range[4];
  real_T RangeRate[4];
  real_T AzimuthAccuracy[4];
  real_T ElevationAccuracy[4];
  real_T RangeAccuracy[4];
  real_T RangeRateAccuracy[4];
  real_T EgoSpeed;
  real_T EgoAngularVelocity[3];
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T BoundingBox[9];
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T BoundingBox[16];
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef c_typedef_fusion_tracker_JIPDAT
#define c_typedef_fusion_tracker_JIPDAT
typedef struct {
  boolean_T tunablePropertyChanged[7];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_4 TargetSpecifications;
  cell_5 SensorSpecifications;
  real_T MaxMahalanobisDistance;
  real_T c_ConfirmationExistenceProbabil;
  real_T DeletionExistenceProbability;
  real_T MaxNumEvents;
  c_fusion_tracker_internal_compo *Scheduler;
  cell_9 Initiator;
  cell_10 Assigner;
  cell_11 Updater;
  m_fusion_tracker_internal_compo TrackListManager;
  n_fusion_tracker_internal_compo TrackMaintenance;
  o_fusion_tracker_internal_compo Outputter;
  trackingEKF _pobj2[10];
  c_fusion_tracker_internal_compo _pobj3;
} fusion_tracker_JIPDATracker;
#endif /* c_typedef_fusion_tracker_JIPDAT */

/* End of code generation (trackerEntryPoint_types.h) */
