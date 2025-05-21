#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n;cin>>n;
    VVI v;
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        v.PB({a, b, i});
    }
    sort(v.begin(), v.end(), [](VI &a, VI &b){return a[1]<b[1];});
    map<int, vector<int>> m;
    int cc{0};
    VI ans(n, 0);
    for(auto &i: v){
        int a{i[0]}, b{i[1]}, c{i[2]};
        auto it = m.lower_bound(a);
        if(it==m.begin()){
            m[b].PB(++cc);
            ans[c]=cc;
            continue;
        }
        it--;
        int cc = it->second.back();
        it->second.pop_back();
        if(it->second.size()==0) m.erase((it));
        m[b].PB(cc);
        ans[c]=cc;
    }
    cout<<cc<<'\n';
    for(auto i: ans) cout<<i<<' ';

    return 0;
}