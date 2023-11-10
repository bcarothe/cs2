//  =========================
//  String class test program
//  =========================
//
//  Tests: Swap
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
        String str1 = "Earth";
        String str2 = "Moon";
        
        // TEST
        str1.swap(str2);
        
        // VERIFY
        assert(str1 == "Moon");
        assert(str2 == "Earth");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str1 = "";
        String str2 = "Moon";
        
        // TEST
        str1.swap(str2);
        
        // VERIFY
        assert(str1 == "Moon");
        assert(str2 == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str1 = "Earth";
        String str2 = "";
        
        // TEST
        str1.swap(str2);
        
        // VERIFY
        assert(str1 == "");
        assert(str2 == "Earth");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF SWAP TEST ]==========\n";
}

