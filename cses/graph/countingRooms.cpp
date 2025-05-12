#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int i, int j, vector<vector<char>> &v, vector<vector<bool>> &comp){
    int n = v.size(); int m = v[0].size();
    if(!(0<=i && i<n && 0<=j && j<m)) return;
    if(v[i][j]=='#' || comp[i][j]) return;
    comp[i][j]=1;
    dfs(i+1, j, v, comp);
    dfs(i-1, j, v, comp);
    dfs(i, j-1, v, comp);
    dfs(i, j+1, v, comp);
}

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin>>v[i][j];
    vector<vector<bool>> comp(n, vector<bool>(m, false));
    int ans{0};
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++){
        if(comp[i][j] || v[i][j]=='#') continue;
        ans++;
        dfs(i, j, v, comp);
    }
    cout<<ans;

    return 0;
}