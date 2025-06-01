#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
int M = 1e9+7;
int powl(int a, int b, int M = M){
    if(b==0) return 1;
    if(b==1) return a;
    int ans = powl(a, b/2, M);
    ans*=ans; ans%=M;
    if(b%2) ans*=a; ans%=M;
    return ans;
}

signed main(){
    int n; cin>>n;
    VVI v(n);
    int ans1{1}, ans2{1}, ans3{1};
    int N{1};
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        v[i]={a, b};
        ans1*=(b+1); ans1%=M;
        // ans2*=(pow(a, b+1)-1)/(a-1);
        ans2*=(powl(a, b+1)-1); ans2%=M;
        ans2*=powl(a-1, M-2); ans2%=M;
        N*=powl(a, b); N%=M;
    }

    // int upp = 1;
    // for(auto &i: v){
    //     int a = i[0]; int b = i[1];
    //     upp *= (b+1); 
    //     upp%=(M-1);
    // }
    // if(upp%2==0) upp/=2;
    // else upp*=powl(2, M-3, M-1); 
    // upp%=M-1;
    // ans3 = powl(N, upp);

    bool flag{false}; int upper{1};
    for(auto &i: v){
        int a{i[0]}, b{i[1]};
        if((b+1)%2==0 and !flag){
            upper*=(b+1)/2;
            flag=1;
        }else{
            upper*=(b+1);
        }
        upper%=M-1;
    }
    if(!flag){
        for(auto &i: v) i[1]/=2;
    }
    int number{1};
    for(auto &i: v){
        number *= powl(i[0], i[1]);
        number%=M;
    }
    ans3 = powl(number, upper);

    cout<<ans1<<' '<<ans2<<' '<<ans3;

    return 0;
}