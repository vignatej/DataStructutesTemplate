#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

// vector<map<int, int>> dp;
// int do_it(int i, int rs, VI &v){
//     int n = v.size();
//     if(rs<0) return 0;
//     if(rs==0) return 1;
//     if(i==n) return 0;
//     if(rs<v[i]) return 0;
//     if(dp[i].find(rs)!=dp[i].end()) return dp[i][rs]; 
//     int ans = do_it(i+1, rs-v[i], v);
//     ans+=do_it(i+1, rs, v);
//     dp[i][rs]=ans;
//     return ans;
// }

signed main(){
    int n, x; cin>>n>>x;
    VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
    // sort(v.begin(), v.end());
    // dp.resize(n);
    // cout<<do_it(0, x, v);
    vector<int> v1, v2, ans1, ans2;
    for(int i = 0;i<n/2;i++) v1.push_back(v[i]);
    for(int i = n/2;i<n;i++) v2.push_back(v[i]);
    for(int i =0;i<(1<<(v1.size()));i++){
        int cs{0};
        for(int j = 0;j<32;j++){
            if(i & (1<<j)) cs+=v1[j];
        }
        ans1.push_back(cs);
    }
    for(int i =0;i<(1<<(v2.size()));i++){
        int cs{0};
        for(int j = 0;j<32;j++){
            if(i & (1<<j)) cs+=v2[j];
        }
        ans2.push_back(cs);
    }

    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());
    int ans{0};
    for(auto i: ans1){
        auto it1 = lower_bound(ans2.begin(), ans2.end(), x-i);
        auto it2 = upper_bound(ans2.begin(), ans2.end(), x-i);
        int d = distance(it1, it2);
        ans+=d;
    }
    cout<<ans;
    // for(auto i: ans1) cout<<i<<' ';
    // cout<<'\n';
    // for(auto i: ans2) cout<<i<<' ';
    
    return 0;
}