//  =========================
//  String class test program
//  =========================
//
//  Tests: Substr
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
        
        String result = str.substr(0, 0);
        
        // VERIFY
        assert(str == "");
        assert(result == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str('a');
        
        String result = str.substr(0, 0);
        
        // VERIFY
        assert(str == "a");
        assert(result == "a");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        String result = str.substr(0, 2);
        
        // VERIFY
        assert(str == "abc");
        assert(result == "abc");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        String result = str.substr(1, 2);
        
        // VERIFY
        assert(str == "abc");
        assert(result == "bc");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        String result = str.substr(-1, 2);
        
        // VERIFY
        assert(str == "abc");
        assert(result == "abc");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        String result = str.substr(3, 2);
        
        // VERIFY
        assert(str == "abc");
        assert(result == "");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF SUBSTR TEST ]==========\n";
}
