
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    std::ofstream out_file("output.txt");
    if (!out_file) {
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;
    }

    double num;
    std::cout << "Entrez des nombres flottants (entree vide pour arreter) : ";
    while (std::cin >> num) {
        out_file << std::fixed << std::setprecision(2) << std::setw(10) << std::left << num << std::endl;
    }
    out_file.close();
    std::cout << "Nombres enregistres dans output.txt" << std::endl;
    return 0;
}
    