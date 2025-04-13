
#include <iostream>
#include <string>
#include <vector>
#include "Account.hpp"
#include "Checking_Account.hpp"


using namespace std;

bool Checking_Account::withdraw(double amount){
    if (amount <= balance){
        balance -= (amount+per_check_fee);
        return true;
    }
    return false;
};

