#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;
map<int, int> m;
int solve(int a, int b){
    if(b==0) return 1;
    if(a==b) return 1;
    if(b==1) return a;
    if(a<b) return 0;
    int hv = (a<<32) + b;
    if(m.find(hv)!=m.end()) return m[hv];
    int ans = solve(a-1, b-1)+solve(a-1, b);
    ans%=M; ans+=M; ans%=M;
    m[hv]=ans;
    return ans;
}

int powl(int a, int b, int M){
    if(b==0) return 1;
    if(b==1) return a;
    int ans = powl(a, b/2, M);
    ans*=ans; ans%=M;
    if(b%2) ans*=a;
    ans%=M;
    return ans;
}

int calc_inv(int a, int m){
    return powl(a, m-2, m);
}

signed main(){
    int T; cin>>T;
    VI fact(1e6+1, 1);
    for(int i =2;i<=1e6;i++){
        fact[i]=(fact[i-1]*i)%M;
    }
    while(T--){
        int a, b; cin>>a>>b;
        // cout<<solve(a, b)<<'\n';
        int ans = fact[a];
        ans*=calc_inv(fact[b], M); ans%=M;
        ans*=calc_inv(fact[a-b], M); ans%=M;
        cout<<ans<<'\n';
    }

    return 0;
}