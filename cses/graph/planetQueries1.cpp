#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    ios_base::sync_with_stdio(); cin.tie(NULL); cout.tie(NULL);
    int n, q; cin>>n>>q;
    vector<vector<int>> v(n+1, vector<int>(31, 0));
    for(int i = 1;i<=n;i++){
        int p; cin>>p;
        v[i][0]=p;
    }
    for(int j = 1;j<31;j++){
        for(int i =1;i<=n;i++){
            int half = v[i][j-1];
            v[i][j] = v[half][j-1];
        }
    }
    while(q--){
        int c, x; cin>>c>>x;
        int ans = c;
        for(int i = 0;i<31;i++){
            if(!(x&(1<<i))) continue;
            ans = v[ans][i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}