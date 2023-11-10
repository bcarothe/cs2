//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    //String bogus; // used to prevent the assertion of a true statement of the first String
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("");
        
        // VERIFY
        assert(str == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("a");
        
        // VERIFY
        assert(str == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        // VERIFY
        assert(str == "abc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu");
        
        // VERIFY
        assert(str == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu");
    }
    
    
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing character array constructor." << std::endl;
    
}

