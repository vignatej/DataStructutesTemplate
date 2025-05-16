#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    int max_t_n{INT_MIN}, best{INT_MIN};
    for(int i= 0;i<n;i++){
        int c; cin>>c;
        max_t_n = max(c, max_t_n+c);
        best = max(best, max_t_n);
    }
    cout<<best;
    return 0;
}