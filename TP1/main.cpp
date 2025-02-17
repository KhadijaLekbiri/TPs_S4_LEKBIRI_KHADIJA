#include <iostream> // Includes the standard input/output

#ifndef EXO
#define EXO 1
#endif


#if EXO == 1
    int main() {
        // display statements
        std::cout << "Hello, World! \n";
        std::cout << "Bienvenue en C++!";
        return 0; 
    }
#elif EXO == 2
    int main() { 
        int nbr; 
        std::cout << "Entrez un nombre:"; // the user enter the number
        std::cin >> nbr;
        std::cout << "Vous avez entre:" << nbr << std::endl; //display the given input
        return 0; 
    }
#elif EXO == 3

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
#elif EXO == 4
    // This code is the correct version

    int main() {
        std::cout << "Entrez un nombre:"; // at this line there was a missing quote and there was no ';'
        int nombre;
        std::cin >> nombre;
        std::cout << "Vous avez entré: " << nombre << std::endl; // at this line there was no ';'
        return 0;
    }

#elif EXO == 5
    int main() { 
        int temp;
        std::cout << "Entrez une température en Celsius: "; 
        std::cin >> temp; //temperature in Celsius
        std::cout << "Température en Fahrenheit: " << temp*9/5+32<< std::endl; //temperature in Fahrenheit
        return 0; 
    }
#else
#error "Veuillez definir EXO a 1,2,3 ou 4 (exemple: -DEXO=1, -DEXO=2, etc.)"
#endif

