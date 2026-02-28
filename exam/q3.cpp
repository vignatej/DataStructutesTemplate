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
        vector<char> v(n); for(auto &i: v) cin>>i;
        stack<char> s;
        for(auto i: v){
            if(s.size()==0){s.push(i); continue;}
            if(s.top()==i){s.pop(); continue;}
            s.push(i);
        }
        cout<<(s.size()==0?"YES":"NO")<<'\n';

    }

    return 0;
}