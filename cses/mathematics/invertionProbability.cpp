#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n; 
    vector<double> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    double ans{0};
    for(int a = 0;a<n;a++){
        for(int b = a+1;b<n;b++){
            double ca{0};
            for(int i = 1;i<=v[a];i++) 
                for(int j =1;j<=v[b];j++) 
                    if(i>j) ca+=1;
            ca=ca/((double)v[a]*v[b]);
            ans+=ca;
        }
    }
    ans*=1e6;
    ans=1LL*round(ans);
    ans/=1e6;
    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}