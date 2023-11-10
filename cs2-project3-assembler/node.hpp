//
//  node.hpp
//  [Project 3] assembler


#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <cassert>

#include "string.cpp"

template <typename T>
class node {
public:
    T data;
    node<T> *next;
    node() : next(0) {}
    node(const T& x) : data(x), next(0) {}
};

#endif
