#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
    int a = 10;
    int &ref = a;
    std::cout<<a<<"--"<<ref<<std::endl;
    a=20;
    std::cout<<a<<"--"<<ref<<std::endl;
    ref=30;
    std::cout<<a<<"--"<<ref<<std::endl;


    std::vector<std::string> ann = {"hello","vigna","tej"};
    for(auto i: ann){
        i="asd";
    }
    for(auto i: ann){
        std::cout<<i<<std::endl;
    }
    for(auto &i: ann){
        i="asd";
    }
    for(auto i: ann){
        std::cout<<i<<std::endl;
    }
    int arr1 [50] {};
    int arr2[50] {};
    

}
