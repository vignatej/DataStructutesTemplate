#include <iostream>
#include <vector>

class Move{
    private:
        int *data;
    public:
        void set_data(int d){*data = d;};
        int get_data(){return *data;};
        Move(int d){
            data = new int;
            *data = d;
            std::cout<<"constructing with "<<d<<std::endl;
        };
        Move(const Move &source);
        Move(Move && src);
        ~Move(){
            if(data != nullptr){
                std::cout<<"destructing for "<<*data<<std::endl;
                delete data;
            }else{
                std::cout<<"destructing for a null ptr"<<std::endl;
            }
        };
};
Move::Move(const Move &src)
    :Move(*src.data){
    std::cout<<"copy constructor - deep copy for "<<*data<<std::endl;
};
Move::Move(Move &&src)
    :data{src.data}{
        src.data = nullptr;
        std::cout<<"using move constructor"<<std::endl;
};
int main(int argc, char const *argv[])
{
    std::vector<Move> a;
    a.push_back(Move(20));
    a.push_back(Move(30));
    return 0;
}
