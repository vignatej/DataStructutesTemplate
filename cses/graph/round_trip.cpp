#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool dfs(int curr, int par, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &order, vector<int> &times){
    times[curr]++;
    if(visited[curr]){order.push_back(curr); return 1;}
    visited[curr]=1;
    order.push_back(curr);
    for(auto i: graph[curr]){
        if(i==par) continue;
        bool cans = dfs(i, curr, graph, visited, order, times);
        if(cans) return 1;
    }
    order.pop_back();
    return false;
}

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> v(n+1);
    for(int i = 1;i<=m;i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> visited(n+1, false);
    vector<int> times;
    times.resize(n+1, 0);
    for(int i =1;i<=n;i++){
        if(visited[i]) continue;
        vector<int> order;
        bool c = dfs(i, 0, v, visited, order, times);
        if(!c) continue;
        int d1 = distance(order.begin(), find(order.begin(), order.end(), order.back()));
        cout<<order.size()-d1<<'\n';
        for(int j =d1;j<order.size();j++)
            cout<<order[j]<<' ';
        return 0;
    }
    cout<<"IMPOSSIBLE";


    return 0;
}