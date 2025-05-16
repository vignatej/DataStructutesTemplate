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
    multiset<int> s;
    for(int i =n-1;i>=0;i--){
        auto it = s.upper_bound(-1ll*v[i]);
        if(it!=s.end()){
            s.erase(it);
        }
        s.insert(-1ll*v[i]);
    }
    cout<<s.size();
    return 0;
}