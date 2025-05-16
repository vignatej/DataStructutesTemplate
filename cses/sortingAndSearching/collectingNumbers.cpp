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
    for(int i = 0;i<n;i++){int a; cin>>a; v[i]={a, i};};
    sort(v.begin(), v.end());
    int ans{0}; int pi = n;
    for(int i = 0;i<n;i++){
        if(pi>v[i][1]) ans++;
        pi=v[i][1];
    }
    cout<<ans;

    return 0;
}