#include "AntiVM.h"



/* 
 * Using the CPUID instruction to get the segnatrue of the machine, which
 * is detcetable if the OS is running in VM.
*/

BOOL AntiVM::Imp_IsVMPresent()
{
    BOOL result = false;

    __asm
    {
        xor eax, eax;
        inc eax;
        cpuid;
        bt ecx, 0x1f; // the 31 byte that holds the flag of the VM.
        jc VMPRES;
        jmp Done;

    VMPRES:;
        mov result, 0x1;
    Done:;
        nop;
    }

    

    return result;
}