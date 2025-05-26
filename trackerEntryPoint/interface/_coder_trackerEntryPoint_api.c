/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_trackerEntryPoint_api.c
 *
 * Code generation for function '_coder_trackerEntryPoint_api'
 *
 */

/* Include files */
#include "_coder_trackerEntryPoint_api.h"
#include "rt_nonfinite.h"
#include "trackerEntryPoint.h"
#include "trackerEntryPoint_data.h"
#include "trackerEntryPoint_emxutil.h"
#include "trackerEntryPoint_types.h"

/* Variable Definitions */
static emlrtRTEInfo bc_emlrtRTEI = {
    1,                              /* lineNo */
    1,                              /* colNo */
    "_coder_trackerEntryPoint_api", /* fName */
    ""                              /* pName */
};

static const char_T *sv[2] = {"Time", "BoundingBox"};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4]);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, struct0_T *y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_struct4_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct1_T *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct2_T *y);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct2_T *y);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[16]);

static struct3_T m_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier);

static struct3_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[4]);

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9]);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[16]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[11] = {"Time",
                                         "Azimuth",
                                         "Elevation",
                                         "Range",
                                         "RangeRate",
                                         "AzimuthAccuracy",
                                         "ElevationAccuracy",
                                         "RangeAccuracy",
                                         "RangeRateAccuracy",
                                         "EgoSpeed",
                                         "EgoAngularVelocity"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 11,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "Time";
  c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "Time")),
      &thisId);
  thisId.fIdentifier = "Azimuth";
  d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "Azimuth")),
      &thisId, y->Azimuth);
  thisId.fIdentifier = "Elevation";
  d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "Elevation")),
      &thisId, y->Elevation);
  thisId.fIdentifier = "Range";
  d_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "Range")),
      &thisId, y->Range);
  thisId.fIdentifier = "RangeRate";
  d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "RangeRate")),
      &thisId, y->RangeRate);
  thisId.fIdentifier = "AzimuthAccuracy";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5,
                                                    "AzimuthAccuracy")),
                     &thisId, y->AzimuthAccuracy);
  thisId.fIdentifier = "ElevationAccuracy";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6,
                                                    "ElevationAccuracy")),
                     &thisId, y->ElevationAccuracy);
  thisId.fIdentifier = "RangeAccuracy";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7,
                                                    "RangeAccuracy")),
                     &thisId, y->RangeAccuracy);
  thisId.fIdentifier = "RangeRateAccuracy";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 8,
                                                    "RangeRateAccuracy")),
                     &thisId, y->RangeRateAccuracy);
  thisId.fIdentifier = "EgoSpeed";
  y->EgoSpeed = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 9, "EgoSpeed")),
      &thisId);
  thisId.fIdentifier = "EgoAngularVelocity";
  f_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 10,
                                                    "EgoAngularVelocity")),
                     &thisId, y->EgoAngularVelocity);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_struct4_T *u)
{
  static const int32_T b_iv[2] = {10, 10};
  static const int32_T iv1[2] = {1, 2};
  static const int32_T iv2[2] = {1, 10};
  static const int32_T b_i = 10;
  static const char_T *b_sv[16] = {"TrackID",
                                   "BranchID",
                                   "SourceIndex",
                                   "UpdateTime",
                                   "Age",
                                   "State",
                                   "StateCovariance",
                                   "StateParameters",
                                   "ObjectClassID",
                                   "ObjectClassProbabilities",
                                   "TrackLogic",
                                   "TrackLogicState",
                                   "IsConfirmed",
                                   "IsCoasted",
                                   "IsSelfReported",
                                   "ObjectAttributes"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *y;
  const struct4_T *u_data;
  real_T *pData;
  int32_T b_j0;
  int32_T c_i;
  int32_T d_i;
  int32_T i;
  u_data = u->data;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructArray(1, &u->size[0], 16,
                                         (const char_T **)&b_sv[0]));
  emlrtCreateField(y, "TrackID");
  emlrtCreateField(y, "BranchID");
  emlrtCreateField(y, "SourceIndex");
  emlrtCreateField(y, "UpdateTime");
  emlrtCreateField(y, "Age");
  emlrtCreateField(y, "State");
  emlrtCreateField(y, "StateCovariance");
  emlrtCreateField(y, "StateParameters");
  emlrtCreateField(y, "ObjectClassID");
  emlrtCreateField(y, "ObjectClassProbabilities");
  emlrtCreateField(y, "TrackLogic");
  emlrtCreateField(y, "TrackLogicState");
  emlrtCreateField(y, "IsConfirmed");
  emlrtCreateField(y, "IsCoasted");
  emlrtCreateField(y, "IsSelfReported");
  emlrtCreateField(y, "ObjectAttributes");
  i = 0;
  for (b_j0 = 0; b_j0 < u->size[0U]; b_j0++) {
    int32_T i1;
    b_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j0].TrackID;
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, "TrackID", b_y, 0);
    c_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j0].BranchID;
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, "BranchID", c_y, 1);
    d_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j0].SourceIndex;
    emlrtAssign(&d_y, m);
    emlrtSetFieldR2017b(y, i, "SourceIndex", d_y, 2);
    e_y = NULL;
    m = emlrtCreateDoubleScalar(u_data[b_j0].UpdateTime);
    emlrtAssign(&e_y, m);
    emlrtSetFieldR2017b(y, i, "UpdateTime", e_y, 3);
    f_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j0].Age;
    emlrtAssign(&f_y, m);
    emlrtSetFieldR2017b(y, i, "Age", f_y, 4);
    g_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&b_i, mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    for (c_i = 0; c_i < 10; c_i++) {
      pData[c_i] = u_data[b_j0].State[c_i];
    }
    emlrtAssign(&g_y, m);
    emlrtSetFieldR2017b(y, i, "State", g_y, 5);
    h_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (c_i = 0; c_i < 10; c_i++) {
      for (d_i = 0; d_i < 10; d_i++) {
        pData[i1 + d_i] = u_data[b_j0].StateCovariance[d_i + 10 * c_i];
      }
      i1 += 10;
    }
    emlrtAssign(&h_y, m);
    emlrtSetFieldR2017b(y, i, "StateCovariance", h_y, 6);
    i_y = NULL;
    emlrtAssign(&i_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
    emlrtSetFieldR2017b(y, i, "StateParameters", i_y, 7);
    j_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)emlrtMxGetData(m) = u_data[b_j0].ObjectClassID;
    emlrtAssign(&j_y, m);
    emlrtSetFieldR2017b(y, i, "ObjectClassID", j_y, 8);
    k_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    pData[0] = u_data[b_j0].ObjectClassProbabilities[0];
    pData[1] = u_data[b_j0].ObjectClassProbabilities[1];
    emlrtAssign(&k_y, m);
    emlrtSetFieldR2017b(y, i, "ObjectClassProbabilities", k_y, 9);
    l_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 10, m,
                             &u_data[b_j0].TrackLogic[0]);
    emlrtAssign(&l_y, m);
    emlrtSetFieldR2017b(y, i, "TrackLogic", l_y, 10);
    m_y = NULL;
    m = emlrtCreateDoubleScalar(u_data[b_j0].TrackLogicState);
    emlrtAssign(&m_y, m);
    emlrtSetFieldR2017b(y, i, "TrackLogicState", m_y, 11);
    n_y = NULL;
    m = emlrtCreateLogicalScalar(u_data[b_j0].IsConfirmed);
    emlrtAssign(&n_y, m);
    emlrtSetFieldR2017b(y, i, "IsConfirmed", n_y, 12);
    o_y = NULL;
    m = emlrtCreateLogicalScalar(u_data[b_j0].IsCoasted);
    emlrtAssign(&o_y, m);
    emlrtSetFieldR2017b(y, i, "IsCoasted", o_y, 13);
    p_y = NULL;
    m = emlrtCreateLogicalScalar(u_data[b_j0].IsSelfReported);
    emlrtAssign(&p_y, m);
    emlrtSetFieldR2017b(y, i, "IsSelfReported", p_y, 14);
    q_y = NULL;
    emlrtAssign(&q_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
    emlrtSetFieldR2017b(y, i, "ObjectAttributes", q_y, 15);
    i++;
  }
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 2,
                         (const char_T **)&sv[0], 0U, (const void *)&dims);
  thisId.fIdentifier = "Time";
  c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "Time")),
      &thisId);
  thisId.fIdentifier = "BoundingBox";
  i_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1,
                                                    "BoundingBox")),
                     &thisId, y->BoundingBox);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  k_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct2_T *y)
{
  static const int32_T dims = 0;
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 2,
                         (const char_T **)&sv[0], 0U, (const void *)&dims);
  thisId.fIdentifier = "Time";
  c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "Time")),
      &thisId);
  thisId.fIdentifier = "BoundingBox";
  l_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1,
                                                    "BoundingBox")),
                     &thisId, y->BoundingBox);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[16])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static struct3_T m_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  struct3_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static struct3_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = {"Time", "EgoPositionalDisplacement",
                                        "EgoRotationalDisplacement"};
  emlrtMsgIdentifier thisId;
  struct3_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "Time";
  y.Time = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "Time")),
      &thisId);
  thisId.fIdentifier = "EgoPositionalDisplacement";
  f_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1,
                                     "EgoPositionalDisplacement")),
      &thisId, y.EgoPositionalDisplacement);
  thisId.fIdentifier = "EgoRotationalDisplacement";
  f_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2,
                                     "EgoRotationalDisplacement")),
      &thisId, y.EgoRotationalDisplacement);
  emlrtDestroyArray(&u);
  return y;
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = {1, 4};
  real_T(*r)[4];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[2] = {1, 3};
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = {3, 3};
  real_T(*r)[9];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[9])emlrtMxGetData(src);
  for (i = 0; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[16])
{
  static const int32_T dims[2] = {4, 4};
  real_T(*r)[16];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[16])emlrtMxGetData(src);
  for (i = 0; i < 16; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

void trackerEntryPoint_api(const mxArray *const prhs[4], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_struct4_T *tracks;
  struct0_T radarDet;
  struct1_T lidarDet;
  struct2_T cameraDet;
  struct3_T egoMotion;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "radarDet", &radarDet);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "lidarDet", &lidarDet);
  j_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "cameraDet", &cameraDet);
  egoMotion = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "egoMotion");
  /* Invoke the target function */
  emxInit_struct4_T(&st, &tracks, &bc_emlrtRTEI);
  trackerEntryPoint(&st, &radarDet, &lidarDet, &cameraDet, &egoMotion, tracks);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, tracks);
  emxFree_struct4_T(&st, &tracks);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_trackerEntryPoint_api.c) */
