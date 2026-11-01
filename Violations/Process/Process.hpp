#pragma once

#include <Windows.h>
#include <TlHelp32.h>

DWORD pid;
HANDLE pHandle;

template<typename T>
T Read(uintptr_t address) {
    T buffer{};
    ReadProcessMemory(pHandle, (LPCVOID)address, &buffer, sizeof(T), nullptr);

    return buffer;
}

__forceinline DWORD GetPIDByName(const char* processName) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
        return 0;

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(pe);

    if (Process32First(snapshot, &pe)) {
        do {
            if (_stricmp(pe.szExeFile, processName) == 0)
                return pe.th32ProcessID;
        } while (Process32Next(snapshot, &pe));
    }

    CloseHandle(snapshot);
    return 0;
}

__forceinline uintptr_t GetModuleBase(const char* moduleName) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
    if (snapshot == INVALID_HANDLE_VALUE)
        return 0;

    MODULEENTRY32 me;
    me.dwSize = sizeof(me);
    if (Module32First(snapshot, &me)) {
        do {
            if (_stricmp(me.szModule, moduleName) == 0)
                return (uintptr_t)me.modBaseAddr;
        } while (Module32Next(snapshot, &me));
    }

    CloseHandle(snapshot);
    return 0;
}