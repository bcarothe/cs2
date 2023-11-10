#include <iostream>
#include <cstdlib>

const int STRING_SIZE = 60;

int calculatePopulation(int, int);

int main(int argc, const char * argv[]) {
    argc = 1;
    
    std::cout << "Enter the name of the university\n";
    char univName [STRING_SIZE];
    std::cin.getline(univName, STRING_SIZE);
    
    
    char done = 'N';
    while(done != 'Y' && done != 'y') {
        
        std::cout << "What is the current population? ";
        int pop;
        std::cin >> pop;
        if (pop < 0) {
            std::cout << "Invalid Input Error!\n";
            return -1;
        }
        
        std::cout << "What is the rate of growth? (e.g., for 10% enter 10) ";
        int growth;
        std::cin >> growth;
        if (growth < 0) {
            std::cout << "Invalid Input Error!\n";
            return -1;
        }
        
        std::cout << "\nYear\tNew Population" << std::endl;
        int *newpop = new int;
        for (int i = 1; i <= 5; ++i) {
            *newpop = calculatePopulation( pop , growth );
            std::cerr << "newpop: " << *newpop << std::endl;
            pop = *newpop;
            std::cout << i << "\t \t" << *newpop << std::endl;
            // delete newpop;
        }
        
        std::cout << "\nFinal population of " << univName
        << " is " << *newpop << std::endl;
        
        std::cout << "Done? (Y/N) ";
        std::cin >> done;
        switch (toupper(done)) {
            case 'Y':
                std::cout << "Exiting...\n";
                break;
            case 'y':
                std::cout << "Exiting...\n";
                break;
            case 'N':
                std::cout << "Starting again\n";
                std::cout << "------------------------------\n";
                break;
            default:
                std::cout << argv[1] << ": Invalid input\n";
                std::cout << "The program will exit\n";
                std::cout << "------------------------------\n";
                return -1;
        }
    }
    return 0;
}

int calculatePopulation( int pop, int growth) {
    float growthRate = (float) growth / 100;
    std::cerr << "pop: " << pop << std::endl;
    float increase = (float) pop * growthRate;
    return (pop + increase);
    
}
