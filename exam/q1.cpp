#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    int T; cin>>T;
    while(T>0){T--;
        string s; cin>>s;
        int ans{0};
        for(auto &i: s) ans+=i-'0';
        cout<<ans<<'\n';
    }
}
