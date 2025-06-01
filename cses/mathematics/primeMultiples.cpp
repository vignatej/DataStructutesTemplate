#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, k; cin>>n>>k;
    VI v(k); for(int i = 0;i<k;i++) cin>>v[i];
    int ans{0};
    for(int i = 1;i<(1<<k);i++){
        int cs = __builtin_popcount(i);
        int cans{n}; int cp{1};
        for(int j = 0;j<=20;j++){
            if(!(i&(1<<j))) continue;
            // cans+=n/v[j];
            cans/=v[j];
        }
        // cans = n/cp;
        if(cs%2) ans+=cans;
        else ans-=cans;
    }
    cout<<ans;
    return 0;
}