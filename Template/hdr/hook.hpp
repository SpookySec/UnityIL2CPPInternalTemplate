#pragma once
#include <Windows.h>
#include <vector>
#include <MinHook.h>
#include <string>

#define PTRCAST(t, a) reinterpret_cast<t>(a)

namespace Hooks
{
    class Hook {
    public:
        std::string name;
        uintptr_t fAddress;
        uintptr_t hkAddress;
        uintptr_t oAddress;
        bool enabled;
        bool created;

        Hook();
        Hook(std::string _name, uintptr_t _fAddress, uintptr_t _hkAddress, uintptr_t _oAddress);
        bool Enable();
        bool Disable();
    };

    class HooksManager {
    public:
        std::vector<Hook*> gHooks;
        bool Add(std::string _name, uintptr_t _fAddress, uintptr_t _hkAddress, uintptr_t _oAddress);
        Hook* Search(char* name);
        bool EnableByName(char* name);
        bool DisableByName(char* name);
        bool EnableAll();
        bool DisableAll();
    };
}