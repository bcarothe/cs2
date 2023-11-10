
//  [Lab 8] Fibonacci

#include <iostream>

//-- Factorial --//
unsigned long long fact(int n) {
    if (n == 1)
        return n;
    return n * fact(n-1);
}

unsigned long long facttr(int n, int result) {
    if (n ==1)
        return result;
    return facttr(n-1, n*result);
}
//-- End Factorial --//

//-- Fibonacci --//
unsigned long long fib(int n) {
    if (n <= 2)
        return 1;
    return fib(n-1) + fib(n-2);
}

unsigned long long fibtr(unsigned int n, unsigned int left, unsigned int right) {
    if (n == 0)
        return left;
    
    if (n == 1)
        return right;
    
    return fibtr(n-1, right, left+right);
}
//-- End Fibonacci --//

int main(int argc, const char * argv[]) {
    std::cout << fib(20) << "\n";
    std::cout << fibtr(50, 1, 1) << "\n";
}
