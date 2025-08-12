#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

void dfs(int curr, int p, vector<bool> &mark,
    vector<int> &tin, vector<int> &low, int &timer,
    vector<vector<int>> &g,
    vector<vector<int>> &bridges){
    if(mark[curr]) return;
    mark[curr]=1;
    tin[curr]=low[curr]=timer++;
    for(auto &i:g[curr]){
        if(i==p) continue;
        if(!mark[i]){
            dfs(i, curr, mark, tin, low, timer, g, bridges);
            low[curr]=min(low[curr], low[i]);
            if(tin[curr]<low[i]) bridges.push_back({i, curr});
        }else{
            low[curr]=min(low[curr], tin[i]);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> mark(n+1, false);
    vector<int> tin(n+1, 0), low(n+1, 0);
    int timer=1; vector<vector<int>> bgs;
    for(int i = 1;i<=n;i++){
        if(!mark[i]) dfs(i, -1, mark, tin, low, timer, g, bgs);
    }
    cout<<bgs.size()<<'\n';
    for(auto i: bgs) cout<<i[0]<<' '<<i[1]<<'\n';
    return 0;
}