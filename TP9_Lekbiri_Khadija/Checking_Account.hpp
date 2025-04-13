#ifndef CHECKINGACCOUNT
#define CHECKINGACCOUNT

#include <iostream>
#include <string>
#include <vector>
#include "Account.hpp"


using namespace std;


class Checking_Account: public Account{
    private:
        static constexpr double per_check_fee = 1.50;
    public:
        Checking_Account(
            std::string val_name = "Unnamed Checking Account",
            double val_balance = 0.00)
        :Account(val_name,val_balance){};

        bool withdraw(double amount);

        friend std::ostream& operator<<(std::ostream& os, const Checking_Account& obj){
            os<<"[Checking_Account: "<<obj.name<<": "<<obj.balance<<"]\n";
        return os;
        };
        
        ~Checking_Account(){};
};
#endif