#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;

VVI mat_min_add(VVI a, VVI b){
    VVI c(a.size(), VI (b[0].size()));
    for(int i = 0;i<a.size(); i++){
        for(int j = 0;j<b[0].size();j++){
            int ans{LLONG_MAX};
            for(int k = 0;k<b.size();k++) 
                if(a[i][k]!=LLONG_MAX && b[k][j]!=LLONG_MAX)
                    ans = min(ans,(a[i][k]+b[k][j]));
            c[i][j]=ans;
        }
    }
    return c;
}
VVI calc_pow(VVI mat, int p){
    if(p==1) return mat;
    VVI ans = calc_pow(mat, p/2);
    ans=mat_min_add(ans, ans);
    if(p%2) ans=mat_min_add(ans, mat);
    return ans;
}

signed main(){
    int n, m, k; cin>>n>>m>>k;
    VVI wts(n, VI(n, LLONG_MAX));
    for(int i = 0;i<m;i++){
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        wts[a][b]=min(wts[a][b], c);
    }
    VVI ans = calc_pow(wts, k);
    if(ans[0][n-1]==LLONG_MAX) cout<<"-1";
    else cout<<ans[0][n-1];

    return 0;
}