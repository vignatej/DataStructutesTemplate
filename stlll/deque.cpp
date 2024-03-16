#include <iostream>
#include <deque>



bool pallindrome1(std::string str){
    std::deque<char> d;
    std::copy(str.begin(), str.end(), std::back_inserter(d));
    auto f1 = d.begin();
    auto f2 = d.rbegin();
    while(f1!=d.end() && f2 != d.rend()){
        while(*f1 == ' ') f1++;
        while(*f2 == ' ') f2++;
        if(*f1 != *f2){
            return false;
        }
        f1++;f2++;
    }return true;
};

bool pall2(std::string str){
    std::deque<char> d;
    std::copy(str.begin(), str.end(), std::back_inserter(d));
    while (d.size()>1){
        while (d.front() == ' ') d.pop_front();
        while (d.back() == ' ') d.pop_back();
        if(d.front() != d.back()) return false;
        d.pop_back();d.pop_front();
    }return true;
}

int main(int argc, char const *argv[])
{
    std::deque<int> d1 {1,2,3,4,5};
    std::cout<<pallindrome1(std::string("helloolleh"))<<std::endl;
    std::cout<<pall2(std::string("helloolleh"))<<std::endl;
    std::cout<<pallindrome1(std::string("noo    oo oon"))<<std::endl;
    std::cout<<pall2(std::string("noo"))<<std::endl;
    

    return 0;
}
