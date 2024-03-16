#include <iostream>
#include <memory>
#include <vector>
int main(int argc, char const *argv[])
{
    std::cout<<"--------unique pointers-----------"<<std::endl;
    std::unique_ptr<int> p {new int {100}};
    std::cout<<*p<<std::endl;
    *p = 500;
    std::cout<<*p<<std::endl;
    std::cout<<p.get()<<std::endl;
    // p.reset();
    std::cout<<p.get()<<std::endl;
    std::vector<std::unique_ptr<int>> vect;
    vect.push_back(std::move(p));
    std::unique_ptr<int> ma = std::make_unique<int>(100);
    std::cout<<*ma<<std::endl;
    for (auto &i: vect){
        std::cout<<*i<<std::endl;
    }
    p.reset();

    std::cout<<"--------shared pointers-----------"<<std::endl;
    {
        std::shared_ptr<int> p = std::make_shared<int>(550);
        std::cout<<*p<<std::endl;
        *p = 500;
        std::cout<<*p<<std::endl;
        std::cout<<p.use_count()<<std::endl;
        std::shared_ptr<int> p1 = p;
        std::cout<<p1.use_count()<<"--"<<p.use_count()<<std::endl;
        p.reset();
        std::cout<<p1.use_count()<<"--"<<p.use_count()<<std::endl;
        
    }

}
