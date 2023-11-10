#include <cstdlib>
#include "utilities.hpp"

////////////////////////////////////////////////////////////
void output_usage_and_exit();

////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    
    // Options
//    std::vector<String> options(2);
//    options[0] = "prefix";
//    options[1] = "postfix";
    
    // Error if there are not 2 or 3 command line arguments
    if ((argc != 2 && argc != 3))
        output_usage_and_exit();
    
//    String option(argv[1]);
    
    // Error if options dont match
//    if (option != options[0] && option != options[1])
//        output_usage_and_exit(options);
    
    // Opens input file
    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cout << "Couldn't open " << argv[1] << "\n";
        exit(2);
    }
    
    if (argc == 2) {
        char ch;
        String expression;
        
        input_file.get(ch);
        while (!input_file.eof()) {
            if (ch != ';' && ch != '\n') {
                expression += ch;
            }
            else if (ch == ';') {
//                if (option == options[0]) {
//                    const String prefix = infix_to_prefix(expression + ";");
//                    std::cout << "Infix expression: " << expression << "\n";
//                    std::cout << "Prefix expression: " << prefix << "\n\n";
//                    std::cout << prefix_to_assembly(prefix + ";") << "\n\n";
//                }
//                else if (option == options[1]) {
                    const String postfix = infix_to_postfix(expression + ";");
                    std::cout << "Infix expression: " << expression << "\n";
                    std::cout << "Postfix expression: " << postfix << "\n\n";
                    std::cout << postfix_to_assembly(postfix) << "\n\n";
//                }
                expression = '\0';
            }
            input_file.get(ch);
        }
        
        // We're done with the file
        input_file.close();
    }
    
    // Open output file if specified
    else if (argc == 3) {
        std::ofstream output_file;
        if (!output_file) {
            std::cout << "Couldn't open " << argv[2] << "\n";
            exit(2);
        }
        output_file.open(argv[2]);
        char ch;
        String expression;
        
        input_file.get(ch);
        while (!input_file.eof()) {
            if (ch != ';' && ch != '\n') {
                expression += ch;
            }
            else if (ch == ';') {
//                if (option == options[0]) {
//                    const String prefix = infix_to_prefix(expression + ";");
//                    output_file << "Infix expression: " << expression << "\n";
//                    output_file << "Prefix expression: " << prefix << "\n\n";
//                    output_file << prefix_to_assembly(prefix + ";") << "\n\n";
//                }
//                else if (option == options[1]) {
                    const String postfix = infix_to_postfix(expression + ";");
                    output_file << "Infix expression: " << expression << "\n";
                    output_file << "Postfix expression: " << postfix << "\n\n";
                    output_file << postfix_to_assembly(postfix) << "\n\n";
//                }
                expression = '\0';
            }
            input_file.get(ch);
        }
        
        output_file.close();
    }
    
    
    // Return success
    return 0;
}

////////////////////////////////////////////////////////////
void output_usage_and_exit() {
    // Output usage message
//    std::cout << "Usage:\n<> - required\n[] - optional\n" <<
//                 "\t.postfix <" << options[0] << "/" << options[1] << "> <input file> [output file]\n";
    std::cout << "Usage:\n./assembler <input file> [output file]\n";
    
    // Exit with error
    exit(1);
}

