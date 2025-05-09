#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int curr, int par, 
        vector<set<int>> &sets, 
        map<int, vector<int>> &tree,
        vector<int> &colors,
        vector<int> &ans
    ){
    sets[curr].insert(colors[curr]);
    int max_ans_child = 0;
    for(auto &i: tree[curr]){
        if(i==par) continue;
        dfs(i, curr, sets, tree, colors, ans);
        if(ans[i]>ans[max_ans_child]) max_ans_child = i;
    }
    if(tree[curr].size()==1 && par!=0){ans[curr]=1; return;}
    swap(sets[curr], sets[max_ans_child]);
    for(auto i: tree[curr]){
        if(i==par) continue;
        for(auto j: sets[i]) sets[curr].insert(j);
        sets[i].clear();
    }
    ans[curr]=sets[curr].size();


}

signed main(){
    int n; cin>>n;
    vector<int> colors(n+1);
    for(int i =1;i<=n;i++) cin>>colors[i];
    map<int, vector<int>> tree;
    for(int i = 1;i<n;i++){
        int a, b; cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<set<int>> sets(n+1);
    vector<int> ans(n+1, 0);
    dfs(1, 0, sets, tree, colors, ans);
    for(int i =1;i<=n;i++) cout<<ans[i]<<' ';

    return 0;
}