// This code is the correct version

#include <iostream>

int main() {
    std::cout << "Entrez un nombre:"; // at this line there was a missing quote and there was no ';'
    int nombre;
    std::cin >> nombre;
    std::cout << "Vous avez entré: " << nombre << std::endl; // at this line there was no ';'
    return 0;
}