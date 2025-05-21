#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, k; cin>>n>>k;
    VI v(n);for(int i = 0;i<n;i++) cin>>v[i];
    int l{*max_element(v.begin(), v.end())};
    int r{LLONG_MAX-l}; 
    int ans = r;
    while(l<=r){
        int m = (l+r)/2;
        int ck{0}; int cs{0};
        for(int i = 0;i<n;i++){
            if(cs+v[i]>m){
                ck++; cs=v[i];
            }else{
                cs+=v[i];
            }
        }ck++;
        if(ck<=k){
            ans=min(ans, m);
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<ans;
    return 0;
}