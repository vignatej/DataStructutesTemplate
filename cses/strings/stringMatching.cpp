#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;
int calc(string &s, string &patt){
    int ss = s.length(); int ps = patt.length();
    if(ps>ss) return 0;
    vector<ll> ppow(ss+1, 1);
    ll p = 37;
    for(int i = 1;i<=ss;i++) ppow[i]=(ppow[i-1]*p)%M;
    ll p_hv{0};
    for(int i = 0;i<ps;i++){
        ll chv = (patt[i]-'a'+1)*ppow[i]; chv%=M;
        p_hv+=chv;
        p_hv%=M;
    }
    vector<ll> s_hv(ss+1, 0);
    for(int i = 0;i<ss;i++){
        s_hv[i+1] = (s_hv[i]+((s[i]-'a'+1)*ppow[i])%M)%M;
    }
    ll ans{0};
    for(int i = 0;i<=ss-ps;i++){
        ll hv = (s_hv[i+ps]+M-s_hv[i])%M;
        if(hv == p_hv) ans++;
        p_hv*=p;
        p_hv%=M;
    }
    return ans;
}

int calc_z_function(string s, string p){
    int ss = s.length(); int ps = p.length();
    string e = p+'$'+s;
    int es = e.length();
    vector<int> z(es, 0);
    int l{0}, r{0};
    for(int i = 1;i<es;i++){
        if(i<r) z[i]=min(r-i,z[i-l]);
        while(i+z[i]<es && e[z[i]]==e[i+z[i]]) z[i]++;
        if(i+z[i]>r){
            l=i;
            r=z[i];
        }
    }
    int ans{0};
    for(auto &i: z) if(i==ps) ans++;
    return ans;
}

signed main(){
    string s, p; cin>>s>>p;
    // cout<<calc(s, p);
    cout<<calc_z_function(s, p);
    return 0;
}