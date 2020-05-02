#include <windows.h>
#include <thread>
#include "DERQModLoader.h"
#include "D3D11Proxy.h"

D3D11Proxy* proxy = nullptr;
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		if (!proxy) {
			proxy = new D3D11Proxy();
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DERQModLoader::Init, 0, 0, 0);
		}
		break;
	case DLL_PROCESS_DETACH:
		// detach from process
		if (proxy)
			delete proxy;
		break;
	}
	return TRUE; // successful
}