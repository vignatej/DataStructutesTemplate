#include<iostream>
#include <list>

void print(std::list<int> &l){
    auto i = l.begin();
    while(i!=l.end()){
        std::cout<<*i<<", ";
        ++i;
    }std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    std::list<int> l {1,2,3,4,5};
    auto a = l.begin();
    print(l);
    a = ++(++a);
    l.insert(a, 20);
    print(l);
    l.erase(a);
    print(l);
    l.resize(100);
    print(l);
}
