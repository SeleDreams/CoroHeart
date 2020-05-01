#ifndef CMDWRAPPER_H
#define CMDWRAPPER_H
class CMDWrapper
{
    public:
        CMDWrapper();
        virtual ~CMDWrapper();
        static void RedirectIOToConsole();
    protected:
        static const int MAX_CONSOLE_LINES = 500;
};

#endif // CMDWRAPPER_H
