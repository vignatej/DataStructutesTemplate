#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n, m; cin>>n>>m;
        VI v(n+1, 0); for(int i =1;i<=n;i++) cin>>v[i];
        map<int, VVI> edges;
        for(int i=1;i<=m;i++){
            int a, b, w; cin>>a>>b>>w;
            edges[a].PB({b, w});
        }
        priority_queue<VI> pq;
        pq.push({0, 0, 1}); bool ans = false;
        while(pq.size()){
            auto t = pq.top();
            int max_on_path = -1*t[0];
            int tot_on_nod = t[1];
            int node = t[2];
            pq.pop();
            if(node==n){
                cout<<max_on_path<<'\n';
                ans=1; break;
            }
            for(auto &i: edges[node]){
                int b = i[0]; int w = i[1];
                int nt = tot_on_nod + v[node];
                int mp = max(max_on_path, w);
                if(nt<w) continue;
                pq.push({-1*mp, nt, b});
            }
        }
        if(!ans) cout<<"-1\n";
    }

    return 0;
}