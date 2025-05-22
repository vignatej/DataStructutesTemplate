#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, q; cin>>n>>q;
    VI v(n); VVI vv(n+1, VI(32, 0));
    for(int i = 0;i<n;i++){
        cin>>v[i];
        vv[i+1]=vv[i];
        for(int j = 0;j<32;j++) 
            if((1&(v[i]>>j))) vv[i+1][j]++;
    }
    while(q--){
        int a, b; cin>>a>>b;
        int cans{0};
        for(int j = 0;j<32;j++){
            int c = vv[b][j]-vv[a-1][j];
            if(c%2==0) continue;
            cans|=(1<<j);
        }
        cout<<cans<<'\n';
    }

    return 0;
}