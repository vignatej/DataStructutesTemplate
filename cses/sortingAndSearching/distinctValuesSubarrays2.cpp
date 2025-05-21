#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, k; cin>>n>>k;
    VI v(n);
    for(int  i =0;i<n;i++){
        cin>>v[i]; 
    }
    map<int, int> m; int ans{0};
    int i{0}, j{1}; 
    set<int> cs{v[i]}; m[v[i]]++;
    while(i<n && j<n){
        cs.insert(v[j]);
        m[v[j]]++;
        if(cs.size()>k){
            int ni = i;
            while(1){
                m[v[ni]]--;
                if(m[v[ni]]==0) break;
                ni++;
            }
            cs.erase(v[ni]);
            int ext = ((j-i)*(j-i+1))/2;
            int rem = ((j-ni-1)*(j-ni))/2;
            ans+=ext-rem;
            i=ni+1;
        }
        j++;
    }
    ans+=((j-i)*(j-i+1))/2;
    cout<<ans;

    return 0;
}