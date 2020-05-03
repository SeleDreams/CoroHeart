#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "detours.h"
#include "logging.h"
#include "offsets.h"

void COROH_InitConsole() {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
}

void COROH_CloseConsole() {
	FreeConsole();
}

void COROH_LogInfo(const char* msg) {
	if (LogLevel <= Info) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 0x000F);
		char buffer[255];
		sprintf(buffer,"Info : %s\n", msg);
		printf(buffer);
	}
}

void COROH_LogWarning(const char* msg) {
	if (LogLevel <= Warning) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 0x000E);
		char buffer[255];
		sprintf(buffer, "Warning : %s\n", msg);
		printf(buffer);
	}
}

void COROH_LogError(const char* msg) {
	if (LogLevel <= Error) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 0x0004);
		char buffer[255];
		sprintf(buffer, "Error : %s\n", msg);
		printf(buffer);
	}
}

void COROH_Log(LoggingLevel logLevel, const char* message, ...) {

	va_list args;
	char buffer[255];
	va_start(args, message);

	int rc = vsprintf_s(buffer,255, message, args);
	switch (logLevel) {
	case Info:
		COROH_LogInfo(buffer);
		break;
	case Warning:
		COROH_LogWarning(buffer);
		break;
	case Error:
		COROH_LogError(buffer);
		break;
	default:
		COROH_LogInfo(buffer);
		memset(buffer, 0, 255);
		const char* errorMessage = "The log level %d is not defined !";
		va_start(args, errorMessage);
		vsprintf_s(buffer,255, errorMessage, args);
		COROH_LogWarning(buffer);
		break;
	}
}

void COROH_InitGameLogging() {
	HMODULE ProcessAddress = GetModuleHandleA(GAME_EXECUTABLE_NAME);
	const long long address = (long long)ProcessAddress + GAME_LOG_FUNCTION_OFFSET;
	DetourTransactionBegin();
	DetourAttach((PVOID*)&address, &COROH_Log);
	DetourTransactionCommit();
}

void COROH_StopGameLogging() {
	HMODULE ProcessAddress = GetModuleHandleA(GAME_EXECUTABLE_NAME);
	const long long address = (long long)ProcessAddress + GAME_LOG_FUNCTION_OFFSET;
	DetourTransactionBegin();
	DetourDetach((PVOID*)&address, &COROH_Log);
	DetourTransactionCommit();
}