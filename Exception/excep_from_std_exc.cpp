#include <iostream>


class IllegalBal: public std::exception{
public:
    IllegalBal() noexcept = default;
    ~IllegalBal() = default;
    virtual const char* what() noexcept{
        return "orey illegal balance raa";
    }
};

int main(int argc, char const *argv[])
{
    int a = 0;
    int b;
    std::cin>>b;
    try{
        if(b==0) throw IllegalBal();
        std::cout<<"ojhsd"<<std::endl;
    }catch(IllegalBal &exc){
        std::cerr<<exc.what()<<std::endl;
    }


}
