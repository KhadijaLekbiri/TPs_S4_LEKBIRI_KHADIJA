#ifndef SAVINGACCOUNT
#define SAVINGACCOUNT

#include <iostream>
#include <string>
#include <vector>
#include "Account.hpp"


using namespace std;


class Savings_Account: public Account{
    private:
        static constexpr double def_int_rate = 0.00;
    public:
        double int_rate;
        Savings_Account(
            std::string val_name = "Unnamed Savings Account",
            double val_balance = 0.00,
             double val_int_rate = def_int_rate)
        :Account(val_name,val_balance), int_rate(val_int_rate){};

        bool deposit(double amount);

        friend std::ostream& operator<<(std::ostream& os, const Savings_Account& obj){
            os<<"[Savings_Account: "<<obj.name<<": "<<obj.balance<<", "<<obj.int_rate<<"]\n";
            return os;
        };

        ~Savings_Account(){};
};

#endif 