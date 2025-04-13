#ifndef ACCOUNT
#define ACCOUNT

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Account{
    private:
        static constexpr const char* def_name = "Unnamed Account"; 
        static constexpr double def_balance = 0.00;
    protected:
        string name;
        double balance;
    public:
        Account(std::string val_name = def_name, double val_balance = def_balance)
            : name(val_name), balance(val_balance) {};

        bool deposit(double amount);
        bool withdraw(double amount);

        string get_name();
        double get_balance();

        void set_name(string val);
        void set_balance(double b);

        friend std::ostream& operator<<(std::ostream& os, const Account& obj){
            os<<"[Account: "<<obj.name<<": "<<obj.balance<<"]\n";
            return os;
        };
        ~Account(){};
};

#endif