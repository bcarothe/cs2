//  ========================
//  Postfix to Assembly Test
//  ========================
//
//  Tests:      postfix_to_assembly
//
//============================================================
#include "stack.hpp"
#include "utilities.hpp"
//============================================================

int main () {
    { //------------------------------------------------------
        String infix = "( AX + ( B * C ) ) ;";
        
        assert(postfix_to_assembly(infix_to_postfix(infix)) == "   LDR   B\n   MUL   C\n   STR   TMP1\n   LDR   AX\n   ADD   TMP1\n   STR   TMP2");
    } //------------------------------------------------------
    { //------------------------------------------------------
        String infix = "( ( AX + ( BY * C ) ) / ( D4 - E ) ) ;";
        
        assert(postfix_to_assembly(infix_to_postfix(infix)) == "   LDR   BY\n   MUL   C\n   STR   TMP1\n   LDR   AX\n   ADD   TMP1\n   STR   TMP2\n   LDR   D4\n   SUB   E\n   STR   TMP3\n   LDR   TMP2\n   DIV   TMP3\n   STR   TMP4");
    } //------------------------------------------------------
    { //------------------------------------------------------
        String infix = "( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;";
        
        assert(postfix_to_assembly(infix_to_postfix(infix)) == "   LDR   B\n   ADD   C\n   STR   TMP1\n   LDR   TMP1\n   MUL   D\n   STR   TMP2\n   LDR   A\n   ADD   TMP2\n   STR   TMP3\n   LDR   TMP3\n   MUL   F\n   STR   TMP4\n   LDR   TMP4\n   MUL   G\n   STR   TMP5\n   LDR   TMP5\n   MUL   E\n   STR   TMP6\n   LDR   H\n   MUL   TMP6\n   STR   TMP7\n   LDR   TMP7\n   ADD   J\n   STR   TMP8");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF POSTFIX_TO_ASSEMBLY TEST ]==========\n";
}
