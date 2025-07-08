#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool ispallindrome(VI &v){
    int n = v.size();
    for(int i = 0;i<n;i++){
        if(v[i]!=v[n-i-1]) return 0;
    }
    return 1;
}

bool solve(int k, map<int, VI> m){
    set<pair<int, int>> cp;
    bool nta{0}; int ntav{0};
    for(auto &i: m){
        int ol = cp.size();
        int cl = i.second.size();
        if(ol==k) break;
        if(ol+cl>k){
            // do_stg;
            nta=1; ntav=i.first;
            break;
        }
        for(auto j: i.second)
            cp.insert({j, i.first});
    }
    VI cs; VI posns;
    for(auto i: cp){ 
        cs.PB(i.second);
        posns.PB(i.first);
    }
    if(!ispallindrome(cs)) return false;
    if(!nta) return 1;
    
    int n = posns.size();
    posns.push_back(1e6);
    
    VI &ntap = m[ntav]; 
    vector<bool> comp(ntap.size(), 0);
    int mr = k - cs.size(); int j = ntap.size()-1;
    for(int i = 0;i<ntap.size() && mr>0 && j>=0;i++){
        if(comp[i]) continue;
        if(mr==1){
            //  do stg
            if(cs.size()%2) return 0;
            int cp = ntap[i];
            auto it = lower_bound(posns.begin(), posns.end(), cp);
            int d = distance(posns.begin(), it);
            if(d==cs.size()/2) mr--;
            continue;
        }
        int cp = ntap[i];
        auto it = lower_bound(posns.begin(), posns.end(), cp);
        int d = distance(posns.begin(), it);
        if(d==n) continue;
        int plb, pub;
        plb = posns[n-d-1]; 
        pub = posns[n-d];
        while(j>=0 && !(comp[j]==0 && plb<=ntap[j] && ntap[j]<=pub)) 
            j--;
        if(j<0) break;
        mr-=2;
        comp[i]=1; comp[j]=1;
    }
    return mr==0;
}

signed main(){
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
        map<int, VI> m;
        for(int i = 0;i<n;i++) m[v[i]].PB(i);
        bool ans = solve(k, m) || solve(k-1, m);
        cout<<(ans ? "YES":"NO")<<'\n';
    }

    return 0;
}