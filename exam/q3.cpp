#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

vector<int> solve_once(vector<int> &v){
    int n = v.size();
    sort(v.begin(), v.end());
    map<int, int> vm; for(auto i: v) vm[i]++;
    int mex = 0;
    int i = 0;
    while(i<n){
        if(mex==v[i]) mex++;
        i++;
    }
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(v[i]>mex){ ans.push_back(mex); continue;}
        if(vm[v[i]]>1){ans.push_back(mex); continue;}
        ans.push_back(v[i]);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        vector<int> v(n); for(int i = 0;i<n;i++) cin>>v[i];
        int ct = 4; vector<int> nex = v;
        while(k && ct--){
            k--;
            nex = solve_once(nex);
        }
        if(!k){
            LL cs{0};
            for(auto i: nex) cs+=i;
            cout<<cs<<'\n';
            continue;
        }
        if(k%2==0){
            LL cs{0};
            for(auto i: nex) cs+=i;
            cout<<cs<<'\n';
            continue;
        }else{
            nex = solve_once(nex);
            LL cs{0};
            for(auto i: nex) cs+=i;
            cout<<cs<<'\n';
            continue;
        }

    }

    return 0;
}