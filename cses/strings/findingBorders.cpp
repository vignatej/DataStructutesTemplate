#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;

signed main(){
    string s; cin>>s; int n = s.length();
    ll p = 31;
    vector<ll> pp(n+1, 1);
    for(int i = 1;i<=n;i++) pp[i]=(pp[i-1]*p)%M;
    ll f_hv{0}, b_hv{0};
    ll ans{0};
    for(int i = 0;i<n-1;i++){
        int j = n-i-1;
        f_hv = (f_hv+((s[i]-'a'+1)*pp[i])%M)%M;
        b_hv=(b_hv*p)%M;
        b_hv+=(s[j]-'a'+1); b_hv%=M;
        if(f_hv==b_hv) cout<<(i+1)<<' ';
    }
    // cout<<ans;
    return 0;
}