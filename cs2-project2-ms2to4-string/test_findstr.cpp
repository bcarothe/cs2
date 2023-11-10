//  =========================
//  String class test program
//  =========================
//
//  Tests: Findstr
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
        String str("abcdef");
        
        // TEST
        int result = str.findstr(1, "cde");
        
        // VERIFY
        assert(str == "abcdef");
        assert(result == 2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abcdef");
        
        // TEST
        int result = str.findstr(-50, "cde");
        
        // VERIFY
        assert(str == "abcdef");
        assert(result == 2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abcdef");
        
        // TEST
        int result = str.findstr(7, "cde");
        
        // VERIFY
        assert(str == "abcdef");
        assert(result == -1);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF FINDSTR TEST ]==========\n";
}
