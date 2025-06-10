#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool solve(VI &v, bool isp1){
    int cc{0};
    for(auto i: v) if(i){cc++;}
    if(cc==0) return false;
    if(cc==1) return true;
    int tc{0}, fc{0};
    for(int i = 0;i<v.size();i++){
        for(int j=1;j<=v[i];j++){
            v[i]-=j;
            bool curr = solve(v, !isp1);
            if(curr) tc++; else fc++;
            v[i]+=j;
        }
    }
    if(fc>tc) return 1;
    return 0;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
        if(solve(v, true)){
            cout<<"first\n";
        }else{
            cout<<"second\n";
        }
    }

    return 0;
}