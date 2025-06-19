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
        int n; cin>>n;
        vector<int> A(n+1, 0), B(n+1, 0);
        for(int i = 1;i<=n;i++) cin>>A[i];
        for(int i = 1;i<=n;i++) cin>>B[i];
        int ans{0};
        stringstream ss;
        for(int i = 1;i<=n;i++){
            int mvp = i;
            for(int j = i+1;j<=n;j++) if(A[j]<A[mvp]) mvp=j;
            int mv = A[mvp];
            for(int j = mvp;j>i;j--) A[j]=A[j-1];
            A[i]=mv;
            ans+=mvp-i;
            for(int j = mvp-1;j>=i;j--) ss<<1<<' '<<j<<'\n';
        }
        for(int i = 1;i<=n;i++){
            int mvp = i;
            for(int j = i+1;j<=n;j++) if(B[j]<B[mvp]) mvp=j;
            int mv = B[mvp];
            for(int j = mvp;j>i;j--) B[j]=B[j-1];
            B[i]=mv;
            ans+=mvp-i;
            for(int j = mvp-1;j>=i;j--) ss<<2<<' '<<j<<'\n';
        }
        for(int i = 1;i<=n;i++){
            if(A[i]>B[i]){
                ans++;
                swap(A[i], B[i]);
                ss<<3<<' '<<i<<'\n';
            }
        }
        cout<<ans<<'\n';
        string sss = ss.str(); 
        cout<<sss;
    }

    return 0;
}