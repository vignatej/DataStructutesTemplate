#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> v(n+1);
    for(int i = 0;i<m;i++){
        int a, b, w; cin>>a>>b>>w;
        v[a].push_back({b, w});
    }
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pair<int, int>> pq; pq.push({0, 1});
    vector<bool> processed(n+1, false);
    while(pq.size()){
        int w = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        if(processed[node]) continue;
        processed[node]=1;
        dist[node]=-1*w;
        for(auto &i: v[node]){
            if(processed[i.first]==true) continue;
            pq.push({w-i.second, i.first});
        }
    }
    for(int i = 1;i<=n;i++) cout<<dist[i]<<' ';


    // vector<int> dist(n+1, INT_MAX);
    // dist[1]=0;
    // for(int i = 1;i<n;i++){
    //     for(int a = 1;a<=n;a++){
    //         if(dist[a]==INT_MAX) continue;
    //         for(auto j: v[a]){
    //             int b = j.first; int c = j.second;
    //             dist[b]=min(dist[b], dist[a]+c);
    //         }
    //     }
    // }

    // for(int i = 1;i<=n;i++) cout<<dist[i]<<' ';
    return 0;
}