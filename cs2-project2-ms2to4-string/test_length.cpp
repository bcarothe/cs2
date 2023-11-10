//  =========================
//  String class test program
//  =========================
//
//  Tests: Length
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
        int result = str.length();
        
        // VERIFY
        assert(str    == "");
        assert(result == 0);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abc");
        
        // TEST
        int result = str.length();
        
        // VERIFY
        assert(str    == "abc");
        assert(result == 3);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("007");
        
        // TEST
        int result = str.length();
        
        // VERIFY
        assert(str    == "007");
        assert(result == 3);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?");
        
        // TEST
        int result = str.length();
        
        // VERIFY
        assert(str    == "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?");
        assert(result == 94);
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu");
        
        // TEST
        int result = str.length();
        
        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu");
        assert(result == 255);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF LENGTH TEST ]==========\n";
}

