//  =========================
//  String class test program
//  =========================
//
//  Tests: Not Equal
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
        bool result = (left != right);
        
        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left('q');
        String  right;
        
        // TEST
        bool result = (left != right);
        
        // VERIFY
        assert(result == true);
        assert(left   == 'q');
        assert(right  == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("r");
        
        // TEST
        bool result = (left != right);
        
        // VERIFY
        assert(result == true);
        assert(left   == '\0');
        assert(right  == "r");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String  left("The golden rule of being a computer scientist or passing computer science class, is to always include memes!");
        String  right("The golden rule of being a computer scientist or passing computer science class, is to always include memes!");
        
        // TEST
        bool result = (left != right);
        
        // VERIFY
        assert(result == false);
        assert(left   == "The golden rule of being a computer scientist or passing computer science class, is to always include memes!");
        assert(right  == "The golden rule of being a computer scientist or passing computer science class, is to always include memes!");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF NOT EQUAL TEST ]==========\n";
}

