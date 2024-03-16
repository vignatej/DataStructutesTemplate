#include <bits/stdc++.h>
using namespace std;

vector<int> prices;
vector<int> pages;
vector<vector<int>> dp;
int do_it(int i, int rem){
    if(i==prices.size()) return 0;
    if(dp[i][rem]!=-1) return dp[i][rem];
    int ans = 0;
    if(rem>=prices[i]) ans = pages[i] + do_it(i+1, rem - prices[i]);
    ans=max(ans, do_it(i+1, rem));
    dp[i][rem] = ans;
    return ans;
}

int main(){
    int n, x; cin>>n>>x;
    prices.resize(n, 0); pages.resize(n, 0);
    for(int i = 0;i<n;i++){cin>>prices[i];}
    for(int i = 0;i<n;i++){cin>>pages[i];}
    dp.resize(n, vector<int> (x+1, -1));
    cout<<do_it(0, x);

}