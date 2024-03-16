#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int solve(int n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    string s = to_string(n);
    int ans = 1e9;
    for(auto i: s) if(i!='0') ans = min(ans, solve(n-(i-'0')));
    dp[n] = ans+1;
    return ans+1;
}
int main(){
    int n;cin>>n;
    dp.resize(n+1, -1);
    cout<<solve(n); 
}