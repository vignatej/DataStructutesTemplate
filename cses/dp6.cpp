#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n; cin>>n; vector<vector<char>> grid(n, vector<char> (n));
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++){
        char c; cin>>c; grid[i][j]=c;
    }
    ll mod = 1e9+7;
    vector<vector<ll>> p(n, vector<ll> (n, 0));
    for(int i = 0;i<n;i++) if(grid[i][0]=='*') break; else p[i][0]=1;
    for(int i = 0;i<n;i++) if(grid[0][i]=='*') break; else p[0][i]=1;
    for(int i = 1;i<n;i++) for(int j = 1;j<n;j++){
        if(grid[i][j]=='*') continue;
        p[i][j]=p[i-1][j]+p[i][j-1];
        p[i][j]%=mod;
    }
    cout<<p[n-1][n-1];
}