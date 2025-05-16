#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VVI v;
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(),[](VI &a, VI &b){
        return a[1]<b[1];
    });
    map<int, int> m;
    for(auto &i: v){
        int a{i[0]}, b{i[1]};
        auto it = m.lower_bound(a);
        if((it->first)==a){
            m[b]=max(m[b], m[a]+1);
        }else{
            if(it==m.begin()){
                m[b]=max(m[b], 1ll);
            }else{
                it--;
                m[b]=max(m[b], it->second+1);
            }
        }
        auto it1 = m.rbegin();
        if(m.size()>1 && next(it1)->second>=it1->second)
            m.erase((++it1).base());
    }
    cout<<(m.rbegin()->second);

    return 0;
}