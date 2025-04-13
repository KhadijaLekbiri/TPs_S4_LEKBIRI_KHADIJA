
#include <iostream>
#include <string>
#include <vector>
#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Trust_Account.hpp"


using namespace std;

bool Trust_Account::deposit(double amount){
    bool res = Savings_Account::deposit(amount); 
    if(res){
        if (amount == bonus_threshold){
            balance += bonus_amount;
        }
        return true;
    }
    return false;
};

bool Trust_Account::withdraw(double amount){
    if(num_withdrawals <3 && amount <= 0.2*balance){
        Savings_Account::withdraw(amount);
        num_withdrawals++;
        return true;
    }
    return false;
};


