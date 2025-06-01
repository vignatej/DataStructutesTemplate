#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;

signed main(){
    int n; cin>>n;
    int ans{0};
    for(int i =1;i<=sqrt(n);i++) ans+=i*((int)(n/i));
    int i = sqrt(n)+1;
    while(i<=n){
        int st = n/i;

        int s = i; int e{n};
        int ei = s;
        while(s<=e){
            int m = (s+e)/2;
            int cv = n/m;
            if(cv>st){
                e=m-1;
            }else{
                ei = max(ei, m);
                s=m+1;
            }
        }
        int tv = ei-i+1;
        int cans = ((ei*(ei+1))/2) - (((i-1)*(i))/2); cans%=M;
        cans*=st; cans%=M;
        ans+=cans; ans%=M;
        i=ei+1;
    }
    cout<<ans<<'\n';

    return 0;
}