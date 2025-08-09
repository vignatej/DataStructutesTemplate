#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

void dfs(int curr, vector<int> &st, vector<bool> &mark, vector<vector<int>> &g){
    if(mark[curr]) return;
    mark[curr]=1;
    for(auto i: g[curr]) dfs(i, st, mark, g);
    st.push_back(curr);
}

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif
    int n, m, k; cin>>n>>m>>k;
    vector<vector<int>> g(n+1), rg(n+1), edges;
    for(int i =0;i<m;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vector<int> st;
    vector<bool> mark(n+1, false);
    for(int i =1;i<=n;i++)
        dfs(i, st, mark, g);

    vector<int> compo(n+1, 0); 
    vector<bool> marked(n+1, false);
    int cc{1};
    for(int i = n-1;i>=0;i--){
        int curr = st[i];
        if(marked[curr]) continue;
        vector<int> cs;
        dfs(curr, cs, marked, rg);
        for(auto j: cs) compo[j]=cc;
        cc++;
    }
    
    vector<bitset<50001>> vbs(cc);
    for(int i =1;i<cc;i++) vbs[i].set(i);
    vector<vector<int>> cg(cc), rcg(cc);
    vector<int> outdeg(cc, 0);
    for(int i = 1;i<=n;i++){
        for(auto j: g[i]){
            int c1 = compo[i];
            int c2 = compo[j];
            if(c1==c2) continue;
            if(vbs[c1][c2]) continue;
            cg[c1].push_back(c2);
            rcg[c2].push_back(c1);
            vbs[c1].set(c2);
            outdeg[c1]++;
        }
    }
    
    deque<int> ts; vector<bool> comp(cc, false);
    for(int i = 1;i<cc;i++) if(outdeg[i]==0) ts.push_back(i);
    while(ts.size()){
        int t = ts.front(); ts.pop_front();
        comp[t]=1;
        for(auto j: rcg[t]){outdeg[j]--;}
        for(auto j: rcg[t]) if(outdeg[j]==0 && comp[j]==false){
            ts.push_back(j); comp[j]=1;
        }
        for(auto j: cg[t]) vbs[t]|=vbs[j];
    }
    
    while(k--){
        int a, b; cin>>a>>b;
        int ac=compo[a];
        int bc=compo[b];
        if(vbs[ac][bc]) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }

    

    return 0;
}