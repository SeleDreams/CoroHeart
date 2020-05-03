#include <windows.h>
#include <coroheart.h>
#include "D3D11Proxy.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			int proxyResult = D3D11Proxy_Init();
			if (proxyResult == EXIT_FAILURE) {
				return FALSE;
			}
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)COROH_Init, 0, 0, 0);
		}
		break;
		case DLL_PROCESS_DETACH:
			D3D11Proxy_Free();
			break;
		}
	return TRUE;
}