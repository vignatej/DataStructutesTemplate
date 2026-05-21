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
    int T; cin>>T;
    while(T--){
        int n, a, b, k; cin>>n>>a>>b>>k;
        if(a>b) swap(a, b);
        int d = min(b-a, n-(b-a));
        if(n==2 || n==3) {cout<<1<<'\n'; continue;}
        cout<<k+d<<'\n';

    }

    return 0;
}