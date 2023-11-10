//  ========================
//  Stack class test program
//  ========================
//
//  Tests:      Swap
//
//  Requires:   Default Constructor
//              Copy Constructor
//              push()
//              pop()
//              Subscript
//              Comparison
//              isEmpty()
//
//============================================================
#include "stack.hpp"
//============================================================

int main () {
    { //------------------------------------------------------
        stack<char> stack1, stack2;
        
        stack1.swap(stack2);
        
        assert(stack1.isEmpty());
        assert(stack2.isEmpty());
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<char> stack1, stack2;
        
        stack1.push('a');
        stack1.push('b');
        stack2.push('c');
        stack2.push('d');
        
        stack1.swap(stack2);
        
        assert(stack1[0] == 'c');
        assert(stack1[1] == 'd');
        assert(stack2[0] == 'a');
        assert(stack2[1] == 'b');
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<char> stack1, stack2, stack3, stack4;
        
        stack1.push('a');
        stack1.push('b');
        stack2.push('c');
        stack2.push('d');
        stack2.push('e');
        
        stack3.push('c');
        stack3.push('d');
        stack3.push('e');
        stack4.push('a');
        stack4.push('b');
        
        stack1.swap(stack2);
        
        assert(stack1 == stack3);
        assert(stack2 == stack4);
    } //------------------------------------------------------
      ////////////////////////////////////////////////////////
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.swap(stack2);
        
        assert(stack1.isEmpty());
        assert(stack2.isEmpty());
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2;
        
        stack1.push("abc");
        stack1.push("def");
        stack2.push("ghi");
        stack2.push("jkl");
        
        stack1.swap(stack2);
        
        assert(stack1[0] == "ghi");
        assert(stack1[1] == "jkl");
        assert(stack2[0] == "abc");
        assert(stack2[1] == "def");
    } //------------------------------------------------------
    { //------------------------------------------------------
        stack<String> stack1, stack2, stack3, stack4;
        
        stack1.push("abc");
        stack1.push("def");
        stack2.push("ghi");
        stack2.push("jkl");
        stack2.push("mno");
        
        stack3.push("ghi");
        stack3.push("jkl");
        stack3.push("mno");
        stack4.push("abc");
        stack4.push("def");
        
        stack1.swap(stack2);
        
        assert(stack1 == stack3);
        assert(stack2 == stack4);
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF SWAP TEST ]==========\n";
}
