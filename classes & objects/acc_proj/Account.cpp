#include "Account.h"

void Account::add_amount(int am){
    balance += am;
};
bool Account::can_dispense_cash(int amount){
    return amount <= balance;
}