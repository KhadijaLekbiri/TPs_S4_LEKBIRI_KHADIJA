#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class  Additionneur {
    private:
        int valeur;
    public:
        Additionneur(int val):valeur{val}{};
        void operator() (int x){
            cout<<x + valeur<<" ";
        };

};

int main(){
    vector<int> vec = {1,2,3,4,5};
    int val = 10;
    Additionneur add(val);
     
    cout<<"Pour un vecteur {";
    for (int j = 0; j < vec.size()-1; j++){
        cout<<vec[j]<<",";
    }
    cout<<vec[vec.size()-1];
    cout<<"}\n";

    for_each(vec.begin(), vec.end(), add);
    return 0;
}