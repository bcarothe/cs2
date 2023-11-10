//  =========================
//  String class test program
//  =========================
//
//  Tests: Subscript
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
        char result = str[0];
        
        // VERIFY
        assert(str    == "");
        assert(result == '\0');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str('a');
        
        // TEST
        char result = str[0];
        
        // VERIFY
        assert(str    == "a");
        assert(result == 'a');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("a");
        
        // TEST
        char result = str[0];
        
        // VERIFY
        assert(str    == "a");
        assert(result == 'a');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("12340");
        
        // TEST
        char result = str[0];
        
        // VERIFY
        assert(str    == "12340");
        assert(result == '1');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("12340");
        
        // TEST
        char result = str[4];
        
        // VERIFY
        assert(str    == "12340");
        assert(result == '0');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("!@#");
        
        // TEST
        char result = str[0];
        
        // VERIFY
        assert(str    == "!@#");
        assert(result == '!');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("!@#");
        
        // TEST
        char result = str[1];
        
        // VERIFY
        assert(str    == "!@#");
        assert(result == '@');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abc");
        
        // TEST
        char result = str[0];
        
        // VERIFY
        assert(str    == "abc");
        assert(result == 'a');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abc");
        
        // TEST
        char result = str[1];
        
        // VERIFY
        assert(str    == "abc");
        assert(result == 'b');
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu");
        
        // TEST
        char result = str[254];
        
        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu");
        assert(result == 'u');
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF SUBSCRIPT TEST ]==========\n";
}

