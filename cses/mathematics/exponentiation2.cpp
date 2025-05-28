#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

const int M = 1e9+7;

int calc_pow(int a, int b, int M){
    if(b==0) return 1;
    if(b==1) return a;
    int fir = calc_pow(a, b/2, M); 
    fir*=fir; fir%=M;
    if(b%2) fir*=a;
    return fir%M;
}
signed main(){
    int T; cin>>T;
    while ((T--)){
        int a, b, c; cin>>a>>b>>c;
        int p = calc_pow(b, c, M-1);       
        cout<<calc_pow(a, p, M)<<'\n';
    }
    

    return 0;
}