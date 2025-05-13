#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define VVI vector<vector<int>> 
#define VI vector<int>
#define VB vector<bool>
#define PB push_back

void dfs1(int curr, VB &mark, VI &stack, VVI &g){
    if(mark[curr]) return;
    mark[curr]=1;
    for(auto i: g[curr]) dfs1(i, mark, stack, g);
    stack.push_back(curr);
}
void dfs2(int curr, VB &mark, VVI &g, VI &comp, int cc){
    if(mark[curr]) return;
    comp[curr]=cc;
    mark[curr]=1;
    for(auto i: g[curr])
        dfs2(i, mark, g, comp, cc);
}

signed main(){
    int n, m; cin>>n>>m;
    VVI g(n+1), rg(n+1);
    VI indeg(n+1, 0), outdeg(n+1, 0);
    bool rev_edge = false;
    VVI edges;
    vector<multiset<int>> vs(n+1);
    
    int ennn{0};
    for(int i = 1;i<=m;i++){
        int a, b; cin>>a>>b;
        ennn=a;
        outdeg[a]++; indeg[b]++;
        g[a].PB(b);
        rg[b].PB(a);
        if(a==n & b==1) rev_edge=true;
        edges.PB({a, b});
        vs[a].insert(b);
    } 
    // if(rev_edge){ 
    //     cout<<"IMPOSSIBLE";
    //     return 0;
    // }
    
    // if(!rev_edge){
        g[n].PB(1);rg[1].PB(n); edges.PB({n, 1}); vs[n].insert(1);
        outdeg[n]++; indeg[1]++;
    // }
    int l{0},r{0}; m=0;
    for(int i =1;i<=n;i++){
        if(indeg[i]<outdeg[i] && indeg[i]+1==outdeg[i]) l++;
        else if(indeg[i]==outdeg[i]) m++;
        else if(indeg[i]>outdeg[i] && indeg[i]==1+outdeg[i]) r++;
    }
    if(!(m==n)){
        cout<<"IMPOSSIBLE"; 
        return 0;
    }
    // if(outdeg[n]>1){
    //     cout<<"IMPOSSIBLE"; 
    //     return 0;
    // }
    VB mark(n+1, false);
    VI stack;
    for(int i =1;i<=n;i++)
        if(!mark[i]) dfs1(i, mark, stack, g);
    for(int i = 0;i<=n;i++) mark[i]=0;
    reverse(stack.begin(), stack.end());
    int cc{0}; VI comp(n+1, 0);
    for(auto i: stack) if(!mark[i])
        dfs2(i, mark, rg, comp, ++cc);
    for(auto i: edges){
        int a{i[0]},b{i[1]};
        if(comp[a]!=comp[ennn]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    vector<int> ans, stk{1};
    while(stk.size()){
        auto t = stk.back();
        for(auto i: vs[t]){
            vs[t].erase(vs[t].find(i));
            stk.push_back(i);
            break;
        }
        if(stk.back()==t){
            stk.pop_back();
            ans.PB(t);
        }
    }
    // if(ans.back()!=1) ans.push_back(1);
    reverse(ans.begin(), ans.end());
    // auto it = find(ans.begin(), ans.end(), n);
    // it++;
    vector<int> temp;
    // copy(it, prev(ans.end()), back_inserter(temp));
    // copy(ans.begin(), it, back_inserter(temp));
    int i;
    for(i =0;i<ans.size()-1;i++){
        if(ans[i]==n && ans[i+1]==1){break;}
    }
    i++;
    for(int j = 0;i+j<ans.size()-1; j++) temp.push_back(ans[i+j]);
    for(int j = 0;j<i;j++) temp.push_back(ans[j]);

    // for(auto i: ans) cout<<i<<' ';
    // cout<<'\n';
    for(auto i: temp) cout<<i<<' ';
    

    return 0;
}