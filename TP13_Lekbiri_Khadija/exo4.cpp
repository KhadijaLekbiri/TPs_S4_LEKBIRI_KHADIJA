#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class  Livre {
    public:
        string titre;
        int pages;
        Livre(string t, int n):titre{t}, pages{n}{};
        friend std::ostream &operator<<(std::ostream &os, const Livre &rhs){
            os<<rhs.titre<<" - "<<rhs.pages<<" pages ";
            return os;
        };

};

int main(){
    vector<Livre> vec = {
        {"C++ Moderne ",350},
        {"Apprendre Python ",500},
        {"Algorithmique",450}
    };
    cout<<"A partir des livres :\n";
    for(Livre livre: vec){
        cout<<livre<<" ";
    }

    cout<<"\n\n- Tri par titre :\n"; 
    sort(vec.begin(), vec.end(), [](Livre l1, Livre l2){
        return l1.titre < l2.titre;});
    for(Livre livre: vec){
        cout<<livre<<"\n";
    }
    
    cout<<"\n- Tri par nombre de pages decroissant :\n"; 
    sort(vec.begin(), vec.end(), [](Livre l1, Livre l2){
        return l1.pages > l2.pages;});
    for(Livre livre: vec){
        cout<<livre<<"\n";
    }
    return 0;
}