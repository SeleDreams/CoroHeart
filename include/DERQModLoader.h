#ifndef DERQMODLOADER_H
#define DERQMODLOADER_H
#include <Windows.h>

enum LoggingLevels {
    Infos,
    Warning,
    Error
};

class DERQModLoader
{
    public:
        static HMODULE ProcessAddress;
        static int Init();
        static void InitConsole();
        static void CloseConsole();
    protected:
        static void Start();
    private:
};
#endif // DEATHENDREQUESTMODDINGHOOK_H
