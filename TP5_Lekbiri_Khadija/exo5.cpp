
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;



void sort_by_length(const std::string& text){
    std::unordered_map<string,int> mp;
    std::istringstream mots(text);
    std::string word = " ";
    std::string result;
    while ( mots >> word){
            mp[word] = word.length();}

    std::vector<std::pair<std::string, int>> sorted_words(mp.begin(), mp.end());
    std::sort(sorted_words.begin(), sorted_words.end(),
    [](const auto& a, const auto& b) {return a.second < b.second;});
    std::cout<<"\n";
    for(size_t i = 0; i < sorted_words.size(); i++){
        result += sorted_words[i].first ;
        result += " "; 
    }
    std::cout<<result;
}


int main(){
    std::string text;
    std::cout<<"Entrer une phrase: ";
    std::getline(std::cin,text);
    cout<<"Trie par longueur :";
    sort_by_length(text);
    return 0;
}