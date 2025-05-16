#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    map<int, int> m;
    for(int i =0;i<n;i++){
        int a, b; cin>>a>>b;
        m[a]++; m[b]--;
    }
    int curr=0; int ans{0};
    for(auto i: m){
        curr+=i.second;
        ans=max(ans, curr);
    }
    cout<<ans;
    return 0;
}