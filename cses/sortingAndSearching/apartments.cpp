#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n, m, k; cin>>n>>m>>k;
    VI D(n), A(m);
    for(int i = 0;i<n;i++) cin>>D[i];
    for(int i =0;i<m;i++) cin>>A[i];
    sort(D.begin(), D.end());
    sort(A.begin(), A.end());
    int i{0}, j{0}; int ans{0};
    while(i<n && j<m){
        int d = D[i]; int a = A[j];
        if(a<d-k) j++;
        else if(d+k<a) i++;
        else{ans++; i++;j++;}
    } 
    cout<<ans<<'\n';

    return 0;
}