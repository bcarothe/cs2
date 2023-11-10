//  ========================
//  Stack class test program
//  ========================
//
//  Tests:      Assignment
//
//  Requires:   Default Constructor
//              Copy Constructor
//              push()
//              pop()
//              operator==
//
//============================================================
#include "stack.hpp"
//============================================================

int main ()
{
    { //------------------------------------------------------
        stack<bool> stack1, stack2, stack3;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        
        stack2 = stack1;
        stack3 = false;
        
        assert(stack1 == stack2);
        assert(!stack3[0]);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2, stack3;
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        
        stack2 = stack1;
        
        assert(stack1 == stack2);
        assert(stack1[0] && stack2[0]);
        
        stack2.push(false);
        stack3 = stack2[1];
        
        assert(!stack3[1]);
        assert(!stack2[1] == stack1[0]);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        stack1.pop();
        
        stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        stack1.push(true);
        
        stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        stack1.push(true);
        stack1.push(true);
        stack1.pop();
        stack1.pop();
        stack1.push(true);
        
        stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<String> stack1, stack2, stack3;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        
        stack2 = stack1;
        stack3 = "jkl";
        
        assert(stack1 == stack2);
        assert(stack3[0] == "jkl");
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2, stack3;
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        
        stack2 = stack1;
        
        assert(stack1 == stack2);
        assert(stack1[0] == "abc" && stack2[0] == "abc");
        
        stack2.push("abc");
        stack3 = stack2[1];
        
        assert(stack3[1] == "abc");
        assert(stack2[1] == stack1[0]);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.pop();
        
        stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.push("ghi");
        
        stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.pop();
        stack1.push("ghi");
        
        stack2 = stack1;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF ASSIGNMENT TEST ]==========\n";
}

