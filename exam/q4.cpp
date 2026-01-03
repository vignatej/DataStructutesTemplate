#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> curr;
        curr.push_back((1<<n)-1);
        curr.push_back(curr.back()-(1<<(n-1)));
        for(int i = n-2;i>=0;i--){
            int cv = (1<<i)-1;
            int bv = n-1-i;
            for(int j = 0;j<(1<<bv);j++){
                int cans = cv;
                cans |= j<<(i+1);
                curr.push_back(cans);
            }

        }
        for(auto i: curr) cout<<i<<' ';
        cout<<'\n';

    }

    return 0;
}