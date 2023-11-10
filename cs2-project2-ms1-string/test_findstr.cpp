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
        String str("abcdef");
        
        int result = str.findstr(1, "cde");
        
        // VERIFY
        assert(str == "abcdef");
        assert(result == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abcdef");
        
        int result = str.findstr(-50, "cde");
        
        // VERIFY
        assert(str == "abcdef");
        assert(result == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abcdef");
        
        int result = str.findstr(7, "cde");
        
        // VERIFY
        assert(str == "abcdef");
        assert(result == -1);
    }
    
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing findstr." << std::endl;
    
}
