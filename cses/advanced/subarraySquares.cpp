#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int eval(vector<int> &l, int x){
    return l[0]*x+l[1];
}

void add_line(
    vector<int> cl, int idx, int l, int r,
    vector<vector<int>> &lines
){
    // if(lines[idx]==vector<long double>{-1, -1}){
    if(lines[idx][0]==-1 && lines[idx][1]==-1){
        lines[idx]=cl;
        return;
    }
    int m = (l+r)/2;
    bool mbv = eval(cl, m) < eval(lines[idx], m);
    bool lbv = eval(cl, l) < eval(lines[idx], l);
    if(mbv) swap(lines[idx], cl);
    if(l==r) return;
    if(lbv != mbv) add_line(cl, idx*2, l, m, lines);
    else add_line(cl, idx*2+1, m+1, r, lines);
}

int query(vector<vector<int>> &lines, int x, int idx, int l, int r){
    // if(lines[idx]==vector<long double> {-1, -1}){
    if(lines[idx][0]==-1 && lines[idx][1]==-1){
        return 1e18;
    }
    int res = eval(lines[idx], x);
    if(l==r) return res;
    int m = (l+r)/2;
    if(x<=m) return min(res, query(lines, x, idx*2, l, m));
    else return min(res, query(lines, x, idx*2+1, m+1, r));
}

int do_it(int i, int j, vector<int> &v, vector<int> &ps){
    if(i<j) return 1e16;
    if(i==j){
        return ps[i+1]*ps[i+1];
    }

}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, x; cin>>n>>x;
    vector<int> v(n+1), ps(n+1);
    for(int i = 1;i<=n;i++) cin>>v[i];
    for(int i = 1;i<=n;i++) ps[i]=ps[i-1]+v[i];
    int maxV{0};
    for(int i = 1;i<=n;i++) maxV = max(maxV, v[i]);
    for(int j = 1;j<=x;j++){

        vector<vector<int>> lines;    
        vector<vector<int>> st(4*maxV+10, {-1, -1});
        

    }

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define LL long long
// #define int LL
// #define VVI vector<vector<int>>
// #define VI vector<int>
// #define PB push_back

// // int solve(int i, int k, int cs, vector<int> &v){
// //     int n = v.size();
// //     if(i==n){
// //         if(cs==0 && k==0) return 0;
// //         return 1e16;
// //     }
// //     if(k<=0) return 1e16;
// //     cs+=v[i];
// //     int ans = solve(i+1, k, cs, v);
// //     ans=min(ans, solve(i+1, k-1, 0, v)+cs*cs);
// //     return ans;
// // }

// int solve(int i, int j, vector<int> &v, vector<vector<int>> &dp, vector<int> &ps){
//     if(j>i) return 1e16;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(j==1){
//         // int cs{0};
//         // while(i>0){cs+=v[i]; i--;}
//         return dp[i][j]=pow(ps[i+1]-ps[1], 2);
//     }
//     if(i==1 && j==1) return v[1]*v[1];
//     if(i==j){ 
//         int ans = v[j]*v[j] + solve(i-1, j-1, v, dp, ps);
//         return dp[i][j]=ans;
//     }
//     int ans = 1e16;
//     int cs = 0;
//     for(int u = 1;i-u>=j-1;i--){
//         cs+=v[i-u+1];
//         ans=min(ans, solve(i-u, j-1, v, dp, ps) + cs*cs);
//     }
//     return dp[i][j]=ans;
// }

// signed main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("in.txt", "r", stdin);
//         freopen("out.txt", "w", stdout);
//     #endif
//     int n, k; cin>>n>>k;
//     // vector<int> v(n); for(int i = 1;i<n;i++) cin>>v[i];
//     // int ans = solve(0, k, 0, v);
//     // cout<<ans;
//     // return 0;
//     vector<int> v(n+1, 0), ps(n+2, 0); 
//     for(int i = 1;i<=n;i++) cin>>v[i]; 
//     for(int i = 1;i<=n;i++) ps[i+1]=ps[i]+v[i];
//     vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
//     cout<<solve(n, k, v, dp, ps);   

// }