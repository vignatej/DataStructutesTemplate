#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, mi, ma; cin>>n>>mi>>ma;
    VI v(n), ps(n+1, 0);
    for(int i =0;i<n;i++){
        int a; cin>>a;
        v[i]=a;ps[i+1]=ps[i]+a;
    }
    multiset<int> ms; int ans{1}; int ans_v{LLONG_MIN};
    for(int i = n-1;i>=0;i--){
        int f = i+mi;
        if(f<=n) ms.insert(ps[f]);
        int s = i+ma+1;
        if(s<=n) ms.erase(ms.find(ps[s]));
        if(ms.size()==0) continue;
        int cm = *ms.rbegin() - ps[i];
        if(cm>ans_v) ans_v = cm;
    }
    cout<<ans_v;
    return 0;
}