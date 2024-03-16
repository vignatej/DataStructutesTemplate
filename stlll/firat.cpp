#include <iostream>
#define PI 3.14
#define Max(a,b) (a>b ? a:b)

template <typename t, typename r>
struct hello{
    t a;
    r b;
};

template <class t>
t relu(t a);

int main(int argc, char const *argv[])
{
    int a = 20 / PI;
    double b = -20;
    std::cout<<Max(a,b)<<std::endl;
    std::cout<<"relu of "<<a<<" and "<<b<<" is "<<relu(a)<<" and "<<relu(b)<<std::endl;
    hello<int, float> asd {10,2.33};
    std::cout<<asd.a<<" "<<asd.b;    

}

template <class t>
t relu(t a){
    return a>0 ? a:0;
}


