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
        int zc{0}, oc{0}, tc{0};
        for(int i = 0;i<n;i++){
            int c; cin>>c;
            if(c==0) zc++;
            else if(c==1) oc++;
            else tc++;
        }
        int ans{zc};
        for(int i = 0; i<=tc && i<=oc;i++){
            int cans = zc;
            cans+=i;
            cans+=(oc-i)/3;
            cans+=(tc-i)/3;
            ans=max(ans, cans);
        }
        // ans=max(ans, zc+oc/3);
        cout<<ans<<'\n';

    }

    return 0;
}