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
    //String bogus; // used to prevent the assertion of a true statement of the first String
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right;
        
        // TEST
        bool result = (left == right);
        
        // VERIFY
        assert(result == true);
        assert(left   == "");
        assert(right  == "");
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('q');
        String  right;
        
        // TEST
        bool result = (left == right);
        
        // VERIFY
        assert(result == false);
        assert(left   == 'q');
        assert(right  == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("r");
        
        // TEST
        bool result = (left == right);
        
        // VERIFY
        assert(result == false);
        assert(left   == '\0');
        assert(right  == "r");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("The golden rule of being a computer scientist or passing computer science class, is to always include memes!");
        String  right("The golden rule of being a computer scientist or passing computer science class, is to always include memes!");
        
        // TEST
        bool result = (left == right);
        
        // VERIFY
        assert(result == true);
        assert(left   == "The golden rule of being a computer scientist or passing computer science class, is to always include memes!");
        assert(right  == "The golden rule of being a computer scientist or passing computer science class, is to always include memes!");
    }
    
    
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing equal." << std::endl;
}

