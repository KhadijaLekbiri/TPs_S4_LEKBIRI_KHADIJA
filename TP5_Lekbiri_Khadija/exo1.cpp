#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if a string is a palindrome
bool is_palindrome(const std::string& chaine) {
    std::string chaine1 = chaine;
    std::string chaine2 = chaine;

    // Remove spaces from both strings
    chaine1.erase(std::remove(chaine1.begin(), chaine1.end(), ' '), chaine1.end());
    chaine2.erase(std::remove(chaine2.begin(), chaine2.end(), ' '), chaine2.end());

    // Convert both strings to lowercase
    std::transform(chaine1.begin(), chaine1.end(), chaine1.begin(), ::tolower);
    std::transform(chaine2.begin(), chaine2.end(), chaine2.begin(), ::tolower);

    // Reverse the second string
    std::reverse(chaine2.begin(), chaine2.end());

    // Check if the original (processed) string is equal to its reverse
    if (chaine1 == chaine2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::string chaine = "Engage le jeu que je le gagne";

    // Call the function and print the result
    if (is_palindrome(chaine)) {
        std::cout << "\"" << chaine << "\" est un palindrome." << std::endl;
    } else {
        std::cout << "\"" << chaine << "\" n'est pas un palindrome." << std::endl;
    }

    return 0;
}
