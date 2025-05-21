#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VI v(n), ps(n+1, 0);
    for(int i =0;i<n;i++){
        int a; cin>>a; v[i]=a; ps[i+1]=ps[i]+a;
    }
    map<int, int> m;
    int cm = ((ps[n]%n)+n)%n;
    // if(ps[n]<0) cm=(n-cm)%n;
    m[cm]++; int ans{0};
    // for(int i = 0;i<n;i++){
    //     int cs{0};
    //     for(int j =i;j<n;j++){
    //         cs+=v[j];
    //         if(cs%n==0){
    //             cout<<i<<' '<<j<<'\n';
    //         }
    //     }
    // }

    for(int i =n-1;i>=0;i--){
        int cm = ((ps[i]%n)+n)%n;
        // if(ps[i]<0) cm=(n-cm)%n;
        int nm = (n-cm)%n;
        if(m.find(cm)!=m.end()){
            ans+=m[cm];
        }m[cm]++;
    }
    cout<<ans;

    return 0;
}