//  ========================
//  Stack class test program
//  ========================
//
//  Tests:      Equality
//
//  Requires:   Default Constructor
//              Copy Constructor
//              push()
//              pop()
//
//============================================================
#include "stack.hpp"
//============================================================

int main () {
    { //------------------------------------------------------
        stack<bool> stack1;
        stack<bool> stack2;
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<bool> stack1;
        stack<bool> stack2;
        
        stack1.push(false);
        
        assert(!(stack1 == stack2));
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<int> stack1, stack2;
        
        stack1.push(123);
        stack1.push(987);
        
        stack2.push(123);
        stack2.push(987);

        assert(stack1 == stack2);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<int> stack1, stack2;
        
        stack1.push(987);
        stack1.push(123);
        stack1.pop();
        stack1.push(654);
        
        stack2.push(987);
        stack2.push(123);
        stack2.pop();
        stack2.push(654);
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<int> stack1, stack2;
        
        stack1.push(987);
        stack1.push(123);
        stack1.pop();
        stack1.push(654);
        
        stack2.push(987);
        stack2.pop();
        stack2.push(987);
        stack2.push(654);
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        
        stack2.push("abc");
        stack2.push("def");
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.push("ghi");
        
        stack2.push("abc");
        stack2.push("def");
        stack2.pop();
        stack2.push("ghi");
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack1.pop();
        stack1.push("ghi");
        
        stack2.push("abc");
        stack2.pop();
        stack2.push("abc");
        stack2.push("ghi");
        
        assert(stack1 == stack2);
    } //------------------------------------------------------
    
    
    std::cout << "==========[ END OF EQUALITY TEST ]==========\n";
}
