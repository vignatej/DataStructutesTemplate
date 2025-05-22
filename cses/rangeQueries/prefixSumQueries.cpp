#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int MAX_v = 1e16;
class SegmentTree{ public:
    VVI arr; int n;
    SegmentTree(VI &v){
        int n = v.size();
        int nn=1;
        while(nn<n) nn=nn<<1;
        this->n =nn;
        arr.resize(2*nn, {LLONG_MIN, 0});
        for(int i = 0;i<n;i++) arr[i+nn][0]=v[i];
        for(int i =nn-1;i>=1;i--) arr[i][0]=max(arr[2*i][0], arr[2*i+1][0]);
    }
    int calc_max_val(int a, int b, int k, int x, int y){
        if(b<x || y<a) return LLONG_MIN;
        if(a<=x && y<=b) return arr[k][0]+arr[k][1];
        int d = (x+y)/2;
        int fv = calc_max_val(a, b, 2*k, x, d);
        int sv = calc_max_val(a, b, 2*k+1, d+1, y);
        return max(fv, sv)+arr[k][1];
    }
    void update_range(int a, int b, int k, int x, int y, int inc){
        if(b<x || y<a) return;
        if(a<=x && y<=b){arr[k][1]+=inc; return;}
        int d = (x+y)/2;
        update_range(a, b, 2*k, x, d, inc);
        update_range(a, b, 2*k+1, d+1, y, inc);
        arr[k][0]=max(arr[2*k][0]+arr[2*k][1],arr[2*k+1][0]+arr[2*k+1][1]);
    }
    int max_val(int a, int b){
        return calc_max_val(a, b, 1, 0, n-1);
    }
    void update(int a, int inc){ // only for updating from start to last
        update_range(a, n-1, 1, 0, n-1, inc);
    }
};

signed main(){
    int n, q; cin>>n>>q;
    VI v(n), ps(n+1, 0);
    for(int i =0;i<n;i++){
        cin>>v[i];
        ps[i+1]=ps[i]+v[i];
    }
    SegmentTree s(ps);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int p, val; cin>>p>>val;
            int inc = val-v[p-1];
            v[p-1]=val;
            // s.update_range(p, n, 1, 0, n, inc);
            s.update(p, inc);
        }else{
            int a, b; cin>>a>>b;
            // int os = s.calc_max_val(a, b, 1, 0, n);
            // int ss = s.calc_max_val(a-1, a-1, 1, 0,n);
            int os = s.max_val(a, b);
            int ss = s.max_val(a-1, a-1);
            cout<<max(1ll*0, os-ss)<<'\n';
        }
    }

    return 0;
}