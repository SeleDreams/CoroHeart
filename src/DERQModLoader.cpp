#include "DERQModLoader.h"
#include "CMDWrapper.h"
#include <windows.h>
#include <iostream>
using namespace std;
DERQModLoader DERQModLoader::Instance;
int DERQModLoader::Init(){
    CMDWrapper::RedirectIOToConsole();
    Instance.ProcessAddress = (void*)GetModuleHandle("Application.exe");
    Instance.Start();
    return 0;
}

void DERQModLoader::Start(){
    cout << "Hook successfully initialized !" << endl;
    cout << "Module Application.exe started at the address " << ProcessAddress << endl;
    const char *thestring = (char*)(ProcessAddress + 0xC107C0);
    cout << thestring << endl;
    int *resW = (int*)(ProcessAddress + 0x132B048);
    int *resH = (int*)(ProcessAddress + 0x13193E8);
    *resW = 100;
    cout << "res w is " << *resW << endl;

    while(!MustStop ){
    }
}
