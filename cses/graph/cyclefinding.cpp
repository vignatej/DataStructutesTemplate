#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<vector<int>>> v(n+1);
    for(int i = 0;i<m;i++){
        int a, b, w; cin>>a>>b>>w;
        v[a].push_back({b, w});
    }

    vector<int> dist(n+1, 1e16);
    vector<int> par(n+1, -1);
    int x;
    for(int i=1;i<=n;i++){
        x=-1;
        for(int a=1;a<=n;a++){
            for(auto &j: v[a]){
                int b = j[0]; int w = j[1];
                if(dist[b]>dist[a]+w){
                    dist[b]=dist[a]+w;
                    par[b]=a;
                    x=b;
                }
            }
        }
    }
    if(x==-1){
        cout<<"NO";
        return 0;
    }
    int c = n;
    while(c--){
        x=par[x];
    }
    vector<int> ans{x};
    x=par[x];
    while(x!=ans.front()){
        ans.push_back(x);
        x=par[x];
    } ans.push_back(x);
    reverse(ans.begin(), ans.end());
    cout<<"YES\n";
    for(auto i: ans) cout<<i<<' ';

    return 0;
}