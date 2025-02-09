#include <iostream> // Includes the standard input/output library

int main() { // Entry point of the C++ program
    int temp;
    std::cout << "Entrez une température en Celsius: ";
    std::cin >> temp; 
    std::cout << "Température en Fahrenheit: " << temp*9/5+32<< std::endl;
    return 0; // Returns 0 to indicate the program ended successfully
}