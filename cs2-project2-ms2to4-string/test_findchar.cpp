//  =========================
//  String class test program
//  =========================
//
//  Tests: Findchar
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
        String str;
        
        // TEST
        int result = str.findchar(0, 'a');
        
        // VERIFY
        assert(str == "");
        assert(result == -1);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abc");
        
        // TEST
        int result = str.findchar(0, 'a');
        
        // VERIFY
        assert(str == "abc");
        assert(result == 0);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abc");
        
        // TEST
        int result = str.findchar(1, 'c');
        
        // VERIFY
        assert(str == "abc");
        assert(result == 2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abc");
        
        // TEST
        int result = str.findchar(-12, 'b');
        
        // VERIFY
        assert(str == "abc");
        assert(result == 1);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abc");
        
        // TEST
        int result = str.findchar(4, 'a');
        
        // VERIFY
        assert(str == "abc");
        assert(result == -1);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF FINDCHAR TEST ]==========\n";
    
}
