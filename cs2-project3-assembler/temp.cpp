//#include "string.hpp"
#include "stack.hpp"
//============================================================

int main ()
{
    { //------------------------------------------------------
        stack<int> stack1, stack2;
        
        stack1.push(123);
        stack1.push(456);
        stack2.push(987);
        stack2.push(654);
        
        stack1.swap(stack2);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF ___ TEST ]==========\n";
}

