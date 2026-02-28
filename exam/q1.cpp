#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v(n); for(auto &i: v) cin>>i;
        int m = v[0]; for(auto i: v) m=max(m, i);
        int c{0}; for(auto i: v) if(i==m) c++;
        cout<<c<<'\n';
        // continue;
    }

    return 0;
}