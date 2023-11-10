// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(10);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10);
      assert(right  == 1);
      assert(result == 11);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(10);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 10);
      assert(result == 10);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(001);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(001);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(12);
      bigint right(12);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 12);
      assert(right  == 12);
      assert(result == 24);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(10000);
      bigint right(1111);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10000);
      assert(right  == 1111);
      assert(result == 11111);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(99999);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 99999);
      assert(right  == 0);
      assert(result == 99999);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(99999);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 99999);
      assert(right  == 1);
      assert(result == 100000);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      bigint right("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      assert(right  == "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      assert(result == "200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      assert(right  == 1);
      assert(result == "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }



    //assert(1 == 2);   //WRONG. This will fail, of course.
                      //You need to add more test cases here.


    std::cout << "Done with testing addition." << std::endl;
}
