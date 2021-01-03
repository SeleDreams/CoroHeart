#ifndef COROHEART_LOGGING_H
#define COROHEART_LOGGING_H
#include <Windows.h>
#include "offsets.h"
#include "../Dependencies/Detours/include/detours.h"

enum {
	Info,
	Warning,
	Error
} typedef LoggingLevel;

void COROH_InitGameLogging();
void COROH_StopGameLogging();
void COROH_InitConsole();
void COROH_CloseConsole();
void COROH_Log(LoggingLevel loggingLevel, const char* msg, ...);

void COROH_LogInfo(const char* msg);
void COROH_LogWarning(const char* msg);
void COROH_LogError(const char* msg);

// Defines the minimum logging level to display on screen, by default it would log everything but you can hide the messages depending on their level
static LoggingLevel LogLevel;


#endif