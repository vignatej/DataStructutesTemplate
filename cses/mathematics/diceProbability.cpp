#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, a, b; cin>>n>>a>>b;
    vector<vector<double>> v(n+1, vector<double>(b+1, 0));
    for(int i = 1;i<=6 && i<=b;i++) v[1][i]=(double)1/6;
    for(int i =2;i<=n;i++){
        for(int j = i;j<=b;j++){
            double cv = 0;
            for(int k = 1;k<=6 && j-k>0;k++) cv+=v[i-1][j-k];
            v[i][j]=cv/6;
        }
    }
    double ans{0};
    for(int i = a;i<=b;i++) ans+=v[n][i];
    ans*=1e6;
    ans=round(1LL*ans);
    ans/=1e6;
    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}