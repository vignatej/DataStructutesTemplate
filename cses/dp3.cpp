#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(int argc, char const *argv[])
{
    ll n, amount; cin>>n>>amount;
    vector<int> coins(n, 0);
    ll ima = (1<<30);
    for(int i = 0;i<n;i++) cin>>coins[i];
    sort(coins.begin(), coins.end());
    vector<int> dp(amount+1, 0); dp[0]=0;
    for(auto i: coins) if(i<=amount)dp[i]=1;
    ll mod = 1e9+7;
    for(int i = 0;i<=amount;i++){
        for(auto c: coins){
            if(i-c>=0)dp[i]+=dp[i-c];
            dp[i]%=mod;
        }
    }
    cout<<dp[amount];
}
