#include <iostream> // Includes the standard input/output library

int main() { 
    int temp;
    std::cout << "Entrez une température en Celsius: "; 
    std::cin >> temp; //temperature in Celsius
    std::cout << "Température en Fahrenheit: " << temp*9/5+32<< std::endl; //temperature in Fahrenheit
    return 0; 
}