#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        vector<int> v;
        int c{0};
        for(auto &i: s){
            if(i=='('){
                v.push_back(i);
            }else{
                v.pop_back();
                if(v.size()==0) c++;
            }
        }
        cout<<(c>1 ? "YES":"NO")<<'\n';
    }

    return 0;
}