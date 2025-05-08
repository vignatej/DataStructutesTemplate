#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    int n; cin>>n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    vector<int> st; 
    vector<int> ind;
    vector<int> trace(n, -1);
    for(int i = 0;i<n;i++){
        if(st.size()==0 || st.back()<v[i]){ 
            st.push_back(v[i]);
            if(ind.size()) trace[i] = ind.back(); 
            ind.push_back(i); 

            continue;
        }
        auto it = lower_bound(st.begin(), st.end(), v[i]);
        int d = distance(st.begin(), it);
        ind[d]=i;
        if(d-1>=0) trace[i] = ind[d-1];
        st[d] = v[i];
    }
    cout<<st.size()<<'\n';
    // int ci = ind.back();
    // while(ci!=-1){
    //     cout<<v[ci]<<'-'<<ci<<' ';
    //     ci = trace[ci];
    // }

    return 0;
}