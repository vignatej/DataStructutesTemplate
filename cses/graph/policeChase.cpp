#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool dfs(int curr, int n, VVI &g, VVI &v, set<int> &visited){
    if(curr==n){
        return 1;
    }
    if(visited.find(curr)!=visited.end()) return false;
    visited.insert(curr);

    for(auto i: g[curr]){
        if(v[curr][i]!=1) continue;
        if(visited.find(i)!=visited.end()) continue;
        int rp = v[i][curr]; v[i][curr]=0;
        auto a = dfs(i, n, g, v, visited);
        if(!a){v[i][curr]=rp; continue;}
        v[i][curr]=1;
        v[curr][i]=0;
        return 1;
    }
    return 0;
}


signed main(){
    int n, m; cin>>n>>m;
    VVI v(n+1, VI(n+1, 0)), g(n+1);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        g[a].PB(b); g[b].PB(a);
        v[a][b]+=1;v[b][a]+=1;
    }
    int ans{0};
    while(1){
        set<int> visited;
        auto a = dfs(1, n, g, v, visited);
        if(!a) break;
        ans++;
    }
    cout<<ans<<'\n';
    set<int> availNodes{1};
    queue<int> nodes; nodes.push(1);
    while(nodes.size()){
        auto t = nodes.front();
        nodes.pop();
        for(auto i: g[t]){
            if(v[t][i]==0) continue;
            if(availNodes.find(i)!=availNodes.end()) continue;
            nodes.push(i);
            availNodes.insert(i);
        }
    }
    for(auto i: availNodes){
        for(auto j: g[i]){
            if(availNodes.find(j)!=availNodes.end()) continue;
            cout<<i<<' '<<j<<'\n';
        }
    }

    return 0;
}