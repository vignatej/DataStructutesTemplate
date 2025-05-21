#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, k; cin>>n>>k;
    VVI v;
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        v.PB({a, b});
    }
    sort(v.begin(), v.end(),[](VI &a, VI &b){
        return a[1]!=b[1] ? a[1]<b[1]:a[0]<b[0];
    });
    multiset<int> ms;
    for(int i = 0;i<k;i++) ms.insert(0);
    int ans{0};
    for(auto i: v){
        int s{i[0]}, e{i[1]};
        auto it = ms.upper_bound(s);
        if(it==ms.begin()) continue;
        it=prev(it);
        ms.erase(it);
        ms.insert(e);
        ans++;
    }
    cout<<ans;

    return 0;
}