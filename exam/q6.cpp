#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool isp(int p, int a, int n){
    p*=n; a*=n;
    if(p%4!=0) return 0;
    int x = p/4;
    int lb = 2*x-1; int ub = x*x;
    if(lb<=a && a<=ub) return 1;
    return 0;
}

signed main(){
    int T; cin>>T;
    while(T--){
        int p, a; cin>>p>>a; 
        int g = gcd(p, a);
        p/=g; a/=g;
        bool ch{0};
        if(p%4!=0){p*=4; a*=4; ch=1;}
        if(!isp(p, a,1)){
            if(ch){p/=4; a/=4;}
            int n = (16*a)/(p*p);
            if(!n) n++;
            int i = 0;
            while(i<50 && !isp(p, a, n+i)){
                i++;
            }
            n+=i;
            if(!isp(p, a, n)){
                if(a*2+2==p){
                    cout<<a<<'\n';
                    for(int i = 0;i<a;i++) cout<<i<<' '<<0<<'\n';
                    continue;
                }else if(2*a*2+2==2*p){
                    a*=2; p*=2;
                    cout<<a<<'\n';
                    for(int i = 0;i<a;i++) cout<<i<<' '<<0<<'\n';
                    continue;
                }
            }
            if(!isp(p, a, n)){
                cout<<"-1\n";
                continue;
            }
            p*=n; a*=n;
        }
        int x = p/4;
        // int lb = 2*x-1; int ub = x*x;
        // if(!(lb<=a && a<=ub)){
        //     cout<<-1<<'\n';
        //     continue;
        // }
        VVI ans(x, VI(x, 1));
        int ca=x*x;
        for(int i = 0;i<x-1 && ca!=a;i++){
            for(int j = x-1;j>0 && ca!=a;j--){
                ans[i][j]=0; ca--;
            }
        }
        cout<<a<<'\n';
        for(int i = 0;i<x;i++){
            for(int j = 0;j<x;j++){
                if(ans[i][j]) cout<<i<<' '<<j<<'\n'; 
            }
        }

    }

    return 0;
}