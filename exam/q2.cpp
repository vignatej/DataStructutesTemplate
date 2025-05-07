#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<int, int> solve(int n, int m, int l, int r){
    int t = max(l, r); l=min(l, r); r = t;
    if(m<=abs(r)){
        return {0, m};
    }else if(n<=abs(l)){
        return {-1*m, 0};
    }else{
        int mor = r-m;
        return {mor, r};
    }
}

signed main(){
    int T; cin>>T;
    while(T>0){T--;
        int a1, a2, b1, b2;
        cin>>a1>>a2>>b1>>b2;
        auto ans = solve(a1,a2,b1,b2);
        cout<<ans.first<<' '<<ans.second<<'\n';
    }
}
