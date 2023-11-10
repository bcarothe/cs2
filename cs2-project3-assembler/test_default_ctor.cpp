//  ========================
//  Stack class test program
//  ========================
//
//  Tests:      Default Constructor
//
//  Requires:   Copy Constructor
//              isEmpty()
//
//============================================================
#include "stack.hpp"
//============================================================

int main ()
{
    { //------------------------------------------------------
        stack<bool> boolStack;
        stack<char> charStack;
        stack<wchar_t> wchar_tStack;
        stack<unsigned char> unsignedCharStack;
        stack<signed char> signedCharStack;
        stack<short int> shortIntStack;
        stack<unsigned short int> unsignedShortIntStack;
        stack<signed short int> signedShortIntStack;
        stack<int> intStack;
        stack<unsigned int> unsignedIntStack;
        stack<signed int> signedIntStack;
        stack<long> longStack;
        stack<unsigned long> unsignedLongStack;
        stack<signed long> signedLongStack;
        stack<float> floatStack;
        stack<double> doubleStack;
        stack<long double> longDoubleStack;
        stack<unsigned long long> unsignedLongLongStack;
        stack<signed long long> signedLongLongStack;
        
        assert(boolStack.isEmpty());
        assert(charStack.isEmpty());
        assert(wchar_tStack.isEmpty());
        assert(unsignedCharStack.isEmpty());
        assert(signedCharStack.isEmpty());
        assert(shortIntStack.isEmpty());
        assert(unsignedShortIntStack.isEmpty());
        assert(signedShortIntStack.isEmpty());
        assert(intStack.isEmpty());
        assert(unsignedIntStack.isEmpty());
        assert(signedIntStack.isEmpty());
        assert(longStack.isEmpty());
        assert(unsignedLongStack.isEmpty());
        assert(signedLongStack.isEmpty());
        assert(floatStack.isEmpty());
        assert(doubleStack.isEmpty());
        assert(longDoubleStack.isEmpty());
        assert(unsignedLongLongStack.isEmpty());
        assert(signedLongLongStack.isEmpty());
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF DEFAULT CONSTRUCTOR TEST ]==========\n";
}

