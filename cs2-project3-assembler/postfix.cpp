#include <cstdlib>
#include "utilities.hpp"

////////////////////////////////////////////////////////////
void output_usage_and_exit();

////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    // Error if there are not 3 things on the command line
    if (argc != 2 && argc != 3)
        output_usage_and_exit();
    
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
                std::cout << infix_to_postfix(expression + ";") << std::endl;
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
                String test = infix_to_postfix(expression + ";");
                output_file << infix_to_postfix(expression + ";") << '\n';
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
    std::cerr << "Usage:\n<> - required\n[] - optional\n\t.postfix <input file> [output file]\n";
    
    // Exit with error
    exit(1);
}

