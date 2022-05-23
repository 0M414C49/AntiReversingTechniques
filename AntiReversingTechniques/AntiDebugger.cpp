#include "AntiDebugger.h"


/*
* This function check the Process Environment Block (PEB) to detect
* the presence of the debugger by Accessing the PEB and checking the secind byte that
* stores the bit that indecate the precense of the debugger in the heap for Windows OS.
*/
BOOL AntiDebugger::Imp_IsDebuggerPresent()
{
    BOOL result = false;

    __asm
    {
        xor eax, eax;
        mov eax, dword ptr fs : [0x30] ;  // Accessing the PEB
        movzx eax, byte ptr[eax + 0x02];  // Getting the the flag
        mov result, eax;
    }

    return result;
}
