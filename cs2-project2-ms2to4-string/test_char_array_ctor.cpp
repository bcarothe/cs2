//  =========================
//  String class test program
//  =========================
//
//  Tests: Character Array Constructor
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
        String str("");
        
        // VERIFY
        assert(str == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("a");
        
        // VERIFY
        assert(str == "a");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abc");
        
        // VERIFY
        assert(str == "abc");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu");
        
        // VERIFY
        assert(str == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF CHARACTER ARRAY CONSTRUCTOR TEST ]==========\n";
}

