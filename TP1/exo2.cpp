#include <iostream> // Includes the standard input/output library

int main() { // Entry point of the C++ program
    int nbr; 
    std::cout << "Entrez un nombre:";
    std::cin >> nbr;
    std::cout << "Vous avez entre:" << nbr << std::endl;
    return 0; // Returns 0 to indicate the program ended successfully
}