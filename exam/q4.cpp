#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class SegmentTreeMin{ public:
    VI arr; int n;
    SegmentTreeMin(VI &v){
        int n = v.size();
        int nn = 1;
        while(nn<n) nn=nn<<1;
        this->n=nn;
        arr.resize(2*nn, 0);
        for(int i = 0;i<n;i++) arr[i+nn]=v[i];
        for(int i = nn-1;i>0;i--) arr[i]=min(arr[2*i],arr[2*i+1]);
    }
    int calc_min(int a, int b){
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

class SegmentTreeMax{ public:
    VI arr; int n;
    SegmentTreeMax(VI &v){
        int n = v.size();
        int nn = 1;
        while(nn<n) nn=nn<<1;
        this->n=nn;
        arr.resize(2*nn, INT_MAX);
        for(int i = 0;i<n;i++) arr[i+nn]=v[i];
        for(int i = nn-1;i>0;i--) arr[i]=max(arr[2*i],arr[2*i+1]);
    }
    int calc_max(int a, int b){
        a+=n; b+=n;
        int ans = arr[a];
        while(a<=b){
            if(a%2==1){ans=max(ans, arr[a]); a++;}
            if(b%2==0){ans=max(ans, arr[b]); b--;}
            a/=2; b/=2;
        }
        return ans;
    }
    void cng_val(int p, int val){
        p+=n; arr[p]=val; p/=2;
        while(p>0){
            arr[p]=max(arr[2*p], arr[2*p+1]);
            p/=2;
        }
    }
};

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        VI x(n), y(n); int xs{0}, ys{0};
        for(int i = 0;i<n;i++){
            int a, b; cin>>a>>b;
            x[i]=a; y[i]=b;
            xs+=a; ys+=b;
        }
        if(n==1){
            cout<<1<<'\n';
            continue;
        }
        int ans = LLONG_MAX;
        SegmentTreeMin xmin(x), ymin(y);
        SegmentTreeMax xmax(x), ymax(y);
        for(int i = 0;i<n;i++){
            int cx = x[i]; int cy = y[i];
            int xavg = (xs-cx)/(n-1);
            int yavg = (ys-cy)/(n-1);
            xmin.cng_val(i, xavg);
            xmax.cng_val(i, xavg);
            ymin.cng_val(i, yavg);
            ymax.cng_val(i, yavg);
            int cx_min = xmin.calc_min(0, n-1);
            int cx_max = xmax.calc_max(0, n-1);
            
            int cy_min = ymin.calc_min(0, n-1);
            int cy_max = ymax.calc_max(0, n-1);
            xmin.cng_val(i, cx);
            xmax.cng_val(i, cx);
            ymin.cng_val(i, cy);
            ymax.cng_val(i, cy);

            int xd = cx_max - cx_min + 1;
            int yd = cy_max - cy_min + 1;
            
            int cans = xd*yd;
            if(xd*yd<n){
                cans = min((xd+1)*yd, xd*(yd+1));
            }
            ans=min(ans, cans);
        }
        cout<<ans<<'\n';

    }

    return 0;
}