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
        int n, k; cin>>n>>k;
        int oc{0}, zc{0};
        for(int i = 0;i<n;i++){
            char c; cin>>c;
            if(c=='1') oc++;
            else zc++;
        }
        int min_p = (max(oc, zc)-min(oc, zc))/2;
        int max_p = (oc/2)+(zc/2);
        bool ans = 1;
        if(k<min_p || max_p<k) ans=0;
        else{
            if((k-min_p)%2!=0) ans=0;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}