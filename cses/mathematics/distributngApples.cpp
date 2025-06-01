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
    int ans = powl(a, b/2, M);
    ans*=ans; ans%=M;
    if(b%2) ans*=a;
    ans%=M; return ans;
}
int inv (int a, int m){
    return powl(a, m-2, m);
}

signed main(){
    VI fact(2e6+1, 1);
    for(int i = 2;i<=2e6;i++) fact[i]=(fact[i-1]*i)%M;
    int n, k; cin>>n>>k;
    int ans = fact[n+k-1];
    ans*=inv(fact[k], M); ans%=M;
    ans*=inv(fact[n-1], M); ans%=M;
    cout<<ans;
    return 0;
}