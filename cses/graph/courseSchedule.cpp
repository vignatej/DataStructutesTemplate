#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    int n, m; cin>>n>>m;
    vector<set<int>> g(n+1), rg(n+1);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        g[a].insert(b);
        rg[b].insert(a);
        // g[b].insert(a);
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 1;i<=n;i++){
        if(g[i].size()>=1) continue; 
        q.push(i);
    }
    while(q.size()){
        int t = q.front();
        ans.push_back(t);
        q.pop();
        for(auto j: rg[t]){
            g[j].erase(t);
            if(g[j].size()==0) q.push(j);
        }
    }
    if(ans.size()!=n){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans) cout<<i<<' ';


    return 0;
}