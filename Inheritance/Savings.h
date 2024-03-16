#ifndef _SAVINGS_H_
#define _SAVINGS_H_
#include "Account.h"
class Savings: public Account{
public:
    Savings();
    ~Savings();
    void deposit(double);
    void withdraw(double);
};
#endif