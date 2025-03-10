
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Etudiant {
    public:
        string nom;
        vector<float> liste_notes;

        float moyenne(){
            float total = 0;
            for (auto note : liste_notes){
                total += note;
            }
            return total/liste_notes.size();
        }
        void display(){
            cout<<"Nom: "<<nom<<endl;
            cout<<"Notes: ";
            for (auto i = 0 ; i < liste_notes.size() ; i++){
                cout<<liste_notes[i];
                if (i != liste_notes.size()-1){
                    cout<<", ";
                }
            }
            cout<<endl;
            cout<<"Moyenne: "<<moyenne()<<endl;
        }
};



int main(){
    Etudiant* student = new Etudiant();
    
    student->nom = "Karim";
    student->liste_notes = {15, 18, 12};

    student->display();

    delete student;

    return 0;
}