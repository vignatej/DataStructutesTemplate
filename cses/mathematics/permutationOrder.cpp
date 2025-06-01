#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int fact(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    return fact(n-1)*n;
}

void solve(VI &v, int i, int s, int k){
    if(s==k){
        for(auto &i: v) cout<<i<<' ';
        cout<<'\n';
        return;
    }
    int n = v.size(); int nex = s + fact(n-i-1);
    for(int curr = i;curr<n;curr++, nex+=fact(n-i-1)){
        if(k>=nex) continue;
        swap(v[i], v[curr]);
        sort(next(v.begin(), i+1), v.end());
        solve(v, i+1, nex - fact(n-i-1), k);
        break;
    }
}

signed main(){
    int T; cin>>T;
    while(T--){
        int t; cin>>t;
        if(t==1){
            int n, k; cin>>n>>k;
            VI v; for(int i = 1;i<=n;i++) v.PB(i);
            solve(v, 0, 1, k);

        }else{
            int n; cin>>n;
            VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
            int ans{0};
            for(int i = 0;i<n;i++){
                int le = 0;
                for(int j = i+1;j<n;j++) if(v[j]<v[i]) le++;
                ans+=le*(fact(n-i-1));
            }
            cout<<ans+1<<'\n';
        }
    }

    return 0;
}