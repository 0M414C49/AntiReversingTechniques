#include "common.h"

int main()
{

    AntiDebugger antiDebugger;
    AntiVM antiVM;

    if (antiDebugger.Imp_IsDebuggerPresent())
    {
        std::cout << "Debugger is active!" << "\n";
    }
    else
    {
        std::cout << "Debugger isn't active!" << "\n";
    }

    if (antiVM.Imp_IsVMPresent())
    {
        std::cout << "VM env detected" << "\n";
    }
    else
    {
        std::cout << "VM env not detected" << "\n";
    }

    

    return 0;


}