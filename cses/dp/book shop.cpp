#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x; cin>>n>>x;
    vector<int> books(n, 0), pages(n, 0);
    for(int i = 0;i<n;i++) cin>>books[i];
    for(int i = 0;i<n;i++) cin>>pages[i];
    vector<vector<int>> dp(n, vector<int> (x+1, 0));
    for(int cc = 0;cc<=x;cc++)
        if(cc>=books[0]) dp[0][cc] = pages[0]; 
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=x;j++){
            if(j>=books[i]) dp[i][j]=pages[i]+dp[i-1][j-books[i]];
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
    }
    cout<<dp[n-1][x];
}