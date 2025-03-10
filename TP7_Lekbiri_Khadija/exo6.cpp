#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Fichier {
    private:
        fstream* flux; // Pointeur vers un flux de fichier
        string cheminFichier; // Nom du fichier à manipuler

    public:
        Fichier(const string& chemin) {
            cheminFichier = chemin;
            flux = nullptr; // Initialisation du pointeur
        }

        ~Fichier() {
            if (flux) {
                delete flux; // Libération de la mémoire
                flux = nullptr;
                cout << "Mémoire du flux libérée." << endl;
            }
        }

        void sauvegarder(const string& contenu) {
            cout << "Sauvegarde des données..." << endl;
            flux = new fstream(cheminFichier, ios::out); // Ouvre le fichier en mode écriture
            if (flux->is_open()) {
                *flux << contenu; // Écrit les données dans le fichier
                flux->close(); // Ferme le fichier
            } else {
                cerr << "Erreur : Impossible d'ouvrir le fichier en écriture." << endl;
            }
            delete flux; // Libération après utilisation
            flux = nullptr;
        }

        void charger() {
            cout << "Lecture des données..." << endl;
            flux = new fstream(cheminFichier, ios::in); // Ouvre le fichier en mode lecture
            if (flux->is_open()) {
                string contenu;
                cout << "Contenu du fichier :" << endl;
                while (getline(*flux, contenu)) {
                    cout << contenu << endl; // Affiche les lignes lues
                }
                flux->close(); // Ferme le fichier
            } else {
                cerr << "Erreur : Impossible d'ouvrir le fichier en lecture." << endl;
            }
            delete flux; // Libération après utilisation
            flux = nullptr;
        }
};

int main() {
    string chemin = "exemple.txt"; // Nom du fichier
    Fichier fichier(chemin);

    // Sauvegarder des données dans le fichier
    fichier.sauvegarder("Bonjour, ceci est un test.");

    // Charger et afficher les données du fichier
    fichier.charger();

    return 0;
}
