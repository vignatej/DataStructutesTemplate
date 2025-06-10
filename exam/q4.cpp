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
        VI v(n+1, 0); for(int i = 1;i<=n;i++) cin>>v[i];
        int k2 = (2*v[1]-v[2])/(n+1);
        int k1 = k2+v[2]-v[1];
        VI gen(n+1, 0);
        for(int i = 1;i<=n;i++){
            gen[i]=i*k1+(n-i+1)*k2;
        }
        if(k1>=0 && k2>=0 && v==gen) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}