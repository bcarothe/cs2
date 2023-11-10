//  ========================
//  Stack class test program
//  ========================
//
//  Tests:      Pop
//
//  Requires:   Default Constructor
//              Copy Constructor
//              operator==
//              push()
//
//============================================================
#include "stack.hpp"
//============================================================

int main ()
{
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        stack1.pop();
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        stack1.pop();
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        stack2.pop();
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        stack1.pop();
        stack1.push(false);
        stack1.pop();
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        stack2.pop();
        stack2.push(false);
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        stack1.pop();
        stack1.push(false);
        stack1.pop();
        
        stack2.push(true);
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        stack2.pop();
        stack2.push(false);
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<int> stack1, stack2;
        
        stack1.push(1);
        stack1.push(2);
        stack1.push(3);
        stack1.pop();
        
        stack2.push(1);
        stack2.push(2);
        stack2.push(3);
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        stack1.pop();
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        stack1.pop();
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        stack2.pop();
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        stack1.pop();
        stack1.push("jkl");
        stack1.pop();
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        stack2.pop();
        stack2.push("jkl");
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        stack1.pop();
        stack1.push("jkl");
        stack1.pop();
        
        stack2.push("abc");
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        stack2.pop();
        stack2.push("abc");
        stack2.pop();
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF POP TEST ]==========\n";
}

