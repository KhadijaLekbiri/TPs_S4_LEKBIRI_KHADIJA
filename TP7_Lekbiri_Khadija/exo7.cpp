#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SharedPtr {
    public:
        vector <string*> tab_ptr;
        string data;
        int conteur = 0;

        SharedPtr(const string& value) {
            string* ptr = new string(value);
            cout<<"Creation d'un SharedPtr vers "<<value<<endl;
            tab_ptr.push_back(ptr);
            conteur = 1;
            data = value;
        }

        
        void copy(){
            string* ptr = new string(data);
            tab_ptr.push_back(ptr);
            cout<<"Création d'une copie "<<endl;
            conteur++;
        }
        void delete_copy(){
            if (!tab_ptr.empty()){
                delete tab_ptr.back();
                tab_ptr.pop_back();
                cout<<"Destruction d'un SharedPtr"<<endl;
                conteur--;
            }
            if (conteur == 0){
                cout << "Objet supprime" << endl;
            }
        }
        void num_copy(){
            cout<<"Nombre de references : "<<conteur<<endl;
        }
        ~SharedPtr() {
            // Free all memory allocated in the vector
            for (auto ptr : tab_ptr) {
                delete ptr;
            }
            tab_ptr.clear();
        }
};

int main() {
    SharedPtr* shared_ptr = new SharedPtr("10");

    shared_ptr->num_copy();
    shared_ptr->copy();

    shared_ptr->num_copy();
    shared_ptr->delete_copy();

    shared_ptr->num_copy();
    shared_ptr->delete_copy();

    delete shared_ptr;

    return 0;
}
