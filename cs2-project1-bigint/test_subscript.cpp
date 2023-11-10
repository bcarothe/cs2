// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {

    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 200];

        // Verify
        assert(bi    == 4);
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 1];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi(40);

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 1];

        // Verify
        assert(bi    == 40);
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi(40);

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 2];

        // Verify
        assert(bi    == 40);
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 201];

        // Verify
        assert(bi    == 4);
        assert(digit == -1);
    }
    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[MAX_ARRAY_SIZE];

        // Verify
        assert(bi    == 4);
        assert(digit == -1);
    }
    {
        // Setup
        bigint bi(185372903);

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 2];

        // Verify
        assert(bi    == 185372903);
        assert(digit == 0);
    }

    {
        // Setup
        bigint bi("8198273976486698134812834719283765912873659123858273489123412348871293659182736489127364928735241534");

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 100];

        // Verify
        assert(bi    == "8198273976486698134812834719283765912873659123858273489123412348871293659182736489127364928735241534");
        assert(digit == 8);
    }
    {
        // Setup
        bigint bi("8198273976486698134812834719283765912873659123858273489123412348871293659182736489127364928735241534");

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 99];

        // Verify
        assert(bi    == "8198273976486698134812834719283765912873659123858273489123412348871293659182736489127364928735241534");
        assert(digit == 1);
    }
    {
        // Setup
        bigint bi("8198273976486698134812834719283765912873659123858273489123412348871293659182736489127364928735241534");

        // Test
        int digit = bi[MAX_ARRAY_SIZE - 50];

        // Verify
        assert(bi    == "8198273976486698134812834719283765912873659123858273489123412348871293659182736489127364928735241534");
        assert(digit == 7);
    }

    std::cout << "Done testing subscript." << std::endl;
}
