#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;

VVI mat_mul(VVI a, VVI b){
    VVI c = a;
    int n = a.size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int ans{0};
            for(int k = 0;k<n;k++) 
                ans = (ans + (a[i][k]*b[k][j])%M)%M;
            c[i][j]=ans;
        }
    }
    return c;
}

VVI mat_pow(VVI a, int m){
    if(m==1) return a;
    VVI an = mat_pow(a, m/2);
    an=mat_mul(an, an);
    if(m%2) an = mat_mul(an, a);
    return an;
}

signed main(){
    int n; cin>>n;
    if(n==0 || n==1){
        cout<<n;
        return 0;
    }
    VVI v{{1,1},{1,0}};
    VVI ans = mat_pow(v, n-1);
    cout<<ans[0][0];
    return 0;
}