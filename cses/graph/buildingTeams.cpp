#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool do_graph_coloring(int curr, bool col, vector<int> &colors, vector<vector<int>> &graph){
    if(colors[curr]!=-1){
        if(colors[curr]!=col)return false;
        return true;
    }
    if(colors[curr]==-1) colors[curr]=col;
    bool ans = 1;
    for(auto i: graph[curr]){
        ans = do_graph_coloring(i, !col, colors, graph);
        if(!ans) return 0;
    }
    return 1;
}

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i = 1;i<=m;i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> colors(n+1, -1);
    bool doable{1};
    for(int i =1;i<=n;i++){
        if(colors[i]!=-1) continue;
        bool c = do_graph_coloring(i, 1, colors, graph);
        doable = c;
    }
    if(!doable){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i = 1;i<=n;i++){
        if(colors[i]) cout<<2<<' ';
        else cout<<1<<' '; 
    }

    return 0;
}