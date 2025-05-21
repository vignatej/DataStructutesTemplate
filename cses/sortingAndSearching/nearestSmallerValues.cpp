#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VI v(n+1, 0), prev(n+1, 0);
    for(int i = 1;i<=n;i++) cin>>v[i];
    VI st{0};
    for(int i =1;i<=n;i++){
        while(st.size()!=0 && v[st.back()]>=v[i]) st.pop_back();
        prev[i]=st.back();
        st.push_back(i);
    }
    for(int i =1;i<=n;i++) cout<<prev[i]<<' ';
    return 0;
}