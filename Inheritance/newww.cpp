#include <iostream>

class Base{
public:
    Base(){
        std::cout<<"simple base"<<std::endl;
    };
    Base(int x){
        std::cout<<"base with "<<x<<std::endl;
    };
};

class Derived: public Base{
public:
    int var;
    Derived():var{0}{
        std::cout<<"Simple derived"<<std::endl;
    };
    Derived(int x) : Base(x), var{x}{
        std::cout<<"drrived with "<<x<<std::endl;
    }
};

int main(int argc, char const *argv[])
{
    // Base b;
    Derived d {100};
    std::cout<<d.var<<std::endl;
    return 0;
}
