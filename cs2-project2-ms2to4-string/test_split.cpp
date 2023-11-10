//  =========================
//  String class test program
//  =========================
//
//  Tests: Split
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
        String str = "Spongebob Patrick Squidward";
        std::vector<String> result;
        
        // TEST
        result = str.split(' ');
        
        // VERIFY
        assert(result[0] == "Spongebob");
        assert(result[1] == "Patrick");
        assert(result[2] == "Squidward");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str = "Spongebob Patrick Squidward";
        std::vector<String> result;
        
        // TEST
        result = str.split('a');
        
        // VERIFY
        assert(result[0] == "Spongebob P");
        assert(result[1] == "trick Squidw");
        assert(result[2] == "rd");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str = "Comma,seperated,words";
        std::vector<String> result;
        
        // TEST
        result = str.split(',');
        
        // VERIFY
        assert(result[0] == "Comma");
        assert(result[1] == "seperated");
        assert(result[2] == "words");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str = "Zer0";
        std::vector<String> result;
        
        // TEST
        result = str.split('0');
        
        // VERIFY
        assert(result[0] == "Zer");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str = "Grrrrrrrrowl";
        std::vector<String> result;
        
        // TEST
        result = str.split('r');
        
        // VERIFY
        assert(result[0] == "G");
        assert(result[1] == "owl");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str = "nnnnnnn";
        std::vector<String> result;
        
        // TEST
        result = str.split('n');
        
        // VERIFY
        assert(result[0] == "");
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str = "";
        std::vector<String> result;
        
        // TEST
        result = str.split('0');
        
        // VERIFY
        assert(result[0] == "");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF SPLIT TEST ]==========\n";
}

