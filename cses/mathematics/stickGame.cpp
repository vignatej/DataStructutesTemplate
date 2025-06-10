#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

vector<vector<pair<int, int>>> dp;
pair<int, int> solve(VI &v, int sticks_rem, bool isp1){
    if(sticks_rem<0) return {0,0};
    if(sticks_rem==0){
        if(isp1) return {0,1};
        return {1, 0};
    }
    if(dp[sticks_rem][isp1]!=pair<int, int> {-1, -1}) return dp[sticks_rem][isp1];
    auto ans = solve(v, sticks_rem-1, !isp1);
    for(auto &i: v){
        int rs = sticks_rem-i;
        auto cans = solve(v, rs, !isp1);
        if(isp1){
            if(ans.first<cans.first) ans = cans;
        }else{
            if(ans.second<cans.second) ans=cans;
        }
    }
    dp[sticks_rem][isp1] = ans;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n,k; cin>>n>>k;
    VI v(k); 
    for(int i = 0;i<k;i++) cin>>v[i];
    dp.resize(n+1, vector<pair<int, int>> (2, {-1,-1}));
    solve(v, n, 1);solve(v, n, 0);
    for(int i = 1;i<=n;i++){
        auto a = solve(v, i, 1);
        if(a.first>a.second) cout<<'W';
        else cout<<'L';
    }

    return 0;
}