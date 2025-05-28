#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VI v(1e6+1, 0);
    for(int i = 0;i<n;i++){
        int a; cin>>a; v[a]++;
    }
    for(int i = 1e6;i>0;i--){
        int d{0};
        for(int j = i;j<=1e6;j+=i){
            if(v[j]) d+=v[j];
        }
        if(d>1){
            cout<<i;
            return 0;
        }
    }

    return 0;
}