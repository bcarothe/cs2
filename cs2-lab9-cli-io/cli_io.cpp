#include <iostream>
#include <fstream>
#include <string>

void get_word(std::ifstream &file, char *arr) {
    int i = 0;
    file.get(arr[i]);
   
    while(arr[i] != ' ' && !file.eof()) {
        ++i;
        file.get(arr[i]);
    }
    arr[i]='\0';

}

void get_line (std::ifstream &file, char arr[]) {
    
    int i = 0;
    file.get(arr[i]);
    
    while(arr[i] != '\n' && !file.eof()) {
        ++i;
        file.get(arr[i]);
    }
    arr[i]='\0';
    
}

int main(int argc, char *argv[]) {
{
    std::ifstream file ("cli_io_file.txt");
    if(!file.is_open()) {
        std::cout << "Unable to open file\n";
        return 1;
    }
    
    // file name
    std::cout << "The file is: " << argv[0] << std::endl << std::endl;
    
    char arr[256];
    
    //-- get_word --//
    std::cout << "=====[ get_word ]=====" << std::endl;
    get_word(file, arr);
    std::cout << "Word: ";
    for(int i = 0; i < 256; ++i) {
        if(arr[i] != '\0')
            std::cout << arr[i];
        else if (arr[i] == '\0')
            break;
    }
    std::cout << std::endl;
    std::cout << "Number of words: " << argc << std::endl << std::endl;
    file.close();
}
{
    std::ifstream file ("cli_io_file.txt");
    if(!file.is_open()) {
        std::cout << "Unable to open file\n";
        return 1;
    }
    
    char arr[256];
    
    //-- get_line --//
    std::cout << "=====[ get_line ]=====" << std::endl;
    get_line(file, arr);
    
    std::cout << "Line: " << std::endl;
    std::cout << arr << std::endl;
    
    std::cout << std::endl;
    file.close();
}
}
