#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;

int powl(int a, int b, int M){
    if(b==0) return 1;
    if(b==1) return a;
    if(a==0) return 0;
    int ans = powl(a, b/2, M);
    ans*=ans; ans%=M;
    if(b%2) ans*=a; ans%=M;
    return ans;
}
int calc_inv(int x, int M){
    return powl(x, M-2, M);
}
VI fact;
int ncr(int n, int r){
    int ans = fact[n];
    ans*=calc_inv(fact[n-r], M);
    ans%=M;
    ans*=calc_inv(fact[r], M);
    ans%=M;
    return ans;
}

signed main(){
    int n; cin>>n;
    string s; cin>>s;
    
    if(n%2){
        cout<<0;
        return 0;
    }
    int rl = n-s.length();
    int rc{n/2}, ro{n/2};
    for(auto i: s) 
        if(i=='(') rc--;
        else ro--;
    if(rc<0 || ro<0){
        cout<<0; 
        return 0;
    }
    int c{0};
    for(auto i: s){
        if(i=='(') c++;
        else c--;
        if(c<0){
            cout<<0; return 0;
        }
    }
    if(n==s.length()){
        cout<<1;
        return 0;
    }
    if(rc==0){
        cout<<1; return 0;
    }
    VI &a = fact;
    fact.resize(1e6+1, 1);
    for(int i = 2;i<1e6+1; i++) 
        fact[i]=(fact[i-1]*i)%M;

    int ans = ncr(rl, rc)-ncr(rl, rc-1);
    ans%=M;ans+=M; ans%=M;
    cout<<ans;

    return 0;
}