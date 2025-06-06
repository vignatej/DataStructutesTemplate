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
    int n; cin>>n;
    VVI coef{
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0},
    };
    VVI om{{32,16,8,4,2,1}};
    VVI fcm = calc_pow(coef, n);
    VVI ans_m = mat_mul(fcm, om);
    cout<<ans_m[0][5];


    return 0;
}