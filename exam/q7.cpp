#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int get_head(VI &head, int i){
    if(head[i]==i) return i;
    head[i]=get_head(head, head[i]);
    return head[i];
}
void unio(VI &head, VI &sizes, int a, int b){
    a = get_head(head, a); 
    b = get_head(head, b);
    if(a==b) return;
    if(sizes[a]<sizes[b]) swap(a, b);
    head[b]=a;
    sizes[a]+=sizes[b];
}

signed main(){
    int T; cin>>T;
    while(T--){
        int n, m; cin>>n>>m;
        vector<vector<int>> edges;
        for(int i = 0;i<m;i++){
            int a, b, w; cin>>a>>b>>w;
            edges.PB({a, b, w});
        }
        sort(edges.begin(), edges.end(), [](VI &a, VI &b){
            return a[2]<b[2];
        });
        VI head(n+1, 0), sizes(n+1, 1);
        for(int i = 0;i<=n;i++) head[i]=i;
        VVI mst;
        vector<vector<vector<int>>> ng(n+1);
        for(auto &i: edges){
            int a{i[0]}, b{i[1]}, w{i[2]};
            if(get_head(head, a)==get_head(head, b)) continue;
            mst.PB(i);
            unio(head, sizes, a, b);
            ng[a].PB({b, w});
            ng[b].PB({a, w});
        }

        vector<bool> comp(n+1, false);
        VI min_wts(n+1, INT_MAX), max_wts(n+1, 0);
        priority_queue<vector<int>> pq; pq.push({1, INT_MAX,0});
        while(pq.size()){
            int min_wt = pq.top()[1]; 
            int max_wt = pq.top()[2];
            int cn = pq.top()[0];
            pq.pop();
            if(comp[cn]) continue;
            min_wts[cn]=min(min_wts[cn], min_wt);
            max_wts[cn]=max(max_wts[cn], max_wt);
            comp[cn]=1;
            for(auto &i: ng[cn]){
                int nn = i[0]; int cw = i[1];
                if(comp[nn]) continue;
                pq.push({nn, min(min_wt, cw), max(max_wt, cw)});
            }
        }

        int mi = min_wts[n]; int ma = max_wts[n];
        int ans = mi+ma;
        for(int i = 2;i<=n;i++){
            int cans = min(mi, min_wts[i])+max(ma, max_wts[i]);
            ans = min(ans, cans);
        }
        cout<<ans<<'\n';
    }

    return 0;
}