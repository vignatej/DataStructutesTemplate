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
        vector<int> st; vector<int> sl(n);
        for(int i = n-1;i>=0;i--){
            while(st.size() && v[st.back()]>v[i]){
                auto t = st.back(); st.pop_back();
                sl[t] = t-i-1;
            }
            st.push_back(i);
        }
        for(auto i: st) sl[i]=i;
        int me = *max_element(sl.begin(), sl.end());
        int mep = 0; for(int i = 0;i<n;i++) if(sl[i]==me) mep=i;
        v[mep]--;
        vector<int> bd(n, 0), bs(n, 0);
        bs[n-1]=v[n-1];
        for(int i = n-2;i>=0;i--){
            bs[i]=min(bs[i+1], v[i]);
            bd[i]=v[i]-bs[i];
        }
        int ans{0};
        for(auto i: bd) ans+=i; 
        cout<<ans<<'\n';

    }

    return 0;
}