#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, m; cin>>n>>m;
    multiset<int> ms;
    for(int i = 0;i<n;i++){
        int a; cin>>a; ms.insert(a);
    }
    for(int i = 0;i<m;i++){
        int c; cin>>c;
        auto it = ms.lower_bound(c);
        if(*it!=c){
            if(it==ms.begin()){
                cout<<"-1"<<'\n';
                continue;
            }else{
                it--;
            }
        }
        cout<<(*it)<<' ';
        ms.erase(it);
    }

    return 0;
}