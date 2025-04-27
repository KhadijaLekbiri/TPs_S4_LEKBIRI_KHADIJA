#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class Conteneur {
    public:
        vector<T> vec;
        int capacity;
        Conteneur(int c)
            :capacity(c){};

        void ajouter(T element){
            if (vec.size() + 1 <= capacity){
                vec.push_back(element);
                return ;
            }
            cout<<"Capacite depassee \n";
        }

        T obtenir(int index){
            return vec[index];
        }
        ~Conteneur(){};
};



int main() {
    Conteneur<int> c1(3); // Capacité de 3
    c1.ajouter(10);
    c1.ajouter(20);
    c1.ajouter(30);
    c1.ajouter(40); // Capacité dépassée
    std::cout << c1.obtenir(0) << " " << c1.obtenir(1) << std::endl; // Affiche 10 20
    Conteneur<std::string> c2(2);
    c2.ajouter("Bonjour");
    c2.ajouter("Monde");
    std::cout << c2.obtenir(0) << " " << c2.obtenir(1) << std::endl; // Affiche Bonjour Monde
    return 0;
}

    