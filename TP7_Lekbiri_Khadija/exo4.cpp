
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Objet {
    public:
        string nom;
        int quantite;
        Objet(string name, int qqt){
            nom = name;
            quantite = qqt;
        }
};
class Inventaire {
    public:
        std::vector<Objet*> objs;
        void append(Objet* obj){
            objs.push_back(obj);
            cout<<"Ajout de "<<obj->nom<<" (x"<<obj->quantite<<")"<<endl;
        }
        void remove(Objet* obj){
            for (auto i = 0 ; i<objs.size() ; i++){
                if (obj == objs[i]){
                    delete objs[i];
                    objs.erase(objs.begin()+i);
                    break;
                }
            }
            return;
        }
        void display(){
            cout<<"Inventaire :"<<endl;
            for (auto item : objs){
                cout<<"- "<<item->nom<<" (x"<<item->quantite<<")"<<endl;
            }
        }
        ~Inventaire(){
            for (auto item : objs){
                delete item;}
            cout<<"Memoire de l'inventaire liberee. "<<endl;
        };
};



int main(){
    Inventaire* produits = new Inventaire();

    Objet* e1 = new Objet("Pomme", 3);
    Objet* e2 = new Objet("Eppe", 1);
    
    produits->append(e1);
    produits->append(e2);

    produits->display();

    delete produits;

    return 0;
}