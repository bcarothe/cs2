//  =========================
//  String class test program
//  =========================
//
//  Tests: Output
//
//============================================================
#include "string.hpp"
#include <cassert>
#include <iostream>
//============================================================

int main ()
{
    std::cout << "=========[ STARTING OUTPUT TEST ]=========\n";
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("Cause and Effect");
        
        // TEST & VERIFY
        std::cout << "Cause and Effect" << std::endl;
        std::cout << str << std::endl;
    } //------------------------------------------------------
    std::cout << "------------------------------------------\n";
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("Line 1\n\tTabbed line 2");
        
        // TEST & VERIFY
        std::cout << "Line 1\n\tTabbed line 2" << std::endl;
        std::cout << str << std::endl;
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF OUTPUT TEST ]==========\n";
}
