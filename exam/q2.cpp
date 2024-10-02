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
        int a1, a2, b1, b2;
        cin>>a1>>a2>>b1>>b2;
        int ans{0};
        if(iswin(a1, a2, b1, b2)) ans++;
        if(iswin(a1, a2, b2, b1)) ans++;
        if(iswin(a2, a1, b1, b2)) ans++;
        if(iswin(a2, a1, b2, b1)) ans++;
        cout<<ans<<'\n';
    }
}
