#include <bits/stdc++.h>
using namespace std;


int solve(int oc, bool l, bool r){
    // if(oc==0) return 0;
    // if(l && r){
    //     if(oc<=2) return 0;
    //     return (oc-1)/2;
    // }
    // if(l || r){
    //     if(oc==1) return 1;
    //     if(oc<=4) return 1;
    //     return (oc-1)/2;
    // }
    // if(oc==1) return 1;
    // return oc/2;
    if(l) oc--;
    if(r) oc--;
    if(oc<=0) return 0;
    return oc/3 + ((oc%3)?1:0);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<char> v(n); for(auto &i: v) cin>>i;
        int ans{0};
        int pi = 0;
        for(pi = 0;pi<n;pi++) if(v[pi]=='1') break;
        if(pi==n){
            cout<<solve(n, 0, 0)<<'\n';
            continue;
        }
        if(pi!=0){
            ans+=solve(pi, 0, 1);
        }
        int li = n-1;
        for(li = n-1;li>=0;li--) if(v[li]=='1') break;
        if(li!=n-1){
            ans+=solve(n-li-1, 1, 0);
        }
        int i = pi;
        while(i!=li){
            int j = i+1;
            while(j<li && v[j]=='0') j++;
            ans+=solve(j-i-1, 1, 1);
            i=j;
        }
        for(auto i: v) if(i=='1') ans++;
        cout<<ans<<'\n';
    }


    return 0;
}