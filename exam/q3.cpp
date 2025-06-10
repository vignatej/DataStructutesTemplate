#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
        int ans{1}; set<int> cs{v[0]};
        int cp = 1;
        while(cp<n){
            int j = cp;
            while(cs.size()>0 && j<n){
                if(cs.find(v[j])!=cs.end())
                    cs.erase(v[j]);
                j++;
            }
            if(cs.size()!=0) break;
            ans++;
            while(cp<j){
                cs.insert(v[cp]);
                cp++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}