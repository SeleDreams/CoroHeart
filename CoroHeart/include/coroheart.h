#ifndef COROHEART_H
#define COROHEART_H
#include <Windows.h>
#include <d3d11.h>

struct {
	D3D_DRIVER_TYPE   driverType;
	HMODULE software;
	UINT flags;
	const D3D_FEATURE_LEVEL* pFeatureLevels;
	UINT FeatureLevels;
	UINT sdkVersion;
	const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc;
	IDXGISwapChain** ppSwapChain;
	ID3D11Device** ppDevice;
	D3D_FEATURE_LEVEL* pFeatureLevel;
	ID3D11DeviceContext** ppImmediateContext;
} typedef COROH_DX11;

__declspec(dllexport) int COROH_Init();
_declspec(dllexport) void COROH_InitDX11(IDXGIAdapter* pAdapter,
	D3D_DRIVER_TYPE   driverType,
	HMODULE software,
	UINT flags,
	const D3D_FEATURE_LEVEL* pFeatureLevels,
	UINT FeatureLevels,
	UINT sdkVersion,
	const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
	IDXGISwapChain** ppSwapChain,
	ID3D11Device** ppDevice,
	D3D_FEATURE_LEVEL* pFeatureLevel,
	ID3D11DeviceContext** ppImmediateContext);
#endif // DEATHENDREQUESTMODDINGHOOK_H
