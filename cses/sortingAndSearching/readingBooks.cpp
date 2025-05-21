#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VI v(n);
    for(int i =0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    int av{0}, bv{0};
    int i = 0; int j =n-1;
    while(i<j){
        if(av<bv){
            av+=v[i];
            i++;
        }else{
            bv+=v[j];
            j--;
        }
    }
    if(bv<av) swap(av, bv);
    if(av+v[i]<=bv) cout<<2*bv;
    else if(av+v[i]<=bv+av) cout<<av+bv+v[i];
    else cout<<max(av+v[i]+bv, av+v[i]*2);

    return 0;
}