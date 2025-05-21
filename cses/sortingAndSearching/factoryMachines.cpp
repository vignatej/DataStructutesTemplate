#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, k; cin>>n>>k;
    VI v(n);
    for(int i =0;i<n;i++) cin>>v[i];
    int l{0}, r{LLONG_MAX};
    
    int ans = r;
    while(l<=r){
        int m = (l+r)/2;
        int cans = 0;
        for(int i = 0;i<n && cans<k;i++){
            cans+=m/v[i];
        }
        if(cans>=k){
            r=m-1;
            ans=min(ans, m);
        }else{
            l=m+1;
        }
    }
    cout<<ans;

    return 0;
}