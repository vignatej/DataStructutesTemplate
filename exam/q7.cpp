#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main() {
    int T; cin>>T;
    while(T){T--;
        int n;cin>>n;
        vector<int> v(n+1, 1); for(int i = 1;i<=n;i++) cin>>v[i];
        vector<ll> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i = 1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int j = 1;j<=i;j++){
                if(j+v[j]-1>=i) dp[i]=min(dp[i], dp[j-1]+1);
            }
        }
        cout<<dp.back()<<"\n";
    }
}
