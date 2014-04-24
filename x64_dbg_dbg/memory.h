#ifndef _MEMORY_H
#define _MEMORY_H

#include "_global.h"

#ifndef KDEBUGGER_ENABLE
#define PAGE_SIZE 0x1000 //TODO: better stuff here
#endif // ndef KDEBUGGER_ENABLE

struct PATTERNNIBBLE
{
    unsigned char n;
    bool all;
};

struct PATTERNBYTE
{
    PATTERNNIBBLE n[2];
};

uint memfindbaseaddr(HANDLE hProcess, uint addr, uint* size);
bool memread(HANDLE hProcess, const void* lpBaseAddress, void* lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead);
bool memwrite(HANDLE hProcess, void* lpBaseAddress, const void* lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten);
bool memisvalidreadptr(HANDLE hProcess, uint addr);
void* memalloc(HANDLE hProcess, uint addr, DWORD size, DWORD fdProtect);
void memfree(HANDLE hProcess, uint addr);
uint memfindpattern(unsigned char* data, uint size, const char* pattern);

#endif // _MEMORY_H
