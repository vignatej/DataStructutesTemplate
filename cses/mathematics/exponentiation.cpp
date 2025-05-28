#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;

int calc_pow(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    int fir = calc_pow(a, b/2); 
    fir*=fir; fir%=M;
    if(b%2) fir*=a;
    return fir%M;
}

signed main(){
    int n; cin>>n;
    while(n--){
        int a, b; cin>>a>>b;
        cout<<calc_pow(a, b)<<'\n';
    }

    return 0;
}