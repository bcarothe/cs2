//  =========================
//  String class test program
//  =========================
//
//  Tests: Greater Than Or Equal
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
        bool result = (left >= right);
        
        // VERIFY
        assert(result == true);
        assert(left   == "");
        assert(right  == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left('a');
        String  right;
        
        // TEST
        bool result = (left >= right);
        
        // VERIFY
        assert(result == true);
        assert(left   == "a");
        assert(right  == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right('a');
        
        // TEST
        bool result = (left >= right);
        
        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "a");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("def");
        
        // TEST
        bool result = (left >= right);
        
        // VERIFY
        assert(result == false);
        assert(left   == "abc");
        assert(right  == "def");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("def");
        String  right("abc");
        
        // TEST
        bool result = (left >= right);
        
        // VERIFY
        assert(result == true);
        assert(left   == "def");
        assert(right  == "abc");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("abcd");
        
        // TEST
        bool result = (left >= right);
        
        // VERIFY
        assert(result == false);
        assert(left   == "abc");
        assert(right  == "abcd");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("abc");
        
        // TEST
        bool result = (left >= right);
        
        // VERIFY
        assert(result == true);
        assert(left   == "abcd");
        assert(right  == "abc");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("abc");
        
        // TEST
        bool result = (left >= right);
        
        // VERIFY
        assert(result == true);
        assert(left   == "abc");
        assert(right  == "abc");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF GREATER THAN OR EQUAL TEST ]==========\n";
}

