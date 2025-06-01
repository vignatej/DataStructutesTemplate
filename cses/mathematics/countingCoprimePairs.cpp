#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n; cin>>n;
    VI v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    int me = *max_element(v.begin(), v.end());
    VVI prime_fact(me+1);
    vector<bool> isp(me+1, 1);
    for(int i =2;i<me+1;i++){
        if(!isp[i]) continue;
        for(int j = i;j<me+1;j+=i){
            prime_fact[j].PB(i);
            if(j!=i) isp[j] = 0;
        }
    }
    VI m(1e6+1, 0);
    for(auto curr: v){
        VI &cpf = prime_fact[curr]; 
        int cs = prime_fact[curr].size();;
        for(int j = 1;j<(1<<cs);j++){
            int cv = 1;
            int css = __builtin_popcount(j);
            for(int k = 0;k<cs;k++){
                if(!(j&(1<<k))) continue;
                cv*=cpf[k];
            }
            m[cv]++;
        }
    }
    int ans{0};
    for(auto curr: v){
        VI &cpf = prime_fact[curr];
        int cans{0}; 
        int cs = prime_fact[curr].size();
        if(cs==0){ ans+=n-1; continue;}
        for(int j = 1;j<(1<<cs);j++){
            int cv = 1;
            for(int k = 0;k<cs;k++){
                if(!(j&(1<<k))) continue;
                cv*=cpf[k];
            }
            int css = __builtin_popcount(j);
            if(css%2==1) cans+=m[cv];
            else cans-=m[cv];
        }
        ans+=n-cans;
    }
    cout<<(ans/2)<<'\n';
    return 0;
}