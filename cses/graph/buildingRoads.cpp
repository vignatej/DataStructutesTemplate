#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int curr, vector<vector<int>> &graph, vector<bool> &comp){
    if(comp[curr]) return 0;
    comp[curr]=1;
    for(auto i: graph[curr]) dfs(i, graph, comp);
    return 1;
}
int find(int a, vector<int> &head){
    if(a==head[a]) return a;
    head[a]=find(head[a], head);
    return head[a];
}
void union_(int a, int b, vector<int> &head, vector<int> &siz){
    if(find(a, head)==find(b, head)) return;
    if(a!=find(a, head) || b!=find(b, head))
        return union_(find(a, head), find(b, head), head, siz);
    if(siz[a]<siz[b]) swap(a, b);
    siz[a]+=siz[b];
    head[b]=head[a];
}

signed main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> v(n+1, vector<int>{});
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> head(n+1, 0);
    vector<int> siz(n+1, 1);
    for(int i =1;i<=n;i++) head[i]=i;
    for(int i = 1;i<=n;i++) for(auto j: v[i]){
        if(find(i, head)!=find(j, head)) union_(i, j, head, siz);
    }
    for(int i =1;i<=n;i++) head[i]=find(i, head);
    set<int> heads;
    for(int i = 1;i<=n;i++) heads.insert(head[i]);
    vector<int> hea; copy(heads.begin(), heads.end(), back_inserter(hea));
    cout<<hea.size()-1<<'\n';
    for(int i = 0;i<hea.size()-1;i++) cout<<hea[i]<<' '<<hea[i+1]<<'\n';


    // vector<bool> comp(n+1, false);
    // int ans{0}; vector<int> ansl;
    // for(int i =1;i<=n;i++) if(dfs(i, v, comp)){
    //     ans++; ansl.push_back(i);
    // };
    // cout<<ans-1<<'\n';
    // for(int i = 0;i<ansl.size()-1;i++) cout<<ansl[i]<<' '<<ansl[i+1]<<'\n';

    return 0;
}