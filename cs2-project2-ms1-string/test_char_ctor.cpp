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
        String str;
        
        // VERIFY
        assert(str == '\0');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str('x');
        
        // VERIFY
        assert(str == 'x');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str('0');
        
        // VERIFY
        assert(str == '0');
    }
    
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing character constructor." << std::endl;
    
}

