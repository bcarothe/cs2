//  String class test program
//
//  Name:  XXX
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
       {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right;
        
        // TEST
        left += right;
        
        // VERIFY
        assert(left   == "");
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("Hello");
        
        // TEST
        left += right;
        
        // VERIFY
        assert(left   == "Hello");
        assert(right  == "Hello");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('0');
        String  right;
        
        // TEST
        left += right;
        
        // VERIFY
        assert(left   == '0');
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("1");
        String  right('2');
        
        // TEST
        left += right;
        
        // VERIFY
        assert(left   == "12");
        assert(right  == "2");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefg");
        String  right('h');
        
        // TEST
        left += right;
        
        // VERIFY
        assert(left   == "abcdefgh");
        assert(right  == "h");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("def");
        
        // TEST
        left += right;
        
        // VERIFY
        assert(left   == "abcdef");
        assert(right  == "def");
    }
    
    
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing addition." << std::endl;
}

