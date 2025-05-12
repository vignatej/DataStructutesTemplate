#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    int n, m, q; cin>>n>>m>>q;
    vector<vector<int>> wts(n, vector<int>(n, 1e16));
    for(int i = 0;i<m;i++){
        int a, b, w; cin>>a>>b>>w;
        a--; b--;
        wts[a][b]=min(w, wts[a][b]); 
        wts[b][a]=min(w, wts[b][a]);
    }
    for(int i = 0;i<n;i++) wts[i][i]=0;
    for(int k = 0;k<n;k++) for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++){
        wts[i][j]=min(wts[i][j], wts[i][k]+wts[k][j]);
    }
    while(q--){
        int a, b; cin>>a>>b; a--; b--;
        if(wts[a][b]==1e16) cout<<-1<<'\n';
        else cout<<wts[a][b]<<'\n';
    }
    return 0;
}