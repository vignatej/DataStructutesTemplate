#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VI v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    set<int> s{v[0]};
    int ans{1};int pp{0};
    for(int i =1;i<n;i++){
        while(s.find(v[i])!=s.end()){
            s.erase(v[pp]); pp++;
        }
        s.insert(v[i]);
        ans=max(ans, (ll)s.size());
    }
    cout<<ans<<'\n';
    return 0;
}