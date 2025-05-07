#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;
ll solve(int n, vector<int> &coins, vector<ll> &dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    ll ans{0};
    for(auto &i: coins) ans=(ans+solve(n-i, coins, dp))%M;
    ans%=M;
    dp[n]=ans;
    return ans;
}

signed main(){
    int n, x; cin>>n>>x;
    vector<int> v(n, 0);
    for(int i = 0;i<n;i++) cin>>v[i];
    vector<ll> dp(x+1, -1);
    cout<<solve(x, v, dp);

    return 0;
}