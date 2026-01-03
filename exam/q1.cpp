#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const LL M = 998244353;

void bridge_finder(int curr, int par, vector<bool> &comp,
    vector<int> &tin, vector<int> &low,
    int &timer, vector<pair<int, int>> &bridges,
    vector<vector<int>> &g
){
    if(comp[curr]) return;
    tin[curr]=low[curr]=++timer;
    comp[curr]=1;
    for(auto i: g[curr]){
        if(i==par) continue;
        if(comp[i]){
            low[curr]=min(low[curr], tin[i]);
        }else{
            bridge_finder(i, curr, comp, tin, low, timer, bridges, g);
            low[curr]=min(low[curr], low[i]);
            if(low[i]>tin[curr]){
                bridges.push_back({min(curr, i), max(curr, i)});
            }
        }
    }

}

set<pair<int, int>> get_bridges(int n, vector<vector<int>> &g){
    vector<bool> comp(n+1, false);
    vector<int> low(n+1, -1);vector<int> tin(n+1, -1);
    vector<pair<int, int>> bridges;
    int timer = 0;
    for(int i =1;i<=n;i++) if(!comp[i]) bridge_finder(1, -1, comp, tin, low, timer, bridges, g);
    set<pair<int, int>> ans;
    copy(bridges.begin(), bridges.end(), inserter(ans, ans.end()));
    return ans;
}

void dfs(int curr, int &counter, vector<int> &comp, 
    vector<vector<int>> &g, set<pair<int, int>> &bridges){
    if(comp[curr]!=0) return;
    comp[curr]=counter;
    for(auto i: g[curr]){
        if(comp[i]!=0) continue;
        if(bridges.find({min(curr, i), max(curr, i)})!=bridges.end()){
            continue;
        }
        dfs(i, counter, comp, g, bridges);
    }
}

bool check_coloring(int curr, int cc, vector<vector<int>> &g, 
    vector<int> &colo_comp, set<pair<int, int>> &bdgs){
    if(colo_comp[curr]!=-1) return colo_comp[curr]==cc;
    colo_comp[curr]=cc;
    for(auto i: g[curr]){
        if(bdgs.find({min(curr, i), max(curr, i)})!=bdgs.end())
            continue;
        bool poss = check_coloring(i, 1-cc, g, colo_comp, bdgs);
        if(!poss) return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n, m, v; cin>>n>>m>>v;
        vector<int> nums(n+1, -1); for(int i = 1;i<=n;i++) cin>>nums[i];
        vector<vector<int>> g(n+1);
        for(int i =0;i<m;i++){
            int a, b; cin>>a>>b;
            g[a].push_back(b); g[b].push_back(a);
        }
        set<pair<int, int>> bdgs = get_bridges(n, g);
        int counter = 1;
        vector<int> comp(n+1, 0);
        for(int i =1;i<=n;i++){
            if(comp[i]!=0) continue;
            counter++;
            dfs(i, counter, comp, g, bdgs);
        }
        map<int, vector<int>> crm;
        for(int i =1;i<=n;i++) crm[comp[i]].push_back(i);
        LL ans{1};
        vector<int> colo_comp(n+1, -1);
        for(auto &i: crm){
            vector<int> &cn = i.second;
            map<int, int> vc;
            for(auto j: cn) vc[nums[j]]++;
            int cns = cn.size();
            if(cns==1){
                if(nums[cn[0]]==-1) ans*=v;
                ans%=M;
                continue;
            }
            if(vc.size()>2){ans=0; break;}
            int m1c = vc[-1]; 
            vc.erase(vc.find(-1));
            if(vc.size()>1){ans=0; break;}
            bool o_n = check_coloring(cn[0], 0, g, colo_comp, bdgs);
            if(o_n){
                if(vc.size()){ans*=1;}
                else if(m1c) ans=(ans*v)%M;
                else ans*=1;
            }else{
                if(vc.size() && vc.begin()->first!=0){ans=0; break;}
                else ans*=1;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}