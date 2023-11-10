#include "object_construction.hpp"
#include <iostream>

test::test() {
    std::cout << "Called default\n";
}

test::test(int n) {
    std::cout << "Called assignment\n";
}

test::~test() {
    std::cout << "Called destructor\n";
}

test::test(const test& test) {
    std::cout << "Called copy\n";
}
