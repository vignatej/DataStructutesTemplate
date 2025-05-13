#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

void dfs1(int c, VI &s, VVI &g, vector<bool> &comp){
    if(comp[c]) return;
    comp[c]=1;
    for(auto i: g[c]) dfs1(i, s, g, comp);
    s.PB(c);
}
void dfs2(int c, VVI &g, vector<bool> &mark, 
    VI & component, int cc){
    if(mark[c]) return;
    mark[c]=1;
    component[c]=cc;
    for(auto i: g[c]) dfs2(i, g, mark, component, cc);
}

bool dfs(int curr, int target, 
    vector<vector<vector<int>>> &g, 
    vector<bool> &edge_avail, vector<int> &cp, bool start){
        if(!start && curr==target){
            return true;
        }
        int ans{false};
        int c{0};
        for(auto q: g[curr]){
            int nex = q[0]; int ep1=q[1]; int ep2=q[2];

            if(edge_avail[ep1]==0 || edge_avail[ep2]==0) continue;
            edge_avail[ep1]=0; edge_avail[ep2]=0;
            bool ca{false};
            c++;
            if(c==1){    
                ca = dfs(nex, target, g, edge_avail, cp, false);
            }
            else{
                ca = dfs(nex, curr, g, edge_avail, cp, false);
            }
            cp.push_back(curr);
            ans = ca;
            c++;
        }
        if(c==1) cp.push_back(curr);
        return ans;
}

signed main(){
    int n, m; cin>>n>>m;
    VVI g(n+1);
    VI deg(n+1, 0);
    VVI edges; int c=0;
    vector<vector<vector<int>>> gg(n+1); int i{0};
    for(int i = 1;i<=m;i++){
        int a, b; cin>>a>>b;
        g[a].PB(b); g[b].PB(a);

        deg[a]++;
        deg[b]++;
        edges.push_back({a, b});
        edges.push_back({b, a});
        gg[a].push_back({b, c, c+1});
        gg[b].push_back({a, c+1, c});
        c+=2;
    }
    vector<bool> visited(n+1, false);
    VI stack;
    for(int i =1;i<=n;i++) if(!visited[i])
        dfs1(i, stack, g, visited);
    for(int i =1;i<=n;i++) visited[i]=false;
    vector<int> component(n+1, 0);
    reverse(stack.begin(), stack.end());
    int cc{0};
    for(auto i: stack) 
        if(!visited[i]) dfs2(i, g, visited, component, ++cc);
    for(auto &i: edges){
        if(component[i[0]]==component[1]) continue;
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i =1;i<=n;i++){
        if(deg[i]%2==0) continue;
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    vector<bool> edge_avail((int) edges.size(), true);
    vector<int> cp;
    dfs(1, 1, gg, edge_avail, cp, true);
    reverse(cp.begin(), cp.end());
    for(auto i: cp) cout<<i<<' '; cout<<1;

    return 0;
}