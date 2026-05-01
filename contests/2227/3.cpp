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
        vector<int> v(n); for(auto &i: v) cin>>i;
        vector<int> m6, m3, m2, ma;
        for(auto i: v){
            if(i%6==0) m6.push_back(i);
            else if(i%2==0) m2.push_back(i);
            else if(i%3==0) m3.push_back(i);
            else ma.push_back(i);
        }
        vector<int> ans;
        copy(m6.begin(), m6.end(), back_inserter(ans));
        bool t = m2.size()<m3.size();
        if(t){
            copy(m2.begin(), m2.end(), back_inserter(ans));
            copy(ma.begin(), ma.end(), back_inserter(ans));
            copy(m3.begin(), m3.end(), back_inserter(ans));    
        }else{
            copy(m3.begin(), m3.end(), back_inserter(ans));
            copy(ma.begin(), ma.end(), back_inserter(ans));
            copy(m2.begin(), m2.end(), back_inserter(ans));
        }
        for(auto i: ans) cout<<i<<' ';
        cout<<'\n';
    }
    
    return 0;
}