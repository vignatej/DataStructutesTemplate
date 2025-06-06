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
        int ans = LLONG_MAX;
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && v[i]==v[j]) j++;
            int cans = i*v[i]+(n-j)*v[i];
            ans = min(ans, cans);
            i=j;
        }
        cout<<ans<<'\n';
    }

    return 0;
}