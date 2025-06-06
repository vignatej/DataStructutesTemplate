#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        VI v{x,x,x};
        int ans{0};
        while(v[0]!=0 || v[1]!=0 || v[2]!=0){
            if(v[0]==v[1] && v[1]==v[2]){
                v[0]/=2;
            }else if(v[0]==v[1]){
                v[2]/=4;
            }else if(v[1]==v[2]){
                v[1]/=2;
            }
            sort(v.begin(), v.end());
            ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}