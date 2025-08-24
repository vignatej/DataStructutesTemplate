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
        int n, m, q; cin>>n>>m>>q;
        vector<int> A(n), B(m), aps(n+1), bps(m+1);
        for(int i = 0;i<n;i++) cin>>A[i];
        for(int i = 0;i<m;i++) cin>>B[i];
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        for(int i = 0;i<n;i++) aps[i+1]=aps[i]+A[i];
        for(int i = 0;i<m;i++) bps[i+1]=bps[i]+B[i];
        while(q--){
            int x, y, z; cin>>x>>y>>z;
            if(z==0){
                cout<<0<<'\n';
                continue; 
            }
            int i1 = max(1LL*0, z-y-1);
            int j1 = min({n-1, x-1, z-1});

            int i2 = max(1LL*0, z-x-1);
            int j2 = min({m-1, y-1, z-1});

            if(i1>j1 || i2>j2){
                if(i1>j1 && i2>j2){
                    cout<<0<<'\n';
                    continue;
                }else if(i1>j1){
                    if(z<=y) cout<<bps[z]<<'\n';
                    else cout<<0<<'\n';
                    continue;
                }else{
                    if(z<=x) cout<<aps[z]<<'\n';
                    else cout<<0<<'\n';
                    continue;
                }
            }

            int ans = aps[i1+1] + bps[z-i1-1];
            while(i1<=j1){
                int m1 = i1 + (j1-i1)/3;
                int m2 = j1 - (j1-i1)/3;
                int cans1 = aps[m1+1]+bps[z-m1-1];
                int cans2 = aps[m2+1]+bps[z-m2-1];
                if(cans1<cans2){
                    ans = max(ans, cans2);
                    i1=m1+1;
                }else{
                    ans=max(ans, cans1);
                    j1=m2-1;
                }
            }

            while(i2<=j2){
                int m1 = i2 + (j2-i2)/3;
                int m2 = j2 - (j2-i2)/3;
                int cans1 = bps[m1+1]+aps[z-m1-1];
                int cans2 = bps[m2+1]+aps[z-m2-1];
                if(cans1<cans2){
                    ans = max(ans, cans2);
                    i2=m1+1;
                }else{
                    ans=max(ans, cans1);
                    j2=m2-1;
                }
            }

            cout<<ans<<'\n';
        }

    }

    return 0;
}