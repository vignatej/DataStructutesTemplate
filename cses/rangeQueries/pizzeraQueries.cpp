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
        int sz = v.size();
        int nn = 1;
        while(nn < sz) nn <<= 1;
        n = nn;
        arr.resize(2 * nn, INT_MAX);
        for(int i = 0; i < sz; i++) arr[i + nn] = v[i];
        for(int i = nn - 1; i > 0; i--) arr[i] = min(arr[2 * i], arr[2 * i + 1]);
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


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, q; cin>>n>>q;
    VI v(n), v1(n), v2(n); 
    for(int i =0;i<n;i++){
        int a; cin>>a;
        v[i]=a; v1[i]=a-i; v2[i]=a+i;
    }
    SegmentTree s1(v1), s2(v2);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int posn, x; cin>>posn>>x;
            s1.cng_val(posn-1, x-posn+1);
            s2.cng_val(posn-1, x+posn-1);
        }else{
            int k; cin>>k;
            int a1{INT_MAX}, a2{INT_MAX};
            if(k!=1) a1 = s1.calc_min(0, k-2);
            if(k!=n) a2 = s2.calc_min(k-1, n-1);
            cout<<min(a1+k-1, a2-k+1)<<'\n';
        }
    }

    
    return 0;
}