// #include <iostream>
// #include <vector>
// #include <deque>
// #include <queue>
// #include <string>
// #include <algorithm>
// #include <map>
// #include <limits>
// #include <utility>
// #include <cmath>
// #include <list>
// #include <sstream>
// #include <set>
// #include <numeric>
// #include <bitset>
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
    vector<int> dp(amount+1, -1); dp[0]=0;
    for(int ca = 1;ca<=amount;ca++){
        int c_ans = ima;
        for(auto i: coins){
            if(ca-i<0) break;
            if(dp[ca-i]!=-1 || dp[ca-i]!=ima) c_ans=min(c_ans, dp[ca-i]+1);
        }
        dp[ca]=c_ans;
    }
    cout<<(dp[amount]==ima ? -1: dp[amount]);
}
