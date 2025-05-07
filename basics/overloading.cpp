#include <bits/stdc++.h>
using namespace std;

class A{
public:
    int a; int b;
    A(int a, int b){
        this->a = a;
        this->b = b;
    }
    ~A(){
        cout<<a<<" "<<b<<" descructed\n";
    }
    A(const A &obj){
        this->a = obj.a;
        this->b = obj.b;
    }
    void operator+=(const A &obj){
        this->a+=obj.a;
    }
    A operator+(const A &obj){
        return A(a+obj.a, b);
    }
};


signed main(){
    vector<A> asa(5, {1, 2});
    asa.clear();
    cout<<"comp\n";


    A a(1,2); A b(3,4);
    asa.push_back(a);
    asa.push_back(b);
    asa[0]+=asa[1];
    asa.clear();
    cout<<"comp\n";

    // A a(1,2); A b(3,4);
    asa.push_back(a);
    asa.push_back(b);
    cout<<(asa[0]+asa[1]).a<<'\n';

}