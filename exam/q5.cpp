#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
int n;

bool dfs(int curr, int pf, int ps, VI &order, set<int> & se, VVI &g, VVI &v){
    se.insert(curr);
    order.PB(curr);
    if(se.size()==n){
        return 1;
    }
    int cf = v[curr][0]; int cs = v[curr][1];
    for(auto &i: g[curr]){
        int nf = v[i][0]; int ns = v[i][1];
        if(cf==nf && cs==ns) continue;
        if(pf==cf && cf==nf) continue;
        if(ps==cs && cs==ns) continue;
        if(se.find(i)!=se.end()) continue;
        bool a = dfs(i, cf, cs, order, se, g, v);
        if(a) return 1;
    }
    se.erase(curr);
    order.pop_back();
    return false;
}

signed main(){
    int T; cin>>T;
    while(T--){
        cin>>n;
        VVI v(1,{0,0});
        map<int, VI> f, s;
        for(int i=1;i<=n;i++){
            int a, b; cin>>a>>b;
            v.PB({a, b});
            f[a].PB(i);
            s[b].PB(i);
        }
        VVI g(n+1);
        for(int i = 1;i<=n;i++){
            int a, b; a=v[i][0]; b=v[i][1];
            for(auto j: f[a]) if(j!=i) g[i].PB(j);
            for(auto j: s[b]) if(j!=i) g[i].PB(j);
        }
        VI order; set<int> se;
        bool ans = dfs(1, -1, -1, order, se, g, v);
        for(auto i: g[1]){
            if(!ans) ans = dfs(i, -1, -1, order, se, g, v);
        }
        if(!ans){
            cout<<"NO\n"; continue;
        }
        cout<<"YES\n";
        for(auto i: order) cout<<i<<' ';
        cout<<'\n';
    }

    return 0;
}