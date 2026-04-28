#include <bits/stdc++.h>
using namespace std;


signed main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v(n); for(int i = 0;i<n;i++) cin>>v[i];
        int ans{0}; if(v.back()==1) ans+=1;
        for(auto i: v) if(i!=1) ans+=i;
        cout<<ans<<'\n';
    }
};
