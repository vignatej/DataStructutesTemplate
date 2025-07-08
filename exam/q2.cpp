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
        double x1, y1, x2, y2; cin>>x1>>x2>>y1>>y2;
        vector<double> v(n);
        for(int i = 0;i<n;i++) cin>>v[i];
        double dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        if(n==1){
            if(dist == v[0]){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
            continue;
        }
        vector<pair<double, double>> curr{{-v[0],v[0]}};
        for(int i = 1;i<n;i++){
            decltype(curr) next;
            for(auto &j: curr) next.push_back({j.first-v[i], j.second-v[i]});
            for(auto &j: curr) next.push_back({j.first+v[i], j.second+v[i]});
            sort(next.begin(), next.end());
            curr.clear();
            double pe = 0;
            for(auto &k: next){
                double s{k.first}, e{k.second};
                if(curr.size()==0){
                    curr.PB({s, e});
                    continue;
                }
                pe = curr.back().second;
                if(pe<s){
                    curr.PB({s, e});
                }else{
                    curr.back().second=max(e, curr.back().second);
                }
            }
        }
        bool ans = 0;
        for(auto k: curr){
            double s{k.first}, e{k.second};
            if(s<=dist && dist<=e) ans=1;
        }
        cout<<(ans?"Yes":"No")<<'\n';

    }

    return 0;
}