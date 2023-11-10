#include <iostream>
#include <fstream>

// Prints everything out until the first space appears
void printAllUntilSpace(std::ifstream &file) {
    char ch;
    file.get(ch);
    while(!file.eof()) {
        std::cout << ch;
        file.get(ch);
    }
}

// Take the first two numbers (each until a ';' appears) and adds them together
void printAdd(std::ifstream &file) {
    // probably too many variables
    char ch;
    int num1 = 0;
    int num2 = 0;
    int pair = 1;
    file.get(ch);
    while(!file.eof()) {
        if (pair == 1) {
            if (ch != ';' && ch != ' ' && ch != '\n') {
                num1 = (num1*10) + (ch - '0'); // adds each digit from left to right
            }
        }
        
        if (ch == ';') {
            ++pair;
            file.get(ch);
        }
        
        if (pair == 2) {
            if (ch != ';' && ch != ' ' && ch != '\n') {
                num2 = (num2*10) + (ch - '0');  // adds each digit from left to right
            }
        }
        
        if (ch == ';') {
            pair = 1;
        }
        
        file.get(ch);
    }
    std::cout << "Result: " << num1 + num2 << std::endl;
}

int main() {
{
    std::ifstream file ("fileio_data.txt");
    if(!file.is_open()) {
        std::cout << "Unable to open file\n";
        return 1;
    }
    
    std::cout << "Printing entire file until the first space..." << std::endl;
    printAllUntilSpace(file);
    file.close();
}
    
    std::cout << std::endl;
    
{
    std::ifstream file ("fileio_data.txt");
    if(!file.is_open()) {
        std::cout << "Unable to open file\n";
        return 1;
    }
    
    std::cout << "Our highly specialized monkeys are calculating the sum of the first two numbers..." << std::endl;
    printAdd(file);
    
    std::cout << '\n';
    file.close();
}
}
