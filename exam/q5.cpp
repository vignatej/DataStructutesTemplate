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
        int n, k, x; cin>>n>>k>>x;
        vector<int> v(n); for(auto &i: v) cin>>i;
        set<int> vs; for(auto i: v) vs.insert(i);
        sort(v.begin(), v.end());
        priority_queue<pair<int, int>> pq;
        set<int> plotted;
        if(v[0]!=0) pq.push({v[0], 0});
        if(v[n-1]!=x) pq.push({x-v[n-1], x});
        for(int i = 1;i<n;i++){
            int a = v[i-1]; int b = v[i];
            if(b-a<=1) continue;
            pq.push({(b-a)/2, (a+b)/2});
            if((b-a)%2==1)pq.push({(b-a)/2, 1LL+(a+b)/2});
        }
        while(plotted.size()<k && pq.size()){
            auto a = pq.top(); pq.pop();
            int dff=a.first; int p = a.second;
            if(plotted.count(p)) continue;
            plotted.insert(p);
            if(p-1>=0 && plotted.count(p-1)==0){
                // skipping edge case - check ra vigna
                auto it = vs.upper_bound(p-1); it--;
                int val = *it;
                pq.push({p-1-val, p-1});
            }
            if(p+1<=x && plotted.count(p+1)==0){
                auto it = vs.lower_bound(p+1);
                int val = *it;
                pq.push({val-p-1, p+1});
            }
        }
        int ce = 0;
        while(plotted.size()<k){
            plotted.insert(ce);
            ce++;
        }
        for(auto i: plotted) cout<<i<<' ';
        cout<<'\n';
    }

    return 0;
}