#include <bits/stdc++.h>
using namespace std;

class A{
    public:
        int x = 10;
    A(int a){
        cout<<a;
    }
};

class B: virtual public A{public:
    B():A(10){}
};
class C: virtual public A{public:
    C():A(20){}
};

class D: public B, public C{public:
    D():A(30){}
};
class MyException: public exception{
    public:
        string what() noexcept{
            return "This exp";
        }
};
signed main(){
    D d;
    d.x;
    try{
        throw MyException();
    }catch(MyException &e){
        cout<<e.what();
    }
}

