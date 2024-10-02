#include <bits/stdc++.h>
using namespace std;


int m;
int get_middle(int dist, int p, int n){
    if(!((dist+1<=n && dist+1+p>=n) || (dist+1>=n && dist+1-p<=n))) return 0;
    if(p<1 || p>m) return 0;
    if(dist==0) return 1;
    return get_middle(dist-1, p-1, n)+get_middle(dist-1, p, n)+get_middle(dist-1, p+1, n);
}
int beg(int cp, int pv){
    if(cp==)
}


int main(){
    int n; cin>>n>>m;
    vector<int> v(n, 0);
    for(int i = 0;i<n;i++) cin>>v[i];
    int i = 0;
    int ans = 1;
    while(i<n){
        while(i<n && v[i]!=0) i++;
        if(i==n) break;
        int j=i+1;
        while(j<n && v[j]==0) j++;
        i--;
        ans*=get_middle(j-i-1, v[i], v[j]); 
        i=j+1;
    }
    cout<<ans;

    // vector<vector<int>> dp(m+2, vector<int>(n, 0));
    // if(v[0]==0) for(int i = 1;i<=m;i++) dp[i][0]=1;
    // else dp[v[0]][0]=1;
    // for(int j = 1;j<n;j++){
    //     for(int i = 1;i<=m;i++){
    //         if(v[j]!=0){
    //             if(j!=v[j]) continue;
    //             dp[i][j]=dp[i-1][j-1]+dp[i][j-1]+dp[i+1][j-1];
    //             if(dp[i][j]==0) dp[i][j]=1;
    //         }else{
    //             dp[i][j]=dp[i-1][j-1]+dp[i][j-1]+dp[i+1][j-1];
    //         }
    //     }
    // }
    // int mv = 0;
    // for(int i = 1;i<=m;i++) mv=max(mv, dp[i][n-1]);
    // cout<<mv;
}