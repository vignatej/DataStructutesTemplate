#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int curr, vector<int> &stack, vector<vector<int>> &g, vector<bool> &mark){
    if(mark[curr]) return;
    mark[curr]=1;
    for(auto i: g[curr])
        dfs(i, stack, g, mark);
    stack.push_back(curr);
}

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> g(n+1), rg(n+1);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vector<int> st;
    vector<bool> marked(n+1, false);
    for(int i =1;i<=n;i++){
        dfs(i, st, g, marked);
    }
    vector<bool> mark(n+1, false);
    vector<int> ans(n+1, 0); int c =1;
    for(int i =n-1;i>=0;i--){
        int curr = st[i];
        if(mark[curr]) continue;
        vector<int> cs;
        dfs(curr, cs, rg, mark);
        for(auto j: cs) ans[j]=c;
        c++;
        // i-=cs.size();
    }
    cout<<c-1<<'\n';
    for(int i =1;i<=n;i++) cout<<ans[i]<<' ';

    return 0;
}