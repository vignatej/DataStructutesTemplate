#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int P = 31;
const int M = 1e9+7;

signed main(){
    string s, rs; cin>>s;
    rs = s; reverse(rs.begin(), rs.end());
    int n = s.length();
    VI fh(n+1, 0), bh(n+1, 0);
    VI ppow(n+1, 1);
    for(int i = 0;i<n;i++){
        fh[i+1]=(fh[i]+(s[i]-'a'+1)*ppow[i])%M;
        bh[i+1]=(bh[i]+(rs[i]-'a'+1)*ppow[i])%M;
        ppow[i+1]=(ppow[i]*P)%M;
    }
    VI len_pall(n, 0);
    for(int i = 0;i<n;i++){
        int l = 1; int r = min(i+1, n-i);
        int ca = 1;
        while(l<=r){
            int m = (l+r)/2;
            int f1 = (fh[i+1]-fh[i+1-m]+M)%M;
            f1 = (f1*ppow[n-(i+1-m)])%M;
            int f2 = (bh[n-i]-bh[n-i-m]+M)%M;
            f2 = (f2*ppow[n-(n-i-m)])%M;
            if(f1==f2){
                ca = max(ca, m);
                l=m+1;
            }else{
                r=m-1;
            }
        }
        len_pall[i+ca-1]=max(len_pall[i+ca-1], 2*ca-1);
    }
    for(int i = 0;i<n;i++){
        int l{1}, r{min(i+1, n-i-1)};
        int ca{0};
        while(l<=r){
            int m = (l+r)/2;
            int f1 = (fh[i+1]-fh[i-m+1]+M)%M;
            f1=(f1*ppow[n-(i-m+1)])%M;
            int f2 = (bh[n-i-1]-bh[n-i-m-1]+M)%M;
            f2=(f2*ppow[n-(n-i-m-1)])%M;
            if(f1==f2){
                ca=max(ca, m);
                l=m+1;
            }else{
                r=m-1;
            }
        }
        len_pall[i+ca]=max(len_pall[i+ca], 2*ca);
    }

    int p{0}; int pp = n-1;
    for(int i =n-1;i>=0;i--){
        if(p<len_pall[i]){
            p=len_pall[i]-2; pp=i; continue;
        }
        int ppv = len_pall[pp];
        int mvt = pp - (ppv/2) - (ppv%2) + 1;
        if(i>=mvt){
            len_pall[i]=p;
            p-=2;
            continue;
        }
        p=len_pall[i]-2; pp=i;
    }
    for(auto &i: len_pall) cout<<i<<' ';

    return 0;
}