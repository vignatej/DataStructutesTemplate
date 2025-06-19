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
        int n, s; cin>>n>>s;
        vector<int> v(n);
        for(int i = 0;i<n;i++) cin>>v[i];
        sort(v.begin(), v.end());
        if(s==v[0] || s==v.back()){
            cout<<v.back()-v.front()<<'\n';
            continue;
        }
        int ans = abs(s-v[0])+v.back()-v[0];
        ans = min(ans, abs(v.back()-s)+v.back()-v[0]);
        cout<<ans<<'\n';
    }

    return 0;
}