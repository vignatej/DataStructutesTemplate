#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;

signed main(){
    int n; cin>>n;
    int ts = (n*(n+1))/2;
    if(ts%2!=0){cout<<0; return 0;}
    int rs{ts/2};
    vector<vector<int>> T(n, vector<int>(rs+1, 0));
    for(int i = 0;i<n;i++) T[i][0]=1;
    T[1][1]=1;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=rs;j++){
            T[i][j]=T[i-1][j];
            if(j-i>=0) T[i][j]+=T[i-1][j-i];
            T[i][j]%=M;
        }
    }
    cout<<T[n-1][rs]<<'\n';

    return 0;
}