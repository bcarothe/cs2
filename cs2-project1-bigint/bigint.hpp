#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

const int MAX_ARRAY_SIZE = 200;
const int MAX_INDEX = MAX_ARRAY_SIZE - 1;

class bigint {
public:
    bigint();               // default constructor
    bigint(int);            // int initializer
    bigint(const char []);  // char initializer
    
    void initToZero();      // initializes to zero
    
    bigint timesDigit(int);
    bigint times10(int);
    
    // overload operators
    bool operator==(const bigint&) const;                           // comparison
    bigint operator+(const bigint&) const;                          // addition
    bigint operator*(bigint);
    int operator[](int) const;                                      // subscript
    friend std::ostream& operator<<(std::ostream&, const bigint&);  // extraction
    friend std::istream& operator>>(std::istream&, bigint&);        // insertion
    
private:
    int bigintArray[MAX_ARRAY_SIZE];
};

#endif

