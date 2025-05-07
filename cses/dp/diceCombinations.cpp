#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

ll solve(int n, vector<ll> &dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    dp[n] = solve(n-1, dp)+solve(n-2, dp)+solve(n-3, dp)+solve(n-4, dp)+solve(n-5, dp)+solve(n-6, dp);
    dp[n]%=M;
    return dp[n];
}

signed main(){
    int n; cin>>n;
    vector<ll> dp(n+1, -1);
    cout<<solve(n, dp);

    return 0;
}