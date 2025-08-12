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
    set<int> &points){
    if(mark[curr]) return;
    int children=0;
    mark[curr]=1;
    tin[curr]=low[curr]=timer++;
    for(auto &i:g[curr]){
        if(i==p) continue;
        if(!mark[i]){
            dfs(i, curr, mark, tin, low, timer, g, points);
            low[curr]=min(low[curr], low[i]);
            if(tin[curr]<=low[i] && p!=-1) points.insert(curr);
            children++;
        }else{
            low[curr]=min(low[curr], tin[i]);
        }
    }
    if(p==-1 && children>1) points.insert(curr);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<int> deg(n+1, 0);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++; deg[b]++;
    }
    vector<bool> mark(n+1, false);
    vector<int> tin(n+1, 0), low(n+1, 0);
    int timer=1; set<int> bgs;
    for(int i = 1;i<=n;i++){
        if(!mark[i]) dfs(i, -1, mark, tin, low, timer, g, bgs);
    }
    cout<<bgs.size()<<'\n';
    for(auto i: bgs) cout<<i<<' ';
    // set<int> ans;
    // for(auto &i: bgs){
    //     int n1 = i[0]; int n2 = i[1];
    //     if(deg[n1]>1) ans.insert(n1);
    //     if(deg[n2]>1) ans.insert(n2);
    // }
    // cout<<ans.size()<<'\n';
    // for(auto i: ans) cout<<i<<' ';
    return 0;
}