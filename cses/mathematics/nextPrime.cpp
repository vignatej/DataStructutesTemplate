#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        // int mu = n+3LL*log2f(n);
        for(int i = n+1;i<=2*n;i++){
            bool isp = 1;
            for(int j = 2;j<=sqrt(i);j++){
                if(i%j==0){isp=false; break;}
            }
            if(isp){
                cout<<i<<'\n';
                break;
            }
        }

    }

    return 0;
}