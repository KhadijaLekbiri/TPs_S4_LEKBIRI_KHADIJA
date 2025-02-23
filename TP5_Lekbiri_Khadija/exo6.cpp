#include <iostream>
#include <regex>


bool contains_email(const std::string& text){
    std::regex email(R"((\w+@\w+\.\w+))");
    std::smatch match;
    bool result = std::regex_search(text , match , email);
    if (result){
        std::cout<<"Adresse email detectee : "<<match[0]<<std::endl;}
    return result;
}

int main(){
    std::string phrase = "Mon email est user@example.com";
    std::cout<<"Phrase : "<<phrase<<std::endl;
    contains_email(phrase);
    return 0;
}