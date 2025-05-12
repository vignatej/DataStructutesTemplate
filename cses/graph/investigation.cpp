#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int M = 1e9+7;

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<vector<int>>> g(n+1);
    for(int i = 1;i<=m;i++){
        int a, b, w; cin>>a>>b>>w;
        g[a].push_back({b, w});
    }
    vector<int> dist(n+1, 1e16);
    vector<int> coun(n+1, 0);
    vector<int> minf(n+1, INT_MAX);
    vector<int> maxf(n+1, 0);
    dist[1]=0;
    coun[1]=1;
    minf[1]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while(pq.size()){
        auto t = pq.top(); pq.pop();
        int w = t.first; int node=t.second;
        if(dist[node]<1ll*(-1)*w){
            continue;
        }
        for(auto i: g[node]){
            int nn=i[0]; int ew=i[1];
            if(dist[nn]>(1ll*(-1)*w+ew)){
                dist[nn]=(1ll*(-1)*w+ew);
                coun[nn]=coun[node];
                minf[nn]=minf[node]+1;
                maxf[nn]=maxf[node]+1;
                pq.push({w-ew, nn});
            }else if(dist[nn]==(1ll*(-1)*w+ew)){
                coun[nn]+=coun[node]; coun[nn]%=M;
                minf[nn]=min(minf[nn], minf[node]+1);
                maxf[nn]=max(maxf[nn], maxf[node]+1);
            }
        }
    }
    cout<<dist[n]<<' '<<coun[n]<<' '<<minf[n]<<' '<<maxf[n];

    return 0;
}