#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool dfs(int curr, int n, int &fv, VVI &g, VVI &v, set<int> &visit, int thres){
    if(curr==n)return true;
    if(visit.find(curr)!=visit.end()) return false;
    visit.insert(curr);
    for(auto i: g[curr]){
        int cfv = min(fv, v[curr][i]);
        if(cfv==0) continue;
        if(cfv<thres) continue;
        if(visit.find(i)!=visit.end()) continue;
        bool a = dfs(i, n, cfv, g, v, visit, thres);
        if(!a) continue;
        fv=cfv;
        v[curr][i]-=fv;
        v[i][curr]+=fv;
        return 1;
    }
    return false;
}


signed main(){
    int n, m; cin>>n>>m;
    VVI v(n+1, vector<int>(n+1, 0));
    VVI graph(n+1);
    for(int i = 0;i<m;i++){
        int a, b, w; cin>>a>>b>>w;
        v[a][b]+=w;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    int ans = 0; bool a = 1;
    int thres = 1e9;
    while(thres){
        set<int> visit;
        int mf = INT_MAX;
        a = dfs(1, n, mf, graph, v, visit, thres);
        if(!a) thres/=2;
        if(a) ans+=mf;
    };
    cout<<ans;

    return 0;
}