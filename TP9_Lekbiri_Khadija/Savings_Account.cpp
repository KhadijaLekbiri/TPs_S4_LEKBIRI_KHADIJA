
#include <iostream>
#include <string>
#include <vector>
#include "Savings_Account.hpp"

using namespace std;

bool Savings_Account::deposit(double amount){
    bool res = Account::deposit(amount);
    if (res){
        balance += amount*int_rate/100;
        return true;
    }
    return false;
};   

