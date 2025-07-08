#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
        int ans = 1;
        for(int i = 0;i<n-1;i++){
            if(v[i+1]%v[i]==0) continue;
            int g = gcd(v[i], v[i+1]);
            int ck = v[i]/g;

            // gcd woth found lcm
            int lg = gcd(ans, ck);
            ans = (ans*ck)/lg;
        }
        cout<<ans<<'\n';
    }

    return 0;
}