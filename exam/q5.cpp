#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int get_hts(int c, vector<set<int>> &g, vector<int> &hts){
    if(hts[c]!=-1) return hts[c];
    int ch = 1;
    for(auto i: g[c]) ch = max(ch, get_hts(i, g, hts));
    return ch;
}

int get_child(int c, vector<set<int>> &g, vector<int> &child){
    if(child[c]!=-1) return child[c];
    int ch = 1;
    for(auto i: g[c]) ch += get_child(i, g, child);
    return ch;
}

int get_rem_count(int node, int h, vector<set<int>> &g, VI &hts, VI &child){
    int ans = 0;
    for(auto &i: g[node]){
        if(get_hts(i, g, hts)<h-1){
            ans+=get_child(i, g, child);
            continue;
        }
        ans += get_rem_count(node, h-1, g, hts, child);
    }
    return ans;
}


signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<set<int>> g(n+1); 
        for(int i=1;i<n;i++){
            int a, b; cin>>a>>b;
            g[a].insert(b); g[b].insert(a);
        }
        VI curr{1};
        while(curr.size()>0){
            VI next;
            for(auto &i: curr){
                for(auto &j: g[i]){
                    g[j].erase(i);
                    next.push_back(j);
                }
            }
            curr=next;
        }
        VI hts(n+1, -1), child(n+1, -1);
        get_hts(1, g, hts); get_child(1, g, child);
        int l{1}, r{get_hts(1, g, hts)};
        int ans = 1;
        while(l<=r){
            int m = (l+r)/2;
            get_rem_count(1, m, )
        }

    }

    return 0;
}