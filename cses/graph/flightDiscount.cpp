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
    vector<int> dist(n+1, 1e16);
    dist[1]=0;
    priority_queue<pair<int, pair<bool, int>>> pq;
    pq.push({0, {false, 1}});
    vector<vector<bool>> processed(n+1, vector<bool>(2, false));
    while(pq.size()){
        auto t = pq.top(); pq.pop();
        int wtl = t.first; bool halved = t.second.first;
        int node = t.second.second;
        if(processed[node][halved]) continue;
        processed[node][halved] = 1;
        dist[node]=min(dist[node],-1*wtl);
        for(auto i: v[node]){
            int nn = i.first; int ew = i.second;
            if(!halved){
                if(processed[nn][1]==false){
                    pq.push({wtl-ew/2,{1, nn}});
                }
            }
            if(processed[nn][halved]==false){
                pq.push({wtl-ew,{halved, nn}});
            }
        }
    }
    cout<<dist[n];


    return 0;
}