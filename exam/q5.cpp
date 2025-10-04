#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

vector<int> solve(int l, int r){
    if(l==r){
        return {l};
    }
    // int n = 1;
    // while(n<=r) n=n<<1;
    // n=n>>1;
    // n is where first bit changes;
    int n = 30;
    while(n>=0 && !(((l>>n)&1)^((r>>n)&1))) n--;

    n=((l>>n)<<n) + (1<<n);
    int le = n-l; int re = r-n+1;
    if(le==re){
        vector<int> ans;
        for(int i = r;i>=l;i--) ans.push_back(i);
        return ans;
    }else if(le<re){
        int ns = n+le;
        auto ans1 = solve(l, ns-1);
        auto ans2 = solve(ns, r);
        copy(ans2.begin(), ans2.end(), back_inserter(ans1));
        return ans1;
    }else{
        auto ans1 = solve(l, n-re-1);
        auto ans2 = solve(n-re, r);
        copy(ans2.begin(), ans2.end(), back_inserter(ans1));
        return ans1;
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int l, r; cin>>l>>r;
        auto ans = solve(l, r);
        int ansv{0}; int ce = l;
        for(auto i: ans){ansv+=i|ce;ce++;}
        cout<<ansv<<'\n';
        for(auto i: ans) cout<<i<<' ';
        cout<<'\n';
    }

    return 0;
}