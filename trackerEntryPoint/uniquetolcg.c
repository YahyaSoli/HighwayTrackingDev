/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * uniquetolcg.c
 *
 * Code generation for function 'uniquetolcg'
 *
 */

/* Include files */
#include "uniquetolcg.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "trackerEntryPoint_emxutil.h"
#include "trackerEntryPoint_types.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo dp_emlrtRSI = {
    17,            /* lineNo */
    "uniquetolcg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pathName */
};

static emlrtRSInfo ep_emlrtRSI = {
    37,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pathName
                                                                         */
};

static emlrtECInfo emlrtECI = {
    -1,            /* nDims */
    19,            /* lineNo */
    9,             /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    27,            /* lineNo */
    29,            /* colNo */
    "",            /* aName */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    27,            /* lineNo */
    43,            /* colNo */
    "",            /* aName */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    19,            /* lineNo */
    19,            /* colNo */
    "",            /* aName */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    35,            /* lineNo */
    21,            /* colNo */
    "",            /* aName */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    36,            /* lineNo */
    17,            /* colNo */
    "",            /* aName */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    33,            /* lineNo */
    16,            /* colNo */
    "",            /* aName */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    28,            /* lineNo */
    37,            /* colNo */
    "",            /* aName */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m", /* pName */
    0                          /* checkKind */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    37,     /* lineNo */
    6,      /* colNo */
    "sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pName
                                                                         */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    38,     /* lineNo */
    5,      /* colNo */
    "sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pName
                                                                         */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    19,            /* lineNo */
    19,            /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    20,            /* lineNo */
    9,             /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    21,            /* lineNo */
    9,             /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    23,            /* lineNo */
    9,             /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    1,             /* lineNo */
    26,            /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    1,             /* lineNo */
    20,            /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    1,             /* lineNo */
    16,            /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    19,            /* lineNo */
    9,             /* colNo */
    "uniquetolcg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\fusion\\core\\fusion\\+fusion\\+"
    "internal\\uniquetolcg.m" /* pName */
};

/* Function Definitions */
void uniquetolcg(const emlrtStack *sp, const emxArray_real_T *in, real_T tol,
                 emxArray_real_T *out)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *iidx;
  emxArray_int32_T *sortid;
  emxArray_real_T *y;
  emxArray_uint32_T *ia;
  emxArray_uint32_T *ic;
  const real_T *in_data;
  real_T *out_data;
  real_T *y_data;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T count;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T *iidx_data;
  int32_T *sortid_data;
  uint32_T *ia_data;
  uint32_T *ic_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  in_data = in->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &dp_emlrtRSI;
  emxInit_real_T(&st, &y, &wb_emlrtRTEI, true);
  loop_ub = in->size[0];
  i = y->size[0];
  y->size[0] = in->size[0];
  emxEnsureCapacity_real_T(&st, y, i, &qb_emlrtRTEI);
  y_data = y->data;
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = in_data[i];
  }
  emxInit_int32_T(&st, &iidx, &ac_emlrtRTEI);
  b_st.site = &ep_emlrtRSI;
  sort(&b_st, y, iidx);
  iidx_data = iidx->data;
  y_data = y->data;
  emxInit_int32_T(&st, &sortid, &wb_emlrtRTEI);
  b_loop_ub = iidx->size[0];
  i = sortid->size[0];
  sortid->size[0] = iidx->size[0];
  emxEnsureCapacity_int32_T(&st, sortid, i, &rb_emlrtRTEI);
  sortid_data = sortid->data;
  for (i = 0; i < b_loop_ub; i++) {
    sortid_data[i] = iidx_data[i];
  }
  i = iidx->size[0];
  iidx->size[0] = b_loop_ub;
  emxEnsureCapacity_int32_T(sp, iidx, i, &sb_emlrtRTEI);
  iidx_data = iidx->data;
  for (i = 0; i < b_loop_ub; i++) {
    if ((sortid_data[i] < 1) || (sortid_data[i] > b_loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(sortid_data[i], 1, b_loop_ub, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    iidx_data[i] = sortid_data[i];
  }
  k = iidx->size[0];
  if (iidx->size[0] != in->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(iidx->size[0], in->size[0], &emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  for (i = 0; i < k; i++) {
    sortid_data[iidx_data[i] - 1] = i + 1;
  }
  emxFree_int32_T(sp, &iidx);
  i = out->size[0];
  out->size[0] = 1;
  emxEnsureCapacity_real_T(sp, out, i, &tb_emlrtRTEI);
  out_data = out->data;
  out_data[0] = y_data[0];
  emxInit_uint32_T(sp, &ic, &xb_emlrtRTEI);
  i = ic->size[0];
  ic->size[0] = in->size[0];
  emxEnsureCapacity_uint32_T(sp, ic, i, &ub_emlrtRTEI);
  ic_data = ic->data;
  for (i = 0; i < loop_ub; i++) {
    ic_data[i] = 0U;
  }
  emxInit_uint32_T(sp, &ia, &yb_emlrtRTEI);
  i = ia->size[0];
  ia->size[0] = 1;
  emxEnsureCapacity_uint32_T(sp, ia, i, &vb_emlrtRTEI);
  ia_data = ia->data;
  ia_data[0] = 1U;
  k = 0;
  count = 1;
  for (b_i = 0; b_i <= loop_ub - 2; b_i++) {
    if (k + 1 > y->size[0]) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, y->size[0], &o_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (b_i + 2 > y->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, y->size[0], &p_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (muDoubleScalarAbs(y_data[k] - y_data[b_i + 1]) > tol) {
      i = out->size[0];
      k = out->size[0];
      out->size[0]++;
      emxEnsureCapacity_real_T(sp, out, k, &wb_emlrtRTEI);
      out_data = out->data;
      if (b_i + 2 > y->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, y->size[0], &u_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      out_data[i] = y_data[b_i + 1];
      i = ia->size[0];
      count = ia->size[0] + 1;
      k = ia->size[0];
      ia->size[0]++;
      emxEnsureCapacity_uint32_T(sp, ia, k, &wb_emlrtRTEI);
      ia_data = ia->data;
      ia_data[i] = (uint32_T)(b_i + 2);
      k = b_i + 1;
    }
    if (b_i + 2 > ic->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ic->size[0], &t_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    ic_data[b_i + 1] = (uint32_T)count;
  }
  emxFree_real_T(sp, &y);
  loop_ub = ia->size[0];
  for (i = 0; i < loop_ub; i++) {
    k = (int32_T)ia_data[i];
    if ((k < 1) || (k > b_loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, b_loop_ub, &r_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
  }
  emxFree_uint32_T(sp, &ia);
  for (i = 0; i < b_loop_ub; i++) {
    k = sortid_data[i];
    if ((k < 1) || (k > ic->size[0])) {
      emlrtDynamicBoundsCheckR2012b(k, 1, ic->size[0], &s_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
  }
  emxFree_uint32_T(sp, &ic);
  emxFree_int32_T(sp, &sortid);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (uniquetolcg.c) */
