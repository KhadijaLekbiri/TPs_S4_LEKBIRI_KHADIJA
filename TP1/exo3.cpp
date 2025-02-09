#include <iostream> // Includes the standard input/output library

int main(){ 
    int nbr1;
    int nbr2; 
    std::cout << "Entrez deux nombres:"; // the user enter the firsst and the second number
    std::cin >> nbr1; 
    std::cin >> nbr2;
    //Displaying the results of different operations using nbr1 and nbr2
    std::cout << "Somme:" << nbr1 + nbr2 << std::endl;
    std::cout << "Difference:" << nbr1 - nbr2 << std::endl;
    std::cout << "Produit:" << nbr1 * nbr2 << std::endl;
    std::cout << "Quotient:" << nbr1/nbr2 << std::endl;
    return 0;
}