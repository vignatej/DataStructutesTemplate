#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, x; cin>>n>>x;
    VVI v;
    for(int i = 0;i<n;i++){int a; cin>>a; v.PB({a, i+1});}
    sort(v.begin(), v.end());
    bool ans{true};
    for(int i = 0;i<n-3 && ans;i++){
        int rs = x-v[i][0];
        for(int j = i+1;j<n-2 && v[j][0]<rs && ans;j++){
            // rs-=v[j][0];
            // for(int k = j+1;k<n-1 && v[k][0]<rs && ans;k++){
            //     rs-=v[k][0];
            //     auto it = lower_bound(next(v.begin(), k+1), v.end(), VI {rs, 0});
            //     if(it==v.end()){rs+=v[k][0]; continue;}
            //     if((*it)[0]!=rs){rs+=v[k][0]; continue;}
            //     cout<<v[i][1]<<' '<<v[j][1]<<' '<<v[k][1]<<' '<<(*it)[1];
            //     ans=false;
            // }
            // rs+=v[j][0];

            rs = x-v[i][0]-v[j][0];
            int k = j+1; int l = n-1;
            // k++; l--;
            while(k<l && ans){
                int cs{v[k][0]+v[l][0]};
                if(cs==rs){
                    ans = 0;
                    cout<<v[i][1]<<' '<<v[j][1]<<' '<<v[k][1]<<' '<<v[l][1];
                }else if(cs<rs){
                    k++;
                }else{
                    l--;
                }

            }




            // rs+=v[j][0];
        }
        // rs+=v[i][0];
    }
    if(ans) cout<<"IMPOSSIBLE";

    return 0;
}