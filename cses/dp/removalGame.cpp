#include <bits/stdc++.h>
using namespace std;
#define ll long long
# define int ll

// pair<int, int> solve(vector<ll> &v, int i, int j, bool first,
//     vector<vector<pair<int, int>>> &dp1, 
//     vector<vector<pair<int, int>>> &dp2,
//     vector<vector<bool>> &comp1, 
//     vector<vector<bool>> &comp2
//     ){
//     int fs1{0}, ss1{0}, fs2{0}, ss2{0};
//     if(i>j) return {0,0};

//     if(first){
//         if(comp1[i][j]) return dp1[i][j];
//         fs1+=v[i];
//         auto a = solve(v, i+1, j, !first, dp1, dp2, comp1, comp2);
//         fs1+=a.first; ss1+=a.second;

//         fs2+=v[j];
//         a = solve(v, i, j-1, !first, dp1, dp2, comp1, comp2);
//         fs2+=a.first; ss2+=a.second;
        
//         comp1[i][j]=1;
//         if(fs1>fs2) return dp1[i][j] = {fs1, ss1};
//         else return dp1[i][j] = {fs2, ss2};
//     }else{
//         if(comp2[i][j]) return dp2[i][j];

//         ss1+=v[i];
//         auto a = solve(v, i+1, j, !first, dp1, dp2, comp1, comp2);
//         fs1+=a.first; ss1+=a.second;

//         ss2+=v[j];
//         a = solve(v, i, j-1, !first, dp1, dp2, comp1, comp2);
//         fs2+=a.first; ss2+=a.second;

//         comp2[i][j]=1;
//         if(ss1>ss2) return dp2[i][j] = {fs1, ss1};
//         return dp2[i][j] = {fs2, ss2};
//     }
// }

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    
    // vector<vector<pair<int, int>>> dp1(n, vector<pair<int, int>>(n)), 
    //                                dp2(n, vector<pair<int, int>>(n));
    // vector<vector<bool>> comp1(n, vector<bool>(n, 0)), comp2(n, vector<bool>(n, 0));
    // auto ans = solve(v, 0, n-1, true, dp1, dp2, comp1, comp2); 
    // cout<<ans.first<<'\n';

    vector<vector<pair<ll, ll>>> first(n, vector<pair<ll, ll>>(n)), 
                                 second(n, vector<pair<ll, ll>>(n));

    for(int l = 0;l<n;l++){
        for(int i = 0, j=i+l;i<n-l;i++, j++){
            if(l==0){
                first[i][j]={v[i], 0}; 
                second[i][j]={0, v[i]};
                continue;
            }
            int f1{0}, s1{0}, f2{0}, s2{0};
            f1+=v[i]; f1+=second[i+1][j].first; s1+=second[i+1][j].second;
            f2+=v[j]; f2+=second[i][j-1].first; s2+=second[i][j-1].second;
            if(f1>f2) first[i][j]={f1, s1};
            else first[i][j]={f2, s2};

            f1 = {0}, s1 = {0}, f2 = {0}, s2 = {0};
            s1+=v[i]; f1+=first[i+1][j].first; s1+=first[i+1][j].second;
            s2+=v[j]; f2+=first[i][j-1].first; s2+=first[i][j-1].second;
            if(s1>s2) second[i][j]={f1, s1};
            else second[i][j]={f2, s2};
        }
    }
    cout<<first[0][n-1].first;
    return 0;
}