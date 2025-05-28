#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        VI vals(n+1, 0); 
        for(int i =1;i<=n;i++) cin>>vals[i];
        map<int, set<int>> nex;
        for(int i =1;i<n;i++){
            int a, b; cin>>a>>b;
            nex[a].insert(b);
            nex[b].insert(a);
        }
        VI par(n+1, 0);
        queue<int> q; q.push(1);
        while(q.size()){
            int t = q.front(); q.pop();
            for(auto &i: nex[t]){
                nex[i].erase(t);
                q.push(i);
                par[i]=t;
            }
        }
        VVI ans(n+1, {0,0});
        VI curr{1};
        while(curr.size()>0){
            VI next;
            for(auto c: curr){
                int p = par[c];
                ans[c][0]=max(vals[c], vals[c]-ans[p][1]);
                ans[c][1]=min(vals[c], vals[c]-ans[p][0]);
                for(auto ne: nex[c]) next.PB(ne);
            }
            curr=next;
        }
        for(int i =1;i<=n;i++) cout<<ans[i][0]<<' ';
        cout<<'\n';

    }

    return 0;
}