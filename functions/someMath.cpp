#include <iostream>
#include <cmath>
const double pi{3.141925};
int main(int argc, char const *argv[])
{
    std::cout<<"square root"<<sqrt(300)<<std::endl;
    std::cout<<"cube root"<<cbrt(300)<<std::endl;

    std::cout<<"sine -> "<<sin(0)<<std::endl;
    std::cout<<"cos -> "<<cos(0)<<std::endl;
    
    std::cout<<"round -> "<<round(1.49)<<std::endl;
    std::cout<<"ceil -> "<<ceil(1.01)<<std::endl;
    std::cout<<"floor -> "<<floor(1.01)<<std::endl;
    
    std::cout<<"power -> "<<pow(3,10)<<std::endl;

    double rando {};
    int min{0},max{10};
    srand(time(0x0));
    for (int i=0;i<50;i++){
        rando = rand()%max + min;
        std::cout<<"-> "<<rando;
    }
    
    
    return 0;
}
