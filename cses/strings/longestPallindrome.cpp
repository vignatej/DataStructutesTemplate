#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;

bool pallin(int n, vector<ll> &fh, vector<ll> &bh, vector<ll> &ppow, int i, int x){
    ll f_hv = (fh[i+x+1]+M-fh[i-x])%M;
    ll b_hv = (bh[n-i+x] + M - bh[n-i-1-x])%M;
    f_hv = (f_hv*ppow[n-i+x-1])%M;
    b_hv = (b_hv*ppow[i+x])%M;
    return f_hv==b_hv;
}
bool pallin2(int n, vector<ll> &fh, vector<ll> &bh, vector<ll> &ppow, int i, int x){
    ll f_hv = (fh[i+x+1]+M-fh[i-x+1])%M;
    ll b_hv = (bh[n-i+x-1] + M - bh[n-i-1-x])%M;
    f_hv = (f_hv*ppow[n-i+x-1])%M;
    b_hv = (b_hv*ppow[i+x+1])%M;
    return f_hv==b_hv;
}

signed main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    string s; cin>>s;
    string r{s}; reverse(r.begin(), r.end()); 
    int n = s.length();
    vector<ll> ppow(n+1, 1);
    int p = 31;
    for(int i = 1;i<=n;i++) ppow[i]=(ppow[i-1]*p)%M;
    vector<ll> fh(n+1, 0);
    vector<ll> bh(n+1, 0);
    for(int i = 0;i<n;i++){
        fh[i+1] = (fh[i]+((s[i]-'a'+1)*ppow[i])%M)%M;
        bh[i+1] = (bh[i]+((r[i]-'a'+1)*ppow[i])%M)%M;
    }
    int ans_l{0}, ans_si{-1}, ans_ei{-1};
    for(int i = 0;i<n;i++){
        int s{0}, e{min(i, n-i-1)};
        while(s<=e){
            int m = (s+e)/2;
            if(pallin(n, fh, bh, ppow, i, m)){
                if(2*m+1>ans_l){
                    ans_l = 2*m+1;
                    ans_si = i-m;
                }
                s=m+1;
            }else{
                e=m-1;
            }
        }
    }
    for(int i = 0;i<n-1;i++){
        int s{1}, e{min(i+1, n-i-1)};
        while(s<=e){
            int m = (s+e)/2;
            if(pallin2(n, fh, bh, ppow, i, m)){
                if(ans_l<2*m){
                    ans_l = 2*m;
                    ans_si = i-m+1;
                }
                s=m+1;
            }else{
                e=m-1;
            }

        }
    }
    cout<<s.substr(ans_si, ans_l);

    return 0;
}