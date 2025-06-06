#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;

VVI mat_mul(VVI a, VVI b){
    VVI c(a.size(), VI (b[0].size()));
    for(int i = 0;i<a.size(); i++){
        for(int j = 0;j<b[0].size();j++){
            int ans{0};
            for(int k = 0;k<b.size();k++) 
                ans = (ans+a[i][k]*b[k][j])%M;
            c[i][j]=ans;
        }
    }
    return c;
}
VVI calc_pow(VVI mat, int p){
    if(p==1) return mat;
    VVI ans = calc_pow(mat, p/2);
    ans=mat_mul(ans, ans);
    if(p%2) ans=mat_mul(ans, mat);
    return ans;
}

signed main(){
    int n, m, k; cin>>n>>m>>k;
    VVI adj(n, VI(n, 0));
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        a--; b--;
        adj[a][b]+=1;
    }
    VVI ans = calc_pow(adj, k);
    cout<<ans[0][n-1];

    return 0;
}