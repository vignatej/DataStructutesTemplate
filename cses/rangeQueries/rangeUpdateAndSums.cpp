#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class lazy_seg_tree{ public:
    VVI arr; int n;
    lazy_seg_tree(VI &v){
        int vs = v.size();
        n = 1; while(n<vs) n=n<<1;
        arr.resize(2*n, {0,0,LLONG_MAX});
        for(int i = 0;i<vs;i++) arr[i+n][0]=v[i];
        for(int i = n-1;i>=0;i--) arr[i][0]=arr[2*i][0]+arr[2*i+1][0];
    }
    int get_common_elements(int a, int b, int x, int y){
        int tce{0};
        if(x<=a && a<=y && y<=b) return tce = (y-a);
        if(x<=a && a<=b && b<=y) return tce = (b-a);
        if(a<=x && x<=y && y<=b) return tce = (y-x);
        if(a<=x && x<=b && b<=y) return tce = (b-x);
        return tce;
    }
    int calc_sum(int a, int b, int k, int x, int y){
        if(b<x || y<a) return 0;
        int te = y-x+1;
        if(a<=x && y<=b){
            if(arr[k][2]!=LLONG_MAX) return arr[k][2]*te+arr[k][1]*te;
            return arr[k][0]+arr[k][1]*te; 
        }
        int tce = get_common_elements(a, b, x, y);
        if(arr[k][2]!=LLONG_MAX){
            return tce*arr[k][2];
        }
        int m = (y+x)/2;
        int a1 = calc_sum(a, b, 2*k, x, m);
        int b1 = calc_sum(a, b, 2*k+1, m+1, y);
        return a1+b1+arr[k][1]*tce;
    }
    int get_sum(int a, int b){
        return calc_sum(a, b, 1, 0, n-1);
    }
    void inc_range(int a, int b, int k, int x, int y, int inc, bool up_set){
        if(b<x || y<a) return;
        if(arr[k][2]!=LLONG_MAX) up_set=1;
        if(a<=x && y<=b){
            if(up_set) arr[k][1]=inc;
            else arr[k][1]+=inc;
            return;
        }
        int m = (x+y)/2;
        inc_range(a, b, 2*k, x, m, inc, up_set);
        inc_range(a, b, 2*k+1, m+1, y, inc, up_set);
    }
};

signed main(){
    int n, q; cin>>n>>q;
    VI v(n); for(int i =0;i<n;i++) cin>>v[i];
    lazy_seg_tree lst(v);
    cout<<lst.get_sum(0,1)<<'\n';
    cout<<lst.get_sum(0,5)<<'\n';
    cout<<lst.get_sum(3,6)<<'\n';
    return 0;
}