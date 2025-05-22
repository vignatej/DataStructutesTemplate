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
        for(int i = nn-1;i>0;i--) arr[i]=arr[2*i]+arr[2*i+1];
    }
    int calc_sum(int a, int b){
        a+=n; b+=n;
        int ans{0};
        while(a<=b){
            if(a%2==1){ans+=arr[a]; a++;}
            if(b%2==0){ans+=arr[b]; b--;}
            a/=2; b/=2;
        }
        return ans;
    }
    void cng_val(int p, int val){
        p+=n; arr[p]=val; p/=2;
        while(p>0){
            arr[p]=arr[2*p]+arr[2*p+1];
            p/=2;
        }
    }
};
signed main(){
    int n, q; cin>>n>>q;
    VI v(n), d_a(n+1, 0);
    int prev = 0;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        d_a[i]=v[i]-prev;
        prev = v[i];
    }
    SegmentTree s(d_a);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int a, b, v; cin>>a>>b>>v;
            int a_v = s.arr[s.n+a-1];
            s.cng_val(a-1, a_v+v);
            int b_v = s.arr[s.n+b];
            s.cng_val(b, b_v-v);

        }else{
            int c; cin>>c;
            cout<<s.calc_sum(0, c-1)<<'\n';
        }
    }


    return 0;
}