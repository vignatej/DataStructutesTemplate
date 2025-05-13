#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

vector<vector<int>> ans_list;
bool dfs(int curr, int dest, VVI &g, VVI &v, bitset<1005> &bs){
    if(curr==dest) return true;
    if(bs[curr]) return false;
    bs.set(curr);
    for(auto i: g[curr]){
        if(v[curr][i]==0) continue;
        if(bs[i]) continue;;
        bool a = dfs(i, dest, g, v, bs);
        if(!a) continue;
        v[curr][i]=0; v[i][curr]++;
        return 1;
    }
    // bs.reset(curr);
    return 0;
}

signed main(){
    int a, b, c; cin>>a>>b>>c;
    int src = a+b+1; int dest = a+b+2;
    vector<vector<int>> g(dest+1);
    VVI v(dest+1, VI(dest+1, 0));
    for(int i = 1;i<=a;i++){
        g[src].PB(i); v[src][i]++;
        g[i].PB(src);
    }
    for(int i = a+1;i<=a+b;i++){
        g[i].PB(dest); v[i][dest]++;
        g[dest].PB(i);
    }
    for(int i = 0;i<c;i++){
        int d,e; cin>>d>>e;
        e+=a;
        g[d].PB(e);g[e].PB(d);
        v[d][e]++;
    }
    int ans{0};
    while(1){
        set<int> visited;
        bitset<1005> bs;
        bool a = dfs(src, dest, g, v, bs);
        if(!a) break;
        ans++;
    }
    cout<<ans<<'\n';
    for(int i = 1;i<=a;i++){
        for(auto j: g[i]){
            if(a+1<=j && j<=a+b &&v[i][j]==0){
                ans--;
                cout<<i<<' '<<j-a<<'\n';
                break;
            }
        }
        if(!ans) break;
    }


    return 0;
}