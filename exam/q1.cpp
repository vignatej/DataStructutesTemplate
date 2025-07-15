#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, l, r; cin>>n>>l>>r;
    int ans{0};
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        if(a<=l && r<=b) ans++;
    }
    cout<<ans;

    return 0;
}