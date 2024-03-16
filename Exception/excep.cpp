#include <iostream>

int main(int argc, char const *argv[])
{
    int a;
    std::cin>>a;
    int b;
    std::cin>>b;
    try{
        if (b==0) throw 0;
        int c = a/b;
        std::cout<<c;
        throw std::string {"asd"};
    }catch(int &a){
        std::cerr<<"div by zero"<<std::endl;
    }catch(...){
        std::cerr<<"uff"<<std::endl;
    }
    
}
