//  ========================
//  Stack class test program
//  ========================
//
//  Tests:      Copy Constructor
//
//  Requires:   Default Constructor
//              Equality
//              push()
//              pop()
//
//============================================================
#include "stack.hpp"
//============================================================

int main ()
{
    { //------------------------------------------------------
        stack<bool> stack1;
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        
        stack<bool> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1;
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        
        stack<bool> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1;
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        stack1.pop();
        
        stack<bool> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1;
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        stack1.push(true);
        
        stack<bool> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1;
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        stack1.pop();
        stack1.push(true);
        
        stack<bool> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<String> stack1;
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        
        stack<String> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1;
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        
        stack<String> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1;
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.pop();
        
        stack<String> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1;
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.push("ghi");
        
        stack<String> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1;
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.pop();
        stack1.push("ghi");
        
        stack<String> stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF COPY CONSTRUCTOR TEST ]==========\n";
}

