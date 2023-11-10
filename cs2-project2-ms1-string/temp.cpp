#include "string.hpp"
#include <iostream>
#include <cassert>

int main() {
    String s1;
    
    String s2('a');
    
    String s3("abcdefg");
    
    String s4(s3);
    
    s3[1] = 'd';
    
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    
    std::cout << std::endl;
    
    String size("abcdef");
    
    String result = s2 + s3 + s4;
    std::cout << result << std::endl;
    
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
}
