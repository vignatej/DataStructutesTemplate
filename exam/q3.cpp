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
        int n; cin>>n;
        int d;
        cout<<"digit"<<'\n'; cin>>d;
        cout<<"digit"<<'\n';cin>>d;
        cout<<"add -8"<<'\n';cin>>d;
        cout<<"add -4"<<'\n';cin>>d;
        cout<<"add -2"<<'\n';cin>>d;
        cout<<"add -1"<<'\n';cin>>d;
        cout<<"add "<<n-1<<'\n';cin>>d;
        cout<<'!'<<'\n'; cin>>d;
    }
}
