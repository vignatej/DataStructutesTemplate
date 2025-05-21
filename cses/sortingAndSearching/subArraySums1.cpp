#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, x; cin>>n>>x;
    VI v(n), ps(n+1, 0);
    for(int i =0;i<n;i++){
        int a; cin>>a;
        v[i]=a;
        ps[i+1]=ps[i]+a;
    }
    int ans{0};
    for(int i = 0;i<n;i++){
        int rs = ps[i]+x;
        auto it = lower_bound(next(ps.begin(), i+1), ps.end(), rs);
        if(it==ps.end()) continue;
        if(*it==rs) ans++;
    }
    cout<<ans;
    return 0;
}