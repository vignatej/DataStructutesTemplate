#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    double n, k; cin>>n>>k;
    double ans{0};
    for(double a =1;a<=k;a+=1){
        double ca = pow(a/k, n)-pow((a-1)/k, n);
        ans+=ca*a;
    }
    // ans*=1e7; 
    // ans=(LL) ans;
    // if
    // // ans=1LL*round(ans);
    // // ans/=1e6;
    cout<<fixed<<setprecision(6)<<ans<<'\n';

    return 0;
}