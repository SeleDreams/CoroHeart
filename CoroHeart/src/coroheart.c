#include "offsets.h"
#include "coroheart.h"
#include <windows.h>
#include <stdlib.h>
#include <logging.h>
#include <inttypes.h>
#include <d3d11.h>

int COROH_Init() {
	COROH_InitConsole();
	COROH_InitGameLogging();
	COROH_Log(Info, "Module %s started at the address 0x%12" PRIxPTR, GAME_EXECUTABLE_NAME, (uintptr_t)GetModuleHandleA(GAME_EXECUTABLE_NAME));
	return EXIT_SUCCESS;
}

void COROH_InitDX11(IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE driverType, HMODULE software, UINT flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT sdkVersion, const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc, IDXGISwapChain** ppSwapChain, ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext)
{
	//TODO
}
