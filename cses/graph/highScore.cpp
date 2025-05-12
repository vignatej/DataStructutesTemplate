#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

void dfs(int curr, int end, vector<vector<pair<int, int>>> &graph, 
    set<int> &comp){
    if(curr==end) return;
    if(comp.find(curr)!=comp.end()) return;
    comp.insert(curr);
    for(auto i: graph[curr]){
        if(comp.find(i.first)!=comp.end()) continue;
        dfs(i.first, end, graph, comp);     
    }
}


signed main(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> v(n+1);
    for(int i = 0;i<m;i++){
        int a, b, w; cin>>a>>b>>w;
        v[a].push_back({b, -1*w});
    }
    vector<int> dist(n+1, 1e16);
    dist[1]=0;
    for(int i =1;i<n;i++){
        for(int a = 1;a<=n;a++) for(auto j: v[a]){
            int b = j.first; int w = j.second;
            dist[b]=min(dist[b], dist[a]+w);
        }
    }

    set<int> neg_n;
    for(int a = 1;a<=n;a++) for(auto j: v[a]){
        int b = j.first; int w = j.second;
        int bef = dist[b];
        dist[b]=min(dist[b], dist[a]+w);
        if(bef!=dist[b]) neg_n.insert(b);
    }
    vector<vector<pair<int, int>>> rev_g(n+1);
    for(int a = 1;a<=n;a++) for(auto j: v[a]){
        int b = j.first; int w = j.second;
        rev_g[b].push_back({a, w});
    }
    set<int> rechable_from_n;
    dfs(n, 0,rev_g, rechable_from_n);
    set<int> reach_first;
    dfs(1, 0, v, reach_first);
    bool rech = false;
    for(auto i: neg_n)
        if(rechable_from_n.find(i)!=rechable_from_n.end()
            && reach_first.find(i)!=reach_first.end()
        ){
            rech=1; break;
        }
    if(rech){
        cout<<-1;
    }else{
        cout<<-1*dist[n];
    }



    return 0;
}