#include <bits/stdc++.h>
using namespace std;
#define ll long long


class Sol{ public:
    vector<int> nex;
    vector<vector<int>> rg;
    vector<bool> marked;
    vector<int> dfs_val;
    vector<int> component;
    vector<bool> isInCycle;
    vector<int> cycleSize;
    vector<int> nearestCycleNode;

    void dfs(int curr, int par, int counter, int comp_val){
        if(marked[curr]){
            // cycle detected
            isInCycle[curr]=1;
            int x = par; int c{1}; 
            while(x!=curr){
                isInCycle[x]=1;
                for(auto i: rg[x]) if(marked[i]){x=i; break;}
                c++;
            }
            cycleSize[curr]=c;
            x=par;
            while(x!=curr){
                cycleSize[x]=c;
                for(auto i: rg[x]) if(marked[i]){x=i; break;}
            }
            nearestCycleNode[curr]=curr;
            return;
        }
        marked[curr]=1;
        dfs_val[curr]=counter;
        component[curr]=comp_val;
        dfs(nex[curr], curr, counter+1, comp_val);
        if(isInCycle[curr]) nearestCycleNode[curr]=curr;
        else nearestCycleNode[curr]=nearestCycleNode[nex[curr]];
        for(auto i: rg[curr])
            rev_dfs(i, curr, counter-1, comp_val);
    }

    void rev_dfs(int curr, int prev, int counter, int comp_val){
        if(marked[curr]) return;
        marked[curr]=1;
        dfs_val[curr]=counter;
        component[curr]=comp_val;
        nearestCycleNode[curr]=nearestCycleNode[prev];
        for(auto i: rg[curr]){
            rev_dfs(i, curr, counter-1, comp_val);
        }
    }
};

signed main(){
    Sol S;
    int n; cin>>n;

    S.nex.resize(n+1, 0);
    S.rg.resize(n+1);
    S.marked.resize(n+1, false);
    S.dfs_val.resize(n+1, 0);
    S.component.resize(n+1, 0);
    S.isInCycle.resize(n+1, false);
    S.cycleSize.resize(n+1, 0);
    S.nearestCycleNode.resize(n+1, 0);
    for(int i =1;i<=n;i++){
        int par; cin>>par;
        S.nex[i]=(par);
        S.rg[par].push_back(i);
    }

    for(int i =1;i<=n;i++){
        if(S.marked[i]) continue;
        S.dfs(i, -1, 0, i);
    }
    for(int i = 1;i<=n;i++){
        int a1 = S.nearestCycleNode[i];
        int ans = (S.dfs_val[a1]-S.dfs_val[i]);
        ans+=S.cycleSize[a1];
        cout<<ans<<' ';
    }


    return 0;
}