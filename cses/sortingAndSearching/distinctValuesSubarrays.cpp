#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VI v(n); for(int i =0;i<n;i++) cin>>v[i];
    set<int> s{v[0]}; int l{0};
    int ans{0}; int i;
    for(i =1;i<n;i++){
        int pl = l;
        while(s.find(v[i])!=s.end()){
            s.erase(v[l]);
            l++;
        }
        if(pl!=l){
            int d = i-pl;
            ans+=(d*(d+1))/2;
            d = i-l;
            ans-=(d*(d+1))/2;
        }
        s.insert(v[i]);
    }
    int d = i-l;
    ans+=((d)*(d+1))/2;
    cout<<ans;
    return 0;
}