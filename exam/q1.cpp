#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <limits>
#include <utility>
#include <cmath>
#include <list>
#include <sstream>
#include <set>
#include <numeric>
#include <bitset>
// #include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v(1e6+5, -2);
ll mod = 1e9+7;
ll solve(ll n){
    if(n<0) return -1;
    if(n==0) return 1;
    if(v[n]!=-2) return v[n];
    ll ans = 0;
    for(ll i= 1;i<=6;i++){
        ll a = solve(n-i);
        if(a>=0) ans+=a;
        ans%=mod;
    }
    v[n]=ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    int T; cin>>T;
    while(T>0){T--;
        int n; string o, r; cin>>n; cin>>o;
        r=o; reverse(r.begin(), r.end());
        if(o==r) cout<<o;
        else if(o<r){
            if(n%2==0){cout<<o;}
            else{cout<<o<<r;}
        }else{
            if(n%2==0){cout<<r<<o;}
            else{cout<<r;}
        }
        cout<<"\n";
    }
}
