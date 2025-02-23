
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


void top_frequent_words(const std::string& text, int n){
    std::unordered_map<string,int> mp;
    std::istringstream mots(text);
    std::string word = " ";
    while (mots >> word){
        if (mp.find(word)==mp.end()){// verify if the map contains the word as a key or not 
            mp[word] = 1;}
        else{
            mp[word] += 1;}}

    std::vector<std::pair<std::string, int>> sorted_words(mp.begin(), mp.end());
    std::sort(sorted_words.begin(), sorted_words.end(),
    [](const auto& a, const auto& b) {return a.second > b.second;});
    cout<<"\n";
    for(size_t i = 0; i < sorted_words.size() && i < n; i++){
        cout<< sorted_words[i].first << " -> " << sorted_words[i].second << endl;
    }
}


int main(){
    std::string text;
    std::cout<<"Entrer une phrase: ";
    std::getline(std::cin,text);
    cout<<"Top 3 mots les plus frequents :";
    top_frequent_words(text,3);
    return 0;
}