#include <iostream>
#include "Account.h"

Account::Account(){};
Account::~Account(){};
void Account::deposit(double amount){
    std::cout<<"Account deposited with: "<<amount<<std::endl;
};
void Account::withdraw(double amount){
    std::cout<<"Account withdrawn was: "<<amount<<std::endl;
}