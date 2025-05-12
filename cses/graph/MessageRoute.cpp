#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs(int curr, set<int> &visited, int target, int max_len, int cl, vector<vector<int>> &graph, vector<int> &order){
    if(visited.find(curr)!=visited.end()) return 0;
    if(cl>max_len) return 0;
    visited.insert(curr); order.push_back(curr);
    if(curr==target) return 1;
    int cans = false;
    for(auto i: graph[curr]){ 
        if(visited.find(i)!=visited.end()) continue;
        cans = dfs(i, visited, target, max_len, cl+1, graph, order);
        if(cans) return 1;
    }
    order.pop_back(); visited.erase(curr);
    return 0;
}


signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int>{});
    for(int i = 0 ;i<m;i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool comp = false;
    vector<int> curr{1}; int cl = 0;
    vector<bool> all(n+1, false); all[1]=1;
    vector<int> prev(n+1, 0);
    while(!comp && curr.size()){
        vector<int> next;
        for(auto i: curr){
            all[i]=1;
            for(auto j: graph[i]){
                if(all[j]) continue;
                next.push_back(j);
                all[j]=true;
                if(j==n) comp=true;
                prev[j]=i;
            }
        }
        curr=next;
        cl++;
    }
    if(!comp){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<cl+1<<'\n';
    vector<int> ans;
    int t = n;
    while(prev[t]!=0){
        ans.push_back(t);
        t=prev[t];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(auto i: ans) cout<<i<<' ';

    // int l{0}; int r = n;
    // int ans{n+1}; vector<int> to;
    // while(l<=r){
    //     int m = (l+r)/2;
    //     set<int> curr;
    //     vector<int> order;
    //     dfs(1, curr, n, m, 0, graph, order);
    //     if(curr.find(n)!=curr.end()){
    //         r=m-1;
    //         if(ans>m){ans=m; to=order;}
    //     }else{
    //         l=m+1;
    //     }
    // }
    // if(ans==n+1){
    //     cout<<"IMPOSSIBLE"<<'\n';
    //     return 0;
    // }
    // cout<<ans+1<<'\n';
    // for(auto i: to) cout<<i<<' ';
    return 0;
}