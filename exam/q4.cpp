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
        int n, x, y; cin>>n>>x>>y;
        vector<int> v(n); for(auto &i: v) cin>>i;
        vector<int> f, s;
        for(int i = 1;i<=n;i++){
            if(i<=x){
                f.push_back(v[i-1]);
            }else if(i<=y){
                s.push_back(v[i-1]);
            }else{
                f.push_back(v[i-1]);
            }
        }
        int min_s = 0; 
        for(int i = 0;i<s.size();i++) if(s[i]<s[min_s]) min_s=i;
        vector<int> ns;
        for(int i = min_s;i<s.size();i++) ns.push_back(s[i]);
        for(int i = 0;i<min_s;i++) ns.push_back(s[i]);
        s=ns;

        vector<int> ans;
        int i = 0;
        for(;i<f.size();i++){
            if(f[i]>s[0]) break;
            ans.push_back(f[i]);
        }
        copy(s.begin(), s.end(), back_inserter(ans));
        for(;i<f.size();i++){
            ans.push_back(f[i]);
        }
        for(auto i: ans) cout<<i<<' ';
        cout<<'\n';
    }

    return 0;
}