
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

std::string encode_rle(const std::string& phrase){
    std::unordered_map<string,int> mp;
    std::string result;
    std::string word = " ";
    std::string lastword = " ";
    for (int i= 0; i <= phrase.length();i++){
        word = phrase[i];
        if (mp.find(word)==mp.end()){// verify if the map contains the word as a key or not 
            if (i>0){
                lastword = phrase[i-1];
                result += to_string(mp[lastword]);
            }
            result += word;
            mp[word] = 1;}
        else{
            mp[word] += 1;}
    }
    return result;
}

int main(){
    std::string phrase;
    std::string sortie;
    std::cout<<"Entrer une phrase: ";
    std::getline(std::cin,phrase);
    sortie = encode_rle(phrase);
    std::cout<<sortie;
    return 0;
}