#include <bits/stdc++.h>
using namespace std;


signed main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int a, b; cin>>a>>b;
        cout<<(((a%2==1) & (b%2==1)) ? "NO":"YES")<<'\n';
    }
};
