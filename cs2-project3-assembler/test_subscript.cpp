//  ========================
//  Stack class test program
//  ========================
//
//  Tests:      Subscript
//
//  Requires:   Default Constructor
//              Copy Constructor
//              push()
//              pop()
//              Subscript
//              Comparison
//
//============================================================
#include "stack.hpp"
//============================================================

int main () {
    { //------------------------------------------------------
        stack<bool> stack1;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        stack1.push(true);
        
        assert(stack1[4]);
        
        stack1.pop();
        stack1.pop();
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        
        assert(stack1[0]);
        assert(stack1[1]);
        assert(!stack1[2]);
        assert(stack1[3]);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1;
        
        stack1.push("abc");
        stack1.push("abc");
        stack1.push("def");
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.push("abc");
        
        assert(stack1[4] == "abc");
        
        stack1.pop();
        stack1.pop();
        stack1.push("abc");
        stack1.push("abc");
        stack1.pop();
        
        assert(stack1[0] == "abc");
        assert(stack1[1] == "abc");
        assert(stack1[2] == "def");
        assert(stack1[3] == "abc");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF SUBSCRIPT TEST ]==========\n";
}
