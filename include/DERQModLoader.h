#ifndef DERQMODLOADER_H
#define DERQMODLOADER_H


class DERQModLoader
{
    public:
        void* ProcessAddress;
        static int Init();
        inline static bool MustStop;
        static DERQModLoader Instance;
    protected:
        void Start();
    private:
};
#endif // DEATHENDREQUESTMODDINGHOOK_H
