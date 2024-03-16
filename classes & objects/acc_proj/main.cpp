#include <iostream>
#include "Account.h"
int main(int argc, char const *argv[])
{
    Account a;
    a.add_amount(200);
    std::cout<<a.can_dispense_cash(500);
    std::cout<<a.can_dispense_cash(50);
    return 0;
}
