// #include <bits/stdc++.h>
// using namespace std;
// #define LL long long
// #define int LL
// #define VVI vector<vector<int>>
// #define VI vector<int>
// #define PB push_back

// vector<vector<double>> next(vector<vector<double>> &curr, int k){
//     if(k==0) return curr;
//     VVI nex{{-1, 0},{1, 0},{0,1},{0,-1}};
//     int n = curr.size();
//     while(k>0){
//         vector<vector<double>> ofv(n, vector<double>(n, 0));
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<n;j++){
//                 VVI np;
//                 for(auto k: nex){
//                     int nx=k[0]+i; int ny = k[1]+j;
//                     if(0<=nx && nx<n && 0<=ny && ny<n) np.PB({nx, ny});
//                 }
//                 double nps = np.size();
//                 for(auto &k: np){
//                     int nx = k[0]; int ny=k[1];
//                     ofv[nx][ny]+=(curr[i][j]/(double)4);
//                 }
//             }
//         }
//         curr=ofv;
//         k--;
//     }
//     return curr;
// }

// signed main(){
//     int k; cin>>k;
//     int n = 8;
//     vector<vector<double>> v(n, vector<double>(n, 0));
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<n;j++){
//             decltype(v) curr(n, vector<double>(n, 0));
//             curr[i][j]=1;
//             curr = next(curr, k);
//             for(int a = 0;a<n;a++) for(int b = 0;b<n;b++){
//                 v[i][j]+=curr[i][j]/((double) 64.0);
//             }
//         }
//     }
//     double ans{1};
//     for(auto &i: v) for(auto &j: i) ans*=1-j;
//     cout<<ans;
//     return 0;
// }