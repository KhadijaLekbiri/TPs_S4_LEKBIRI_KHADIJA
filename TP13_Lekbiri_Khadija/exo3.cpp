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
    vector<int> vec = {10,12,15,17};
    cout<<"Pour un vecteur {";
    for (int j = 0; j < vec.size()-1; j++){
        cout<<vec[j]<<",";
    }
    cout<<vec[vec.size()-1];
    cout<<"}\n";

    transform(vec.begin(), vec.end(),vec.begin(), [](int &x){return x+=5;});
    for (int j = 0; j < vec.size(); j++){
        cout<<vec[j]<<" ";
    }
    return 0;
}