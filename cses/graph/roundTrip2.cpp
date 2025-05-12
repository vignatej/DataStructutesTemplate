#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs(int curr, vector<bool> &all, 
    vector<vector<int>> &graph, 
    vector<int> &order,
    vector<bool> &comp){
    if(all[curr]){
        order.push_back(curr);
        return true;
    }
    all[curr]=1;
    comp[curr]=1;
    order.push_back(curr);
    for(auto i: graph[curr]){
        bool ans = dfs(i, all, graph, order, comp);
        if(ans) return true;
    }
    all[curr]=0;
    order.pop_back();
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m;cin>>n>>m;
    vector<vector<int>> v(n+1);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
    }
    vector<bool> all(n+1, false), comp(n+1, 0);
    vector<int> order;
    for(int i =1;i<=n;i++){
        if(comp[i]) continue;
        bool c = dfs(i, all, v, order, comp);
        if(!c) continue;
        int d = distance(order.begin(), find(order.begin(), order.end(), order.back()));
        cout<<order.size()-d<<'\n';
        for(int i = d;i<order.size();i++) cout<<order[i]<<' ';
        return 0;    
    }
    cout<<"IMPOSSIBLE";
    return 0;


    // vector<int> dist(n+1, INT_MAX);
    // vector<int> par(n+1, 0);
    // int x{-1};
    // for(int i =1;i<=n;i++){
    //     x=-1;
    //     for(int a = 1;a<=n;a++) for(auto b: v[a]){
    //         // dist[b] = min(dist[b], dist[a]-1);
    //         if(dist[b]>dist[a]-1){
    //             dist[b] = dist[a]-1;
    //             par[b]=a;
    //             x=b;
    //         }
    //     }
    // }
    // if(x==-1){
    //     cout<<"IMPOSSIBLE"; return 0;
    // }
    // int c{n};
    // while(c--){
    //     x=par[x];
    // }
    // vector<int> ans{x};
    // x=par[x];
    // while(x!=ans[0]){
    //     ans.push_back(x);
    //     x=par[x];
    // }
    // ans.push_back(x);
    // reverse(ans.begin(), ans.end());
    // cout<<ans.size()<<'\n';
    // for(auto i: ans) cout<<i<<' ';


    return 0;
}