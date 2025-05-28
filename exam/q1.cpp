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
        int a; cin>>a;
        int b = sqrt(a);
        if(b*b==a){
            cout<<0<<' '<<b<<'\n';
        }else{
            cout<<-1<<'\n';
        }

    }

    return 0;
}