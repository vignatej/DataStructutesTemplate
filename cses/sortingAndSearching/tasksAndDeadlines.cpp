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
    for(int i=0;i<n;i++){
        int a, b; cin>>a>>b;
        v.PB({a, b});
    }
    sort(v.begin(), v.end());
    int ans{0};
    int st{0};
    for(auto i: v){
        int dur = i[0]; int dl = i[1];
        ans+=dl-st-dur;
        st+=dur;
    }   
    cout<<ans<<'\n';

    return 0;
}