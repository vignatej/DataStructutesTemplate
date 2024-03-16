#include <iostream>
#include <memory>

class Base{
    public:
        virtual void say_hello() const {
            std::cout<<"hello from base class"<<std::endl;
        }
        virtual ~Base(){
            std::cout<<"base destructor"<<std::endl;
        }
};
class Derived final: public Base{
    public:
        virtual void say_hello() const override {
            std::cout<<"hello from derived class"<<std::endl;
        }
        virtual ~Derived() final{
            std::cout<<"Derived destructor"<<std::endl;
        }
};

void greetings(const Base &b){
    std::cout<<"greetings"<<std::endl;
    b.say_hello();
}

int main(int argc, char const *argv[])
{
    Base b;
    b.say_hello();
    Derived d;
    d.say_hello();
    Base *g = &d;
    g->say_hello();
    greetings(b);
    greetings(d); 
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();

    Base *a = new Base();
    a->say_hello();
    Base* bq = new Derived();
    bq->say_hello();
    {
        std::cout<<"start"<<std::endl;
        Derived *d = new Derived();
        Base *b = d;
        delete d;
        // d->say_hello();
        std::cout<<"123"<<std::endl;
        std::cout<<"end"<<std::endl;
    }
    
    std::cout<<"completed"<<std::endl;
}
