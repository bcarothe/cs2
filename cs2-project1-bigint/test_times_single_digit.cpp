// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test
        bi = bi.timesDigit(0);  //Or whatever you call it.

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test
        bi = bi.timesDigit(0);  //Or whatever you call it.

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test
        bi = bi.timesDigit(1);  //Or whatever you call it.

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.timesDigit(1);  //Or whatever you call it.

        // Verify
        assert(bi == 3);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555");

        // Test
        bi = bi.timesDigit(2);  //Or whatever you call it.

        // Verify
        assert(bi == "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1234);

        // Test
        bi = bi.timesDigit(-1);  //Or whatever you call it.

        // Verify
        assert(bi == 1234);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1234);

        // Test
        bi = bi.timesDigit(10);  //Or whatever you call it.

        // Verify
        assert(bi == 1234);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("123456789");

        // Test
        bi = bi.timesDigit(-1);  //Or whatever you call it.

        // Verify
        assert(bi == "123456789");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("123456789");

        // Test
        bi = bi.timesDigit(10);  //Or whatever you call it.

        // Verify
        assert(bi == "123456789");
    }


    //Add test cases as needed.

    std::cout << "Done testing bigint * single digit" << std::endl;
}
