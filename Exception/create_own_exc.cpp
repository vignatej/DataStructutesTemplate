#include <iostream>




class DivideByZeroExc{};
class NegValExcep{};

double speed(double dist, double time){
    if (time == 0) throw DivideByZeroExc();
    if (dist<0 || time<0) throw NegValExcep();
    return static_cast<double> (dist/time);
}

int main(int argc, char const *argv[])
{
    double a, b;
    std::cout<<"enter a: ";
    std::cin>>a;
    std::cout<<"enter b: ";
    std::cin>>b;
    try{
        double c = speed(a, b);
        std::cout<<"speed is: "<<c<<std::endl;
    }catch( NegValExcep &a ){
        std::cerr<<"give a neg val"<<std::endl;
    }catch(DivideByZeroExc &b ){
        std::cerr<<"b cant be '0' "<<std::endl;
    }catch(...){
        std::cerr<<"unknown error occured"<<std::endl;
    }

}
