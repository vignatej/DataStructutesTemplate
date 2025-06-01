#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;

int powl(int a, int b, int M){
    if(b==0) return 1;
    if(b==1) return a;
    int ans = powl(a, b/2, M);
    ans*=ans; ans%=M;
    if(b%2) ans*=a;
    ans%=M; return ans;
}
int inv (int a, int m){
    return powl(a, m-2, m);
}

signed main(){
    int n; cin>>n;
    VI v(n+1);
    for(int i = 1;i<=n;i++) cin>>v[i];
    vector<bool> comp(n+1,false);
    set<int> rounds;
    for(int i = 1;i<=n;i++){
        if(comp[i]) continue;
        comp[i]=1;
        int j = v[i]; int cans{1};
        while(j!=i){
            comp[j] = 1;
            j=v[j];
            cans++;
        }
        rounds.insert(cans);
    }
    // int clcm = 1;
    // for(auto i: rounds){
    //     int g = gcd(i, clcm);
    //     clcm = (clcm*i); 
    //     clcm%=M;
    //     clcm *= inv(g, M);
    //     clcm %= M;
    // }
    // cout<<clcm;
    vector<bool> isp(2e5+1, 1);
    VVI primes(2e5+1);
    for(int i = 2;i<isp.size();i++){
        if(!isp[i]) continue;
        for(int j = i;j<2e5+1;j+=i){
            isp[j]=0;
            primes[j].PB(i);
        }
    }
    map<int, int> on;
    for(auto i: rounds){
        VI &pf = primes[i];
        map<int, int> cn;
        for(auto j: pf){
            while(i%j==0){
                i/=j;
                cn[j]++;
            }
        }
        for(auto &j: cn) on[j.first] = max(on[j.first], cn[j.first]);
    }
    int ans{1};
    for(auto &i: on){
        ans*=powl(i.first, i.second, M);
        ans%=M;
    }
    cout<<ans;
    return 0;
}