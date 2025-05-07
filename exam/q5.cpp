#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

    
signed main(){
    int T; cin>>T;
    while(T>0){T--;
        int n; cin>>n;
        vector<ll> v(n);
        for(int i = 0;i<n;i++) cin>>v[i];
        ll ans{0};
        ll ts = accumulate(v.begin(), v.end(), 1ll*0);
        map<int, int> m;
        for(int i = 0;i<32;i++){
            for(auto j: v){
                if(((j>>i)&(1))) m[i]++;
            }
        }
        for(int i = 0;i<n;i++){
            int c_s = ts;
            c_s+=v[i]*n;
            for(int j = 0;j<32;j++){
                int cv = 1ll*((v[i]>>j)&1)*m[j]*powl(2, j);
                c_s -= 2*(cv);
            }
            ans = max(ans, c_s);
        }
        cout<<ans<<'\n';

        // int ans{-1}; int req{0};
        // for(auto &i: v){
        //     int ca = 0;
        //     for(auto &j: v){
        //         ca+=i^j;
        //     }
        //     if(ans<ca){ans=ca; req=i;}
        // }
        // cout<<ans<<' '<<req<<'\n';
    }
}
