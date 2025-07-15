#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, k; cin>>n>>k;
    vector<bitset<30>> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    int ans = k;
    for(int i = 0;i<n;i++)
        for(int j = i+1;j<n;j++)
            ans = min(ans, (int) (v[i]^v[j]).count());
    cout<<ans;
    return 0;
}