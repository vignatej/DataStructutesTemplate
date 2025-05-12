#include <bits/stdc++.h>
using namespace std;
#define ll long long

int get_max_dist(int curr, vector<vector<int>> &rg, 
    vector<int> &dist, vector<int> &par, vector<bool> &comp){
    if(comp[curr]) return dist[curr];
    comp[curr]=1;
    for(auto i: rg[curr]){
        int ca = get_max_dist(i, rg, dist, par, comp);
        if(ca==-1) continue;
        if(ca+1>dist[curr]){
            dist[curr]=ca+1;
            par[curr]=i;
        }
    }
    return dist[curr];
}

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> g(n+1), rg(n+1);
    for(int i = 1;i<=m;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vector<int> dist(n+1, -1); dist[1]=0;
    vector<int> par(n+1, 0);
    vector<bool> comp(n+1, 0); comp[1]=1;
    int cou = get_max_dist(n, rg, dist, par, comp);
    if(cou==-1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<cou+1<<'\n';
    int curr = n;
    vector<int> ans;
    while(curr!=0){
        // cout<<curr<<' ';
        ans.push_back(curr);
        curr=par[curr];
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans) cout<<i<<' ';
    return 0;
}