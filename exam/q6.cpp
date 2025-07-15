#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        vector<set<int>> v(n+1);
        for(int i = 1;i<n;i++){
            int a, b; cin>>a>>b;
            v[a].insert(b); v[b].insert(a);
        }
        vector<int> curr{1};
        while(curr.size()){
            VI nex;
            for(auto i: curr){
                for(auto j: v[i]){
                    v[j].erase(i);
                    nex.push_back(j);
                }
            }
            curr=nex;
        }
        curr.push_back(1);
        vector<int> ans(n+1, -1); int t = 0;
        while(curr.size()){
            if(t%k==0){
                for(auto i: curr) ans[i]=t/k;
            }
            vector<int> nex;
            for(auto i: curr){
                for(auto j: v[i]){
                    nex.push_back(j);
                }
            }
            curr = nex;
            t++;
        }
        for(int i = 2;i<=n;i++) cout<<ans[i]<<' ';
        cout<<'\n';
    }

    return 0;
}