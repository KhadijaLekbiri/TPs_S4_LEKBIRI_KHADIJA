#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void filtrer(vector<int> vec, function<bool(int)> pre){
    for (int i = 0; i < vec.size(); i++){
        if(pre(vec[i])){
            cout<<vec[i]<<" ";
        }
    }
    cout<<'\n';
};
    
    
int main(){
    vector<int> vec = {10,15,20,25,30,50,75};
    auto l1 = [](int x){return (x > 20)? true: false;};
    auto l2 = [](int x){return (x % 2)? false: true;};
    cout<<"Pour un vecteur {";
    for (int j = 0; j < vec.size()-1; j++){
        cout<<vec[j]<<",";
    }
    cout<<vec[vec.size()-1];
    cout<<"}\n";
    
    cout<<"- Predicat : 'x > 20'"<<'\n';
    filtrer(vec, l1);
    cout<<"- Predicat : 'x % 2 == 0'"<<'\n';
    filtrer(vec, l2);
    return 0;
}