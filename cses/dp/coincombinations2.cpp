#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;
signed main(){
    int n; int x; cin>>n>>x;
    vector<ll> coins(n);
    for(int i = 0;i<n;i++) cin>>coins[i];
    sort(coins.begin(), coins.end());
    vector<ll> curr(x+1, 0);
    for(int i = 0;i<=x;i++) 
        if(i%coins[0]==0) curr[i]=1;
    for(int i = 1;i<n;i++){
        vector<ll> next = curr;
        for(int j = 1;j<=x;j++){
            if(j-coins[i]>=0) next[j]+=next[j-coins[i]];
            next[j]%=M;
        }
        curr=next;
    }
    cout<<curr[x];

    return 0;
}