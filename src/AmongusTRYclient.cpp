#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <tchar.h>
#include <thread>
#include <stdio.h>
#include <cstdio>;
#include <cstring>
DWORD GetModuleBase(DWORD processId, const wchar_t* szModuleName)
{
    uintptr_t modBaseAddr = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);
    if (hSnap != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(hSnap, &modEntry)) {
            do {
                if (!_wcsicmp(modEntry.szModule, szModuleName)) {
                    modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                    break;
                }

            } while (Module32Next(hSnap, &modEntry));
        }
    }
    CloseHandle(hSnap);
    return modBaseAddr;
    
}
uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets) {
    uintptr_t addr = ptr;
    printf("Addr: %p\n", addr);
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(DWORD), 0);
        addr += offsets[i];
        printf("Addr: %p\n", addr);
    }
    return addr;
}
int main()
{
//get pid
HWND hwnd_AC = FindWindowA(NULL, "Among Us");
DWORD pID = NULL;
GetWindowThreadProcessId(hwnd_AC, &pID);

//get module base
uintptr_t moduleBase = GetModuleBase(pID, L"GameAssembly.dll");

//handle for reading read procces memory func
HANDLE hProcces = 0;
hProcces = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID);

//get dynmaicptr
uintptr_t dynamicptr = moduleBase + 0x0214D698;

//prepare offset adress
std::vector<unsigned int> speedoffsets = { 0x40,0xBC,0x3C,0x5C,0x0,0x30,0x74 };
uintptr_t ammoAddr = FindDMAAddy(hProcces, dynamicptr, speedoffsets);
printf("ammoAddr : %p \n", ammoAddr);


//read memory value
float speedvalue;
BOOL rpmResult = ReadProcessMemory(hProcces, (BYTE*)ammoAddr, &speedvalue, sizeof(float), nullptr);
printf("Rpm result : %f \n", speedvalue);
std::cout << speedvalue; //2 type for printing value
}
