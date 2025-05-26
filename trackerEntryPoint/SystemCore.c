/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.c
 *
 * Code generation for function 'SystemCore'
 *
 */

/* Include files */
#include "SystemCore.h"
#include "JIPDATrackMaintainer.h"
#include "JIPDATracker.h"
#include "ObjectTrackOutputter.h"
#include "TrackEstimator1.h"
#include "rt_nonfinite.h"
#include "trackEstimator.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_emxutil.h"
#include "trackerEntryPoint_types.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qc_emlrtRSI = {
    1,                 /* lineNo */
    "SystemCore/step", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    128,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    131,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    135,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    140,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    179,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    149,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    160,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    170,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    175,                      /* lineNo */
    "JIPDATracker/setupImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    51,                       /* lineNo */
    "TrackListManager/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\TrackListManager.m" /* pathName */
};

static emlrtRSInfo gm_emlrtRSI = {
    37,                          /* lineNo */
    "JIPDATrackInitiator/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackInitiator"
    ".m" /* pathName */
};

static emlrtRSInfo hm_emlrtRSI = {
    37,                         /* lineNo */
    "JIPDATrackAssigner/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackAssigner."
    "m" /* pathName */
};

static emlrtRSInfo im_emlrtRSI = {
    36,                        /* lineNo */
    "JIPDATrackUpdater/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackUpdater.m" /* pathName */
};

static emlrtRSInfo dn_emlrtRSI = {
    29,                                          /* lineNo */
    "JIPDATrackMaintainer/JIPDATrackMaintainer", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m" /* pathName */
};

static emlrtRSInfo in_emlrtRSI = {
    34,                           /* lineNo */
    "JIPDATrackMaintainer/setup", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m" /* pathName */
};

static emlrtRSInfo jn_emlrtRSI = {
    246,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo kn_emlrtRSI = {
    248,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo ln_emlrtRSI = {
    252,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo mn_emlrtRSI = {
    254,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo nn_emlrtRSI = {
    258,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo on_emlrtRSI = {
    260,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo pn_emlrtRSI = {
    264,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo qn_emlrtRSI = {
    266,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo rn_emlrtRSI = {
    270,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo sn_emlrtRSI = {
    276,                                       /* lineNo */
    "JIPDATracker/processTunedPropertiesImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo ro_emlrtRSI = {
    317,                                        /* lineNo */
    "JIPDATracker/updateConfirmationThreshold", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo so_emlrtRSI = {
    322,                                    /* lineNo */
    "JIPDATracker/updateDeletionThreshold", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    1,                 /* lineNo */
    1,                 /* colNo */
    "SystemCore/step", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    135,            /* lineNo */
    13,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    344,            /* lineNo */
    42,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    344,            /* lineNo */
    13,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    135,            /* lineNo */
    46,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    294,            /* lineNo */
    63,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    294,            /* lineNo */
    13,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

/* Function Declarations */
static void SystemCore_checkTunableProps(const emlrtStack *sp,
                                         fusion_tracker_JIPDATracker *obj);

/* Function Definitions */
static void SystemCore_checkTunableProps(const emlrtStack *sp,
                                         fusion_tracker_JIPDATracker *obj)
{
  c_fusion_tracker_internal_compo *b_obj;
  d_fusion_tracker_internal_compo c_obj;
  e_fusion_tracker_internal_compo g_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  f_fusion_tracker_internal_compo j_obj;
  m_fusion_tracker_internal_compo m_obj;
  n_fusion_tracker_internal_compo d_obj;
  o_fusion_tracker_internal_compo n_obj;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (obj->TunablePropsChanged) {
    real_T d;
    boolean_T sensorSpecChange;
    obj->TunablePropsChanged = false;
    st.site = &qc_emlrtRSI;
    b_st.site = &jn_emlrtRSI;
    sensorSpecChange = obj->tunablePropertyChanged[1];
    if (sensorSpecChange) {
      c_fusion_tracker_sensorspecs_Au r1;
      cell_5 val;
      d_fusion_tracker_sensorspecs_Au r;
      g_fusion_tracker_internal_compo e_obj;
      h_fusion_tracker_internal_compo f_obj;
      i_fusion_tracker_internal_compo h_obj;
      j_fusion_tracker_internal_compo i_obj;
      k_fusion_tracker_internal_compo k_obj;
      l_fusion_tracker_internal_compo l_obj;
      b_st.site = &kn_emlrtRSI;
      b_obj = obj->Scheduler;
      obj->Scheduler = b_obj;
      r = obj->SensorSpecifications.f1;
      c_obj = obj->Initiator.f1;
      c_obj.SensorSpecifications[0] = r;
      c_obj.Estimator.StateEstimator.StateEstimator.SensorSpecifications[0] = r;
      c_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
          .SensorSpecifications[0] = r;
      c_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
          .SensorSpecifications[0] = r;
      obj->Initiator.f1 = c_obj;
      e_obj = obj->Initiator.f2;
      obj->Initiator.f2 = e_obj;
      r1 = obj->SensorSpecifications.f3;
      f_obj = obj->Initiator.f3;
      f_obj.SensorSpecifications[0] = r1;
      f_obj.Estimator.StateEstimator.StateEstimator.SensorSpecifications[0] =
          r1;
      f_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
          .SensorSpecifications[0] = r1;
      f_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
          .SensorSpecifications[0] = r1;
      obj->Initiator.f3 = f_obj;
      r = obj->SensorSpecifications.f1;
      g_obj = obj->Assigner.f1;
      g_obj.SensorSpecifications[0] = r;
      g_obj.Estimator.StateEstimator.StateEstimator.SensorSpecifications[0] = r;
      g_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
          .SensorSpecifications[0] = r;
      g_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
          .SensorSpecifications[0] = r;
      obj->Assigner.f1 = g_obj;
      h_obj = obj->Assigner.f2;
      obj->Assigner.f2 = h_obj;
      r1 = obj->SensorSpecifications.f3;
      i_obj = obj->Assigner.f3;
      i_obj.SensorSpecifications[0] = r1;
      i_obj.Estimator.StateEstimator.StateEstimator.SensorSpecifications[0] =
          r1;
      i_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
          .SensorSpecifications[0] = r1;
      i_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
          .SensorSpecifications[0] = r1;
      obj->Assigner.f3 = i_obj;
      r = obj->SensorSpecifications.f1;
      j_obj = obj->Updater.f1;
      j_obj.SensorSpecifications[0] = r;
      j_obj.Estimator.StateEstimator.StateEstimator.SensorSpecifications[0] = r;
      j_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
          .SensorSpecifications[0] = r;
      j_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
          .SensorSpecifications[0] = r;
      obj->Updater.f1 = j_obj;
      k_obj = obj->Updater.f2;
      obj->Updater.f2 = k_obj;
      r1 = obj->SensorSpecifications.f3;
      l_obj = obj->Updater.f3;
      l_obj.SensorSpecifications[0] = r1;
      l_obj.Estimator.StateEstimator.StateEstimator.SensorSpecifications[0] =
          r1;
      l_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
          .SensorSpecifications[0] = r1;
      l_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
          .SensorSpecifications[0] = r1;
      obj->Updater.f3 = l_obj;
      c_emxInitStruct_fusion_tracker_(&b_st, &m_obj, &y_emlrtRTEI, true);
      c_emxCopyStruct_fusion_tracker_(&b_st, &m_obj, &obj->TrackListManager,
                                      &y_emlrtRTEI);
      m_obj.SensorSpecifications = obj->SensorSpecifications;
      c_emxCopyStruct_fusion_tracker_(&b_st, &obj->TrackListManager, &m_obj,
                                      &ab_emlrtRTEI);
      c_emxFreeStruct_fusion_tracker_(&b_st, &m_obj);
      d_obj = obj->TrackMaintenance;
      val = obj->SensorSpecifications;
      d_obj.SensorSpecifications = val;
      d_obj.Estimator.StateEstimator.StateEstimator.SensorSpecifications[0] =
          val.f1;
      d_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
          .SensorSpecifications[0] = val.f1;
      d_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
          .SensorSpecifications[0] = val.f1;
      obj->TrackMaintenance = d_obj;
      n_obj = obj->Outputter;
      val = obj->SensorSpecifications;
      n_obj.SensorSpecifications = val;
      n_obj.Estimator.StateEstimator.StateEstimator.SensorSpecifications[0] =
          val.f1;
      n_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
          .SensorSpecifications[0] = val.f1;
      n_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
          .SensorSpecifications[0] = val.f1;
      obj->Outputter = n_obj;
    }
    b_st.site = &ln_emlrtRSI;
    sensorSpecChange = obj->tunablePropertyChanged[0];
    if (sensorSpecChange) {
      b_st.site = &mn_emlrtRSI;
      c_JIPDATracker_updateTargetSpec(&b_st, obj);
    }
    b_st.site = &nn_emlrtRSI;
    sensorSpecChange = obj->tunablePropertyChanged[3];
    if (sensorSpecChange) {
      b_st.site = &on_emlrtRSI;
      d = obj->c_ConfirmationExistenceProbabil;
      d_obj = obj->TrackMaintenance;
      c_st.site = &ro_emlrtRSI;
      c_JIPDATrackMaintainer_set_Conf(&c_st, &d_obj, d);
      obj->TrackMaintenance = d_obj;
    }
    b_st.site = &pn_emlrtRSI;
    sensorSpecChange = obj->tunablePropertyChanged[4];
    if (sensorSpecChange) {
      b_st.site = &qn_emlrtRSI;
      d = obj->DeletionExistenceProbability;
      d_obj = obj->TrackMaintenance;
      c_st.site = &so_emlrtRSI;
      c_JIPDATrackMaintainer_set_Dele(&c_st, &d_obj, d);
      obj->TrackMaintenance = d_obj;
    }
    b_st.site = &rn_emlrtRSI;
    b_st.site = &sn_emlrtRSI;
    st.site = &qc_emlrtRSI;
    for (i = 0; i < 7; i++) {
      obj->tunablePropertyChanged[i] = false;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void SystemCore_step(const emlrtStack *sp, fusion_tracker_JIPDATracker *obj,
                     real_T varargin_4_Time,
                     const real_T c_varargin_4_EgoRotationalDispl[3],
                     emxArray_struct4_T *varargout_1)
{
  c_fusion_tracker_internal_estim c_t59_StateEstimator_Estimators;
  c_fusion_tracker_internal_estim c_t62_StateEstimator_Estimators;
  c_fusion_tracker_internal_estim c_t65_StateEstimator_Estimators;
  c_fusion_tracker_internal_motio f_args_next_value_f2_StateTrans;
  c_fusion_tracker_internal_motio j_args_next_value_f2_StateTrans;
  c_fusion_tracker_sensorspecs_Au b_spec;
  c_fusion_tracker_targetspecs_Hi args_next_value_f1;
  cell_6 t72_Estimators;
  cell_6 t75_Estimators;
  cell_6 t78_Estimators;
  d_fusion_tracker_internal_estim d_t59_StateEstimator_Estimators;
  d_fusion_tracker_internal_estim d_t62_StateEstimator_Estimators;
  d_fusion_tracker_internal_estim d_t65_StateEstimator_Estimators;
  d_fusion_tracker_sensorspecs_Au spec;
  d_fusion_tracker_targetspecs_Hi args_next_value_f2;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  f_fusion_tracker_internal_estim b_trackEstimator_StateEstimator;
  f_fusion_tracker_internal_estim trackEstimator_StateEstimator;
  k_fusion_tracker_internal_estim obj_Estimator_StateEstimator;
  m_fusion_tracker_internal_compo b_obj;
  n_fusion_tracker_internal_compo c_obj;
  o_fusion_tracker_internal_compo r;
  o_fusion_tracker_internal_estim b_obj_Estimator_StateEstimator;
  trackingEKF lobj_0[2];
  real_T d_args_value_f1_MeasurementMode[18];
  real_T c_args_value_f3_MeasurementMode[9];
  real_T g_expl_temp;
  int32_T i;
  uint32_T d_expl_temp;
  uint32_T e_expl_temp;
  boolean_T f_expl_temp;
  boolean_T flag;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(
        sp, &b_emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }
  if (obj->isInitialized != 1) {
    cell_4 val;
    struct_T expl_temp[2];
    real_T c_args_value_f1_MeasurementMode[6];
    real_T b_expl_temp[2];
    real_T c_args_next_next_next_value_f1_[2];
    real_T c_args_next_value_f1_StateTrans[2];
    real_T c_args_next_value_f2_StateTrans[2];
    real_T d_args_next_next_next_value_f1_[2];
    real_T d_args_next_value_f1_StateTrans[2];
    real_T d_args_next_value_f2_StateTrans[2];
    real_T e_args_next_next_next_value_f1_[2];
    real_T e_args_next_value_f1_StateTrans[2];
    real_T e_args_next_value_f2_StateTrans[2];
    real_T f_args_next_value_f1_StateTrans[2];
    real_T g_args_next_value_f1_StateTrans[2];
    real_T g_args_next_value_f2_StateTrans[2];
    real_T h_args_next_value_f1_StateTrans[2];
    real_T h_args_next_value_f2_StateTrans[2];
    real_T i_args_next_value_f2_StateTrans[2];
    real_T k_args_next_value_f1_StateTrans[2];
    real_T m_args_next_value_f1_StateTrans[2];
    real_T n_args_next_value_f1_StateTrans[2];
    real_T o_args_next_value_f1_StateTrans[2];
    real_T p_args_next_value_f1_StateTrans[2];
    real_T q_args_next_value_f1_StateTrans[2];
    real_T r_args_next_value_f1_StateTrans[2];
    real_T c_args_value_f3_NumNewTargetsPe;
    real_T f_args_next_next_next_value_f1_;
    real_T g_args_next_next_next_value_f1_;
    real_T h_args_next_next_next_value_f1_;
    real_T h_expl_temp;
    real_T i_args_next_value_f1_StateTrans;
    real_T j_args_next_value_f1_StateTrans;
    real_T l_args_next_value_f1_StateTrans;
    real_T s_args_next_value_f1_StateTrans;
    boolean_T c_expl_temp[2];
    st.site = &qc_emlrtRSI;
    b_st.site = &oc_emlrtRSI;
    if (obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &b_emlrtRTEI,
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
          "setup");
    }
    obj->isInitialized = 1;
    c_st.site = &qc_emlrtRSI;
    spec = obj->SensorSpecifications.f1;
    obj->SensorSpecifications.f1 = spec;
    d_st.site = &rc_emlrtRSI;
    flag = (obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged[1] = true;
    }
    d_st.site = &rc_emlrtRSI;
    flag = (obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged[1] = true;
    }
    b_spec = obj->SensorSpecifications.f3;
    obj->SensorSpecifications.f3 = b_spec;
    d_st.site = &rc_emlrtRSI;
    flag = (obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged[1] = true;
    }
    val = obj->TargetSpecifications;
    val.f1 = obj->TargetSpecifications.f1;
    d_st.site = &sc_emlrtRSI;
    flag = (obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged[0] = true;
    }
    d_st.site = &sc_emlrtRSI;
    obj->TargetSpecifications = val;
    val = obj->TargetSpecifications;
    val.f2 = obj->TargetSpecifications.f2;
    d_st.site = &sc_emlrtRSI;
    flag = (obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged[0] = true;
    }
    d_st.site = &sc_emlrtRSI;
    obj->TargetSpecifications = val;
    c_emxInitStruct_fusion_tracker_(&c_st, &b_obj, &x_emlrtRTEI, true);
    b_obj.TargetSpecifications = obj->TargetSpecifications;
    b_obj.SensorSpecifications = obj->SensorSpecifications;
    d_st.site = &tc_emlrtRSI;
    e_st.site = &dd_emlrtRSI;
    trackEstimator(&e_st, &b_obj.TargetSpecifications.f1,
                   &b_obj.TargetSpecifications.f2,
                   &b_obj.SensorSpecifications.f1, &lobj_0[0],
                   &trackEstimator_StateEstimator);
    b_trackEstimator_StateEstimator = trackEstimator_StateEstimator;
    c_TrackEstimator_sampleDistribu(
        &b_trackEstimator_StateEstimator, &d_expl_temp, &e_expl_temp, &flag,
        &f_expl_temp, expl_temp, b_expl_temp, c_expl_temp, &g_expl_temp);
    b_obj.InternalTrackList->size[0] = 0;
    c_emxCopyStruct_fusion_tracker_(&c_st, &obj->TrackListManager, &b_obj,
                                    &u_emlrtRTEI);
    d_st.site = &uc_emlrtRSI;
    obj->_pobj3.TimeTolerance = 1.0E-6;
    obj->Scheduler = &obj->_pobj3;
    spec = obj->SensorSpecifications.f1;
    args_next_value_f1 = obj->TargetSpecifications.f1;
    args_next_value_f2 = obj->TargetSpecifications.f2;
    d_st.site = &wc_emlrtRSI;
    e_st.site = &gm_emlrtRSI;
    trackEstimator(&e_st, &args_next_value_f1, &args_next_value_f2, &spec,
                   &obj->_pobj2[0], &trackEstimator_StateEstimator);
    val.f1.StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.LengthLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.LengthLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.WidthLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.WidthLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.HeightLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.HeightLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[0] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f1.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[1] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f1.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.LengthLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.LengthLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.WidthLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.WidthLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.HeightLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.HeightLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[0] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f2.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[1] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f2.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[1];
    c_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    c_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    d_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    d_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    e_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    e_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    f_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    f_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    g_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    g_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    h_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    h_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    i_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    j_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    k_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    k_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    l_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    c_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    c_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    d_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    d_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    e_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    e_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    f_args_next_value_f2_StateTrans =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel;
    d_st.site = &wc_emlrtRSI;
    e_st.site = &gm_emlrtRSI;
    b_trackEstimator(
        &e_st, c_args_next_value_f1_StateTrans, d_args_next_value_f1_StateTrans,
        e_args_next_value_f1_StateTrans, f_args_next_value_f1_StateTrans,
        g_args_next_value_f1_StateTrans, h_args_next_value_f1_StateTrans,
        i_args_next_value_f1_StateTrans, j_args_next_value_f1_StateTrans,
        k_args_next_value_f1_StateTrans, l_args_next_value_f1_StateTrans,
        c_args_next_value_f2_StateTrans, d_args_next_value_f2_StateTrans,
        e_args_next_value_f2_StateTrans, &f_args_next_value_f2_StateTrans,
        &obj_Estimator_StateEstimator);
    b_spec = obj->SensorSpecifications.f3;
    b_expl_temp[0] = obj->TargetSpecifications.f1.StateTransitionModel
                         .StationaryMotionModel.LengthLimits[0];
    b_expl_temp[1] = obj->TargetSpecifications.f1.StateTransitionModel
                         .StationaryMotionModel.LengthLimits[1];
    m_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    m_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    n_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    n_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    o_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    o_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    p_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    p_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    q_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    q_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    h_expl_temp =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    g_expl_temp =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    r_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    r_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    s_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    g_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    g_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    h_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    h_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    i_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    i_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    j_args_next_value_f2_StateTrans =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel;
    d_st.site = &wc_emlrtRSI;
    e_st.site = &gm_emlrtRSI;
    c_trackEstimator(
        &e_st, b_expl_temp, m_args_next_value_f1_StateTrans,
        n_args_next_value_f1_StateTrans, o_args_next_value_f1_StateTrans,
        p_args_next_value_f1_StateTrans, q_args_next_value_f1_StateTrans,
        h_expl_temp, g_expl_temp, r_args_next_value_f1_StateTrans,
        s_args_next_value_f1_StateTrans, g_args_next_value_f2_StateTrans,
        h_args_next_value_f2_StateTrans, i_args_next_value_f2_StateTrans,
        &j_args_next_value_f2_StateTrans, &b_spec,
        &b_obj_Estimator_StateEstimator);
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .HorizontalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .HorizontalAccelerationVariance;
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .AngularAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .AngularAccelerationVariance;
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .HorizontalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .HorizontalAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .AngularAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .AngularAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalAccelerationVariance;
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    obj->Initiator.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    obj->Initiator.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    obj->Initiator.f1.SensorSpecifications[0] = spec;
    c_t59_StateEstimator_Estimators.TargetSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .TargetSpecifications[0];
    c_t59_StateEstimator_Estimators.SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .SensorSpecifications[0];
    c_t59_StateEstimator_Estimators.TrackingFilter =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .TrackingFilter;
    d_t59_StateEstimator_Estimators.TargetSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .TargetSpecifications[0];
    d_t59_StateEstimator_Estimators.SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .SensorSpecifications[0];
    d_t59_StateEstimator_Estimators.TrackingFilter =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .TrackingFilter;
    t72_Estimators.f1 = c_t59_StateEstimator_Estimators;
    t72_Estimators.f2 = d_t59_StateEstimator_Estimators;
    obj->Initiator.f1.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications = val;
    obj->Initiator.f1.Estimator.StateEstimator.StateEstimator
        .SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.SensorSpecifications[0];
    obj->Initiator.f1.Estimator.StateEstimator.StateEstimator.Estimators =
        t72_Estimators;
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        c_args_next_value_f1_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        c_args_next_value_f1_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        d_args_next_value_f1_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        d_args_next_value_f1_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        e_args_next_value_f1_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        e_args_next_value_f1_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        f_args_next_value_f1_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        f_args_next_value_f1_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        g_args_next_value_f1_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        g_args_next_value_f1_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        h_args_next_value_f1_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        h_args_next_value_f1_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        i_args_next_value_f1_StateTrans;
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        j_args_next_value_f1_StateTrans;
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        k_args_next_value_f1_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        k_args_next_value_f1_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        l_args_next_value_f1_StateTrans;
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        c_args_next_value_f2_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        c_args_next_value_f2_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        d_args_next_value_f2_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        d_args_next_value_f2_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        e_args_next_value_f2_StateTrans[0];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        e_args_next_value_f2_StateTrans[1];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        f_args_next_value_f2_StateTrans.SpeedLimits[0];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        f_args_next_value_f2_StateTrans.SpeedLimits[1];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        f_args_next_value_f2_StateTrans.YawLimits[0];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        f_args_next_value_f2_StateTrans.YawLimits[1];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        f_args_next_value_f2_StateTrans.YawRateLimits[0];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        f_args_next_value_f2_StateTrans.YawRateLimits[1];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        f_args_next_value_f2_StateTrans.HorizontalAccelerationVariance;
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        f_args_next_value_f2_StateTrans.AngularAccelerationVariance;
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        f_args_next_value_f2_StateTrans.VerticalVelocityLimits[0];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        f_args_next_value_f2_StateTrans.VerticalVelocityLimits[1];
    obj->Initiator.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        f_args_next_value_f2_StateTrans.VerticalAccelerationVariance;
    obj->Initiator.f2.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications =
        obj_Estimator_StateEstimator.StateEstimator.TargetSpecifications;
    obj->Initiator.f2.Estimator.StateEstimator.StateEstimator.Estimators =
        obj_Estimator_StateEstimator.StateEstimator.Estimators;
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] = b_expl_temp[0];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] = b_expl_temp[1];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        m_args_next_value_f1_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        m_args_next_value_f1_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        n_args_next_value_f1_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        n_args_next_value_f1_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        o_args_next_value_f1_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        o_args_next_value_f1_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        p_args_next_value_f1_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        p_args_next_value_f1_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        q_args_next_value_f1_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        q_args_next_value_f1_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        h_expl_temp;
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        g_expl_temp;
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        r_args_next_value_f1_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        r_args_next_value_f1_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        s_args_next_value_f1_StateTrans;
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        g_args_next_value_f2_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        g_args_next_value_f2_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        h_args_next_value_f2_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        h_args_next_value_f2_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        i_args_next_value_f2_StateTrans[0];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        i_args_next_value_f2_StateTrans[1];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        j_args_next_value_f2_StateTrans.SpeedLimits[0];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        j_args_next_value_f2_StateTrans.SpeedLimits[1];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        j_args_next_value_f2_StateTrans.YawLimits[0];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        j_args_next_value_f2_StateTrans.YawLimits[1];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        j_args_next_value_f2_StateTrans.YawRateLimits[0];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        j_args_next_value_f2_StateTrans.YawRateLimits[1];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        j_args_next_value_f2_StateTrans.HorizontalAccelerationVariance;
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        j_args_next_value_f2_StateTrans.AngularAccelerationVariance;
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        j_args_next_value_f2_StateTrans.VerticalVelocityLimits[0];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        j_args_next_value_f2_StateTrans.VerticalVelocityLimits[1];
    obj->Initiator.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        j_args_next_value_f2_StateTrans.VerticalAccelerationVariance;
    obj->Initiator.f3.SensorSpecifications[0] = b_spec;
    obj->Initiator.f3.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications =
        b_obj_Estimator_StateEstimator.StateEstimator.TargetSpecifications;
    obj->Initiator.f3.Estimator.StateEstimator.StateEstimator
        .SensorSpecifications[0] =
        b_obj_Estimator_StateEstimator.StateEstimator.SensorSpecifications[0];
    obj->Initiator.f3.Estimator.StateEstimator.StateEstimator.Estimators =
        b_obj_Estimator_StateEstimator.StateEstimator.Estimators;
    spec = obj->SensorSpecifications.f1;
    args_next_value_f1 = obj->TargetSpecifications.f1;
    args_next_value_f2 = obj->TargetSpecifications.f2;
    d_st.site = &xc_emlrtRSI;
    e_st.site = &hm_emlrtRSI;
    trackEstimator(&e_st, &args_next_value_f1, &args_next_value_f2, &spec,
                   &obj->_pobj2[2], &trackEstimator_StateEstimator);
    val.f1.StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.LengthLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.LengthLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.WidthLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.WidthLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.HeightLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.HeightLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[0] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f1.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[1] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f1.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.LengthLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.LengthLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.WidthLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.WidthLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.HeightLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.HeightLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[0] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f2.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[1] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f2.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[1];
    b_expl_temp[0] = obj->TargetSpecifications.f1.StateTransitionModel
                         .StationaryMotionModel.LengthLimits[0];
    b_expl_temp[1] = obj->TargetSpecifications.f1.StateTransitionModel
                         .StationaryMotionModel.LengthLimits[1];
    m_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    m_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    n_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    n_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    o_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    o_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    p_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    p_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    q_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    q_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    h_expl_temp =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    g_expl_temp =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    r_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    r_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    s_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    g_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    g_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    h_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    h_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    i_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    i_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    f_args_next_value_f2_StateTrans =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel;
    d_st.site = &xc_emlrtRSI;
    e_st.site = &hm_emlrtRSI;
    b_trackEstimator(
        &e_st, b_expl_temp, m_args_next_value_f1_StateTrans,
        n_args_next_value_f1_StateTrans, o_args_next_value_f1_StateTrans,
        p_args_next_value_f1_StateTrans, q_args_next_value_f1_StateTrans,
        h_expl_temp, g_expl_temp, r_args_next_value_f1_StateTrans,
        s_args_next_value_f1_StateTrans, g_args_next_value_f2_StateTrans,
        h_args_next_value_f2_StateTrans, i_args_next_value_f2_StateTrans,
        &f_args_next_value_f2_StateTrans, &obj_Estimator_StateEstimator);
    b_spec = obj->SensorSpecifications.f3;
    c_args_next_next_next_value_f1_[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    c_args_next_next_next_value_f1_[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    d_args_next_next_next_value_f1_[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    d_args_next_next_next_value_f1_[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    e_args_next_next_next_value_f1_[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    e_args_next_next_next_value_f1_[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    c_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    c_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    d_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    d_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    e_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    e_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    f_args_next_next_next_value_f1_ =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    g_args_next_next_next_value_f1_ =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    f_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    f_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    h_args_next_next_next_value_f1_ =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    g_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    g_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    h_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    h_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    k_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    k_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    j_args_next_value_f2_StateTrans =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel;
    d_st.site = &xc_emlrtRSI;
    e_st.site = &hm_emlrtRSI;
    c_trackEstimator(
        &e_st, c_args_next_next_next_value_f1_, d_args_next_next_next_value_f1_,
        e_args_next_next_next_value_f1_, c_args_next_value_f1_StateTrans,
        d_args_next_value_f1_StateTrans, e_args_next_value_f1_StateTrans,
        f_args_next_next_next_value_f1_, g_args_next_next_next_value_f1_,
        f_args_next_value_f1_StateTrans, h_args_next_next_next_value_f1_,
        g_args_next_value_f1_StateTrans, h_args_next_value_f1_StateTrans,
        k_args_next_value_f1_StateTrans, &j_args_next_value_f2_StateTrans,
        &b_spec, &b_obj_Estimator_StateEstimator);
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .HorizontalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .HorizontalAccelerationVariance;
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .AngularAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .AngularAccelerationVariance;
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .HorizontalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .HorizontalAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .AngularAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .AngularAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalAccelerationVariance;
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    obj->Assigner.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    obj->Assigner.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    obj->Assigner.f1.SensorSpecifications[0] = spec;
    c_t62_StateEstimator_Estimators.TargetSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .TargetSpecifications[0];
    c_t62_StateEstimator_Estimators.SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .SensorSpecifications[0];
    c_t62_StateEstimator_Estimators.TrackingFilter =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .TrackingFilter;
    d_t62_StateEstimator_Estimators.TargetSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .TargetSpecifications[0];
    d_t62_StateEstimator_Estimators.SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .SensorSpecifications[0];
    d_t62_StateEstimator_Estimators.TrackingFilter =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .TrackingFilter;
    t75_Estimators.f1 = c_t62_StateEstimator_Estimators;
    t75_Estimators.f2 = d_t62_StateEstimator_Estimators;
    obj->Assigner.f1.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications = val;
    obj->Assigner.f1.Estimator.StateEstimator.StateEstimator
        .SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.SensorSpecifications[0];
    obj->Assigner.f1.Estimator.StateEstimator.StateEstimator.Estimators =
        t75_Estimators;
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] = b_expl_temp[0];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] = b_expl_temp[1];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        m_args_next_value_f1_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        m_args_next_value_f1_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        n_args_next_value_f1_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        n_args_next_value_f1_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        o_args_next_value_f1_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        o_args_next_value_f1_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        p_args_next_value_f1_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        p_args_next_value_f1_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        q_args_next_value_f1_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        q_args_next_value_f1_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        h_expl_temp;
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        g_expl_temp;
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        r_args_next_value_f1_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        r_args_next_value_f1_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        s_args_next_value_f1_StateTrans;
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        g_args_next_value_f2_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        g_args_next_value_f2_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        h_args_next_value_f2_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        h_args_next_value_f2_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        i_args_next_value_f2_StateTrans[0];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        i_args_next_value_f2_StateTrans[1];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        f_args_next_value_f2_StateTrans.SpeedLimits[0];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        f_args_next_value_f2_StateTrans.SpeedLimits[1];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        f_args_next_value_f2_StateTrans.YawLimits[0];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        f_args_next_value_f2_StateTrans.YawLimits[1];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        f_args_next_value_f2_StateTrans.YawRateLimits[0];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        f_args_next_value_f2_StateTrans.YawRateLimits[1];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        f_args_next_value_f2_StateTrans.HorizontalAccelerationVariance;
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        f_args_next_value_f2_StateTrans.AngularAccelerationVariance;
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        f_args_next_value_f2_StateTrans.VerticalVelocityLimits[0];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        f_args_next_value_f2_StateTrans.VerticalVelocityLimits[1];
    obj->Assigner.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        f_args_next_value_f2_StateTrans.VerticalAccelerationVariance;
    obj->Assigner.f2.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications =
        obj_Estimator_StateEstimator.StateEstimator.TargetSpecifications;
    obj->Assigner.f2.Estimator.StateEstimator.StateEstimator.Estimators =
        obj_Estimator_StateEstimator.StateEstimator.Estimators;
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        c_args_next_next_next_value_f1_[0];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        c_args_next_next_next_value_f1_[1];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        d_args_next_next_next_value_f1_[0];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        d_args_next_next_next_value_f1_[1];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        e_args_next_next_next_value_f1_[0];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        e_args_next_next_next_value_f1_[1];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        c_args_next_value_f1_StateTrans[0];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        c_args_next_value_f1_StateTrans[1];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        d_args_next_value_f1_StateTrans[0];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        d_args_next_value_f1_StateTrans[1];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        e_args_next_value_f1_StateTrans[0];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        e_args_next_value_f1_StateTrans[1];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        f_args_next_next_next_value_f1_;
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        g_args_next_next_next_value_f1_;
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        f_args_next_value_f1_StateTrans[0];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        f_args_next_value_f1_StateTrans[1];
    obj->Assigner.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        h_args_next_next_next_value_f1_;
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        g_args_next_value_f1_StateTrans[0];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        g_args_next_value_f1_StateTrans[1];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        h_args_next_value_f1_StateTrans[0];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        h_args_next_value_f1_StateTrans[1];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        k_args_next_value_f1_StateTrans[0];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        k_args_next_value_f1_StateTrans[1];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        j_args_next_value_f2_StateTrans.SpeedLimits[0];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        j_args_next_value_f2_StateTrans.SpeedLimits[1];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        j_args_next_value_f2_StateTrans.YawLimits[0];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        j_args_next_value_f2_StateTrans.YawLimits[1];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        j_args_next_value_f2_StateTrans.YawRateLimits[0];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        j_args_next_value_f2_StateTrans.YawRateLimits[1];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        j_args_next_value_f2_StateTrans.HorizontalAccelerationVariance;
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        j_args_next_value_f2_StateTrans.AngularAccelerationVariance;
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        j_args_next_value_f2_StateTrans.VerticalVelocityLimits[0];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        j_args_next_value_f2_StateTrans.VerticalVelocityLimits[1];
    obj->Assigner.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        j_args_next_value_f2_StateTrans.VerticalAccelerationVariance;
    obj->Assigner.f3.SensorSpecifications[0] = b_spec;
    obj->Assigner.f3.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications =
        b_obj_Estimator_StateEstimator.StateEstimator.TargetSpecifications;
    obj->Assigner.f3.Estimator.StateEstimator.StateEstimator
        .SensorSpecifications[0] =
        b_obj_Estimator_StateEstimator.StateEstimator.SensorSpecifications[0];
    obj->Assigner.f3.Estimator.StateEstimator.StateEstimator.Estimators =
        b_obj_Estimator_StateEstimator.StateEstimator.Estimators;
    spec = obj->SensorSpecifications.f1;
    args_next_value_f1 = obj->TargetSpecifications.f1;
    args_next_value_f2 = obj->TargetSpecifications.f2;
    d_st.site = &yc_emlrtRSI;
    e_st.site = &im_emlrtRSI;
    trackEstimator(&e_st, &args_next_value_f1, &args_next_value_f2, &spec,
                   &obj->_pobj2[4], &trackEstimator_StateEstimator);
    val.f1.StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.LengthLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.LengthLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.WidthLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.WidthLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.HeightLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.HeightLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[0] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f1.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[1] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f1.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[1];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[0];
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.LengthLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.LengthLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.WidthLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.WidthLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.HeightLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.HeightLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[0] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f2.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .SpeedLimits[1] = trackEstimator_StateEstimator.StateEstimator
                              .TargetSpecifications.f2.StateTransitionModel
                              .StationaryMotionModel.MotionModel.SpeedLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .YawRateLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .YawRateLimits[1];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[0] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[0];
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalVelocityLimits[1] =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalVelocityLimits[1];
    b_expl_temp[0] = obj->TargetSpecifications.f1.StateTransitionModel
                         .StationaryMotionModel.LengthLimits[0];
    b_expl_temp[1] = obj->TargetSpecifications.f1.StateTransitionModel
                         .StationaryMotionModel.LengthLimits[1];
    m_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    m_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    n_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    n_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    o_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    o_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    p_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    p_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    q_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    q_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    h_expl_temp =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    g_expl_temp =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    r_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    r_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    s_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    g_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    g_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    h_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    h_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    i_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    i_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    f_args_next_value_f2_StateTrans =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel;
    d_st.site = &yc_emlrtRSI;
    e_st.site = &im_emlrtRSI;
    b_trackEstimator(
        &e_st, b_expl_temp, m_args_next_value_f1_StateTrans,
        n_args_next_value_f1_StateTrans, o_args_next_value_f1_StateTrans,
        p_args_next_value_f1_StateTrans, q_args_next_value_f1_StateTrans,
        h_expl_temp, g_expl_temp, r_args_next_value_f1_StateTrans,
        s_args_next_value_f1_StateTrans, g_args_next_value_f2_StateTrans,
        h_args_next_value_f2_StateTrans, i_args_next_value_f2_StateTrans,
        &f_args_next_value_f2_StateTrans, &obj_Estimator_StateEstimator);
    b_spec = obj->SensorSpecifications.f3;
    c_args_next_next_next_value_f1_[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    c_args_next_next_next_value_f1_[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    d_args_next_next_next_value_f1_[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    d_args_next_next_next_value_f1_[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    e_args_next_next_next_value_f1_[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    e_args_next_next_next_value_f1_[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    c_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    c_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    d_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    d_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    e_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    e_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    f_args_next_next_next_value_f1_ =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    g_args_next_next_next_value_f1_ =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    f_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    f_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    h_args_next_next_next_value_f1_ =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    g_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    g_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    h_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    h_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    k_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    k_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    j_args_next_value_f2_StateTrans =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel;
    d_st.site = &yc_emlrtRSI;
    e_st.site = &im_emlrtRSI;
    c_trackEstimator(
        &e_st, c_args_next_next_next_value_f1_, d_args_next_next_next_value_f1_,
        e_args_next_next_next_value_f1_, c_args_next_value_f1_StateTrans,
        d_args_next_value_f1_StateTrans, e_args_next_value_f1_StateTrans,
        f_args_next_next_next_value_f1_, g_args_next_next_next_value_f1_,
        f_args_next_value_f1_StateTrans, h_args_next_next_next_value_f1_,
        g_args_next_value_f1_StateTrans, h_args_next_value_f1_StateTrans,
        k_args_next_value_f1_StateTrans, &j_args_next_value_f2_StateTrans,
        &b_spec, &b_obj_Estimator_StateEstimator);
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .HorizontalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .HorizontalAccelerationVariance;
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .AngularAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .AngularAccelerationVariance;
    val.f1.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f1
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .HorizontalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .HorizontalAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .AngularAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .AngularAccelerationVariance;
    val.f2.StateTransitionModel.StationaryMotionModel.MotionModel
        .VerticalAccelerationVariance =
        trackEstimator_StateEstimator.StateEstimator.TargetSpecifications.f2
            .StateTransitionModel.StationaryMotionModel.MotionModel
            .VerticalAccelerationVariance;
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    obj->Updater.f1.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        args_next_value_f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    obj->Updater.f1.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        args_next_value_f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    obj->Updater.f1.SensorSpecifications[0] = spec;
    c_t65_StateEstimator_Estimators.TargetSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .TargetSpecifications[0];
    c_t65_StateEstimator_Estimators.SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .SensorSpecifications[0];
    c_t65_StateEstimator_Estimators.TrackingFilter =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f1
            .TrackingFilter;
    d_t65_StateEstimator_Estimators.TargetSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .TargetSpecifications[0];
    d_t65_StateEstimator_Estimators.SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .SensorSpecifications[0];
    d_t65_StateEstimator_Estimators.TrackingFilter =
        trackEstimator_StateEstimator.StateEstimator.Estimators.f2
            .TrackingFilter;
    t78_Estimators.f1 = c_t65_StateEstimator_Estimators;
    t78_Estimators.f2 = d_t65_StateEstimator_Estimators;
    obj->Updater.f1.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications = val;
    obj->Updater.f1.Estimator.StateEstimator.StateEstimator
        .SensorSpecifications[0] =
        trackEstimator_StateEstimator.StateEstimator.SensorSpecifications[0];
    obj->Updater.f1.Estimator.StateEstimator.StateEstimator.Estimators =
        t78_Estimators;
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] = b_expl_temp[0];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] = b_expl_temp[1];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        m_args_next_value_f1_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        m_args_next_value_f1_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        n_args_next_value_f1_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        n_args_next_value_f1_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        o_args_next_value_f1_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        o_args_next_value_f1_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        p_args_next_value_f1_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        p_args_next_value_f1_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        q_args_next_value_f1_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        q_args_next_value_f1_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        h_expl_temp;
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        g_expl_temp;
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        r_args_next_value_f1_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        r_args_next_value_f1_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        s_args_next_value_f1_StateTrans;
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        g_args_next_value_f2_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        g_args_next_value_f2_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        h_args_next_value_f2_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        h_args_next_value_f2_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        i_args_next_value_f2_StateTrans[0];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        i_args_next_value_f2_StateTrans[1];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        f_args_next_value_f2_StateTrans.SpeedLimits[0];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        f_args_next_value_f2_StateTrans.SpeedLimits[1];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        f_args_next_value_f2_StateTrans.YawLimits[0];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        f_args_next_value_f2_StateTrans.YawLimits[1];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        f_args_next_value_f2_StateTrans.YawRateLimits[0];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        f_args_next_value_f2_StateTrans.YawRateLimits[1];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        f_args_next_value_f2_StateTrans.HorizontalAccelerationVariance;
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        f_args_next_value_f2_StateTrans.AngularAccelerationVariance;
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        f_args_next_value_f2_StateTrans.VerticalVelocityLimits[0];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        f_args_next_value_f2_StateTrans.VerticalVelocityLimits[1];
    obj->Updater.f2.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        f_args_next_value_f2_StateTrans.VerticalAccelerationVariance;
    obj->Updater.f2.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications =
        obj_Estimator_StateEstimator.StateEstimator.TargetSpecifications;
    obj->Updater.f2.Estimator.StateEstimator.StateEstimator.Estimators =
        obj_Estimator_StateEstimator.StateEstimator.Estimators;
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        c_args_next_next_next_value_f1_[0];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        c_args_next_next_next_value_f1_[1];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        d_args_next_next_next_value_f1_[0];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        d_args_next_next_next_value_f1_[1];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        e_args_next_next_next_value_f1_[0];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        e_args_next_next_next_value_f1_[1];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        c_args_next_value_f1_StateTrans[0];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        c_args_next_value_f1_StateTrans[1];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        d_args_next_value_f1_StateTrans[0];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        d_args_next_value_f1_StateTrans[1];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        e_args_next_value_f1_StateTrans[0];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        e_args_next_value_f1_StateTrans[1];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        f_args_next_next_next_value_f1_;
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        g_args_next_next_next_value_f1_;
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        f_args_next_value_f1_StateTrans[0];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        f_args_next_value_f1_StateTrans[1];
    obj->Updater.f3.TargetSpecifications.f1.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        h_args_next_next_next_value_f1_;
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[0] =
        g_args_next_value_f1_StateTrans[0];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.LengthLimits[1] =
        g_args_next_value_f1_StateTrans[1];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[0] =
        h_args_next_value_f1_StateTrans[0];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.WidthLimits[1] =
        h_args_next_value_f1_StateTrans[1];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[0] =
        k_args_next_value_f1_StateTrans[0];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.HeightLimits[1] =
        k_args_next_value_f1_StateTrans[1];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[0] =
        j_args_next_value_f2_StateTrans.SpeedLimits[0];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.SpeedLimits[1] =
        j_args_next_value_f2_StateTrans.SpeedLimits[1];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[0] =
        j_args_next_value_f2_StateTrans.YawLimits[0];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawLimits[1] =
        j_args_next_value_f2_StateTrans.YawLimits[1];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[0] =
        j_args_next_value_f2_StateTrans.YawRateLimits[0];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.YawRateLimits[1] =
        j_args_next_value_f2_StateTrans.YawRateLimits[1];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.HorizontalAccelerationVariance =
        j_args_next_value_f2_StateTrans.HorizontalAccelerationVariance;
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.AngularAccelerationVariance =
        j_args_next_value_f2_StateTrans.AngularAccelerationVariance;
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[0] =
        j_args_next_value_f2_StateTrans.VerticalVelocityLimits[0];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalVelocityLimits[1] =
        j_args_next_value_f2_StateTrans.VerticalVelocityLimits[1];
    obj->Updater.f3.TargetSpecifications.f2.StateTransitionModel
        .StationaryMotionModel.MotionModel.VerticalAccelerationVariance =
        j_args_next_value_f2_StateTrans.VerticalAccelerationVariance;
    obj->Updater.f3.SensorSpecifications[0] = b_spec;
    obj->Updater.f3.Estimator.StateEstimator.StateEstimator
        .TargetSpecifications =
        b_obj_Estimator_StateEstimator.StateEstimator.TargetSpecifications;
    obj->Updater.f3.Estimator.StateEstimator.StateEstimator
        .SensorSpecifications[0] =
        b_obj_Estimator_StateEstimator.StateEstimator.SensorSpecifications[0];
    obj->Updater.f3.Estimator.StateEstimator.StateEstimator.Estimators =
        b_obj_Estimator_StateEstimator.StateEstimator.Estimators;
    c_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    c_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    d_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    d_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    e_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    e_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    f_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[0];
    f_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.SpeedLimits[1];
    g_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    g_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    h_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    h_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    i_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    j_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    k_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    k_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    l_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    c_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[0];
    c_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .LengthLimits[1];
    d_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[0];
    d_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .WidthLimits[1];
    e_args_next_value_f2_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[0];
    e_args_next_value_f2_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .HeightLimits[1];
    b_expl_temp[0] = obj->TargetSpecifications.f2.StateTransitionModel
                         .StationaryMotionModel.MotionModel.SpeedLimits[0];
    b_expl_temp[1] = obj->TargetSpecifications.f2.StateTransitionModel
                         .StationaryMotionModel.MotionModel.SpeedLimits[1];
    m_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[0];
    m_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawLimits[1];
    n_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[0];
    n_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.YawRateLimits[1];
    h_expl_temp =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.HorizontalAccelerationVariance;
    g_expl_temp =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.AngularAccelerationVariance;
    o_args_next_value_f1_StateTrans[0] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[0];
    o_args_next_value_f1_StateTrans[1] =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalVelocityLimits[1];
    s_args_next_value_f1_StateTrans =
        obj->TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
            .MotionModel.VerticalAccelerationVariance;
    for (i = 0; i < 6; i++) {
      c_args_value_f1_MeasurementMode[i] =
          obj->SensorSpecifications.f1.MeasurementModel.OriginPosition[i];
    }
    for (i = 0; i < 18; i++) {
      d_args_value_f1_MeasurementMode[i] =
          obj->SensorSpecifications.f1.MeasurementModel.Orientation[i];
    }
    p_args_next_value_f1_StateTrans[0] =
        obj->SensorSpecifications.f1.DetectabilityModel.AzimuthLimits[0];
    p_args_next_value_f1_StateTrans[1] =
        obj->SensorSpecifications.f1.DetectabilityModel.AzimuthLimits[1];
    q_args_next_value_f1_StateTrans[0] =
        obj->SensorSpecifications.f1.DetectabilityModel.ElevationLimits[0];
    q_args_next_value_f1_StateTrans[1] =
        obj->SensorSpecifications.f1.DetectabilityModel.ElevationLimits[1];
    r_args_next_value_f1_StateTrans[0] =
        obj->SensorSpecifications.f1.DetectabilityModel.RangeLimits[0];
    r_args_next_value_f1_StateTrans[1] =
        obj->SensorSpecifications.f1.DetectabilityModel.RangeLimits[1];
    g_args_next_value_f2_StateTrans[0] =
        obj->SensorSpecifications.f1.DetectabilityModel.RangeRateLimits[0];
    g_args_next_value_f2_StateTrans[1] =
        obj->SensorSpecifications.f1.DetectabilityModel.RangeRateLimits[1];
    f_args_next_next_next_value_f1_ =
        obj->SensorSpecifications.f1.NumFalsePositivesPerScan;
    g_args_next_next_next_value_f1_ =
        obj->SensorSpecifications.f1.NumNewTargetsPerScan;
    for (i = 0; i < 9; i++) {
      c_args_value_f3_MeasurementMode[i] =
          obj->SensorSpecifications.f3.MeasurementModel.Intrinsics[i];
    }
    h_args_next_value_f2_StateTrans[0] =
        obj->SensorSpecifications.f3.MeasurementModel.ImageSize[0];
    h_args_next_value_f2_StateTrans[1] =
        obj->SensorSpecifications.f3.MeasurementModel.ImageSize[1];
    i_args_next_value_f2_StateTrans[0] =
        obj->SensorSpecifications.f3.DetectabilityModel.AzimuthLimits[0];
    i_args_next_value_f2_StateTrans[1] =
        obj->SensorSpecifications.f3.DetectabilityModel.AzimuthLimits[1];
    c_args_next_next_next_value_f1_[0] =
        obj->SensorSpecifications.f3.DetectabilityModel.ElevationLimits[0];
    c_args_next_next_next_value_f1_[1] =
        obj->SensorSpecifications.f3.DetectabilityModel.ElevationLimits[1];
    d_args_next_next_next_value_f1_[0] =
        obj->SensorSpecifications.f3.DetectabilityModel.RangeLimits[0];
    d_args_next_next_next_value_f1_[1] =
        obj->SensorSpecifications.f3.DetectabilityModel.RangeLimits[1];
    e_args_next_next_next_value_f1_[0] =
        obj->SensorSpecifications.f3.DetectabilityModel.RangeRateLimits[0];
    e_args_next_next_next_value_f1_[1] =
        obj->SensorSpecifications.f3.DetectabilityModel.RangeRateLimits[1];
    h_args_next_next_next_value_f1_ =
        obj->SensorSpecifications.f3.NumFalsePositivesPerImage;
    c_args_value_f3_NumNewTargetsPe =
        obj->SensorSpecifications.f3.NumNewTargetsPerImage;
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .LengthLimits[0] = c_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .LengthLimits[1] = c_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .WidthLimits[0] = d_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .WidthLimits[1] = d_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .HeightLimits[0] = e_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .HeightLimits[1] = e_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.SpeedLimits[0] = f_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.SpeedLimits[1] = f_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawLimits[0] = g_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawLimits[1] = g_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawRateLimits[0] = h_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawRateLimits[1] = h_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.HorizontalAccelerationVariance =
        i_args_next_value_f1_StateTrans;
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.AngularAccelerationVariance =
        j_args_next_value_f1_StateTrans;
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalVelocityLimits[0] =
        k_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalVelocityLimits[1] =
        k_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalAccelerationVariance =
        l_args_next_value_f1_StateTrans;
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .LengthLimits[0] = c_args_next_value_f2_StateTrans[0];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .LengthLimits[1] = c_args_next_value_f2_StateTrans[1];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .WidthLimits[0] = d_args_next_value_f2_StateTrans[0];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .WidthLimits[1] = d_args_next_value_f2_StateTrans[1];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .HeightLimits[0] = e_args_next_value_f2_StateTrans[0];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .HeightLimits[1] = e_args_next_value_f2_StateTrans[1];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.SpeedLimits[0] = b_expl_temp[0];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.SpeedLimits[1] = b_expl_temp[1];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawLimits[0] = m_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawLimits[1] = m_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawRateLimits[0] = n_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.YawRateLimits[1] = n_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.HorizontalAccelerationVariance = h_expl_temp;
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.AngularAccelerationVariance = g_expl_temp;
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalVelocityLimits[0] =
        o_args_next_value_f1_StateTrans[0];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalVelocityLimits[1] =
        o_args_next_value_f1_StateTrans[1];
    r.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
        .MotionModel.VerticalAccelerationVariance =
        s_args_next_value_f1_StateTrans;
    for (i = 0; i < 6; i++) {
      r.SensorSpecifications.f1.MeasurementModel.OriginPosition[i] =
          c_args_value_f1_MeasurementMode[i];
    }
    cell_5 args_next_next_value;
    memcpy(&r.SensorSpecifications.f1.MeasurementModel.Orientation[0],
           &d_args_value_f1_MeasurementMode[0], 18U * sizeof(real_T));
    r.SensorSpecifications.f1.DetectabilityModel.AzimuthLimits[0] =
        p_args_next_value_f1_StateTrans[0];
    r.SensorSpecifications.f1.DetectabilityModel.AzimuthLimits[1] =
        p_args_next_value_f1_StateTrans[1];
    r.SensorSpecifications.f1.DetectabilityModel.ElevationLimits[0] =
        q_args_next_value_f1_StateTrans[0];
    r.SensorSpecifications.f1.DetectabilityModel.ElevationLimits[1] =
        q_args_next_value_f1_StateTrans[1];
    r.SensorSpecifications.f1.DetectabilityModel.RangeLimits[0] =
        r_args_next_value_f1_StateTrans[0];
    r.SensorSpecifications.f1.DetectabilityModel.RangeLimits[1] =
        r_args_next_value_f1_StateTrans[1];
    r.SensorSpecifications.f1.DetectabilityModel.RangeRateLimits[0] =
        g_args_next_value_f2_StateTrans[0];
    r.SensorSpecifications.f1.DetectabilityModel.RangeRateLimits[1] =
        g_args_next_value_f2_StateTrans[1];
    r.SensorSpecifications.f1.NumFalsePositivesPerScan =
        f_args_next_next_next_value_f1_;
    r.SensorSpecifications.f1.NumNewTargetsPerScan =
        g_args_next_next_next_value_f1_;
    memcpy(&r.SensorSpecifications.f3.MeasurementModel.Intrinsics[0],
           &c_args_value_f3_MeasurementMode[0], 9U * sizeof(real_T));
    r.SensorSpecifications.f3.MeasurementModel.ImageSize[0] =
        h_args_next_value_f2_StateTrans[0];
    r.SensorSpecifications.f3.MeasurementModel.ImageSize[1] =
        h_args_next_value_f2_StateTrans[1];
    r.SensorSpecifications.f3.DetectabilityModel.AzimuthLimits[0] =
        i_args_next_value_f2_StateTrans[0];
    r.SensorSpecifications.f3.DetectabilityModel.AzimuthLimits[1] =
        i_args_next_value_f2_StateTrans[1];
    r.SensorSpecifications.f3.DetectabilityModel.ElevationLimits[0] =
        c_args_next_next_next_value_f1_[0];
    r.SensorSpecifications.f3.DetectabilityModel.ElevationLimits[1] =
        c_args_next_next_next_value_f1_[1];
    r.SensorSpecifications.f3.DetectabilityModel.RangeLimits[0] =
        d_args_next_next_next_value_f1_[0];
    r.SensorSpecifications.f3.DetectabilityModel.RangeLimits[1] =
        d_args_next_next_next_value_f1_[1];
    r.SensorSpecifications.f3.DetectabilityModel.RangeRateLimits[0] =
        e_args_next_next_next_value_f1_[0];
    r.SensorSpecifications.f3.DetectabilityModel.RangeRateLimits[1] =
        e_args_next_next_next_value_f1_[1];
    r.SensorSpecifications.f3.NumFalsePositivesPerImage =
        h_args_next_next_next_value_f1_;
    r.SensorSpecifications.f3.NumNewTargetsPerImage =
        c_args_value_f3_NumNewTargetsPe;
    d_st.site = &ad_emlrtRSI;
    ObjectTrackOutputter_setup(&d_st, &r, &obj->_pobj2[6]);
    obj->Outputter = r;
    d_st.site = &vc_emlrtRSI;
    val = obj->TargetSpecifications;
    args_next_next_value = obj->SensorSpecifications;
    h_expl_temp = obj->c_ConfirmationExistenceProbabil;
    g_expl_temp = obj->DeletionExistenceProbability;
    c_obj.TargetSpecifications = val;
    c_obj.SensorSpecifications = args_next_next_value;
    e_st.site = &dn_emlrtRSI;
    c_JIPDATrackMaintainer_set_Conf(&e_st, &c_obj, h_expl_temp);
    e_st.site = &dn_emlrtRSI;
    c_JIPDATrackMaintainer_set_Dele(&e_st, &c_obj, g_expl_temp);
    d_st.site = &vc_emlrtRSI;
    e_st.site = &in_emlrtRSI;
    trackEstimator(&e_st, &c_obj.TargetSpecifications.f1,
                   &c_obj.TargetSpecifications.f2,
                   &c_obj.SensorSpecifications.f1, &obj->_pobj2[8],
                   &c_obj.Estimator.StateEstimator);
    obj->TrackMaintenance = c_obj;
    obj->TunablePropsChanged = false;
    b_st.site = &oc_emlrtRSI;
    c_emxCopyStruct_fusion_tracker_(&b_st, &b_obj, &obj->TrackListManager,
                                    &v_emlrtRTEI);
    b_obj.InternalTrackList->size[0] = 0;
    c_emxCopyStruct_fusion_tracker_(&b_st, &obj->TrackListManager, &b_obj,
                                    &w_emlrtRTEI);
    c_emxFreeStruct_fusion_tracker_(&b_st, &b_obj);
  }
  st.site = &oc_emlrtRSI;
  SystemCore_checkTunableProps(&st, obj);
  st.site = &qc_emlrtRSI;
  JIPDATracker_stepImpl(&st, obj, varargin_4_Time,
                        c_varargin_4_EgoRotationalDispl, varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (SystemCore.c) */
