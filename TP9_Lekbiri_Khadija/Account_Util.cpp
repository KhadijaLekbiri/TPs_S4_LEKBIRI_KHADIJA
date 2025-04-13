#include "Account_Util.hpp"

using namespace std;

void display(const std::vector<Account>& accounts){
    cout<<"=== Accounts==========================================="<<'\n';
    for (Account acc: accounts){
        cout<<acc;
    }
    cout<<'\n';
};

void deposit(std::vector<Account>& accounts, double amount){
    cout<<"=== Depositing to Accounts ================================="<<'\n';
    for (Account& acc: accounts){
        bool res = acc.deposit(amount);
        if (res){
            cout<<"Deposited "<<amount<<" to "<<acc;
        }        
    }
    cout<<'\n';
};

void withdraw(std::vector<Account>& accounts, double amount){
    cout<<"=== Withdrawing from Accounts======================="<<'\n';
    for (Account& acc: accounts){
        bool res = acc.withdraw(amount);
        if (res){
            cout<<"Withdrew "<<amount<<" from "<<acc;
        }
        else{
            cout<<"Failed Withdrawal of "<<amount<<" from "<<acc;
        }
        
        
    }
    cout<<'\n';
};
   

void display(const std::vector<Savings_Account>& accounts){
    cout<<"=== Savings Accounts====================================="<<'\n';
    for (Savings_Account acc: accounts){
        cout<<acc;
    }
    cout<<'\n';
};

void deposit(std::vector<Savings_Account>& accounts, double amount){
    cout<<"=== Depositing to Savings Accounts==========================="<<'\n';
    for (Savings_Account& acc: accounts){
        bool res = acc.deposit(amount);
        if (res){
            cout<<"Deposited "<<amount<<" to "<<acc;
        }        
    }
    cout<<'\n';
};

void withdraw(std::vector<Savings_Account>& accounts, double amount){
    cout<<"=== Withdrawing from Savings Accounts======================="<<'\n';
    for (Savings_Account& acc: accounts){
        bool res = acc.Account::withdraw(amount);
        if (res){
            cout<<"Withdrew "<<amount<<" from "<<acc;
        }
        else{
            cout<<"Failed Withdrawal of "<<amount<<" from "<<acc;
        }
        
        
    }
    cout<<'\n';
};


void display(const std::vector<Checking_Account>& accounts){
    cout<<"=== Checking Accounts====================================="<<'\n';
        for (Checking_Account acc: accounts){
            cout<<acc;
        }
        cout<<'\n';
    };

void deposit(std::vector<Checking_Account>& accounts, double amount){
    cout<<"=== Depositing to Checking Accounts==========================="<<'\n';
    for (Checking_Account& acc: accounts){
        bool res = acc.Account::deposit(amount);
        if (res){
            cout<<"Deposited "<<amount<<" to "<<acc;
        }        
    }
    cout<<'\n';
};

void withdraw(std::vector<Checking_Account>& accounts, double amount){
    cout<<"=== Withdrawing from Checking Accounts======================="<<'\n';
    for (Checking_Account& acc: accounts){
        bool res = acc.withdraw(amount);
        if (res){
            cout<<"Withdrew "<<amount<<" from "<<acc;
        }
        else{
            cout<<"Failed Withdrawal of "<<amount<<" from "<<acc;
        }
        
        
    }
    cout<<'\n';
};



void display(const std::vector<Trust_Account>& accounts){
    cout<<"=== Trust Accounts====================================="<<'\n';
        for (Trust_Account acc: accounts){
            cout<<acc;
        }
        cout<<'\n';
    };

void deposit(std::vector<Trust_Account>& accounts, double amount){
    cout<<"=== Depositing to Trust Accounts==========================="<<'\n';
    for (Trust_Account& acc: accounts){
        bool res = acc.deposit(amount);
        if (res){
            cout<<"Deposited "<<amount<<" to "<<acc;
        }        
    }
    cout<<'\n';
};

void withdraw(std::vector<Trust_Account>& accounts, double amount){
    cout<<"=== Withdrawing from Trust Accounts======================="<<'\n';
    for (Trust_Account& acc: accounts){
        bool res = acc.withdraw(amount);
        if (res){
            cout<<"Withdrew "<<amount<<" from "<<acc;
        }
        else{
            cout<<"Failed Withdrawal of "<<amount<<" from "<<acc;
        }
        
        
    }
    cout<<'\n';
};


