#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int curr, vector<vector<int>> &g, vector<int> &stack, vector<bool> &marked){
    if(marked[curr]) return;
    marked[curr]=1;
    for(auto i: g[curr])
        dfs(i, g, stack, marked);
    stack.push_back(curr);
}
void dfs(int curr, vector<vector<int>> &g, set<int> &stack, vector<bool> &marked){
    if(marked[curr]) return;
    marked[curr]=1;
    for(auto i: g[curr])
        dfs(i, g, stack, marked);
    stack.insert(curr);
}

signed main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n+1), rg(n+1);
    for(int i=1;i<=m;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vector<bool> marked(n+1, false);
    vector<int> stack;
    for(int i =1;i<=n;i++){
        if(marked[i]) continue;
        dfs(i, g, stack, marked);
    }
    
    set<int> cs;
    vector<bool> new_marked(n+1, false);
    marked=new_marked;
    dfs(stack[n-1], rg, cs, marked);
    if(cs.size()==n){
        cout<<"YES"; return 0;
    }
    for(int i =1;i<=n;i++){
        if(cs.find(i)!=cs.end()) continue;
        cout<<"NO\n"<<i<<' '<<(*cs.begin());
        return 0;
    }



}