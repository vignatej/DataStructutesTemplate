#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back


VI z_func(string &s){
    int n = s.length();
    VI z(n, 0);
    int x{0}, y{0};
    for(int i =1;i<n;i++){
        z[i]=max(1LL*0, min(z[i-x], y-i+1));
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            x=i; y=i+z[i];
            z[i]++;
        }
    }
    return z;
}

signed main(){
    string s; cin>>s;
    VI z = z_func(s);
    int n = s.length();
    for(int i = 0;i<n;i++){
        if(z[i]==n-i) cout<<i<<' ';
    }
    cout<<n;

    return 0;
}