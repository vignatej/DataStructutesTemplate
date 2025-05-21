#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, q; cin>>n>>q;
    VI v(n), ps(n+1, 0);
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v[i]=a;
        ps[i+1]=ps[i]+a;
    }
    while(q--){
        int a, b; cin>>a>>b;
        cout<<ps[b]-ps[a-1]<<'\n';
    }

    return 0;
}