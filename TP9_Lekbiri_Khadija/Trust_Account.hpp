#ifndef TRUSTACCOUNT
#define TRUSTACCOUNT

#include <iostream>
#include <string>
#include <vector>
#include "Savings_Account.hpp"


using namespace std;


class Trust_Account: public Savings_Account{
    private:
        static constexpr double bonus_amount = 50.0;
        static constexpr double bonus_threshold = 5000.0;
        static constexpr double max_withdrawals = 3;
        static constexpr double max_withdraw_percent = 0.2;
    public:
        int num_withdrawals = 0;

        Trust_Account(
            std::string val_name = "Unnamed Trust Account",
            double val_balance = 0.00,
            double val_int_rate = 0.00)
            :Savings_Account(val_name, val_balance, val_int_rate){};

        bool deposit(double amount);
        
        bool withdraw(double amount);

        friend std::ostream& operator<<(std::ostream& os, const Trust_Account& obj){
            os<<"[Trust Account: "<<obj.name<<": "<<obj.balance<<", "<<obj.int_rate<<"%, withdrawals:"<<obj.num_withdrawals<<"]\n";
            return os;
        };

        ~Trust_Account(){};
};

#endif