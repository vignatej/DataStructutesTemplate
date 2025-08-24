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
        string s, V, D, b, v; cin>>s;
        cin>>n; cin>>b; cin>>v;
        int cs = b.length();
        for(int i = 0;i<cs;i++){
            if(v[i]=='V') V.push_back(b[i]);
            else D.push_back(b[i]);
        }
        reverse(V.begin(), V.end());
        cout<<V<<s<<D<<'\n';
    }

    return 0;
}