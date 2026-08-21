// DllMain.cpp
//

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Objbase.h>
#include <stdio.h>
#include <new>
#include "TClassFactory.h"
#include "CoRayLib_h.h"
#include "CoRayLib.h"
#include "CoRayLibColor.h"
#include "CoRayLibVector2.h"
#include "CoRayLibVector3.h"
#include "CoRayLibVector4.h"
#include "CoRayLibRectangle.h"
#include "CoRayLibTexture.h"
#include "CoRayLibRenderTexture.h"
#include "CoRayLibMatrix.h"
#include "CoRayLibCamera2D.h"
#include "CoRayLibCamera3D.h"
#include "CoRayLibRay.h"
#include "CoRayLibBoundingBox.h"
#include "reghelper.h"


static HINSTANCE g_hModule = NULL;
static LONG g_cComponents = 0;
static LONG g_cServerLocks = 0;


BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD     fdwReason,
	LPVOID    lpvReserved
)
{
    if (fdwReason == DLL_PROCESS_ATTACH) {
        g_hModule = hinstDLL;
        DisableThreadLibraryCalls(hinstDLL);
    }
    return TRUE;
}

typedef struct tagClassItem {
    LPCWSTR progId;
    LPCWSTR friendlyName;
    CLSID clsid;
} ClassItem;

ClassItem classes[] = {
    { L"RayLib",                 L"RayLib Class",                 CLSID_RayLib            },
    { L"RayLib.Color",           L"RayLib.Color Class",           CLSID_RayLibColor       },
    { L"RayLib.Vector2",         L"RayLib.Vector2 Class",         CLSID_RayLibVector2     },
    { L"RayLib.Vector3",         L"RayLib.Vector3 Class",         CLSID_RayLibVector3     },
    { L"RayLib.Vector4",         L"RayLib.Vector4 Class",         CLSID_RayLibVector4     },
    { L"RayLib.Quaternion",      L"RayLib.Quaternion Class",      CLSID_RayLibQuaternion  },
    { L"RayLib.Rectangle",       L"RayLib.Rectangle Class",       CLSID_RayLibRectangle   },
    { L"RayLib.Texture",         L"RayLib.Texture Class",         CLSID_RayLibTexture     },
    { L"RayLib.Texture2D",       L"RayLib.Texture2D Class",       CLSID_RayLibTexture2D   },
    { L"RayLib.RenderTexture",   L"RayLib.RenderTexture Class",   CLSID_RayLibTexture     },
    { L"RayLib.RenderTexture2D", L"RayLib.RenderTexture2D Class", CLSID_RayLibTexture     },
    { L"RayLib.Matrix",          L"RayLib.Matrix Class",          CLSID_RayLibMatrix      },
    { L"RayLib.Camera2D",        L"RayLib.Camera2D Class",        CLSID_RayLibCamera2D    },
    { L"RayLib.Camera3D",        L"RayLib.Camera3D Class",        CLSID_RayLibCamera3D    },
    { L"RayLib.Camera",          L"RayLib.Camera Class",          CLSID_RayLibCamera      },
    { L"RayLib.Ray",             L"RayLib.Ray Class",             CLSID_RayLibRay         },
    { L"RayLib.BoundingBox",     L"RayLib.BoundingBox Class",     CLSID_RayLibBoundingBox },
};

STDAPI DllGetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv
)
{
    if (!ppv)
        return E_POINTER;

    *ppv = NULL;

    IClassFactory* pFactory = NULL;

    if (rclsid == CLSID_RayLib) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLib>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibColor) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibColor>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibVector2) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibVector2>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibVector3) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibVector3>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibVector4) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibVector4>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibQuaternion) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibVector4>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibRectangle) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibRectangle>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibTexture) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibTexture>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibTexture2D) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibTexture>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibRenderTexture) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibRenderTexture>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibRenderTexture2D) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibRenderTexture>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibMatrix) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibMatrix>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibCamera2D) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibCamera2D>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibCamera3D) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibCamera3D>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibCamera) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibCamera3D>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibRay) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibRay>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else if (rclsid == CLSID_RayLibBoundingBox) {
        pFactory = new (std::nothrow) TClassFactory<CoRayLibBoundingBox>(g_hModule, &g_cComponents, &g_cServerLocks);
    }
    else {
        return CLASS_E_CLASSNOTAVAILABLE;
    }
    if (!pFactory)
        return E_OUTOFMEMORY;

    const HRESULT hr = pFactory->QueryInterface(riid, ppv);
    pFactory->Release();
    return hr;
}

STDAPI DllCanUnloadNow(void)
{
    return (g_cComponents == 0 && g_cServerLocks == 0) ? S_OK : S_FALSE;
}

STDAPI DllRegisterServer(void)
{
    HRESULT hr = S_OK;

    for (size_t i = 0; (i < (sizeof(classes) / sizeof(classes[0]))) && SUCCEEDED(hr); ++i) {
        hr = DllRegisterClass(
            g_hModule,
            classes[i].clsid,
            classes[i].progId,
            classes[i].friendlyName,
            L"Apartment"
        );
    }

    return hr;
}

STDAPI DllUnregisterServer(void)
{
    HRESULT hr = S_OK;

    for (size_t i = 0; (i < (sizeof(classes) / sizeof(classes[0]))) && SUCCEEDED(hr); ++i) {
        hr = DllUnregisterClass(
            classes[i].clsid,
            classes[i].progId
        );
    }

    return hr;
}
