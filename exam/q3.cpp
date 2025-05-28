#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        int l = -1; int ans{0};
        for(int i = 0;i<n;i++){
            int c; cin>>c;
            if(l+1>=c) continue;
            l=c; ans++; 
        }
        cout<<ans<<'\n';
    }

    return 0;
}