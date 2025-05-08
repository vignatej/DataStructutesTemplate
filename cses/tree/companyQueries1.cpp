#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    int n, q; cin>>n>>q;
    vector<vector<int>> v(n+1, vector<int>(32, 0));
    for(int i=2;i<=n;i++){
        int p; cin>>p;
        v[i][0]=p;
    }
    for(int j = 1;j<=30;j++){
        for(int i=1;i<=n;i++){
            int ans_by_2 = v[i][j-1];
            if(ans_by_2==0) continue;
            v[i][j]=v[ans_by_2][j-1];
        }
    }
    while(q--){
        int x, k; cin>>x>>k;
        int ans{x};
        for(int i = 0;i<32;i++){
            if(!(k&(1<<i))) continue;
            ans = v[ans][i];
            if(ans==0) break;
        }
        cout<<(ans>0 ? ans:-1)<<' ';
    }


    return 0;
}