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
    for(int i = 1;i<=n;i++){
        int a; cin>>a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<n;i++){
        int curr = v[i][0];
        VI req = {x-curr, 0};
        auto it = lower_bound(next(v.begin(), i+1), v.end(), req);
        if(it==v.end()) continue;
        if((*it)[0]+curr==x){
            cout<<v[i][1]<<' '<<(*it)[1];
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}