#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    VI tn;
    for(int i = 1;;i++){
        int c = i*(i+1); c/=2;
        if(c>1e12) break;
        tn.PB(c);
    }
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        int ans{0};
        while(n){
            auto it = upper_bound(tn.begin(), tn.end(), n);
            it = prev(it);
            n-=*it;
            ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}