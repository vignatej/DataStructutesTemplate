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
        vector<int> rem;
        while(n>0){
            rem.push_back(n%3);
            n/=3;
        }
        int ans{0};
        for(int i = 0;i<rem.size();i++){
            int cv{0};
            if(i==0) cv = 3;
            else cv = powl(3, i-1)*(9+i);
            ans+=rem[i]*cv;
        }
        cout<<ans<<'\n';
    }

    return 0;
}