#ifndef OBJECT_CONSTRUCTION_HPP
#define OBJECT_CONSTRUCTION_HPP

class test {
public:
    test(); // default
    test(int); // assignment
    ~test(); // destructor
    test(const test&); // copy constructor
};

#endif
