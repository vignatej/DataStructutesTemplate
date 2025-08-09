#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    vector<vector<int>> v(n+1), rv(n+1);
    vector<bitset<50001>> g(n+1);
    vector<int> od(n+1, 0);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
        rv[b].push_back(a);
        od[a]++;
        g[a].set(b);
    }
    for(int i = 1;i<=n;i++) g[i].set(i);
    vector<int> ans(n+1, 0);
    deque<int> ts; vector<bool> comp(n+1, false);
    for(int i = 1;i<=n;i++) if(od[i]==0){ts.push_back(i); comp[i]=1;}
    while(ts.size()){
        auto t = ts.front(); ts.pop_front();
        for(auto &j: rv[t]) od[j]--;
        for(auto &j: rv[t]) if(od[j]==0 && comp[j]==false){
            ts.push_back(j); comp[j]=1;
        }
        for(auto &j: v[t]) g[t]|=g[j];
        ans[t]=g[t].count();
    }

    for(int i =1;i<=n;i++) cout<<ans[i]<<' ';
    return 0;
}