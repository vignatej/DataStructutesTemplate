#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, m; cin>>n>>m;
    VI h(n), r(m);
    for(int i =0;i<n;i++) cin>>h[i];
    for(int i =0;i<m;i++) cin>>r[i];
    int nn=1;
    while(nn<n) nn=nn<<1;
    VI arr(2*nn, 0);
    for(int i =0;i<n;i++) arr[i+nn]=h[i];
    for(int i =nn-1;i>0;i--) arr[i]=max(arr[2*i], arr[2*i+1]);
    for(int q = 0;q<m; q++){
        int rs = r[q];
        int s = 1;
        while(s<nn && arr[s]>=rs){
            if(arr[2*s]>=rs) s =2*s;
            else s=2*s+1;
        }
        if(arr[s]<rs){
            cout<<0<<'\n';
            continue;
        }
        cout<<s-nn+1<<'\n';
        arr[s]-=rs; s/=2;
        while(s){
            arr[s]=max(arr[2*s], arr[2*s+1]);
            s/=2;
        }
    }

    return 0;
}