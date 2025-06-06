#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool isp(int cb, VVI & avail){
    int n = avail.size();
    int posn = -1;
    for(int i = 0;i<n;i++){
        if(!(avail[i][0]>=cb && avail[i][1]>=cb && avail[i][2]>=cb)) continue;
        posn=i;
    }
    if(posn==-1) return false;
    VI v = avail[posn];
    avail.erase(next(avail.begin(), posn));
    sort(v.rbegin(), v.rend());
    int x{v[0]}, y{v[1]}, z{v[2]};
    int a = cb;
    avail.PB({a, a, z-a});
    avail.PB({x, y-a, z});
    avail.PB({x-a, a, z});
    return 1;
}

signed main(){
    int T; cin>>T;
    VI fibb{1,2};
    while(fibb.size()<10) 
        fibb.PB(fibb[fibb.size()-1]+fibb[fibb.size()-2]);
    while(T--){
        int n, m; cin>>n>>m;
        VI ans(m, 0);
        for(int i = 0;i<m;i++){
            int x,y,z; cin>>x>>y>>z;
            VVI avail{{x,y,z}};
            bool ya = 1;
            for(int j = n-1;j>=0 && ya;j--){
                ya = isp(fibb[j], avail);
            }
            if(ya) ans[i]=1;
        }
        for(auto &i: ans) cout<<i;
        cout<<'\n';
    }

    return 0;
}