/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * JIPDATracker.c
 *
 * Code generation for function 'JIPDATracker'
 *
 */

/* Include files */
#include "JIPDATracker.h"
#include "MultiModalEKFEstimator.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_emxutil.h"
#include "trackerEntryPoint_types.h"
#include "uniquetolcg.h"
#include "ypr2rotmat.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo to_emlrtRSI = {
    189,                     /* lineNo */
    "JIPDATracker/stepImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo uo_emlrtRSI = {
    197,                     /* lineNo */
    "JIPDATracker/stepImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo vo_emlrtRSI = {
    202,                     /* lineNo */
    "JIPDATracker/stepImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo wo_emlrtRSI = {
    204,                     /* lineNo */
    "JIPDATracker/stepImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo xo_emlrtRSI = {
    207,                     /* lineNo */
    "JIPDATracker/stepImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo yo_emlrtRSI = {
    234,                     /* lineNo */
    "JIPDATracker/stepImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo ap_emlrtRSI = {
    237,                     /* lineNo */
    "JIPDATracker/stepImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pathName */
};

static emlrtRSInfo bp_emlrtRSI = {
    57,                             /* lineNo */
    "SensorDataScheduler/schedule", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m" /* pathName */
};

static emlrtRSInfo cp_emlrtRSI = {
    59,                             /* lineNo */
    "SensorDataScheduler/schedule", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m" /* pathName */
};

static emlrtRSInfo fq_emlrtRSI = {
    42,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pathName
                                                                         */
};

static emlrtRSInfo gq_emlrtRSI = {
    65,                         /* lineNo */
    "SensorDataScheduler/next", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m" /* pathName */
};

static emlrtRSInfo hq_emlrtRSI = {
    70,                         /* lineNo */
    "SensorDataScheduler/next", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m" /* pathName */
};

static emlrtRSInfo jq_emlrtRSI = {
    339,                                      /* lineNo */
    "HighwayVehicleSpecification/selectTime", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "targetspecs\\+internal\\HighwayVehicleSpec"
    "ification.m" /* pathName */
};

static emlrtRSInfo kq_emlrtRSI = {
    337,                                      /* lineNo */
    "HighwayVehicleSpecification/selectTime", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "targetspecs\\+internal\\HighwayVehicleSpec"
    "ification.m" /* pathName */
};

static emlrtRSInfo lq_emlrtRSI = {
    325,                                      /* lineNo */
    "HighwayVehicleSpecification/selectTime", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "targetspecs\\+internal\\HighwayVehicleSpec"
    "ification.m" /* pathName */
};

static emlrtRSInfo mq_emlrtRSI = {
    324,                                      /* lineNo */
    "HighwayVehicleSpecification/selectTime", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "targetspecs\\+internal\\HighwayVehicleSpec"
    "ification.m" /* pathName */
};

static emlrtRSInfo nq_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo br_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRSInfo cr_emlrtRSI = {
    355,                                       /* lineNo */
    "HighwayVehicleSpecification/updateModel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "targetspecs\\+internal\\HighwayVehicleSpec"
    "ification.m" /* pathName */
};

static emlrtRSInfo gr_emlrtRSI = {
    44,                            /* lineNo */
    "ObjectTrackOutputter/output", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m" /* pathName */
};

static emlrtRSInfo hr_emlrtRSI = {
    45,                            /* lineNo */
    "ObjectTrackOutputter/output", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m" /* pathName */
};

static emlrtRSInfo ir_emlrtRSI = {
    69,                                             /* lineNo */
    "ObjectTrackOutputter/trackListToObjectTracks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m" /* pathName */
};

static emlrtRSInfo jr_emlrtRSI = {
    69,                  /* lineNo */
    "horzcatStructList", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\horzcatStructList.m" /* pathName */
};

static emlrtRSInfo kr_emlrtRSI = {
    25,                  /* lineNo */
    "horzcatStructList", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\horzcatStructList.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    44,                              /* lineNo */
    50,                              /* colNo */
    "",                              /* aName */
    "JIPDATrackMaintainer/maintain", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    50,                              /* lineNo */
    67,                              /* colNo */
    "",                              /* aName */
    "JIPDATrackMaintainer/maintain", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = {
    359,                                       /* lineNo */
    21,                                        /* colNo */
    "HighwayVehicleSpecification/updateModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "targetspecs\\+internal\\HighwayVehicleSpec"
    "ification.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                             /* iFirst */
    -1,                                             /* iLast */
    72,                                             /* lineNo */
    75,                                             /* colNo */
    "",                                             /* aName */
    "ObjectTrackOutputter/trackListToObjectTracks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtRTEInfo k_emlrtRTEI =
    {
        138,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI =
    {
        133,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                             /* iFirst */
    -1,                                             /* iLast */
    72,                                             /* lineNo */
    35,                                             /* colNo */
    "",                                             /* aName */
    "ObjectTrackOutputter/trackListToObjectTracks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    47,                            /* lineNo */
    43,                            /* colNo */
    "",                            /* aName */
    "ObjectTrackOutputter/output", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    65,                         /* lineNo */
    53,                         /* colNo */
    "SensorDataScheduler/next", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m", /* pName */
    1     /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    65,                         /* lineNo */
    53,                         /* colNo */
    "",                         /* aName */
    "SensorDataScheduler/next", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m", /* pName */
    0     /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    45,                              /* lineNo */
    74,                              /* colNo */
    "",                              /* aName */
    "JIPDATrackMaintainer/maintain", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    50,                              /* lineNo */
    32,                              /* colNo */
    "",                              /* aName */
    "JIPDATrackMaintainer/maintain", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                                        /* iFirst */
    1,                                        /* iLast */
    324,                                      /* lineNo */
    74,                                       /* colNo */
    "",                                       /* aName */
    "HighwayVehicleSpecification/selectTime", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "targetspecs\\+internal\\HighwayVehicleSpec"
    "ification.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                                        /* iFirst */
    1,                                        /* iLast */
    337,                                      /* lineNo */
    46,                                       /* colNo */
    "",                                       /* aName */
    "HighwayVehicleSpecification/selectTime", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "targetspecs\\+internal\\HighwayVehicleSpec"
    "ification.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    52,                              /* lineNo */
    35,                              /* colNo */
    "",                              /* aName */
    "JIPDATrackMaintainer/maintain", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                                             /* iFirst */
    -1,                                             /* iLast */
    72,                                             /* lineNo */
    97,                                             /* colNo */
    "",                                             /* aName */
    "ObjectTrackOutputter/trackListToObjectTracks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                                             /* iFirst */
    -1,                                             /* iLast */
    72,                                             /* lineNo */
    17,                                             /* colNo */
    "",                                             /* aName */
    "ObjectTrackOutputter/trackListToObjectTracks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    46,                            /* lineNo */
    43,                            /* colNo */
    "",                            /* aName */
    "ObjectTrackOutputter/output", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m", /* pName */
    0      /* checkKind */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    310,            /* lineNo */
    63,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    310,            /* lineNo */
    13,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    52,                    /* lineNo */
    13,                    /* colNo */
    "SensorDataScheduler", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    57,                    /* lineNo */
    66,                    /* colNo */
    "SensorDataScheduler", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    59,                    /* lineNo */
    13,                    /* colNo */
    "SensorDataScheduler", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\SensorDataScheduler"
    ".m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    234,            /* lineNo */
    84,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    31,                 /* lineNo */
    13,                 /* colNo */
    "TrackListManager", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\TrackListManager.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    48,                     /* lineNo */
    13,                     /* colNo */
    "JIPDATrackMaintainer", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\JIPDATrackMaintaine"
    "r.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    187,            /* lineNo */
    30,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    234,            /* lineNo */
    13,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    36,                 /* lineNo */
    13,                 /* colNo */
    "TrackListManager", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\TrackListManager.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    237,            /* lineNo */
    63,             /* colNo */
    "JIPDATracker", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "tracker\\JIPDATracker.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    44,                     /* lineNo */
    13,                     /* colNo */
    "ObjectTrackOutputter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    67,                  /* lineNo */
    10,                  /* colNo */
    "horzcatStructList", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\horzcatStructList.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    45,                     /* lineNo */
    13,                     /* colNo */
    "ObjectTrackOutputter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+tracker\\+"
    "internal\\+components\\ObjectTrackOutputte"
    "r.m" /* pName */
};

/* Function Definitions */
void JIPDATracker_stepImpl(const emlrtStack *sp,
                           fusion_tracker_JIPDATracker *b_tracker,
                           real_T varargin_4_Time,
                           const real_T c_varargin_4_EgoRotationalDispl[3],
                           emxArray_struct4_T *varargout_1)
{
  static const char_T logicType[10] = {'I', 'n', 't', 'e', 'g',
                                       'r', 'a', 't', 'e', 'd'};
  b_struct_T *val_data;
  c_fusion_tracker_internal_compo *obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_boolean_T *isConfirmed;
  emxArray_boolean_T *toDeleteTracks;
  emxArray_real_T b_tmp_data;
  emxArray_real_T *b_processTimestamps;
  emxArray_real_T *processTimestamps;
  emxArray_struct4_T *tracksObjectTrack;
  emxArray_struct_T *val;
  m_fusion_tracker_internal_compo b_obj;
  n_fusion_tracker_internal_compo r;
  o_fusion_tracker_internal_compo r1;
  struct4_T s1;
  struct4_T *tracksObjectTrack_data;
  struct4_T *varargout_1_data;
  real_T unusedExpr[9];
  real_T tmp_data;
  real_T *b_processTimestamps_data;
  real_T *processTimestamps_data;
  int32_T b_tmp_size[2];
  int32_T startIdx_size[2];
  int32_T c_i;
  int32_T i;
  int32_T partialTrueCount;
  int32_T resultSize_idx_1;
  int32_T tmp_size;
  int32_T trueCount;
  boolean_T *toDeleteTracks_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &to_emlrtRSI;
  obj = b_tracker->Scheduler;
  tmp_size = 1;
  tmp_data = -1.7976931348623157E+308;
  b_tmp_data.data = &tmp_data;
  b_tmp_data.size = &tmp_size;
  b_tmp_data.allocatedSize = 1;
  b_tmp_data.numDimensions = 1;
  b_tmp_data.canFreeData = false;
  emxInit_real_T(&st, &processTimestamps, &db_emlrtRTEI, true);
  b_st.site = &bp_emlrtRSI;
  uniquetolcg(&b_st, &b_tmp_data, obj->TimeTolerance, processTimestamps);
  processTimestamps_data = processTimestamps->data;
  emxInit_real_T(&st, &b_processTimestamps, &eb_emlrtRTEI, true);
  i = b_processTimestamps->size[0];
  b_processTimestamps->size[0] = processTimestamps->size[0];
  emxEnsureCapacity_real_T(&st, b_processTimestamps, i, &eb_emlrtRTEI);
  b_processTimestamps_data = b_processTimestamps->data;
  resultSize_idx_1 = processTimestamps->size[0] - 1;
  for (i = 0; i <= resultSize_idx_1; i++) {
    b_processTimestamps_data[i] = processTimestamps_data[i];
  }
  b_st.site = &bp_emlrtRSI;
  uniquetolcg(&b_st, b_processTimestamps, obj->TimeTolerance,
              processTimestamps);
  processTimestamps_data = processTimestamps->data;
  i = b_processTimestamps->size[0];
  b_processTimestamps->size[0] = processTimestamps->size[0];
  emxEnsureCapacity_real_T(&st, b_processTimestamps, i, &eb_emlrtRTEI);
  b_processTimestamps_data = b_processTimestamps->data;
  resultSize_idx_1 = processTimestamps->size[0] - 1;
  for (i = 0; i <= resultSize_idx_1; i++) {
    b_processTimestamps_data[i] = processTimestamps_data[i];
  }
  b_st.site = &bp_emlrtRSI;
  uniquetolcg(&b_st, b_processTimestamps, obj->TimeTolerance,
              processTimestamps);
  emxFree_real_T(&st, &b_processTimestamps);
  b_st.site = &cp_emlrtRSI;
  c_st.site = &fq_emlrtRSI;
  b_sort(&c_st, processTimestamps);
  processTimestamps_data = processTimestamps->data;
  resultSize_idx_1 = processTimestamps->size[0];
  i = obj->ProcessingTimestamps->size[0];
  obj->ProcessingTimestamps->size[0] = processTimestamps->size[0];
  emxEnsureCapacity_real_T(&st, obj->ProcessingTimestamps, i, &fb_emlrtRTEI);
  for (i = 0; i < resultSize_idx_1; i++) {
    obj->ProcessingTimestamps->data[i] = processTimestamps_data[i];
  }
  emxFree_real_T(&st, &processTimestamps);
  obj->CurrentIndex = 1.0;
  int32_T exitg1;
  boolean_T tf;
  do {
    exitg1 = 0;
    st.site = &uo_emlrtRSI;
    obj = b_tracker->Scheduler;
    tf = (obj->CurrentIndex == obj->ProcessingTimestamps->size[0]);
    if (!tf) {
      cell_4 b_val;
      real_T b_i;
      real_T timeInterval_idx_0;
      real_T timeInterval_idx_1;
      st.site = &vo_emlrtRSI;
      obj = b_tracker->Scheduler;
      b_i = obj->CurrentIndex;
      b_st.site = &gq_emlrtRSI;
      indexShapeCheck(&b_st, obj->ProcessingTimestamps->size[0]);
      resultSize_idx_1 = obj->ProcessingTimestamps->size[0];
      if (b_i != (int32_T)muDoubleScalarFloor(b_i)) {
        emlrtIntegerCheckR2012b(b_i, &emlrtDCI, &st);
      }
      if (((int32_T)b_i < 1) || ((int32_T)b_i > resultSize_idx_1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, resultSize_idx_1,
                                      &f_emlrtBCI, &st);
      }
      if (b_i + 1.0 != (int32_T)muDoubleScalarFloor(b_i + 1.0)) {
        emlrtIntegerCheckR2012b(b_i + 1.0, &emlrtDCI, &st);
      }
      if (((int32_T)(b_i + 1.0) < 1) ||
          ((int32_T)(b_i + 1.0) > resultSize_idx_1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1.0), 1, resultSize_idx_1,
                                      &f_emlrtBCI, &st);
      }
      timeInterval_idx_0 = obj->ProcessingTimestamps->data[(int32_T)b_i - 1];
      timeInterval_idx_1 =
          obj->ProcessingTimestamps->data[(int32_T)(b_i + 1.0) - 1];
      b_st.site = &hq_emlrtRSI;
      if (!(timeInterval_idx_0 - varargin_4_Time <= 0.0)) {
        timeInterval_idx_0 = varargin_4_Time - timeInterval_idx_0;
        if (timeInterval_idx_0 > 0.0) {
          partialTrueCount = 1;
          resultSize_idx_1 = 1;
        } else {
          partialTrueCount = 0;
          resultSize_idx_1 = 0;
        }
        resultSize_idx_1 *= partialTrueCount;
        for (i = 0; i < resultSize_idx_1; i++) {
          emlrtDynamicBoundsCheckR2012b(0, 1, 1, &i_emlrtBCI, &b_st);
        }
        c_st.site = &mq_emlrtRSI;
        startIdx_size[0] = partialTrueCount;
        startIdx_size[1] = partialTrueCount;
        for (i = 0; i < resultSize_idx_1; i++) {
          b_i = varargin_4_Time - varargin_4_Time;
        }
        b_tmp_size[0] = partialTrueCount;
        b_tmp_size[1] = partialTrueCount;
        d_st.site = &nq_emlrtRSI;
        mrdiv(&d_st, (real_T *)&timeInterval_idx_0, b_tmp_size, (real_T *)&b_i,
              startIdx_size);
        c_st.site = &lq_emlrtRSI;
        d_st.site = &br_emlrtRSI;
        if ((b_tmp_size[0] == 1) && (b_tmp_size[1] == 1)) {
          emlrtErrorWithMessageIdR2018a(
              &d_st, &l_emlrtRTEI,
              "Coder:toolbox:mtimes_noDynamicScalarExpansion",
              "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&d_st, &k_emlrtRTEI, "MATLAB:innerdim",
                                        "MATLAB:innerdim", 0);
        }
      }
      timeInterval_idx_0 = timeInterval_idx_1 - varargin_4_Time;
      if (!(timeInterval_idx_0 >= 0.0)) {
        if (varargin_4_Time - timeInterval_idx_1 > 0.0) {
          partialTrueCount = 1;
          resultSize_idx_1 = 1;
        } else {
          partialTrueCount = 0;
          resultSize_idx_1 = 0;
        }
        resultSize_idx_1 *= partialTrueCount;
        for (i = 0; i < resultSize_idx_1; i++) {
          emlrtDynamicBoundsCheckR2012b(0, 1, 1, &j_emlrtBCI, &b_st);
        }
        c_st.site = &kq_emlrtRSI;
        startIdx_size[0] = partialTrueCount;
        startIdx_size[1] = partialTrueCount;
        for (i = 0; i < resultSize_idx_1; i++) {
          b_i = varargin_4_Time - varargin_4_Time;
        }
        b_tmp_size[0] = partialTrueCount;
        b_tmp_size[1] = partialTrueCount;
        d_st.site = &nq_emlrtRSI;
        mrdiv(&d_st, (real_T *)&timeInterval_idx_0, b_tmp_size, (real_T *)&b_i,
              startIdx_size);
        c_st.site = &jq_emlrtRSI;
        d_st.site = &br_emlrtRSI;
        if ((b_tmp_size[0] == 1) && (b_tmp_size[1] == 1)) {
          emlrtErrorWithMessageIdR2018a(
              &d_st, &l_emlrtRTEI,
              "Coder:toolbox:mtimes_noDynamicScalarExpansion",
              "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&d_st, &k_emlrtRTEI, "MATLAB:innerdim",
                                        "MATLAB:innerdim", 0);
        }
      }
      obj->CurrentIndex++;
      b_val = b_tracker->TargetSpecifications;
      st.site = &wo_emlrtRSI;
      b_val.f1 = b_tracker->TargetSpecifications.f1;
      b_st.site = &cr_emlrtRSI;
      ypr2rotmat(&b_st, c_varargin_4_EgoRotationalDispl, unusedExpr);
      emlrtForLoopVectorCheckR2021a(0.0, -1.0, 1.0, mxDOUBLE_CLASS, 0,
                                    &j_emlrtRTEI, &st);
      st.site = &wo_emlrtRSI;
      b_st.site = &nc_emlrtRSI;
      tf = (b_tracker->isInitialized == 1);
      if (tf) {
        b_tracker->TunablePropsChanged = true;
        b_tracker->tunablePropertyChanged[0] = true;
      }
      st.site = &wo_emlrtRSI;
      b_tracker->TargetSpecifications = b_val;
      b_val = b_tracker->TargetSpecifications;
      st.site = &wo_emlrtRSI;
      b_val.f2 = b_tracker->TargetSpecifications.f2;
      b_st.site = &cr_emlrtRSI;
      ypr2rotmat(&b_st, c_varargin_4_EgoRotationalDispl, unusedExpr);
      emlrtForLoopVectorCheckR2021a(0.0, -1.0, 1.0, mxDOUBLE_CLASS, 0,
                                    &j_emlrtRTEI, &st);
      st.site = &wo_emlrtRSI;
      b_st.site = &nc_emlrtRSI;
      tf = (b_tracker->isInitialized == 1);
      if (tf) {
        b_tracker->TunablePropsChanged = true;
        b_tracker->tunablePropertyChanged[0] = true;
      }
      st.site = &wo_emlrtRSI;
      b_tracker->TargetSpecifications = b_val;
      st.site = &xo_emlrtRSI;
      c_JIPDATracker_updateTargetSpec(&st, b_tracker);
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  c_emxInitStruct_fusion_tracker_(sp, &b_obj, &gb_emlrtRTEI, true);
  c_emxCopyStruct_fusion_tracker_(sp, &b_obj, &b_tracker->TrackListManager,
                                  &gb_emlrtRTEI);
  emxInit_struct_T(sp, &val, &gb_emlrtRTEI, true);
  resultSize_idx_1 = b_obj.InternalTrackList->size[0];
  i = val->size[0];
  val->size[0] = b_obj.InternalTrackList->size[0];
  emxEnsureCapacity_struct_T(sp, val, i, &hb_emlrtRTEI);
  val_data = val->data;
  for (i = 0; i < resultSize_idx_1; i++) {
    val_data[i] = b_obj.InternalTrackList->data[i];
  }
  st.site = &yo_emlrtRSI;
  r = b_tracker->TrackMaintenance;
  for (c_i = 0; c_i < resultSize_idx_1; c_i++) {
    if (c_i + 1 > val->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, val->size[0], &emlrtBCI, &st);
    }
    if (val_data[c_i].IsConfirmed ||
        (val_data[c_i].ExistenceProbability >= r.ConfirmationThreshold)) {
      if (c_i + 1 > val->size[0]) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, val->size[0], &g_emlrtBCI,
                                      &st);
      }
      val_data[c_i].IsConfirmed = true;
    }
  }
  emxInit_boolean_T(&st, &toDeleteTracks, &ib_emlrtRTEI);
  i = toDeleteTracks->size[0] * toDeleteTracks->size[1];
  toDeleteTracks->size[0] = 1;
  resultSize_idx_1 = val->size[0];
  toDeleteTracks->size[1] = val->size[0];
  emxEnsureCapacity_boolean_T(&st, toDeleteTracks, i, &ib_emlrtRTEI);
  toDeleteTracks_data = toDeleteTracks->data;
  for (i = 0; i < resultSize_idx_1; i++) {
    toDeleteTracks_data[i] = false;
  }
  for (c_i = 0; c_i < resultSize_idx_1; c_i++) {
    if (c_i + 1 > resultSize_idx_1) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, resultSize_idx_1, &b_emlrtBCI,
                                    &st);
    }
    if (c_i + 1 > toDeleteTracks->size[1]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, toDeleteTracks->size[1],
                                    &h_emlrtBCI, &st);
    }
    toDeleteTracks_data[c_i] =
        (val_data[c_i].ExistenceProbability < r.DeletionThreshold);
  }
  resultSize_idx_1 = toDeleteTracks->size[1];
  trueCount = 0;
  for (c_i = 0; c_i < resultSize_idx_1; c_i++) {
    if (!toDeleteTracks_data[c_i]) {
      trueCount++;
    }
  }
  partialTrueCount = 0;
  for (c_i = 0; c_i < resultSize_idx_1; c_i++) {
    if (!toDeleteTracks_data[c_i]) {
      if (c_i > val->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(c_i, 0, val->size[0] - 1, &k_emlrtBCI,
                                      &st);
      }
      val_data[partialTrueCount] = val_data[c_i];
      partialTrueCount++;
    }
  }
  emxFree_boolean_T(&st, &toDeleteTracks);
  i = val->size[0];
  val->size[0] = trueCount;
  emxEnsureCapacity_struct_T(&st, val, i, &jb_emlrtRTEI);
  val_data = val->data;
  c_emxCopyStruct_fusion_tracker_(sp, &b_obj, &b_tracker->TrackListManager,
                                  &kb_emlrtRTEI);
  i = b_obj.InternalTrackList->size[0];
  b_obj.InternalTrackList->size[0] = trueCount;
  emxEnsureCapacity_struct_T(sp, b_obj.InternalTrackList, i, &lb_emlrtRTEI);
  for (i = 0; i < trueCount; i++) {
    b_obj.InternalTrackList->data[i] = val_data[i];
  }
  emxFree_struct_T(sp, &val);
  c_emxCopyStruct_fusion_tracker_(sp, &b_tracker->TrackListManager, &b_obj,
                                  &kb_emlrtRTEI);
  c_emxCopyStruct_fusion_tracker_(sp, &b_obj, &b_tracker->TrackListManager,
                                  &mb_emlrtRTEI);
  st.site = &ap_emlrtRSI;
  r1 = b_tracker->Outputter;
  s1.ObjectClassProbabilities[0] = r1.SampleTrack.ObjectClassProbabilities[0];
  s1.ObjectClassProbabilities[1] = r1.SampleTrack.ObjectClassProbabilities[1];
  memcpy(&s1.State[0], &r1.SampleTrack.pState[0], 10U * sizeof(real_T));
  memcpy(&s1.StateCovariance[0], &r1.SampleTrack.pStateCovariance[0],
         100U * sizeof(real_T));
  b_st.site = &gr_emlrtRSI;
  s1.TrackLogicState = r1.SampleTrack.pTrackLogicState;
  s1.TrackID = r1.SampleTrack.TrackID;
  s1.BranchID = r1.SampleTrack.BranchID;
  s1.SourceIndex = r1.SampleTrack.SourceIndex;
  s1.UpdateTime = r1.SampleTrack.pUpdateTime;
  s1.Age = r1.SampleTrack.Age;
  s1.ObjectClassID = r1.SampleTrack.ObjectClassID;
  for (i = 0; i < 10; i++) {
    s1.TrackLogic[i] = logicType[i];
  }
  s1.IsConfirmed = r1.SampleTrack.IsConfirmed;
  s1.IsCoasted = r1.SampleTrack.IsCoasted;
  s1.IsSelfReported = r1.SampleTrack.IsSelfReported;
  c_st.site = &ir_emlrtRSI;
  emxInit_struct4_T(&c_st, &tracksObjectTrack, &nb_emlrtRTEI);
  resultSize_idx_1 = b_obj.InternalTrackList->size[0];
  i = tracksObjectTrack->size[0];
  tracksObjectTrack->size[0] = b_obj.InternalTrackList->size[0];
  emxEnsureCapacity_struct4_T(&c_st, tracksObjectTrack, i, &nb_emlrtRTEI);
  tracksObjectTrack_data = tracksObjectTrack->data;
  for (i = 0; i < resultSize_idx_1; i++) {
    tracksObjectTrack_data[i] = s1;
  }
  for (c_i = 0; c_i < resultSize_idx_1; c_i++) {
    real_T statePdf_StateCovariance[100];
    real_T statePdf_State[10];
    real_T c_statePdf_ObjectClassProbabili[2];
    if (c_i + 1 > resultSize_idx_1) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, resultSize_idx_1, &c_emlrtBCI,
                                    &b_st);
    }
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &l_emlrtBCI, &b_st);
    }
    partialTrueCount = c_MultiModalEKFEstimator_toObje(
        b_obj.InternalTrackList->data[c_i].Hypothesis,
        b_obj.InternalTrackList->data[c_i].LogWeights, statePdf_State,
        statePdf_StateCovariance, c_statePdf_ObjectClassProbabili);
    for (i = 0; i < 10; i++) {
      if (c_i + 1 > tracksObjectTrack->size[0]) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                      &m_emlrtBCI, &b_st);
      }
      tracksObjectTrack_data[c_i].State[i] = statePdf_State[i];
    }
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    for (i = 0; i < 100; i++) {
      tracksObjectTrack_data[c_i].StateCovariance[i] =
          statePdf_StateCovariance[i];
    }
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    tracksObjectTrack_data[c_i].ObjectClassProbabilities[0] =
        c_statePdf_ObjectClassProbabili[0];
    tracksObjectTrack_data[c_i].ObjectClassProbabilities[1] =
        c_statePdf_ObjectClassProbabili[1];
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    tracksObjectTrack_data[c_i].ObjectClassID = partialTrueCount;
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    for (i = 0; i < 10; i++) {
      tracksObjectTrack_data[c_i].TrackLogic[i] = logicType[i];
    }
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    tracksObjectTrack_data[c_i].TrackLogicState =
        b_obj.InternalTrackList->data[c_i].ExistenceProbability;
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    tracksObjectTrack_data[c_i].Age = b_obj.InternalTrackList->data[c_i].Age;
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    tracksObjectTrack_data[c_i].IsConfirmed =
        b_obj.InternalTrackList->data[c_i].IsConfirmed;
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    tracksObjectTrack_data[c_i].IsCoasted =
        b_obj.InternalTrackList->data[c_i].IsCoasted;
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    tracksObjectTrack_data[c_i].TrackID =
        b_obj.InternalTrackList->data[c_i].TrackID;
    if (c_i + 1 > tracksObjectTrack->size[0]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, tracksObjectTrack->size[0],
                                    &d_emlrtBCI, &b_st);
    }
    tracksObjectTrack_data[c_i].UpdateTime =
        b_obj.InternalTrackList->data[c_i].Time;
  }
  c_emxFreeStruct_fusion_tracker_(&b_st, &b_obj);
  b_st.site = &hr_emlrtRSI;
  partialTrueCount = tracksObjectTrack->size[0];
  if (tracksObjectTrack->size[0] == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = tracksObjectTrack->size[0];
    c_st.site = &kr_emlrtRSI;
    if (tracksObjectTrack->size[0] > 2147483646) {
      d_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }
  emxInit_boolean_T(&b_st, &isConfirmed, &pb_emlrtRTEI);
  i = isConfirmed->size[0] * isConfirmed->size[1];
  isConfirmed->size[0] = 1;
  isConfirmed->size[1] = resultSize_idx_1;
  emxEnsureCapacity_boolean_T(&b_st, isConfirmed, i, &ob_emlrtRTEI);
  toDeleteTracks_data = isConfirmed->data;
  c_st.site = &jr_emlrtRSI;
  for (c_i = 0; c_i < partialTrueCount; c_i++) {
    toDeleteTracks_data[c_i] = tracksObjectTrack_data[c_i].IsConfirmed;
  }
  resultSize_idx_1 = isConfirmed->size[1];
  trueCount = 0;
  for (c_i = 0; c_i < resultSize_idx_1; c_i++) {
    if (toDeleteTracks_data[c_i]) {
      trueCount++;
    }
  }
  i = varargout_1->size[0];
  varargout_1->size[0] = trueCount;
  emxEnsureCapacity_struct4_T(&st, varargout_1, i, &jb_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  partialTrueCount = 0;
  for (c_i = 0; c_i < resultSize_idx_1; c_i++) {
    if (toDeleteTracks_data[c_i]) {
      if (c_i > tracksObjectTrack->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(c_i, 0, tracksObjectTrack->size[0] - 1,
                                      &n_emlrtBCI, &st);
      }
      varargout_1_data[partialTrueCount] = tracksObjectTrack_data[c_i];
      partialTrueCount++;
    }
  }
  for (c_i = 0; c_i < resultSize_idx_1; c_i++) {
    if ((!toDeleteTracks_data[c_i]) && (c_i > tracksObjectTrack->size[0] - 1)) {
      emlrtDynamicBoundsCheckR2012b(c_i, 0, tracksObjectTrack->size[0] - 1,
                                    &e_emlrtBCI, &st);
    }
  }
  emxFree_boolean_T(&st, &isConfirmed);
  emxFree_struct4_T(&st, &tracksObjectTrack);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void c_JIPDATracker_updateTargetSpec(const emlrtStack *sp,
                                     fusion_tracker_JIPDATracker *obj)
{
  d_fusion_tracker_internal_compo b_obj;
  e_fusion_tracker_internal_compo e_obj;
  f_fusion_tracker_internal_compo h_obj;
  g_fusion_tracker_internal_compo c_obj;
  h_fusion_tracker_internal_compo d_obj;
  i_fusion_tracker_internal_compo f_obj;
  j_fusion_tracker_internal_compo g_obj;
  k_fusion_tracker_internal_compo i_obj;
  l_fusion_tracker_internal_compo j_obj;
  m_fusion_tracker_internal_compo k_obj;
  n_fusion_tracker_internal_compo l_obj;
  o_fusion_tracker_internal_compo m_obj;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  b_obj = obj->Initiator.f1;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  b_obj.TargetSpecifications = c_obj.TargetSpecifications;
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  b_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  b_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  b_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Initiator.f1 = b_obj;
  c_obj = obj->Initiator.f2;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  c_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  c_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  c_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Initiator.f2 = c_obj;
  d_obj = obj->Initiator.f3;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  d_obj.TargetSpecifications = c_obj.TargetSpecifications;
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  d_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  d_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  d_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Initiator.f3 = d_obj;
  e_obj = obj->Assigner.f1;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  e_obj.TargetSpecifications = c_obj.TargetSpecifications;
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  e_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  e_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  e_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Assigner.f1 = e_obj;
  f_obj = obj->Assigner.f2;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  f_obj.TargetSpecifications = c_obj.TargetSpecifications;
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  f_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  f_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  f_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Assigner.f2 = f_obj;
  g_obj = obj->Assigner.f3;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  g_obj.TargetSpecifications = c_obj.TargetSpecifications;
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  g_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  g_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  g_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Assigner.f3 = g_obj;
  h_obj = obj->Updater.f1;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  h_obj.TargetSpecifications = c_obj.TargetSpecifications;
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  h_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  h_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  h_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Updater.f1 = h_obj;
  i_obj = obj->Updater.f2;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  i_obj.TargetSpecifications = c_obj.TargetSpecifications;
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  i_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  i_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  i_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Updater.f2 = i_obj;
  j_obj = obj->Updater.f3;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  j_obj.TargetSpecifications = c_obj.TargetSpecifications;
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  j_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  j_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  j_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Updater.f3 = j_obj;
  c_emxInitStruct_fusion_tracker_(sp, &k_obj, &bb_emlrtRTEI, true);
  c_emxCopyStruct_fusion_tracker_(sp, &k_obj, &obj->TrackListManager,
                                  &bb_emlrtRTEI);
  k_obj.TargetSpecifications = obj->TargetSpecifications;
  c_emxCopyStruct_fusion_tracker_(sp, &obj->TrackListManager, &k_obj,
                                  &cb_emlrtRTEI);
  c_emxFreeStruct_fusion_tracker_(sp, &k_obj);
  l_obj = obj->TrackMaintenance;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  l_obj.TargetSpecifications = c_obj.TargetSpecifications;
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  l_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  l_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  l_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->TrackMaintenance = l_obj;
  m_obj = obj->Outputter;
  c_obj.TargetSpecifications = obj->TargetSpecifications;
  m_obj.TargetSpecifications = c_obj.TargetSpecifications;
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f1
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f1.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.LengthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .LengthLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.WidthLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .WidthLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.HeightLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .HeightLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.SpeedLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.SpeedLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel.YawRateLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.YawRateLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .HorizontalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.HorizontalAccelerationVariance;
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .AngularAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.AngularAccelerationVariance;
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[0] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[0];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalVelocityLimits[1] =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalVelocityLimits[1];
  m_obj.Estimator.StateEstimator.StateEstimator.TargetSpecifications.f2
      .StateTransitionModel.StationaryMotionModel.MotionModel
      .VerticalAccelerationVariance =
      c_obj.TargetSpecifications.f2.StateTransitionModel.StationaryMotionModel
          .MotionModel.VerticalAccelerationVariance;
  m_obj.Estimator.StateEstimator.StateEstimator.Estimators.f1
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f1;
  m_obj.Estimator.StateEstimator.StateEstimator.Estimators.f2
      .TargetSpecifications[0] = c_obj.TargetSpecifications.f2;
  obj->Outputter = m_obj;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (JIPDATracker.c) */
