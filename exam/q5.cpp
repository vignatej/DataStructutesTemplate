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
        int n, m; cin>>n>>m;
        vector<char> v(n);
        for(int i = 0;i<n;i++){
            cin>>v[i];
        }
        map<string, set<int>> ma;
        for(int i=0;i<m;i++){
            char l1, l2; cin>>l1>>l2;
            string s; s+=l1; s+=l2;
            ma[s].insert(i);
        }
        for(int i=0;i<n;i++){
            char curr=v[i];
            if(curr=='a') continue;
            else if(curr=='b'){
                if(ma["ba"].size()){
                    v[i]='a';
                    ma["ba"].erase(ma["ba"].begin());
                    continue;
                }
                if(ma["bc"].size()==0) continue;
                int p1 = *ma["bc"].begin();
                auto it = ma["ca"].upper_bound(p1);
                if(it==ma["ca"].end()) continue;
                ma["ca"].erase(it);
                ma["bc"].erase(ma["bc"].begin());
                v[i]='a';
            }else{
                if(ma["ca"].size()>0){
                    ma["ca"].erase(ma["ca"].begin());
                    v[i]='a';
                    continue;
                }
                if(ma["cb"].size()==0) continue;
                int p = *ma["cb"].begin();
                ma["cb"].erase(ma["cb"].begin());
                v[i]='b';
                auto it = ma["ba"].upper_bound(p);
                if(it==ma["ba"].end()) continue;
                ma["ba"].erase(it);
                v[i]='a';
            }
        }
        for(auto i: v) cout<<i;
        cout<<'\n';
    }

    return 0;
}