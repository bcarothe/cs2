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
        
        int result = str.findchar(0, 'a');
        
        // VERIFY
        assert(str == "");
        assert(result == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        int result = str.findchar(0, 'a');
        
        // VERIFY
        assert(str == "abc");
        assert(result == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        int result = str.findchar(1, 'c');
        
        // VERIFY
        assert(str == "abc");
        assert(result == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        int result = str.findchar(-12, 'b');
        
        // VERIFY
        assert(str == "abc");
        assert(result == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String str("abc");
        
        int result = str.findchar(4, 'a');
        
        // VERIFY
        assert(str == "abc");
        assert(result == -1);
    }
    
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing findchar." << std::endl;
    
}
