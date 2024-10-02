#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool iswin(int a1, int a2, int b1, int b2){
    int ans{0};
    if(a1>b1) ans++;
    else if(a1<b1) ans--;
    if(a2>b2) ans++;
    else if(a2<b2) ans--;
    return (ans>0);
}

signed main(){
    int T; cin>>T;
    while(T>0){T--;
        int n, rt, ot;cin>>n>>rt>>ot;
        bool cs{false};
        int prev = 0;
        for(int i = 0;i<n;i++){
            int l, r; cin>>l>>r;
            if(l-prev>=rt) cs=true;
            prev = r;
        } 
        if(ot-prev>=rt) cs=true;
        cout<<(cs?"YES":"NO")<<'\n';
    }
}
