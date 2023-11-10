//  =========================
//  String class test program
//  =========================
//
//  Tests: Default Constructor
//
//============================================================
#include "string.hpp"
#include <cassert>
#include <iostream>
//============================================================

int main ()
{
    { //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str;
        
        // VERIFY
        assert(str == "");
        assert(str[0] == 0);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF DEFAULT CONSTRUCTOR TEST ]==========\n";
    
}

