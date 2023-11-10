#include "bigint.hpp"
#include <iostream>

// default consturctor
bigint::bigint() {
    for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
        bigintArray[i] = 0;
}

// int initializer
bigint::bigint(int initInt) {
    initToZero();
    
    int i = MAX_INDEX;
    
    // takes each digit of int & assigns them in the array
    while (initInt > 0) {
        bigintArray[i--] = initInt % 10;
        initInt /= 10;
    }
}

// char initializer
bigint::bigint(const char num[]) {
    initToZero();
    
    int length = 0;
    
    // gets the length of char array
    while (num[length] != 0)
        ++length;
    
    --length;
    
    // converts char into int & assigns them in the array
    int i = MAX_INDEX;
    while (i >= 0 && length != -1)
        bigintArray[i--] = num[length--] - '0';
}

// initializes to zero
void bigint::initToZero() {
    for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
        bigintArray[i] = 0;
}

// ----------------------------------------
// Multiply
// ----------------------------------------

bigint bigint::timesDigit(int digit) {
    if (digit >= 0 && digit <= 9) {
        bigint result;
        int remainder = 0;
        for (int i = MAX_INDEX; i >= 0; --i) {
            remainder = bigintArray[i] * digit + remainder;
            result.bigintArray[i] = remainder % 10;
            remainder /= 10;
        }
        return result;
    }
    else
        return *this;
}

bigint bigint::times10(int exponent) {
    bigint result;
    for (int i = MAX_INDEX - exponent; i >= 0; --i) {
        result.bigintArray[i] = bigintArray[i + exponent];
    }
    return result;
}

////////// End of Multiply //////////

// ----------------------------------------
// Overload Operators
// ----------------------------------------

// ########## Comparison ##########
bool bigint::operator==(const bigint& rhs) const {
    for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
        if (bigintArray[i] != rhs.bigintArray[i])
            return false;
    }
    return true;
}

// ########## Addition ##########
bigint bigint::operator+(const bigint& rhs) const {
    bigint result;
    int remainder = 0, number = 0;
    for (int i = MAX_INDEX; i >= 0; --i) {
        number = bigintArray[i] + rhs.bigintArray[i] + remainder;
        remainder = number / 10;
        result.bigintArray[i] = number % 10;
    }
    return result;
}

// ########## Multiply ##########
bigint bigint::operator*(bigint rhs) {
    bigint result;
    for (int i = 0; i < MAX_ARRAY_SIZE; ++i)/*(int i = MAX_INDEX; i >= 0; --i)*/ {
        result = result + (timesDigit(rhs.bigintArray[i])).times10(MAX_INDEX - i);
    }
    return result;
}

// ########## Subscript ##########
int bigint::operator[](int index) const {
    if (index < 0 || index >= MAX_ARRAY_SIZE) {
        std::cout << "Invalid index: " << index << std::endl;
        return -1;
    }
    return bigintArray[index];
}

// ########## Extraction ##########
std::ostream& operator<<(std::ostream& out, const bigint& rhs) {
    bool startOfNum = false;
    int allZero = 0;
    int maxLine = 0;
    
    for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
        // checks if a digit exists > zero
        if (rhs.bigintArray[i] != 0 && startOfNum == false)
            startOfNum = true;
        
        // checks if all digits are zero
         else if (rhs.bigintArray[i] == 0) {
            ++allZero;
            if (allZero == MAX_ARRAY_SIZE)
                out << rhs.bigintArray[i];
        }
        
        // returns number > 0
        if (startOfNum == true) {
            out << rhs.bigintArray[i];
            ++maxLine;
            if (maxLine % 50 == 0)
                out << '\n';
        }
    }
    return out;
}

// ########## Insertion ##########
std::istream& operator>>(std::istream& in, bigint& rhs) {
    char ch, arr[MAX_ARRAY_SIZE];
    
    // initializes array to 0
    for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
        arr[i] = 0;
    
    in >> ch;
    
    // keeps taking an input until MAX_ARRAY_SIZE or a semicolon appears
    for (int i = 0; i < MAX_ARRAY_SIZE && ch != ';'; ++i) {
        arr[i] = ch;
        in >> ch;
    }
    
    rhs = bigint(arr);
    return in;
}

////////// End of Overload Operators //////////
