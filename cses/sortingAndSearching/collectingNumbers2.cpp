#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, m; cin>>n>>m;
    VI v(n+1,0); for(int i = 1;i<=n;i++) cin>>v[i];
    VVI vv(n+1); for(int i = 0;i<=n;i++) vv[i]={v[i], i};
    sort(vv.begin(), vv.end());
    int ans{1};
    for(int i = 1;i<=n;i++) 
        if(vv[i-1][1]>vv[i][1]) ans++;
    while(m--){
        int a, b; cin>>a>>b;
        int av{v[a]}, bv{v[b]};
        set<vector<int>> sv;
        sv.insert(vv[av]);
        if(av+1<=n) sv.insert(vv[av+1]);
        sv.insert(vv[bv]);
        if(bv+1<=n) sv.insert(vv[bv+1]);
        for(auto &i: sv){
            int cn = i[0]; int cp=i[1];
            int pn = i[0]-1; int pp = vv[pn][1];
            if(pp>cp) ans--;
        }
        swap(v[a], v[b]);
        swap(vv[av][1], vv[bv][1]);
        sv.clear();
        sv.insert(vv[av]);
        if(av+1<=n) sv.insert(vv[av+1]);
        sv.insert(vv[bv]);
        if(bv+1<=n) sv.insert(vv[bv+1]);
        for(auto &i: sv){
            int cn = i[0]; int cp=i[1];
            int pn = i[0]-1; int pp = vv[pn][1];
            if(pp>cp) ans++;
        }
        cout<<ans<<' ';
    }
    return 0;
}