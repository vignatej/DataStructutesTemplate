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
        int mu = 1; int cn = powl(10, mu)+1;
        vector<int> ans;
        while((n/cn)>0 && mu<19 && cn<=n){
            if(n%cn==0){
                ans.push_back(n/cn);
            }
            mu++; cn = powl(10, mu)+1;
        }
        cout<<ans.size()<<'\n';
        sort(ans.begin(), ans.end());
        for(auto i: ans) cout<<i<<' '; 
        if(ans.size())cout<<'\n';
    }

    return 0;
}