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
        int n, ax, ay, bx, by; 
        cin>>n>>ax>>ay>>bx>>by;
        vector<int> v1(n), v2(n);
        for(auto &i: v1) cin>>i;
        for(auto &i: v2) cin>>i;
        map<int, int> mi, ma;
        mi[ax]=ay; ma[ax]=ay;
        mi[bx]=by; ma[bx]=by;
        for(int i = 0;i<n;i++)
            if(mi.find(v1[i])==mi.end()) mi[v1[i]]=v2[i]; 
            else mi[v1[i]]=min(mi[v1[i]], v2[i]);
        for(int i = 0;i<n;i++) 
            if(ma.find(v1[i])==ma.end()) ma[v1[i]]=v2[i];
            else ma[v1[i]]=max(ma[v1[i]], v2[i]);
        int XD = ma.rbegin()->first - ma.begin()->first;
        vector<vector<int>> v;
        for(auto i: ma){
            int x = i.first;
            int l = mi[x]; int h = ma[x];
            v.push_back({l, h});
        }
        n = v.size();
        vector<vector<int>> dp(n, vector<int> (2, 0));
        for(int i = n-2;i>=0;i--){
            dp[i][0]=v[i][1]-v[i][0]+min(
                dp[i+1][1]+abs(v[i+1][1]-v[i][1]),
                dp[i+1][0]+abs(v[i+1][0]-v[i][1])
            );
            dp[i][1]=v[i][1]-v[i][0]+min(
                dp[i+1][0]+abs(v[i+1][0]-v[i][0]),
                dp[i+1][1]+abs(v[i+1][1]-v[i][0])
            );
        }
        cout<<XD+min(dp[0][0], dp[0][1])<<'\n';

    }

    return 0;
}