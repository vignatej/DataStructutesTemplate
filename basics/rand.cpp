#include <bits/stdc++.h>
using namespace std;

class A {
    public:
        A() { cout << "A constructor\n"; }
        ~A() { cout << "A destructor\n"; }
        void virtual stg(){
            cout<<"A raa\n";
        }
    };
    
class B : public A {
    public:
        B() { cout << "B constructor\n"; }
        ~B() { cout << "B destructor\n"; }
        void stg() override{
            cout<<"B raa\n";
        }
    };


signed main(){
    B b;
    // b.stg();
    A* a = new B();
    a->stg();
}