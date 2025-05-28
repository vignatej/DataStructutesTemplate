#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back


int solve(vector<int> &v, int thres){
    int n = v.size();
    if(n==0) return 0;
    VVI dp((1<<n), VI(2));
    dp[0][0]=1; dp[0][1]=1;;
    for(int i =1;i<(1<<n);i++){
        // dp[i]={n+1, 0};
        dp[i][0]=n+1; dp[i][1]=0;
        for(int j = 0;j<n;j++){
            if(!(i&(1<<j))) continue;
            int prev = i^(1<<j);
            VI &last = dp[prev];
            // VI cb = dp[i];
            VI cb(2);
            if(last[1]*v[j]<=thres){
                cb[0]=last[0];
                cb[1]=last[1]*v[j];
            }else{
                cb[0]=last[0]+1;
                cb[1]=min(v[j], last[1]);
            }
            dp[i] = min(dp[i], cb);
        }
    }
    return dp[(1<<n) - 1][0];
}


signed main(){
    int T; cin>>T;
    VI is_p(1e6+1, 1);
    VI primes;
    for(int i =2;i<is_p.size();i++){
        if(!is_p[i]) continue;
        primes.PB(i);
        for(int j = i*2;j<is_p.size();j+=i) is_p[j]=0;
    }
    while(T--){
        int x, y, k; cin>>x>>y>>k;
        map<int, int> xm;
        map<int, int> ym;
        for(auto &i: primes){
            while(x%i==0){
                x/=i;
                xm[i]++;
            }
            if(x==1) break;
        }
        for(auto &i: primes){
            while(y%i==0){
                y/=i;
                ym[i]++;
            }
            if(y==1) break;
        }
        
        VI prod, div;
        for(auto &i: ym){
            int a = i.first; int b = i.second;
            if(xm[a]>=b) continue;
            for(int j = 0;j<b-xm[a]; j++) prod.PB(a);
        }
        for(auto &i: xm){
            int a = i.first; int b = i.second;
            if(ym[a]>=b) continue;
            for(int j = 0;j<b-ym[a];j++) div.PB(a);
        }
        bool is_a = 1;
        for(auto &i: prod) if(i>k) is_a=false;
        for(auto &i: div) if(i>k) is_a=false;
        if(!is_a){
            cout<<-1<<'\n';
            continue;
        }
        int ans = prod.size()+div.size();
        map<multiset<int>, int> m1;
        ans = solve(prod, k);
        ans += solve(div, k);
        cout<<ans<<'\n';
    }

    return 0;
}