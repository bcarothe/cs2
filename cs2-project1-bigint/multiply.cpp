//==============================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream file("data1-2.txt");    // Define stream for input
    // Make sure it opened correctly.
    if(!file) {
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
    
    //Until end of file
    //Read two bigints
    //Print them out
    //Add them together
    //Print out results
    
    bigint bi1;
    bigint bi2;
    
    char ch;
    bool pair = false;
    
    file.get(ch);
    while(!file.eof()) {
        // reads the number for bi1
        if (!pair) {
            if (ch != ';' && ch != ' ' && ch != '\n')
                bi1 = bi1.times10(1) + (ch - '0'); // moves each digit in bi1 over & adds next read digit
            
            else if (ch == ';')
                pair = true;
        }
        
        // read the number for bi2
        else if (pair) {
            if (ch != ';' && ch != ' ' && ch != '\n')
                bi2 = bi2.times10(1) + (ch - '0');
            
            // after both bi1 and bi2 are completed, print out the sum
            else if (ch == ';') {
                pair = false;
                std::cout << "Result:\n" << bi1 * bi2 << "\n\n"; // moves each digit in bi2 over & multiplies next read digit
                bi1 = 0;
                bi2 = 0;
            }
        }
        
        file.get(ch);
    }
    
    // Closes file
    file.close();
    return 0;
}

