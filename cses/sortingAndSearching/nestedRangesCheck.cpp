#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VVI v(n);
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        v[i]={a, b, i};
    }
    sort(v.begin(), v.end(), [](VI &a, VI &b){
        return a[1]!=b[1] ? a[1]<b[1] : a[0]>b[0];
    });
    VI ans1(n, 0), ans2(n, 0);
    int msi = v[0][0];
    for(int i =1;i<n;i++){
        int a{v[i][0]}, b{v[i][1]}, c{v[i][2]};
        if(msi>=a) ans1[c]=1;
        msi=max(msi, a);
    }
    for(auto i: ans1) cout<<i<<' ';
    cout<<'\n';
    sort(v.begin(), v.end(), [](VI &a, VI &b){
        return a[1]!=b[1] ? a[1]>b[1] : a[0]<b[0];
    });
    int minp = v[0][0];
    for(int i=1;i<n;i++){
        int a{v[i][0]}, b{v[i][1]}, c{v[i][2]};
        if(minp<=a) ans2[c]=1;
        minp=min(minp, a);
    }
    
    for(auto i: ans2) cout<<i<<' ';
    cout<<'\n'; 

    return 0;
}