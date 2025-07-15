#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, k; cin>>n>>k;
    vector<string> v(n);
    vector<vector<bitset<3000>>> vbs(26, vector<bitset<3000>>(n));
    set<char> s;
    for(int i = 0;i<n;i++){ 
        cin>>v[i];
        for(int j = 0;j<n;j++){
            int d = v[i][j]-'A';
            vbs[d][i].set(j);
            s.insert(v[i][j]);
        } 
    }
    for(auto ch: s){
        int d = ch-'A';
        bool ya = 0;
        for(int i = 0;i<n && !ya;i++){
            if(vbs[d][i].count()<=1) continue;
            for(int j = i+1;j<n;j++){
                if(vbs[d][j].count()<=1) continue;
                if((vbs[d][i]&vbs[d][j]).count()>1){
                    ya = 1;
                    break;
                }
            }
        }
        cout<<(ya ? "YES\n":"NO\n");
    }
    for(int i = s.size();i<k;i++) cout<<"NO\n";
    
    return 0;
}