#include <iostream> // Includes the standard input/output library

int main() { // Entry point of the C++ program
    int nbr1;
    int nbr2; 
    std::cout << "Entrez deux nombres:";
    std::cin >> nbr1; 
    std::cin >> nbr2;
    std::cout << "Somme:" << nbr1 + nbr2 << std::endl;
    std::cout << "Différence:" << nbr1 - nbr2 << std::endl;
    std::cout << "Produit:" << nbr1 * nbr2 << std::endl;
    std::cout << "Quotient:" << nbr1/nbr2 << std::endl;
    return 0; // Returns 0 to indicate the program ended successfully
}