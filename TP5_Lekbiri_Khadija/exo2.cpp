
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

void word_frequency(const std::string& phrase){
    std::unordered_map<string,int> mp;
    std::istringstream mots(phrase);
    std::string word;
    while (mots >> word){
        if (mp.find(word)==mp.end()){// verify if the map contains the word as a key or not 
            mp[word] = 1;}
        else{
            mp[word] += 1;}
    }
    
    for (auto paire : mp){
        cout<<paire.first<<" -> "<<paire.second<<endl;
    }}

int main(){
    std::string phrase;
    cout<<"Entrer une phrase: ";
    std::getline(std::cin,phrase);
    word_frequency(phrase);
    return 0;
}