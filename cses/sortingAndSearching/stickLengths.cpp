#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VI v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    ll ts = accumulate(v.begin(), v.end(), 1ll*0);
    sort(v.begin(), v.end());
    int ans{(ll) 1e16};
    int ps{0}; int ns{ts};
    for(int i = 0;i<n;i++){
        ns-=v[i];
        int cans = i*v[i]-ps + ns - (n-i-1)*v[i];
        ans=min(ans, cans);
        ps+=v[i];
    }   
    cout<<ans;

    return 0;
}