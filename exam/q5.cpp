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
    int n, m; cin>>n>>m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 1e16));
    for(int i = 0;i<m;i++){
        int a, b, c; cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b], c);
        adj[b][a]=min(adj[b][a], c);
    }
    for(int i = 1;i<=n;i++) adj[i][i]=0;
    for(int k = 1;k<=n;k++){
        for(int i =1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    int k, t; cin>>k>>t;
    vector<int> A(k); 
    for(int i = 0;i<k;i++) cin>>A[i];
    vector<int> Airport(n+1, 1e16);
    for(int i =1;i<=n;i++){
        for(auto &j: A){
            Airport[i]=min(Airport[i], adj[i][j]);
        }
    }
    int q; cin>>q;
    while(q--){
        int typ; cin>>typ;
        if(typ==1){
            int x, y, v; cin>>x>>y>>v;
            adj[x][y]=min(v, adj[x][y]); 
            adj[y][x]=min(v, adj[y][x]);
            for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++){
                adj[i][j]=min({
                    adj[i][j], 
                    adj[i][x]+v+adj[y][j], 
                    adj[i][y]+v+adj[x][j]
                });
            }
            for(int i = 1;i<=n;i++){
                for(auto &j: A){
                    Airport[i]=min(Airport[i], adj[i][j]);
                }
            }
        }else if(typ==2){
            int x; cin>>x;
            A.push_back(x);
            for(int i = 1;i<=n;i++) 
                Airport[i]=min(Airport[i], adj[i][x]);
        }else if(typ==3){
            int ans{0};
            for(int i =1;i<=n;i++) for(int j = 1;j<=n;j++){
                int cans = adj[i][j];
                cans = min(cans, Airport[i]+Airport[j]+t);
                if(cans>=1e16) continue;
                else ans+=cans;
            }
            cout<<ans<<'\n';
        }
    }


    return 0;
}