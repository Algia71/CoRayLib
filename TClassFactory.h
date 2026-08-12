// TClassFactory.h
//

#ifndef _TCLASSFACTORY_H
#define _TCLASSFACTORY_H

#include <unknwn.h>


template<class CObjCls>
class TClassFactory : public IClassFactory
{
    LONG m_cRef;
    HMODULE m_hModule;
    LONG* m_pcComponents;
    LONG* m_pcServerLocks;

public:
    TClassFactory(
        HMODULE hModule,
        LONG* pcComponents,
        LONG* pcServerLocks
    )
    {
        m_cRef = 1;
        m_hModule = hModule;
        m_pcComponents = pcComponents;
        m_pcServerLocks = pcServerLocks;

        InterlockedIncrement(m_pcComponents);
    }
    ~TClassFactory()
    {
        InterlockedDecrement(m_pcComponents);
    }

    // IUnknown
    STDMETHODIMP QueryInterface(
        REFIID riid,
        void** ppvObject
    )
    {
        if (ppvObject == nullptr)
            return E_POINTER;

        if (riid == IID_IUnknown) {
            *ppvObject = static_cast<IClassFactory*>(this);
        }
        else if (riid == IID_IClassFactory) {
            *ppvObject = static_cast<IClassFactory*>(this);
        }
        else {
            *ppvObject = nullptr;
            return E_NOINTERFACE;
        }

        AddRef();
        return S_OK;
    }
    STDMETHODIMP_(ULONG) AddRef(
        void
    )
    {
        return InterlockedIncrement(&m_cRef);
    }
    STDMETHODIMP_(ULONG) Release(
        void
    )
    {
        const ULONG cRef = InterlockedDecrement(&m_cRef);
        if (cRef == 0)
            delete this;
        return cRef;
    }

    // IClassFactory
    STDMETHODIMP CreateInstance(
        IUnknown* pUnkOuter,
        REFIID riid,
        void** ppvObject
    )
    {
        if (!ppvObject)
            return E_POINTER;

        *ppvObject = NULL;

        if (pUnkOuter)
            return CLASS_E_NOAGGREGATION;

        CObjCls* pObj = new (std::nothrow) CObjCls(m_hModule);
        if (!pObj)
            return E_OUTOFMEMORY;

        const HRESULT hr = pObj->QueryInterface(riid, ppvObject);
        pObj->Release();
        return hr;
    }
    STDMETHODIMP LockServer(
        BOOL fLock
    )
    {
        if (fLock)
            InterlockedIncrement(m_pcServerLocks);
        else
            InterlockedDecrement(m_pcServerLocks);

        return S_OK;
    }
};

#endif // _TCLASSFACTORY_H
