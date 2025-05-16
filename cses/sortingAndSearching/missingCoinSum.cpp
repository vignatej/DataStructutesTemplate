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
    sort(v.begin(), v.end());
    int mv{0};
    for(int i = 0;i<n;i++){
        if(v[i]>mv+1){cout<<mv+1; return 0;}
        mv+=v[i];
    }
    cout<<mv+1;

    return 0;
}