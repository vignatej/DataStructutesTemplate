#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

class Sol{ public:   
    vector<int> head, siz;
    int getHead(int i){
        if(head[i]==i) 
            return i;
        return head[i]=getHead(head[i]);
    }
    void union_(int a, int b){
        a = getHead(a); b = getHead(b);
        if(a==b) return;
        if(siz[a]<siz[b]) swap(a, b);
        siz[a]+=siz[b];
        head[b]=a;
    }
};

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> G;
    for(int i =0;i<m;i++){
        int a, b, w; cin>>a>>b>>w;
        G.push_back({a, b, w});
    }
    Sol S;
    S.head.resize(n+1, 0);
    S.siz.resize(n+1, 1);
    for(int i = 1;i<=n;i++) S.head[i]=i;
    sort(G.begin(), G.end(), [](vector<int> &a, vector<int> &b){
        return a[2]<b[2];
    });
    int ans{0};
    for(auto i: G){
        int a{i[0]},b{i[1]},w{i[2]};
        if(S.getHead(a)==S.getHead(b)) continue;
        ans+=w;
        S.union_(a, b);
    }
    for(int i =1;i<n;i++){
        if(S.getHead(i)!=S.getHead(1)){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    cout<<ans;
    return 0;
}