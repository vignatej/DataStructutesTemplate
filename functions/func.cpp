#include <iostream>

inline void cng(int&a, int &b){
    int tm = a;
    a=b;b=tm;
}

int main(int argc, char const *argv[])
{
    int a{1}, b{6};
    std::cout<<a<<"--"<<b<<std::endl;
    cng(a, b);
    std::cout<<a<<"--"<<b<<std::endl;
    return 0;
}
