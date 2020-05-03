#pragma once
#ifdef DEATH_END_REQUEST
#define GAME_EXECUTABLE_NAME "Application.exe"
#define GAME_LOG_FUNCTION_OFFSET 0x4BBFF0
#elif NEPTUNIA_VIIR
#define GAME_EXECUTABLE_NAME "v2r.exe"
#define GAME_LOG_FUNCTION_OFFSET 0x56E410
#else
#error No game was defined, this is required !
#endif