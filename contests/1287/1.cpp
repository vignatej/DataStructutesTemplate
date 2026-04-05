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
        int n; cin>>n;
        string s; cin>>s;
        int i{0}; int j{1};
        int ans{0};
        while(i<n){
            while(i<n && s[i]=='P') i++;
            if(j<=i) j=i+1;
            while(j<n && s[j]=='P') j++;
            ans=max(ans, j-i-1);
            i=j;
        }
        cout<<ans<<'\n';
    }

    return 0;
}