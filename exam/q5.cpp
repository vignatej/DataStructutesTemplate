#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9+7;
const int N = 1e5+7;
vector<int> fact(N + 1, 1);
int binexp(int no, int power) {
    int ans = 1;
    while (power) {
        if (power & (int)1) {
            ans = (ans * no) % M;
        }
        no = (no * no) % M;
        power >>= 1;
    }
    return ans%M;
}
int ncr(int n, int r) {
    if (r < 0 || n < 0 || n < r) return 0;
    int value = (fact[r] * fact[n - r]) % M;
    int ans = (fact[n] * binexp(value, M - 2)) % M;
    return ans;
}
signed main(){
    int T; cin>>T;
    for(int i = 1;i<=N;i++) fact[i]=(fact[i-1]*i)%M;
    while(T>0){T--;
        int n, k; cin>>n>>k; vector<int> v(n);
        int r1{0}; int oz{0}; int l1{0};
        for(int i = 0;i<n;i++) {
            int a; cin>>a; v[i]=a; 
            if(a==1) r1++; else oz++;
        }
        int ans{0};
        for(int i= 0;i<n;i++){
            if(v[i]==1)r1--;
            if(v[i]==0) continue;
            int cans =ncr(oz+l1,(k/2)); cans%=M;
            cans*=ncr(r1, k/2); cans%=M;
            ans+=cans; ans%=M;
            if(v[i]==1)l1++;
        }
        cout<<ans<<'\n';
    }
}
