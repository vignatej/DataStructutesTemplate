#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;
VI dp;
int val(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    // cout<<n<<'\n';
    int ans{0};
    for(int i = 0;i<n;i++) 
        ans = (ans + val(n-i-1)*val(i))%M;
    dp[n]=ans;
    return ans;
}

signed main(){
    int n; cin>>n;
    dp.resize(1e6+1, -1);
    if(n%2){
        cout<<0<<'\n';
        return 0;
    }
    n/=2;
    cout<<val(n)<<'\n';

    return 0;
}