#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int solve(int i, int k, int cs, vector<int> &v){
    int n = v.size();
    if(i==n){
        if(cs==0 && k==0) return 0;
        return 1e16;
    }
    if(k<=0) return 1e16;
    cs+=v[i];
    int ans = solve(i+1, k, cs, v);
    ans=min(ans, solve(i+1, k-1, 0, v)+cs*cs);
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, k; cin>>n>>k;
    vector<int> v(n); for(int i = 0;i<n;i++) cin>>v[i];
    int ans = solve(0, k, 0, v);
    cout<<ans;
    return 0;
}