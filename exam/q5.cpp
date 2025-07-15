#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 998244353;

int powl(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    int hlf = powl(a, b/2);
    hlf=(hlf*hlf)%M;
    if(b%2) hlf=(hlf*a)%M;
    return hlf;
}
int calc_inv(int x, int m){
    return powl(x, m-2);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n; cin>>n;
    int ans{0};
    ans = ((((n%M)*((n+1)%M))%M)*calc_inv(2, M))%M;
    for(int i =1;i<=n;){
        int curr = floor(n/i);
        int l{i},r{n};
        int nex = l;
        while(l<=r){
            int m = (l+r)/2;
            if(floor(n/m)==curr){
                nex=max(nex, m);
                l=m+1;
            }else{
                r=m-1;
            }
        }
        ans= (ans - ((nex-i+1)*curr)%M + M)%M;
        i=nex+1;
    }
    cout<<ans%M;

    return 0;
}