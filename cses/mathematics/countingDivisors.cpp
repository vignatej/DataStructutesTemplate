#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

// signed main(){
//     int T; cin>>T;
//     VI isp(1e6+1, 1), primes;
//     for(int i =2;i<isp.size();i++){
//         if(isp[i]==0) continue;
//         primes.PB(i);
//         for(int j = i+i;j<isp.size();j+=i) isp[i]=0;
//     }
//     while(T--){
//         int n; cin>>n;
//         map<int, int> m;
//         for(auto i: primes){
//             while(n%i==0){
//                 n/=i; m[i]++;
//             }
//             if(i>n) break; 
//         }
//         int ans{1};
//         for(auto i: m) ans*=(i.second+1);
//         cout<<ans<<'\n';
//     }

//     return 0;
// }

signed main(){

    VI counts(1e6+1, 1);
    for(int i=2;i<counts.size();i++){
        for(int j = i;j<counts.size();j+=i) 
            counts[j]++;
    }
    int T; cin>>T;
    while(T--){
        int n; cin>>n; cout<<counts[n]<<'\n';
    }
    return 0;
}