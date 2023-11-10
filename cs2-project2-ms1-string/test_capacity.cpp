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
        String  str("Wumbo, it's first grade!");
        
        // TEST
        int result = str.capacity();
        
        // VERIFY
        assert(str    == "Wumbo, it's first grade!");
        assert(result == 255);
    }
    
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing capacity." << std::endl;
}

