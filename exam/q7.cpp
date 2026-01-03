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
        vector<int> v(n), c(n);
        for(int i = 0;i<n;i++) cin>>v[i];
        for(int i = 0;i<n;i++) cin>>c[i];
        map<int, int> m;
        for(int i = 0;i<n;i++){
            if(m.size()==0){m[v[i]]=c[i]; continue;}
            auto it = m.upper_bound(v[i]);
            if(it==m.begin()){
                m[v[i]]=c[i];
            }else{
                it--;
                int val = it->second;
                m[v[i]]=val+c[i];
            }
            auto it1 = m.upper_bound(v[i]);
            auto it2 = it1;
            while(it2!=m.end()){
                if(it2->second>m[v[i]]) break;
                it2++; 
            }
            if(it1==it2) continue;
            m.erase(it1, it2);
        }
        int ans{0};
        for(auto i: c) ans+=i;
        cout<<ans-m.rbegin()->second<<'\n';
    }

    return 0;
}