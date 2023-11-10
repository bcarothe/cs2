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
        assert(str == "");
    }
    
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing default constructor." << std::endl;
    
}

