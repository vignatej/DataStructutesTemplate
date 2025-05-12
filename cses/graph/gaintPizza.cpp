#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back

void dfs(int curr, vector<vector<int>> &g, vector<int> &stack, vector<bool> &mark){
    if(mark[curr]) return;
    mark[curr]=1;
    for(int j: g[curr])
        dfs(j, g, stack, mark);
    stack.push_back(curr);
}

void dfs2(int curr, int cc, vector<vector<int>> &rg, vector<int> &component, vector<bool> &mark){
    if(mark[curr]) return;
    mark[curr]=1;
    component[curr]=cc;
    for(auto i: rg[curr])
        dfs2(i, cc, rg, component,mark);
}

signed main(){
    int n, m; cin>>n>>m;
    swap(n, m);
    vector<vector<int>> g(2*n+1), rg(2*n+1);
    for(int i = 0;i<m;i++){
        int a, b; char c, d;
        cin>>c>>a>>d>>b;
        if(c=='+' && d=='+'){
            g[a+n].PB(b);
            g[b+n].PB(a);
        }else if(d=='+'){
            g[a].PB(b);
            g[b+n].PB(a+n);
        }else if(c=='+'){
            g[a+n].push_back(b+n);
            g[b].push_back(a);
        }else{
            g[a].push_back(b+n);
            g[b].push_back(a+n);
        }
    }
    for(int i=1;i<=2*n;i++){
        for(auto &j: g[i]){
            rg[j].push_back(i);
        }
    }
    vector<int> stack;
    vector<bool> mark(2*n+1, false);
    for(int i = 1;i<=2*n;i++)
        if(!mark[i]) dfs(i, g, stack, mark);
    vector<int> component(2*n+1, 0);
    vector<bool> newM(2*n+1, false);
    reverse(stack.begin(), stack.end());
    int cc{1};
    for(auto i: stack){
        if(newM[i]) continue;
        dfs2(i, cc, rg, component, newM);
        cc++;
    }
    vector<int> ans(n+1, 0);
    for(int i = 1;i<=n;i++){
        if(component[i]==component[i+n]){
            cout<<"IMPOSSIBLE";
            return 0;
        }else if(component[i]>component[i+n]){
            ans[i]=true;
        }else{
            ans[i]=false;
        }
    }
    for(int i = 1;i<=n;i++){
        if(ans[i]) cout<<'+';
        else cout<<'-';
        cout<<' ';
    }

    return 0;
}