//  ========================
//  Stack class test program
//  ========================
//
//  Tests:      Push
//
//  Requires:   Default Constructor
//              Copy Constructor
//              operator==
//              pop()
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
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        
        stack2.push(true);
        stack2.push(true);
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        stack1.push(true);
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        stack2.push(true);
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        stack1.pop();
        stack1.pop();
        stack1.push(true);
        
        stack2.push(true);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        stack2.pop();
        stack2.pop();
        stack2.push(true);
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1, stack2;
        
        stack1.push(true);
        stack1.push(true);
        stack1.push(false);
        stack1.pop();
        stack1.push(true);
        
        stack2.push(false);
        stack2.push(true);
        stack2.push(false);
        stack2.pop();
        stack2.pop();
        stack2.pop();
        stack2.push(true);
        stack2.push(true);
        stack2.push(true);
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<char> stack1, stack2;
        
        stack1.push('a');
        stack1.push('b');
        stack1.push('c');
        
        stack2.push('a');
        stack2.push('b');
        stack2.push('c');
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<char> stack1, stack2;
        
        stack1.push('a');
        stack1.push('b');
        stack1.push('c');
        
        stack2.push('a');
        stack2.push('b');
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<char> stack1, stack2;
        
        stack1.push('a');
        stack1.push('b');
        
        stack2.push('a');
        stack2.push('b');
        stack2.push('c');
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<char> stack1, stack2;
        
        stack1.push('a');
        stack1.push('b');
        stack1.push('c');
        stack1.pop();
        stack1.push('d');
        
        stack2.push('a');
        stack2.push('b');
        stack2.push('c');
        stack2.pop();
        stack2.push('d');
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<char> stack1, stack2;
        
        stack1.push('a');
        stack1.push('b');
        stack1.push('c');
        stack1.pop();
        stack1.pop();
        stack1.pop();
        stack1.push('d');
        
        stack2.push('a');
        stack2.push('b');
        stack2.push('c');
        stack2.pop();
        stack2.pop();
        stack2.pop();
        stack2.push('d');
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<char> stack1, stack2;
        
        stack1.push('a');
        stack1.push('b');
        stack1.push('c');
        stack1.pop();
        stack1.push('d');
        
        stack2.push('a');
        stack2.push('b');
        stack2.push('c');
        stack2.pop();
        stack2.pop();
        stack2.pop();
        stack2.push('a');
        stack2.push('b');
        stack2.push('d');
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<int> stack1, stack2;
        
        stack1.push(1);
        stack1.push(2);
        stack1.push(3);
        
        stack2.push(1);
        stack2.push(2);
        stack2.push(3);
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        
        stack2.push("abc");
        stack2.push("def");
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        stack1.push("jkl");
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        stack2.push("jkl");
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        stack1.pop();
        stack1.pop();
        stack1.push("jkl");
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        stack2.pop();
        stack2.pop();
        stack2.push("jkl");
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.push("ghi");
        stack1.pop();
        stack1.push("jkl");
        
        stack2.push("abc");
        stack2.push("def");
        stack2.push("ghi");
        stack2.pop();
        stack2.pop();
        stack2.pop();
        stack2.push("abc");
        stack2.push("def");
        stack2.push("jkl");
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF PUSH TEST ]==========\n";
}

