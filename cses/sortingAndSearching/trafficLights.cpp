#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int x, n; cin>>x>>n;
    set<pair<int, int>> s{{0, x}};
    map<int, set<pair<int, int>>> m; m[x].insert({0, x});
    while(n--){
        int a; cin>>a;
        auto it = s.lower_bound({a,0});
        it--;
        int f{(*it).first}, se{(*it).second};
        s.erase(it);
        int d = se-f;
        m[d].erase({f, se});
        if(m[d].size()==0) m.erase(d);
        s.insert({f, a}); s.insert({a, se});
        m[a-f].insert({f, a});
        m[se-a].insert({a, se});
        cout<<m.rbegin()->first<<' ';
    }

    return 0;
}