//  =========================
//  String class test program
//  =========================
//
//  Tests: Addition
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
        String  left;
        String  right;
        
        // TEST
        String result = (left + right);
        
        // VERIFY
        assert(result == "");
        assert(left   == "");
        assert(right  == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("Hello");
        
        // TEST
        String result = (left + right);
        
        // VERIFY
        assert(result == "Hello");
        assert(left   == "");
        assert(right  == "Hello");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left('0');
        String  right;
        
        // TEST
        String result = (left + right);
        
        // VERIFY
        assert(result == "0");
        assert(left   == '0');
        assert(right  == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("1");
        String  right('2');
        
        // TEST
        String result = (left + right);
        
        // VERIFY
        assert(result == "12");
        assert(left   == '1');
        assert(right  == "2");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefg");
        String  right('h');
        
        // TEST
        String result = (left + right);
        
        // VERIFY
        assert(result == "abcdefgh");
        assert(left   == "abcdefg");
        assert(right  == "h");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("def");
        
        // TEST
        String result = (left + right);
        
        // VERIFY
        assert(result == "abcdef");
        assert(left   == "abc");
        assert(right  == "def");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF ADDITION TEST ]==========\n";
}

