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
        int n; cin>>n;
        VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
        int mtn = v[0];
        bool ya = 0;
        for(int i =1;i<n;i++){
            if(mtn>v[i]) ya=1;
            mtn = max(mtn, v[i]);
        }
        if(!ya){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n2\n";
        mtn=v[0];
        for(int i =1;i<n;i++){
            if(mtn>v[i]){
                cout<<mtn<<" "<<v[i]<<'\n';
                break;
            }
            mtn = max(mtn, v[i]);
        }
    }

    return 0;
}