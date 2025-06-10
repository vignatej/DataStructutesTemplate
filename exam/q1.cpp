#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n, x; cin>>n>>x;
        int fi = -1;
        VI v(n);
        for(int i = 0;i<n;i++){
            cin>>v[i];
            if(v[i]==1 && fi==-1) fi=i;
        }
        fi+=x; bool ya = false;
        for(int i = fi;i<n;i++) if(v[i]==1) ya=1;
        if(ya) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}