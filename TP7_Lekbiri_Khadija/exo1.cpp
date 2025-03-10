
#include <iostream>
#include <string>

using namespace std;

class Joueur {
    public:
        string name;
        int score;
        void display(){
            cout<<"Joueur: "<<name<<", "<<"Score: "<<score<<endl;
        }
};

int main(){
    Joueur p1;
    Joueur p2;

    p1.name = "Alice";
    p1.score = 100;

    p2.name = "Bob";
    p2.score = 200;
    p1.display();
    p2.display();
    
    return 0;
}