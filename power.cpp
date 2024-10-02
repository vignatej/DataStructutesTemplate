#include <bits/stdc++.h>
using namespace std;
#define ll long long

int calc_pow(int x, int y, int m){
    x%=m;
    if(y==0) return 1;
    if(y==1) return x;
    ll a = calc_pow(x, y/2, m);
    if(y%2==0) return (a*a)%m;
    return (((x*a)%m)*a)%m;
}


int main(){
    cout<<calc_pow(3000, 1000053, 100005);
}