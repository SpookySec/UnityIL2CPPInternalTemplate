#pragma once
#include "../hdr/hook.hpp"

namespace Hooks
{
    Hook::Hook()
    {
        name = "";
        fAddress = 0x0;
        hkAddress = 0x0;
        oAddress = 0x0;
        enabled = false;
        created = true;
    }

    Hook::Hook(std::string _name, uintptr_t _fAddress, uintptr_t _hkAddress, uintptr_t _oAddress)
    {
        name = _name;
        fAddress = _fAddress;
        hkAddress = _hkAddress;
        oAddress = _oAddress;
        created = true;
        MH_STATUS status;

        status = MH_CreateHook(PTRCAST(LPVOID*, fAddress), (LPVOID)&hkAddress, (LPVOID*)&oAddress);

        if (status != MH_OK)
            return;
    }

    bool Hook::Enable() {
        if (!enabled)
            return MH_EnableHook(PTRCAST(LPVOID, fAddress)) == MH_OK;

        return false;
    }

    bool Hook::Disable() {
        if (enabled)
            return MH_DisableHook(PTRCAST(LPVOID, fAddress)) == MH_OK;

        return false;
    }

    bool HooksManager::Add(std::string _name, uintptr_t _fAddress, uintptr_t _hkAddress, uintptr_t _oAddress)
    {
        Hook hook = Hook(_name, _fAddress, _hkAddress, _oAddress);

        if (!hook.created)
            return false;

        gHooks.push_back(&hook);
        return true;
    }

    bool HooksManager::Del(Hooks::Hook* hook)
    {
        if (!hook->created)
            return false;

        if (hook->enabled)
            hook->Disable();

        return MH_RemoveHook(PTRCAST(LPVOID, hook->hkAddress)) == MH_OK;
    }

    Hook* HooksManager::Search(char* name)
    {
        for (auto hook : gHooks)
            if (hook->name == name)
                return hook;

        return nullptr;
    }

    bool HooksManager::EnableByName(char* name) {
        Hooks::Hook* hook;
        hook = Search(name);

        if (hook && !hook->enabled)
        {
            hook->enabled = true;
            if (hook->Enable())
                return true;
        }

        return false;
    }

    bool HooksManager::DisableByName(char* name) {
        Hooks::Hook* hook;
        hook = Search(name);

        if (hook && !hook->enabled)
        {
            hook->enabled = false;
            if (hook->Enable())
                return true;
        }

        return false;
    }

    bool HooksManager::EnableAll() {
        for (auto hook : gHooks)
            if (!hook->enabled)
                if (hook->Enable())
                    return true;

        return false;
    }

    bool HooksManager::DisableAll() {
        for (auto hook : gHooks)
            if (hook->enabled)
                if (hook->Disable())
                    return true;

        return false;
    }
};