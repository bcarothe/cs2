//  =========================
//  String class test program
//  =========================
//
//  Tests: Assignment
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
        str = 'a';
        
        // VERIFY
        assert(str == "a");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str;
        
        // TEST
        str = "May the force be with you!";
        
        // VERIFY
        assert(str == "May the force be with you!");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str = 'a';
        
        // VERIFY
        assert(str == "a");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str = "May the force be with you!";
        
        // VERIFY
        assert(str == "May the force be with you!");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF ASSIGNMENT TEST ]==========\n";
}

