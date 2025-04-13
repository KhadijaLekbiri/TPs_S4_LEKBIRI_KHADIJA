#include <iostream>
#include <string>
#include "Account.hpp"

using namespace std;

bool Account::deposit(double amount){
    if (amount >= 0 ){
        this->balance += amount; 
        return true;
    }
    return false;
};

bool Account::withdraw(double amount){
    if (amount <= balance){
        this->balance -= amount; 
        return true;
    }
    return false;
};


