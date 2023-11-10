#include "utilities.hpp"

// Converts infix to prefix
String infix_to_prefix(const String expression) {
    stack<String> prefixStack;
    String left, right, oper, prefix;
    const String space = " ";
    
    for (int i = 0; i < expression.length(); ++i) {
        char token = expression[i];
        if (token == ')') {
            right = prefixStack.pop();
            oper = prefixStack.pop();
            left = prefixStack.pop();
            prefixStack.push(oper + left + right);
        }
        else if (token != '(' && token != ' ' && token != '\n' && token != '\0' && token != ';') {
            String temp;
            while (token != ' ' && token != '\0') {
                temp += token;
                token = expression[++i];
            }
            prefixStack.push(temp + space);
        }
        
        if (token == ';') {
            prefix = prefixStack.gettos();
            prefixStack.pop();
        }
    }
    return prefix;
}

// Converts infix to postfix
String infix_to_postfix(const String expression) {
    stack<String> postfixStack;
    String left, right, oper, postfix;
    const String space = " ";
    
    for (int i = 0; i < expression.length(); ++i) {
        char token = expression[i];
        if (token == ')') {
            right = postfixStack.pop();
            oper = postfixStack.pop();
            left = postfixStack.pop();
            postfixStack.push(left + right + oper);
        }
        else if (token != '(' && token != ' ' && token != '\n' && token != '\0' && token != ';') {
            String temp;
            while (token != ' ' && token != '\0') {
                temp += token;
                token = expression[++i];
            }
            postfixStack.push(temp + space);
        }
        
        if (token == ';') {
            postfix = postfixStack.gettos();
            postfixStack.pop();
        }
    }
    return postfix;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Converts prefix to assembly
String prefix_to_assembly(const String prefix) {
    String assembly;
    stack<String> assemblyStack;
    std::vector<String> tokens = prefix.split(' ');
    int counter = 1;
    
    for (int i = (int) tokens.size() - 1; i >= 0; --i) {
        const String token = tokens[i];
        if ((token != '*' && token != '/' && token != '+' && token != '-') || token == ';')
            assemblyStack.push(token);
        else {
            char number = counter + '0';
            const String TMP = "TMP";
            String left = assemblyStack.gettos();
            assemblyStack.pop();
            String right = assemblyStack.gettos();
            assemblyStack.pop();
            assemblyStack.push(TMP + number);
            
            if (counter > 1)
                assembly += '\n';
            
            if (token == '+')
                assembly += "   LDR   " + left + "\n" + "   ADD   " + right + "\n   STR   TMP" + number;
            else if (token == '-')
                assembly += "   LDR   " + left + "\n" + "   SUB   " + right + "\n   STR   TMP" + number;
            else if (token == '*')
                assembly += "   LDR   " + left + "\n" + "   MUL   " + right + "\n   STR   TMP" + number;
            else if (token == '/')
                assembly += "   LDR   " + left + "\n" + "   DIV   " + right + "\n   STR   TMP" + number;
            counter += 1;
        }
    }
    
    return assembly;
}

// Converts postfix to assembly
String postfix_to_assembly(const String postfix) {
    String assembly;
    stack<String> assemblyStack;
    std::vector<String> tokens = postfix.split(' ');
    int counter = 1;
    
    for (size_t i = 0; i < tokens.size() && tokens[i] != ';'; ++i) {
        const String token = tokens[i];
        if (token != '*' && token != '/' && token != '+' && token != '-')
            assemblyStack.push(token);
        else {
            char number = counter + '0';
            const String TMP = "TMP";
            String right = assemblyStack.gettos();
            assemblyStack.pop();
            String left = assemblyStack.gettos();
            assemblyStack.pop();
            assemblyStack.push(TMP + number);
            
            if (counter > 1)
                assembly += '\n';
            
            if (token == '+')
                assembly += "   LDR   " + left + "\n" + "   ADD   " + right + "\n   STR   TMP" + number;
            else if (token == '-')
                assembly += "   LDR   " + left + "\n" + "   SUB   " + right + "\n   STR   TMP" + number;
            else if (token == '*')
                assembly += "   LDR   " + left + "\n" + "   MUL   " + right + "\n   STR   TMP" + number;
            else if (token == '/')
                assembly += "   LDR   " + left + "\n" + "   DIV   " + right + "\n   STR   TMP" + number;
            counter += 1;
        }
    }
    
    return assembly;
}
