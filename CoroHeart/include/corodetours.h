#ifndef CORO_DETOURS_H
#define CORO_DETOURS_H
// TODO
int COROH_StartDetour(void* src, void* target,void *original);
int COROH_StopDetour(void* src, void* target, void* original);
#endif