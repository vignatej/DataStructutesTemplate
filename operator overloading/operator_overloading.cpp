#include <iostream>
#include <cstring>

class MyString{
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream &operator>>(std::istream &in, MyString &rhs);
    private:
        char *p;
    public:
        MyString();
        MyString(const char *src);
        MyString(const MyString &src);
        ~MyString();

        MyString &operator=(const MyString &rhs);//copy assignment
        MyString &operator=(MyString &&rhs);//move assignment

        void dispaly() const;
        int getLength() const;
        const char* getstr() const;
};

MyString::MyString()
    :p{nullptr}{
        p = new char[1];
        *p = '\0';
};

MyString::MyString(const char* src)
    :p{nullptr}{
        if(src == nullptr){
            p = new char[1];
            *p = '\0';
        }else{
            p = new char[strlen(src)+1];
            strcpy(p,src);
        } 
};



MyString::MyString(const MyString & src)
    :p{nullptr}
{
    p = new char[strlen(src.p)+1];
    strcpy(p, src.p);
};




MyString::~MyString(){
    delete [] p;
};
void MyString::dispaly() const{
    std::cout<<p<<":"<<getLength()<<std::endl;
};
int MyString::getLength() const {return std::strlen(p);};
const char* MyString::getstr() const{return p;};

MyString &MyString::operator=(const MyString &rhs){
    std::cout<<"op inv"<<std::endl;
    if(this == &rhs){
        return *this;
    }
    delete [] p;
    p = new char[strlen(rhs.p)+1];
    strcpy(p, rhs.p);
    return *this;
}

MyString &MyString::operator=(MyString &&rhs){
    std::cout<<"move assignment oper"<<std::endl;
    if(&rhs == this){
        return *this;
    };
    delete [] p;
    p = rhs.p;
    rhs.p = nullptr;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const MyString &rhs){
    os<<rhs.p;
    return os; 
}

std::istream &operator>>(std::istream &in, MyString &rhs){
    char *buff = new char[1000];
    in>>buff;
    rhs = MyString(buff);
    delete [] buff;
    return in;
}


int main(int argc, char const *argv[])
{
    MyString empty;
    MyString hello("hello");
    MyString qwer {hello};

    empty.dispaly();
    hello.dispaly();
    qwer.dispaly();
    MyString hel = hello;
    hel.dispaly();
    hel = empty; //operator assignment
    hel.dispaly();
    std::cout<<"last"<<std::endl;
    MyString qwerty;
    qwerty = "ufff";
    qwerty.dispaly();
    std::cout<<qwerty<<std::endl;
    std::cin>>hel;
    std::cout<<hel<<std::endl;
    
    
    std::cout<<"completed"<<std::endl;

    return 0;
}
