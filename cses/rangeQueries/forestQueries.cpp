#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, q; cin>>n>>q;
    VVI v(n+1, VI (n+1, 0));
    for(int i =1;i<=n;i++) {
        v[i]=v[i-1];
        int cv{0};
        for(int j =1;j<=n;j++){
            char c; cin>>c;
            if(c=='*') cv++;
            v[i][j]+=cv;
        }   
    }
    while(q--){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        int ans = v[x2][y2]-v[x2][y1-1]-v[x1-1][y2]+v[x1-1][y1-1];
        cout<<ans<<'\n';
    }

    return 0;
}