#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n; cin>>n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for(int i = 0;i<n;i++){
        cin>>v[i][0]; 
        cin>>v[i][1]; 
        cin>>v[i][2];
    }

    sort(v.begin(), v.end(),[](vector<int> &v1, vector<int> &v2){
        return v1[1]<v2[1];
    });

    map<int, int> m;
    for(auto &i: v){
        int s{i[0]}, e{i[1]}, w{i[2]};
        if(m.size()==0){m[e]=w; continue;}
        auto it = m.lower_bound(s);
        int cw{w};
        if(it!=m.begin()){it--; cw+=it->second;}
        if(m.find(e)!=m.end()){
            m[e]=max(m[e], cw);
            continue;
        }
        int lv = m.rbegin()->second; 
        if(lv>cw) continue;
        m[e]=cw;
    }
    cout<<m.rbegin()->second;

    return 0;
}