#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int LN = 300000;


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    vector<vector<int>> div(LN+5);
    for(int i =2;i<=LN+2;i++){
        for(int j = 1;i*j<=LN+2;j++) div[i*j].push_back(i);
    }
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v(n); for(auto &i: v) cin>>i;
        vector<int> ans(n+1, INT_MAX);
        for(auto i: v) ans[i]=1;
        for(int i = 2;i<=n;i++){
            for(auto j: div[i])
                ans[i]=min(ans[i], ans[i/j]+ans[j]);
        }
        for(auto &i: ans) if(i>=INT_MAX) i=-1;
        for(int i =1;i<=n;i++) cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}