#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

void dfs1(int curr, vector<int> &s, vector<vector<int>> &g, vector<bool> &comp){
    if(comp[curr]) return;
    comp[curr]=1;
    for(auto i: g[curr]) dfs1(i, s, g, comp);
    s.push_back(curr);
}
void dfs2(int curr, int cc, vector<int> &component, vector<vector<int>> &rg){
    if(component[curr]!=0) return;
    component[curr]=cc;
    for(auto i: rg[curr]) dfs2(i, cc, component, rg);
}

int calc_ans(int curr, vector<vector<int>> rg, vector<int> compo_sums, vector<int> &dp){
    if(dp[curr]!=-1) return dp[curr];
    int ans = compo_sums[curr];
    int mv{0};
    for(auto i: rg[curr]){
        int pa = calc_ans(i, rg, compo_sums, dp);
        if(pa>mv) mv=pa;
    }
    ans+=mv;
    dp[curr]=ans;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    vector<int> coins(n+1, 0);
    for(int i =1;i<=n;i++) cin>>coins[i];
    vector<vector<int>> g(n+1), rg(n+1);
    for(int i = 1;i<=m;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vector<bool> comp(n+1, 0);
    vector<int> st;
    for(int i = 1;i<=n;i++) if(!comp[i]) dfs1(i, st, g, comp);
    vector<int> component(n+1, 0);
    int cc{1};
    reverse(st.begin(), st.end());
    for(auto i: st){
        if(component[i]!=0) continue;
        dfs2(i, cc, component, rg);
        cc++;
    }
    vector<int> c_sums(cc, 0);
    for(int i = 1;i<=n;i++){
        int cv = component[i];
        c_sums[cv]+=coins[i];
    }
    vector<vector<int>> cg(cc+1), rcg(cc+1);
    for(int i = 1;i<=n;i++){
        for(auto j: g[i]){
            int c1 = component[i];
            int c2 = component[j];
            if(c1==c2) continue;
            cg[c1].push_back(c2);
            rcg[c2].push_back(c1);
        }
    }
    int fans{0};
    vector<int> dp(cc+1, -1);
    for(int i = 1;i<cc;i++) 
        fans = max(fans, calc_ans(i, rcg, c_sums, dp));
    cout<<fans;


    return 0;
}