#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n,k; cin>>n>>k;
    VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    int i{0}, j{n-1}; int ans{0};
    while(i<=j){
        if(v[i]+v[j]<=k){i++; j--; ans++;}
        else{j--; ans++;}
    }
    // if(i==j) ans++;
    cout<<ans;
    return 0;
}