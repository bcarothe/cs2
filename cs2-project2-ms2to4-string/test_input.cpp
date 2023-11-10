//  =========================
//  String class test program
//  =========================
//
//  Tests: Input
//
//============================================================
#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
//============================================================

int main ()
{
    std::cout << "=========[ STARTING INPUT TEST ]=========\n";
    { //------------------------------------------------------
        // SETUP FIXTURE
        String str;
        
        // TEST
        std::cout << "INPUT:\t";
        std::cin >> str;
        
        // VERIFY
        std::cout << "OUTPUT:\t";
        std::cout << str << "\n";
    } //------------------------------------------------------
    { //------------------------------------------------------
        // SETUP FIXTURE
        std::ifstream file ("log_1_tiny.txt");
        if(!file.is_open()) {
            std::cout << "Unable to open file\n";
            return 1;
        }
        
        // TEST & VERIFY
        std::cout << "\nPrinting from log_1_tiny.txt..." << std::endl;
        char ch;
        file.get(ch);
        while(!file.eof()) {
            std::cout << ch;
            file.get(ch);
        }
        file.close();
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF INPUT TEST ]==========\n";
}
