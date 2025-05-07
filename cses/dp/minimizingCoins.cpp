#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int n, x; cin>>n>>x;
    vector<int> coins(n);
    for(int i = 0;i<n;i++) cin>>coins[i];
    sort(coins.begin(), coins.end());
    // vector<vector<ll>> T(n, vector<ll>(x+1));
    vector<ll> curr(x+1, INT_MAX);
    for(int i = 0;i<x+1;i++){
        curr[i]=INT_MAX;
        if(i%coins[0]==0) curr[i]=i/coins[0];
    }
    for(int i =1;i<n;i++){
        vector<ll> next = curr;
        for(int j = 1;j<=x;j++){
            if(j-coins[i]>=0)
                next[j]=min(next[j], next[j-coins[i]]+1);
        }
        curr=next;
    }
    if(curr[x]>=INT_MAX) cout<<-1;
    else cout<<curr[x];

    return 0;
}