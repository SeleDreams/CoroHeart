#pragma once
#include <Windows.h>
#include <d3d11.h>

class D3D11Proxy {
public:
	D3D11Proxy();
	~D3D11Proxy();
	static HRESULT(*D3D11CreateDeviceAndSwapChainFunction)(IDXGIAdapter*, D3D_DRIVER_TYPE, HMODULE, UINT, const D3D_FEATURE_LEVEL*, UINT, UINT, const DXGI_SWAP_CHAIN_DESC*, IDXGISwapChain**, ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext**);
private:
	HMODULE d3d11Module;
};


extern "C" {
	HRESULT _stdcall Custom_D3D11CreateDeviceAndSwapChain(
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
		ID3D11DeviceContext** ppImmediateContext);
}

