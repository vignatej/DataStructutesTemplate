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
        int n; cin>>n;
        int oc{0}, zc{0}; bool ans = 1;
        int p; cin>>p; if(p==1) oc++; else zc++;
        for(int i =1;i<n;i++){
            int c; cin>>c;
            if(c==1) oc++;
            else zc++;
            if(p==0 && c==0) ans=false;
            p=c;
        }
        if(oc==n) ans=false;
        if(!ans) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }

    return 0;
}