
#include <iostream>
#include <string>

using namespace std;

class Joueur {
    public:
        string name;
        int score;

        Joueur(string player_name=" ", int player_score=0){
            name = player_name;
            score = player_score;
        }

        void display(){
            cout<<"Nom: "<<name<<", "<<"Score: "<<score<<endl;
        }

        ~Joueur(){
            cout<<"Objet dynamique supprime. ";
        }
};

int main(){
    Joueur* p1 = new Joueur();

    p1->name = "Alice";
    p1->score = 100;

    p1->display();
    
    delete p1;

    return 0;
}