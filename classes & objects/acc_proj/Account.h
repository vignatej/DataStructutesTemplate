#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
class Account{
    private:
        int balance {0};
    public:
        void add_amount(int amount);
        bool can_dispense_cash(int amount);
};
#endif