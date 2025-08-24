#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back


void dfs(int curr, int par, int &counter,
        vector<int> &low, vector<int> &tin, 
        vector<vector<vector<int>>> &g, vector<bool> &marked,
        set<int> &bridges
    ){
    if(marked[curr]) return;
    marked[curr]=1;
    tin[curr]=low[curr]=++counter;
    for(auto &c: g[curr]){
        int nc = c[0]; int posn = c[1];
        if(nc==par) continue;
        if(marked[nc]){
            low[curr]=min(low[curr], tin[nc]);
        }else{
            dfs(nc, curr, counter, low, tin, g, marked, bridges);
            low[curr]=min(low[curr], low[nc]);
            if(tin[curr]<low[nc]) bridges.insert(posn);
        }
    }
}

vector<int> get_sortest_path(int s, vector<vector<vector<int>>> &g){
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> comp(n, false);
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    while(pq.size()){
        auto t = pq.top(); pq.pop();
        int cd = t.first; int cn = t.second;
        if(comp[cn]) continue;
        comp[cn]=1;
        dist[cn]=-1*cd;
        for(auto &i: g[cn]){
            int nn = i[0]; 
            if(comp[nn]) continue;
            pq.push({cd-1, nn});
        }
    }
    return dist;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){

        int n, m; cin>>n>>m;
        vector<vector<int>> edges;
        vector<vector<vector<int>>> g(n+1);
        for(int i = 0;i<m;i++){
            int a, b; cin>>a>>b;
            g[a].push_back({b, i+1});
            g[b].push_back({a, i+1});
            edges.push_back({a, b});
        }
        vector<int> tin(n+1, 0), low(n+1, 0);
        set<int> bridges;
        int counter=0;
        vector<bool> marked(n+1, 0);
        for(int i = 1;i<=n;i++) 
            if(!marked[i]) dfs(i, -1, counter, low, tin, g, marked, bridges);


        
        // vector<bool> from1 = solve(1, n, g);
        // vector<bool> fromN = solve(n, 1, g);
        // for(int i = 1;i<=n;i++) from1[i] = from1[i]&fromN[i];
        
        // vector<int> inb_bridges;
        // for(auto i: bridges){
        //     i--;
        //     int l = edges[i][0]; int r = edges[i][1];
        //     if(from1[l] && from1[r]) inb_bridges.push_back(i+1);
        // }

        vector<int> dist_s = get_sortest_path(1, g);
        vector<int> dist_e = get_sortest_path(n, g);
        vector<int> inb_bridges;
        for(auto i: bridges){
            i--;
            int l = edges[i][0]; int r = edges[i][1];
            if(dist_s[l]+1+dist_e[r]==dist_s[n] || dist_s[r]+1+dist_e[l]==dist_s[n])
                inb_bridges.push_back(i+1);
        }


        vector<bool> comp(n+1, false);
        vector<int> nnd(n+1, INT_MAX);
        vector<int> nei(n+1, -1);

        priority_queue<vector<int>> pq;
        for(auto i: inb_bridges){
            i-=1;
            int l = edges[i][0]; int r = edges[i][1];
            pq.push({0, -1LL*(i+1), l}); pq.push({0, -1LL*(i+1), r});
        }
        while(pq.size()){
            auto a = pq.top(); pq.pop();
            int cd = a[0]; int ni = a[1]; int cn = a[2];
            if(comp[cn]) continue;
            comp[cn]=1;
            nnd[cn]=-1*cd;
            nei[cn]=-1*ni;
            comp[cn]=1;
            for(auto i: g[cn]){
                int nn = i[0]; int nn_ei = i[1];
                if(comp[nn]) continue;
                pq.push({cd-1, ni, nn});
            }
        }

        int q; cin>>q;
        while(q--){
            int curr; cin>>curr;
            cout<<nei[curr]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}