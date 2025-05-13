#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool dfs(int curr, int dest,VVI &g, VVI &v, bitset<505> &visited){
    if(curr==dest){return 1;}
    if(visited[curr]) return false;
    visited[curr]=1;
    for(auto i: g[curr]){
        if(v[curr][i]==0) continue;
        if(visited[i]) continue;
        bool a = dfs(i, dest, g, v, visited);
        if(!a) continue;
        v[curr][i]=0; v[i][curr]=1;
        return 1;
    }
    visited[curr]=0;
    return 0;
}
bool dfs2(int curr, int dest, VVI &v, VVI &g, VI &path, 
    bitset<505> &inPath, vector<vector<bool>> &oe,
    vector<vector<bool>> &ue){
    if(curr==dest){
        path.push_back(curr);
        return 1;
    }
    // if(req==0) return;
    if(inPath[curr]) return 0;
    path.push_back(curr); inPath[curr]=1;
    for(auto i: g[curr]){
        if(!oe[curr][i]) continue;
        if(v[curr][i]!=0) continue;
        if(inPath[i]) continue;
        if(ue[curr][i]) continue;
        ue[curr][i]=1;
        bool ans = dfs2(i, dest, v, g, path, inPath, oe, ue);
        // if(req==0) break;
        if(!ans){ ue[curr][i]=0; continue;}
        return 1;
    }
    // inPath[curr]=0;
    path.pop_back();
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    VVI g(n+1), v(n+1, VI(n+1, 0));
    vector<vector<bool>> oe(n+1, vector<bool> (n+1, false));
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        g[a].PB(b); g[b].PB(a);
        v[a][b]++;
        oe[a][b]=1;
    }
    int ans{0};
    while(1){
        bitset<505> bs;
        bool a = dfs(1, n, g, v, bs);
        if(!a) break;
        ans++;
    }

    cout<<ans<<'\n';
    VI path; bitset<505> bs;
    decltype(oe) ue(n+1, vector<bool>(n+1, false));
    while(ans){
        VI path; bitset<505> bs;
        dfs2(1, n, v, g, path, bs, oe, ue);
        cout<<path.size()<<'\n';
        for(auto i: path) cout<<i<<' ';
        cout<<'\n'; ans--;
    }

    return 0;
}