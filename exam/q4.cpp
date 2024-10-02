#include <bits/stdc++.h>
using namespace std;
#define int long long
int calc(int pp, int ca, int l, int r){
    int ans{0};
    while(!(pp<=l && l<pp*3)){pp*=3; ca++;}
    if(pp<=r && r<pp*3){
        ans += (r-l+1)*ca;
        return ans;
    }
    return (pp*3 -l)*ca + calc(pp*3, ca+1, pp*3, r) ;
}
signed main(){
    int T; cin>>T;
    while(T>0){T--;
        int l, r; cin>>l>>r;
        int s = l; int ans{0};
        while(s){s/=3; ans+=2;}
        l++;
        // int ca{1}; int pp{1};
        // while(!(pp<=l && l<pp*3)){pp*=3; ca++;}
        // if(pp<=r && r<=pp*3){
        //     ans += (r-l+1)*ca;
        //     cout<<ans<<'\n'; 
        //     continue;
        // }
        cout<<ans+calc(1, 1, l, r)<<'\n';
    }
}
