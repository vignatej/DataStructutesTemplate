#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
#define PII pair<int, int>
int calc1(int n, int m, int a, int b);
map<int, int> ma;
int calc(int n, int m, int a, int b, bool f){
    if(n==1 && m==1) return 0;
    int ans = INT_MAX;
    // if(!f && ma.find((n<<32)+m)!=ma.end()) return ma[(n<<32)+m];
    // if(ma.size()>1e5) ma.clear();
    if(n!=1){
        int fir{INT_MAX}, sec{INT_MAX};
        if(n-a+1!=n) fir = 1+calc1(n-a+1, m, (n-a+2)/2, (1+m)/2);
        if(a!=n) sec = 1+calc1(a, m, (a+1)/2, (m+1)/2);
        ans = min({ans, fir, sec});
    }
    if(m!=1){
        int fir{INT_MAX}, sec{INT_MAX};
        if(m-b+1!=m) fir = 1+calc1(n, m-b+1, (n+1)/2, (m-b+2)/2);
        if(b!=m) sec = 1+calc1(n, b, (n+1)/2, (b+1)/2);
        ans=min({ans, fir, sec});
    }
    // if(!f) ma[(n<<32)+m]=ans;
    return ans;
}
int calc1(int n, int m, int a, int b){
    if(n==1 && m==1) return 0;
    if(n==1){
        int ans{0};
        while(m>1){
            m = m/2 + ((m%2)?1:0);
            ans++;
        }
        return ans;
    }
    if(m==1){
        int ans{0};
        while(n>1){
            n = n/2 + ((n%2)?1:0);
            ans++;
        }
        return ans;
    }
    int fi = a-1; int t = b-1;
    int s = n-a; int fo = m-b;
    if(fi==max({fi, s, t, fo})){
        return 1+calc1(n-a+1, m, (n-a+2)/2, (1+m)/2);
    } else if(s==max({fi, s, t, fo})){
        return 1+calc1(a, m, (a+1)/2, (m+1)/2);
    } else if(t==max({fi, s, t, fo})){
        return 1+calc1(n, m-b+1, (n+1)/2, (m-b+2)/2);
    } else{
        return 1+calc1(n, b, (n+1)/2, (b+1)/2);
    }
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n, m, a, b; cin>>n>>m>>a>>b;
        cout<<calc(n, m, a, b, true)<<'\n';


    }

    return 0;
}