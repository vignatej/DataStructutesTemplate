#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<vector<int>>> v(n+1);
    for(int i = 0;i<m;i++){
        int a, b, w; cin>>a>>b>>w;
        v[a].push_back({b, w});
    }
    vector<int> distances;
    vector<int> times(n+1, 0);
    priority_queue<pair<int, int>> pq;
    pq.push({0,1});
    while(pq.size() && times[n]<k){
        auto t = pq.top(); pq.pop();
        int node = t.second; int wt = t.first;
        if(times[node]>k) continue;
        times[node]++;
        if(node==n) distances.push_back(1ll*(-1)*wt);
        for(auto i: v[node]){
            int nn = i[0]; int ew=i[1];
            if(times[nn]>=k) continue;
            pq.push({wt-ew, nn});
        }
    }
    for(auto i: distances) cout<<i<<' ';

    return 0;
}