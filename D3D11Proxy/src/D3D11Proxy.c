#include "D3D11Proxy.h"
#include <d3d11.h>
#include <windows.h>
#include <coroheart.h>
#include <stdio.h>

int D3D11Proxy_Init()
{
	char dllPath[MAX_PATH];
	GetSystemDirectoryA(dllPath, MAX_PATH);
	const char* dllName = "\\d3d11.dll";
	size_t str1Length = strlen(dllPath);
	size_t str2length = strlen(dllName);
	size_t size = (str1Length + str2length + 1) * sizeof(char);
	strcat_s(dllPath, size, dllName);
	D3D11Proxy_D3D11_Library = LoadLibraryA(dllPath);
	if (!D3D11Proxy_D3D11_Library)
		return EXIT_FAILURE;
	D3D11Proxy_D3D11CreateDeviceAndSwapChainCallback = (HRESULT(*)(IDXGIAdapter*, D3D_DRIVER_TYPE, HMODULE, UINT, const D3D_FEATURE_LEVEL*, UINT, UINT, const DXGI_SWAP_CHAIN_DESC*, IDXGISwapChain**, ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext**))GetProcAddress(D3D11Proxy_D3D11_Library, "D3D11CreateDeviceAndSwapChain");
	return EXIT_SUCCESS;
}

void D3D11Proxy_Free()
{
	if (D3D11Proxy_D3D11_Library) {
		FreeLibrary(D3D11Proxy_D3D11_Library);
	}
}

HRESULT D3D11Proxy_D3D11CreateDeviceAndSwapChain(
	IDXGIAdapter* pAdapter,
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
	ID3D11DeviceContext** ppImmediateContext)
{
	int result = D3D11Proxy_D3D11CreateDeviceAndSwapChainCallback(
		pAdapter,
		driverType,
		software,
		flags,
		pFeatureLevels,
		FeatureLevels,
		sdkVersion,
		pSwapChainDesc,
		ppSwapChain,
		ppDevice,
		pFeatureLevel,
		ppImmediateContext);
	COROH_InitDX11(pAdapter, driverType, software, flags, pFeatureLevels, FeatureLevels, sdkVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext);
	return result;
}