#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

class Sol{ public:
    vector<int> nex;
    vector<vector<int>> rg;
    vector<bool> marked;
    vector<int> dfs_vals;
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
        dfs_vals[curr]=counter;
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
        dfs_vals[curr]=counter;
        component[curr]=comp_val;
        nearestCycleNode[curr]=nearestCycleNode[prev];
        for(auto i: rg[curr]){
            rev_dfs(i, curr, counter-1, comp_val);
        }
    }
};

// void do_rev_dfs(int curr, int prev,
//     vector<vector<int>> &rg, 
//     vector<int> &component, int component_val,
//     int counter, vector<int> &dfs_val,
//     vector<int> &nearestCycle,
//     vector<bool> &marked){
//         if(marked[curr]) return;
//         marked[curr]=1;
//         component[curr]=component_val;
//         dfs_val[curr]=counter;
//         nearestCycle[curr]=nearestCycle[prev];
//         for(auto i: rg[curr])
//             do_rev_dfs(i, curr, rg,component, component_val, counter-1,dfs_val,nearestCycle,marked);
        
// }

// void dfs(int curr, int prev,
//     vector<int> &next, vector<vector<int>> &rg, 
//     vector<int> &component, int component_val,
//     vector<bool> &marked,  
//     vector<bool> &isInCycle, vector<int> &nearestCycle,
//     int counter, vector<int> &dfs_val, 
//     vector<int> &cycle_size){
//         if(marked[curr]){
//             // cycle detected
//             isInCycle[curr]=1;
//             int x = prev;
//             int cs{1};
//             while(x!=curr){
//                 isInCycle[x]=1;
//                 for(auto i: rg[x]){
//                     if(marked[i]){x=i; break;}
//                 };
//                 cs++;
//             }
//             cycle_size[curr]=cs;
//             nearestCycle[curr]=curr;
//             return;
//         }
//         marked[curr]=1;
//         dfs_val[curr]=counter;
//         component[curr]=component_val;
//         // dfs(next[curr], curr, next, rg, component, component_val, marked, counter+1, dfs_val);
//         dfs(next[curr], curr, next, rg, component, component_val, marked, isInCycle, nearestCycle, counter+1, dfs_val, cycle_size);

//         if(isInCycle[curr]) nearestCycle[curr]=curr;
//         else nearestCycle[curr]=nearestCycle[next[curr]];
        
//         cycle_size[curr] = cycle_size[next[curr]];

//         for(auto i: rg[curr]){
//             do_rev_dfs(i, curr, rg, component, component_val,counter-1,dfs_val, nearestCycle, marked);
//         }
//     }

signed main(){
    int n, q; cin>>n>>q;
    Sol S;
    S.nex.resize(n+1, 0);
    S.rg.resize(n+1);
    S.marked.resize(n+1, false);
    S.dfs_vals.resize(n+1, 0);
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
    while(q--){
        int a, b; cin>>a>>b;
        if(S.component[a]!=S.component[b]){
            cout<<-1<<'\n'; continue;
        }
        if(S.isInCycle[a] && S.isInCycle[b]){
            cout<<(S.dfs_vals[b]-S.dfs_vals[a]+S.cycleSize[a])%S.cycleSize[a]<<'\n';
        }else if(S.isInCycle[a]){
            cout<<"-1\n";
        }else if(S.isInCycle[b]){
            int a1 = S.nearestCycleNode[a];
            int ans = S.dfs_vals[a1]-S.dfs_vals[a];
            ans+=(S.dfs_vals[b]-S.dfs_vals[a1]+S.cycleSize[a1])%S.cycleSize[a1];
            cout<<ans<<'\n';
        }else{
            int a1 = S.nearestCycleNode[a];
            int b1 = S.nearestCycleNode[b];
            if(a1!=b1){
                cout<<"-1\n";
            }else{
                int ans = S.dfs_vals[b]-S.dfs_vals[a];
                if(ans>0) cout<<ans<<'\n';
                else if(a==b) cout<<0<<'\n';
                else cout<<"-1\n";
            }
        }
    }
    // vector<int> next(n+1, 0);
    // vector<vector<int>> rg(n+1);
    // for(int i = 1;i<=n;i++){
    //     int p; cin>>p;
    //     next[i]=p;
    //     rg[p].push_back(i);
    // }
    // vector<bool> marked(n+1, false), isInCycle(n+1, false);
    // vector<int> component(n+1, 0);
    // vector<int> nearestCycle(n+1, 0), dfs_vals(n+1, 0);
    // vector<int> cycle_size(n+1, 0);
    // for(int i = 1;i<=n;i++){
    //     if(marked[i]) continue;
    //     dfs(i, -1, next, rg, component, i, marked, isInCycle,nearestCycle, 0, dfs_vals, cycle_size);
    // }
    // while(q--){
    //     int a, b; cin>>a>>b;
    //     if(component[a]!=component[b]){
    //         cout<<-1<<'\n'; continue;
    //     }
    //     if(isInCycle[a] && isInCycle[b]){
    //         cout<<(dfs_vals[b]-dfs_vals[a]+cycle_size[a])%cycle_size[a]<<'\n';
    //     }else if(isInCycle[a]){
    //         cout<<"-1\n";
    //     }else if(isInCycle[b]){
    //         int a1 = nearestCycle[a];
    //         int ans = dfs_vals[a1]-dfs_vals[a];
    //         ans+=(dfs_vals[b]-dfs_vals[a1]+cycle_size[a1])%cycle_size[a1];
    //         cout<<ans<<'\n';
    //     }else{
    //         int a1 = nearestCycle[a];
    //         int b1 = nearestCycle[b];
    //         if(a1!=b1){
    //             cout<<"-1\n";
    //         }else{
    //             int ans = dfs_vals[b]-dfs_vals[a];
    //             if(ans>0) cout<<ans<<'\n';
    //             else if(a==b) cout<<0<<'\n';
    //             else cout<<"-1\n";
    //         }
    //     }
    // }

    return 0;
}