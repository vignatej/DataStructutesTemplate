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
        string s; cin>>s;
        int l{-1}, r{-1};
        for(int i = 0;i<n && i<x-1;i++)
            if(s[i]=='#') l=i+1;
        for(int i = x;i<n && r==-1;i++) 
            if(s[i]=='#') r=i+1;
        
        int ans1 = min(x, 1+n-r+1);
        if(r==-1) ans1=1;

        int ans2 = min(l+1,n-x+1);
        if(l==-1) ans2=1;

        int ans = max(ans1, ans2);
        cout<<ans<<'\n';

    }

    return 0;
}