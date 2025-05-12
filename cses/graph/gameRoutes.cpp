#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int M = 1e9+7;

int ways(int curr, vector<vector<int>> &rg, vector<int> &dp){
    if(dp[curr]!=-1) return dp[curr];
    dp[curr]=0;
    for(auto i: rg[curr]){
        int i_w = ways(i, rg, dp);
        dp[curr]+=i_w;
        dp[curr]%=M;
    }
    return dp[curr];
}

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> g(n+1), rg(n+1);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a); 
    } 
    vector<int> dp(n+1, -1); dp[1]=1;
    ways(n, rg, dp);
    cout<<dp[n];

    return 0;
}