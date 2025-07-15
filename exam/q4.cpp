#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int poss(int x, vector<int> &posns, int m){
    int i = 0; int n = posns.size();
    int prev = posns[0]-1;
    for(auto i: posns){
        if(prev<i){
            prev = i+x;
            m--;
        }
    }
    if(m<0) return -1;
    int ans{0};
    for(int i = 0;i<n;){
        auto it = upper_bound(next(posns.begin(), i), posns.end(), posns[i]+x);
        it--;
        ans+=(*it)-posns[i];
        i=distance(posns.begin(), it)+1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    vector<int> posns(n);
    for(int i = 0;i<n;i++) cin>>posns[i];
    sort(posns.begin(), posns.end());
    int l{0},r{(int)1e18};
    int ans{r};
    while(l<=r){
        int mid = (l+r)/2;
        int cans = poss(mid, posns, m);
        if(cans!=-1){
            r=mid-1;
            ans = min(ans, cans);
        }else{
            l=mid+1;
        }
    }
    cout<<ans;

    return 0;
}