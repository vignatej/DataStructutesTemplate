#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int get_fir_zero(int a){
    for(int j = 0;j<63;j++) 
        if((a &(((LL)1LL)<<j))==0){
            a=j; break;
        }
    return a;    
}
int count_ones(int a){
    int cnt{0};
    for(int j = 0;j<63;j++) 
        if((a &(((LL)1LL)<<j))){
            cnt++;
        }
    return cnt;
}
signed main(){
    int T; cin>>T;
    while(T--){
        int n, m; cin>>n>>m;
        VVI v(n, VI(m, 0));
        for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin>>v[i][j];
        int mv = 0;
        for(int i = 0;i<n;i++) for(int j = 0;j<m;j++)
            mv = max(mv, v[i][j]);
        VVI mvp;
        for(int i = 0;i<n;i++) for(int j = 0;j<m;j++)
            if(v[i][j]==mv) mvp.PB({i, j});
        int c = -1; bool all_on_same_col{true};
        for(int i =1;i<mvp.size();i++){
            if(mvp[i][0]==mvp[0][0]) continue;
            if(c==-1) c = mvp[i][1];
            if(c!=mvp[i][1]) all_on_same_col = false;
        }
        if(all_on_same_col){
            cout<<mv-1<<'\n';
            continue;
        }
        int r = -1; bool all_on_same_row{true};
        for(int i = 1;i<mvp.size();i++){
            if(mvp[i][1]==mvp[0][1]) continue;
            if(r==-1) r = mvp[i][0];
            if(r!=mvp[i][0]) all_on_same_row = false;
        }
        if(all_on_same_row){
            cout<<mv-1<<'\n';
            continue;
        }
        cout<<mv<<'\n';
    }

    return 0;
}