// CoRayLibMatrix.h
//

#ifndef _CORAYLIBMATRIX_H
#define _CORAYLIBMATRIX_H

#include "CoRayLib_h.h"


class CoRayLibMatrix : IRayLibMatrix
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    float m_m0;
    float m_m1;
    float m_m2;
    float m_m3;
    float m_m4;
    float m_m5;
    float m_m6;
    float m_m7;
    float m_m8;
    float m_m9;
    float m_m10;
    float m_m11;
    float m_m12;
    float m_m13;
    float m_m14;
    float m_m15;

public:
    CoRayLibMatrix(HMODULE hModule);
    ~CoRayLibMatrix();

    // IUnknown
    STDMETHODIMP QueryInterface(
        REFIID riid,
        void** ppvObject
    ) override;
    STDMETHODIMP_(ULONG) AddRef(
        void
    ) override;
    STDMETHODIMP_(ULONG) Release(
        void
    ) override;

    // IDispatch
    STDMETHODIMP GetTypeInfoCount(
        UINT* pctinfo
    ) override;
    STDMETHODIMP GetTypeInfo(
        UINT iTInfo,
        LCID lcid,
        ITypeInfo** ppTInfo
    ) override;
    STDMETHODIMP GetIDsOfNames(
        REFIID riid,
        LPOLESTR* rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID* rgDispId
    ) override;
    STDMETHODIMP Invoke(
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS* pDispParams,
        VARIANT* pVarResult,
        EXCEPINFO* pExcepInfo,
        UINT* puArgErr
    ) override;

    // IRayLibMatrix
    STDMETHODIMP get_m0(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m0(
        float val
    ) override;
    STDMETHODIMP get_m1(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m1(
        float val
    ) override;
    STDMETHODIMP get_m2(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m2(
        float val
    ) override;
    STDMETHODIMP get_m3(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m3(
        float val
    ) override;
    STDMETHODIMP get_m4(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m4(
        float val
    ) override;
    STDMETHODIMP get_m5(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m5(
        float val
    ) override;
    STDMETHODIMP get_m6(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m6(
        float val
    ) override;
    STDMETHODIMP get_m7(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m7(
        float val
    ) override;
    STDMETHODIMP get_m8(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m8(
        float val
    ) override;
    STDMETHODIMP get_m9(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m9(
        float val
    ) override;
    STDMETHODIMP get_m10(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m10(
        float val
    ) override;
    STDMETHODIMP get_m11(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m11(
        float val
    ) override;
    STDMETHODIMP get_m12(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m12(
        float val
    ) override;
    STDMETHODIMP get_m13(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m13(
        float val
    ) override;
    STDMETHODIMP get_m14(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m14(
        float val
    ) override;
    STDMETHODIMP get_m15(
        float* pRetVal
    ) override;
    STDMETHODIMP put_m15(
        float val
    ) override;
};

#endif // _CORAYLIBMATRIX_H
