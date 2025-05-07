#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n, vector<ll> &dp){
    if(n==0) return 0;
    if(dp[n]!=INT_MAX) return dp[n];
    string s = to_string(n);
    ll ans{INT_MAX};
    for(auto &i: s){
        if(i=='0') continue;
        ll nn = n-(i-'0');
        ans = min(ans, 1+solve(nn, dp));
    }
    dp[n]=ans;
    return ans;
}

signed main(){
    int n; cin>>n;
    // for(int i =0;i<n;i++) cout<<i<<' '<<solve(i)<<'\n';
    vector<ll> dp(n+1, INT_MAX);
    cout<<solve(n, dp);
    return 0;
}