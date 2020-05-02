#include "DERQModLoader.h"
#include "CMDWrapper.h"
#include <windows.h>
#include <iostream>
#include <dxgi.h>
#include <d3d11.h>
#include "detours.h"
#include <string>
#include <sstream>
using namespace std;
HMODULE DERQModLoader::ProcessAddress;

int DERQModLoader::Init() {
	ProcessAddress = GetModuleHandleA("Application.exe");
	InitConsole();
	Start();
	return 0;
}

void DERQModLoader::InitConsole() {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	ios::sync_with_stdio();
}

void DERQModLoader::CloseConsole() {
	FreeConsole();
}

void LogInfo(string message) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0x000F);
	cout << "Info : " << message << endl;
}

void LogWarning(string message) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0x000E);
	cout << "Warning : " << message << endl;
}

void LogError(string message) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0x0004);
	cout << "Error : " << message << endl;
}
void Logger(LoggingLevels logLevel, const char* message, ...) {
	va_list args;
	char buffer[255];
	va_start(args, message);
	int rc = vsprintf_s(buffer, message, args);
	string endMessage = buffer;
	switch (logLevel) {
	case LoggingLevels::Infos:
		LogInfo(endMessage);
		break;
	case LoggingLevels::Warning:
		LogWarning(endMessage);
		break;
	case LoggingLevels::Error:
		LogError(endMessage);
		break;
	default:
		LogInfo(endMessage);
		LogWarning("This log level is not defined !");
		break;
	}
}

void StringLogger(LoggingLevels logLevel, string message) {
	Logger(logLevel, message.c_str());
}

void DERQModLoader::Start() {

	std::stringstream stream;
	stream << "0x" << std::hex << ProcessAddress;
	StringLogger(LoggingLevels::Infos, string("Module Application.exe started at the address ") + stream.str() + string("\n"));
	//const char *thestring = (char*)(ProcessAddress + 0xC107C0);
	const long long address = (long long)ProcessAddress + 0x4BBFF0;
	void(*LogError)(unsigned int errorCode, const char* message);
	LogError = (void(*)(unsigned int, const char*))(address);
	DetourTransactionBegin();
	DetourAttach((PVOID*)&address, &Logger);
	DetourTransactionCommit();

	//cout << thestring << endl;
  /*  int *resW = (int*)(ProcessAddress + 0x132B048);
	int *resH = (int*)(ProcessAddress + 0x13193E8);*/
	/*resW = 100;
	cout << "res w is " << *resW << endl;*/
}
