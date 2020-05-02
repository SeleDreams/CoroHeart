#include "D3D11Proxy.h"
#include <d3d11.h>
#include <Windows.h>

HRESULT(*D3D11Proxy::D3D11CreateDeviceAndSwapChainFunction)(IDXGIAdapter*, D3D_DRIVER_TYPE, HMODULE, UINT, const D3D_FEATURE_LEVEL*, UINT, UINT, const DXGI_SWAP_CHAIN_DESC*, IDXGISwapChain**, ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext**);

D3D11Proxy::D3D11Proxy()
{
	char dllPath[MAX_PATH];
	GetSystemDirectoryA(dllPath, MAX_PATH);
	const char* dllName = "\\d3d11.dll";
	size_t str1Length = strlen(dllPath);
	size_t str2length = strlen(dllName);
	size_t size = (str1Length + str2length + 1) * sizeof(char);
	strcat_s(dllPath, size, dllName);
	d3d11Module = LoadLibraryA(dllPath);
	if (!d3d11Module)
		return;
	D3D11CreateDeviceAndSwapChainFunction = (HRESULT(*)(IDXGIAdapter*, D3D_DRIVER_TYPE, HMODULE, UINT, const D3D_FEATURE_LEVEL*, UINT, UINT, const DXGI_SWAP_CHAIN_DESC*, IDXGISwapChain**, ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext**))GetProcAddress(d3d11Module, "D3D11CreateDeviceAndSwapChain");
}

D3D11Proxy::~D3D11Proxy(){
	if (d3d11Module) {
		FreeModule(d3d11Module);
	}
}

HRESULT Custom_D3D11CreateDeviceAndSwapChain(
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
	int result = D3D11Proxy::D3D11CreateDeviceAndSwapChainFunction(
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
	return result;
}