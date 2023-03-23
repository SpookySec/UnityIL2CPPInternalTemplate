// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "../hdr/hook.hpp"

void HackThread(){
    //something
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        const HANDLE hThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HackThread, hModule, NULL, NULL);
        if (hThread)
            CloseHandle(hThread);
    }

    return TRUE;
}