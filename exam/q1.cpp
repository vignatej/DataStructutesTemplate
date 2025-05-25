#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        VI v(n); for(int i =0;i<n;i++) cin>>v[i];
        sort(v.begin(), v.end());
        int ans = n-1;
        int l = n-1;
        while(l>=0 && v[l]%2==1) l--;
        if(l!=-1){
            // dont consider
            int s{0};
            while(s<n && v[s]%2==1) s++;
            ans=min(ans, n-1-l+s);
        }
        l=n-1;
        while(l>=0 && v[l]%2==0) l--;
        if(l!=-1){
            int s{0};
            while(s<n && v[s]%2==0) s++;
            ans=min(ans, n-1-l+s);
        }
        cout<<ans<<'\n';
    }

    return 0;
}