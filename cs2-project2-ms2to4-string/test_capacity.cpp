//  =========================
//  String class test program
//  =========================
//
//  Tests: Capacity
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
        String  str("Wumbo, it's first grade!");
        
        // TEST
        int result = str.capacity();
        
        // VERIFY
        assert(str    == "Wumbo, it's first grade!");
        assert(result == 24);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF CAPACITY TEST ]==========\n";
}

