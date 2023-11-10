#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <fstream>

#include "stack.hpp"

String infix_to_prefix(const String);
String infix_to_postfix(const String);
String prefix_to_assembly(const String);
String postfix_to_assembly(const String);

#endif
