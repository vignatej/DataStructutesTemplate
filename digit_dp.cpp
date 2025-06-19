// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int dp[100][100][20][2];

// int solve(string &num, int cn, int pos, bool equ, int cns, int k) {
//     if(k>=100) return 0;
//     int n = num.size();
//     if (pos == n) {
//         return (cn % k == 0 && cns % k == 0);
//     }

//     if (dp[cn][cns][pos][equ] != -1) return dp[cn][cns][pos][equ];

//     int ans = 0;
//     int limit = equ ? (num[pos] - '0') : 9;

//     for (int i = 0; i <= limit; i++) {
//         bool next_equ = equ && (i == (num[pos] - '0'));
//         ans += solve(num, (cn * 10 + i) % k, pos + 1, next_equ, (cns + i) % k, k);
//     }

//     return dp[cn][cns][pos][equ] = ans;
// }

// int32_t main() {
//     int T;
//     cin >> T;
//     for (int tc = 1; tc <= T; ++tc) {
//         int a, b, k;
//         cin >> a >> b >> k;

//         if (k >= 100) {
//             cout << "Case " << tc << ": 0\n";
//             continue;
//         }

//         string as = to_string(a - 1);
//         string bs = to_string(b);

//         memset(dp, -1, sizeof(dp));
//         int hi = solve(bs, 0, 0, 1, 0, k);
//         memset(dp, -1, sizeof(dp));
//         int lo = solve(as, 0, 0, 1, 0, k);
//         cout << "Case " << tc << ": " << (hi - lo) << "\n";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int lids(string number, int pos, bool tight, int lm, int ml, int &mml){
    int n = number.size();
    mml = max(mml, ml);
    if(pos==n){
        return 1;
    }
    int ans{0};
    for(int i = lm+1;i<=9 && (tight ? i<=(number[pos]-'0'):1);i++){
        ans += lids(number, pos+1, (tight ? (i==number[pos]-'0') : false), i, ml+1, mml);
    }
    return ans;
}

signed main(){
    int t; cin>>t;
    int ct{1};
    while(ct<=t){
        int a, b; cin>>a>>b;
        string a_s = to_string(a-1);
        string bs = to_string(b);
        int mml = 0;
        int ans = lids(bs, 0, 1, -1, 0, mml);
        ans -= lids(a_s, 0, 1, -1, 0, mml);
        cout<<"Case "<<ct<<": "<<ans<<' '<<mml<<'\n';
    }

    return 0;
}
