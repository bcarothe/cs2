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
        bi = bi.times10(0); //Or whatever you call it.

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test
        bi = bi.times10(1); //Or whatever you call it.

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.times10(0); //Or whatever you call it.

        // Verify
        assert(bi == 3);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.times10(1); //Or whatever you call it.

        // Verify
        assert(bi == 30);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.times10(9); //Or whatever you call it.

        // Verify
        assert(bi == "3000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(10);

        // Test
        bi = bi.times10(0); //Or whatever you call it.

        // Verify
        assert(bi == 10);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(10);

        // Test
        bi = bi.times10(1); //Or whatever you call it.

        // Verify
        assert(bi == 100);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("123456789");

        // Test
        bi = bi.times10(1); //Or whatever you call it.

        // Verify
        assert(bi == "1234567890");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("123456789");

        // Test
        bi = bi.times10(9); //Or whatever you call it.

        // Verify
        assert(bi == "123456789000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("123456789");

        // Test
        bi = bi.times10(9); //Or whatever you call it.

        // Verify
        assert(bi == "123456789000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test
        bi = bi.times10(198); //Or whatever you call it.

        // Verify
        assert(bi == "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }





    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(0); //Or whatever you call it.

        // Verify
        assert(bi == 23);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(1); //Or whatever you call it.

        // Verify
        assert(bi == 230);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(2); //Or whatever you call it.

        // Verify
        assert(bi == 2300);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(3); //Or whatever you call it.

        // Verify
        assert(bi == 23000);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(4); //Or whatever you call it.

        // Verify
        assert(bi == 230000);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(5); //Or whatever you call it.

        // Verify
        assert(bi == 2300000);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(6); //Or whatever you call it.

        // Verify
        assert(bi == 23000000);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(7); //Or whatever you call it.

        // Verify
        assert(bi == 230000000);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(8); //Or whatever you call it.

        // Verify
        assert(bi == "2300000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(9); //Or whatever you call it.

        // Verify
        assert(bi == "23000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(23);

        // Test
        bi = bi.times10(10); //Or whatever you call it.

        // Verify
        assert(bi == "230000000000");
    }


    //Add test cases as needed.

    std::cout << "Done testing times10" << std::endl;
}
