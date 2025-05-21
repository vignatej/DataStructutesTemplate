#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class SegmentTree{ public:
    VI arr; int n;
    SegmentTree(VI &v){
        int n = v.size();
        int nn = 1;
        while(nn<n) nn=nn<<1;
        this->n=nn;
        arr.resize(2*nn, 0);
        for(int i = 0;i<n;i++) arr[i+nn]=v[i];
        for(int i = nn-1;i>0;i--) arr[i]=min(arr[2*i],arr[2*i+1]);
    }
    int calc_sum(int a, int b){
        a+=n; b+=n;
        int ans = arr[a];
        while(a<=b){
            if(a%2==1){ans=min(ans, arr[a]); a++;}
            if(b%2==0){ans=min(ans, arr[b]); b--;}
            a/=2; b/=2;
        }
        return ans;
    }
    void cng_val(int p, int val){
        p+=n; arr[p]=val; p/=2;
        while(p>0){
            arr[p]=min(arr[2*p], arr[2*p+1]);
            p/=2;
        }
    }
};

signed main(){
    int n, q; cin>>n>>q;
    VI v(n, 0);
    for(int i = 0;i<n;i++) cin>>v[i];
    SegmentTree s(v);
    while(q--){
        int t, a, b; cin>>t>>a>>b;
        if(t==2) cout<<s.calc_sum(a-1, b-1)<<'\n';
        if(t==1) s.cng_val(a-1, b);
    }
    return 0;
}