
#include <iostream>
#include <string>

using namespace std;

class Joueur {
    public:
        string name;
        int score;
        Joueur(string player_name, int player_score){
            cout<<"Constructeur appele \n";
            name = player_name;
            score = player_score;
        }
        void display(){
            cout<<"Joueur: "<<name<<", "<<"Score: "<<score<<endl;
        }
        ~Joueur(){
            cout<<"Destructeur appele \n";
        }
};

int main(){
    Joueur person("Alice", 100);

    person.display();

    return 0;
}