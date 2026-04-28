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
    int n; cin>>n;
    vector<int> p(n+1, 0), c(n+1, 0), outdeg(n+1, 0);
    vector<vector<int>> g(n+1);
    vector<vector<int>> order(n+1);
    for(int i=1;i<=n;i++){
        int par, cv; cin>>par>>cv;
        p[i]=par; c[i]=cv;
        g[par].push_back(i);
        outdeg[par]++;
    }
    vector<int> zero_outdeg;

    
    vector<vector<int>> state(n+1);
    for(int i=1;i<=n;i++){
        if(g[i].size()==0) zero_outdeg.push_back(i);
        else continue;
        // state[i].push_back(i);
    }
    vector<int> curr = zero_outdeg;
    while(curr.size() && curr!=vector<int>{0}){
        vector<int> nex;
        for(auto cn: curr){
            for(auto i: g[cn]) copy(state[i].begin(), state[i].end(), back_inserter(state[cn]));
            if(c[cn]>state[cn].size()){
                cout<<"NO\n";
                return 0;
            }
            state[cn].insert(next(state[cn].begin(), c[cn]), cn);
            outdeg[p[cn]]--;
            if(outdeg[p[cn]]==0) nex.push_back(p[cn]);
        }
        curr=nex;
    }
    vector<int> colors(n+1, 0);
    for(int i = 0;i<state[g[0][0]].size();i++){
        int cv = state[g[0][0]][i];
        colors[cv]=i+1;
    }
    cout<<"YES\n";
    for(int i =1;i<=n;i++) cout<<colors[i]<<' ';


    return 0;
}