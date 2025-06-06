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
        int n, m; cin>>n>>m;
        VI v(m); for(int i = 0;i<m;i++) cin>>v[i];
        sort(v.begin(), v.end(), [](int a, int b){
            return (a/100)<(b/100);
        });
        VVI ans(n, VI(6, 0));
        int j = 0;
        for(int i = 0;i<n;i++){
            if(i%2==1){
                ans[i][0]=ans[i-1][1];ans[i][1]=ans[i-1][0];
                ans[i][2]=ans[i-1][1];ans[i][3]=ans[i-1][0];
                ans[i][4]=ans[i-1][1];ans[i][5]=ans[i-1][0];
                continue;
            }
            ans[i][0]=v[j];ans[i][1]=v[m-1-j];
            ans[i][2]=v[j];ans[i][3]=v[m-1-j];
            ans[i][4]=v[j];ans[i][5]=v[m-1-j];
            j++;
        }
        
        for(auto &i: ans){
            for(auto j: i) cout<<j<<' ';
            cout<<'\n';
        }


        // VI first, second;
        // for(int i = 0;i<(n/2 + n%2);i++) first.PB(v[i]);
        // for(int i = 0;i<n/2;i++) second.PB(v[m-(n/2)+i]);
        // VVI ans(n, VI(6));
        // bool f = 1;
        // for(int j = 0;j<6;j++){
        //     if(f){
        //         int i;
        //         for(i = 0;i<(n/2 + n%2);i++) ans[i][j]=first[i];
        //         for(;i<n;i++) ans[i][j]=second[i-(n/2)-(n%2)];
        //     }else{
        //         int i;
        //         for(i = 0;i<(n/2);i++) ans[i][j]=second[i];
        //         for(;i<n;i++) ans[i][j]=first[i-(n/2)];
        //     }
        //     f=!f;
        // }
        // for(auto &i: ans){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
    }

    return 0;
}