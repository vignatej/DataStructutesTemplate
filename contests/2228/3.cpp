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
        int a, n; cin>>a>>n;
        int b0, b1; cin>>b0>>b1;
        string min_s, max_s; 
        while(min_s.length()!=to_string(a).length()-1) min_s.push_back('0'+b1);
        if(min_s.length()==0) min_s.push_back('0'+b0);
        int ans = abs(a-stoll(min_s));
        
        if(b0==0) max_s.push_back('0'+b1);
        else max_s.push_back('0'+b0);
        while(max_s.length()!=to_string(a).length()+1) max_s.push_back('0'+b0);
        ans=min(ans, abs(a-stoll(max_s)));
        

        int as = to_string(a).length();
        for(int i = 0;i<(1<<as);i++){
            int cn{0};
            for(int j = as-1;j>=0;j--){
                cn*=10;
                if(i&(1<<j)) cn+=b1;
                else cn+=b0;
            }
            ans=min(ans, abs(cn-a));
        }
        cout<<ans<<'\n';
    }

    return 0;
}