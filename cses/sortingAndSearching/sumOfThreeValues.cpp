#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, x; cin>>n>>x;
    VVI v;
    for(int i =0;i<n;i++){
        int a; cin>>a;
        v.PB({a, i+1});
    }
    sort(v.begin(), v.end());
    bool ans{true};
    for(int i = 0;i<n && ans;i++){
        for(int j = i+1;j<n && ans;j++){
            int cs = v[i][0]+v[j][0];
            auto it = lower_bound(next(v.begin(), j+1), v.end(), VI{x-cs, 0});
            if(it==v.end()) continue;
            if((*it)[0]==x-cs){
                ans=false;
                cout<<v[i][1]<<' '<<v[j][1]<<' '<<(*it)[1];
            }
        }
    }
    if(ans) cout<<"IMPOSSIBLE";

    return 0;
}