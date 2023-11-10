//  ========================
//  Postfix to Assembly Test
//  ========================
//
//  Tests:      prefix_to_assembly
//
//============================================================
#include "stack.hpp"
#include "utilities.hpp"
//============================================================

int main () {
    { //------------------------------------------------------
        String infix = "( B * C ) ;";
        
        assert(prefix_to_assembly(infix_to_prefix(infix)) == "   LDR   B\n   MUL   C\n   STR   TMP1");
    } //------------------------------------------------------
    { //------------------------------------------------------
        String infix = "( AX + ( B * C ) ) ;";
        
        assert(prefix_to_assembly(infix_to_prefix(infix)) == "   LDR   B\n   MUL   C\n   STR   TMP1\n   LDR   AX\n   ADD   TMP1\n   STR   TMP2");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF POSTFIX_TO_ASSEMBLY TEST ]==========\n";
}
