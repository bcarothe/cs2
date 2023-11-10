//  =====================
//  Infix to Postfix Test
//  =====================
//
//  Tests:      prefix_to_postfix
//
//============================================================
#include "stack.hpp"
#include "utilities.hpp"
//============================================================

int main () {
    { //------------------------------------------------------
        String infix = "( ( AX + ( BY * C ) ) / ( D4 - E ) ) ;";
        String temp = infix_to_prefix(infix);
        assert(infix_to_prefix(infix) == "/ + AX * BY C - D4 E ");
    } //------------------------------------------------------
    { //------------------------------------------------------
        String infix = "( A + ( B * C ) ) ;";
        
        assert(infix_to_prefix(infix) == "+ A * B C ");
    } //------------------------------------------------------
    { //------------------------------------------------------
        String infix = "( A + B ) ;";
        
        assert(infix_to_prefix(infix) == "+ A B ");
    } //------------------------------------------------------
    { //------------------------------------------------------
        String infix = "( ( ABCDEFG + ( BY * C ) ) / ( D4 - E ) ) ;";
        
        assert(infix_to_prefix(infix) == "/ + ABCDEFG * BY C - D4 E ");
    } //------------------------------------------------------
    { //------------------------------------------------------
        String infix = "( ( 4 + ( 5 * 72 ) ) - ( 63 / 48 ) ) ;";
        
        assert(infix_to_prefix(infix) == "- + 4 * 5 72 / 63 48 ");
    } //------------------------------------------------------
    { //------------------------------------------------------
        String infix = "4 + 5 * 72 ) ) - 63 / 48 ) ) ;";
        
        assert(infix_to_prefix(infix) == "- + 4 * 5 72 / 63 48 ");
    } //------------------------------------------------------
    
    std::cout << "==========[ END OF INFIX_TO_POSTFIX TEST ]==========\n";
}
