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
        string s; string p;
        cin>>p>>s;
        int sl = s.length(); int pl = p.length();
        int i = 0; int j = 0;
        bool ya = true;
        while(i<sl && j<pl){
            char c = s[i];
            if(s[i]!=p[j]){ya=false; break;}
            int i1{i}, j1{j};
            while(i1<sl && s[i1]==c) i1++;
            while(j1<pl && p[j1]==c) j1++;
            int csl{i1-i}, cpl{j1-j};
            if(!(csl>=cpl && csl<=2*cpl)){ ya=false; break;}
            i=i1; j=j1;
        }
        if(i!=sl || j!=pl) ya=false;
        cout<<(ya ? "YES":"NO")<<'\n';

    }
}
