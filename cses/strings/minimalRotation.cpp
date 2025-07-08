#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int P = 31;
const int M = 1e9+9;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    string s; cin>>s;
    int n = s.length();
    s=s+s;
    VI hash(2*n+1, 0);
    VI ppow(2*n+1, 1);
    for(int i = 0;i<2*n;i++){
        hash[i+1]= (hash[i] + (s[i]-'a'+1)*ppow[i])%M;
        ppow[i+1] = (ppow[i]*P)%M;
    }
    int mv = 0;
    for(int i = 1;i<n;i++){
        int l{1}, r{n};
        int a_m = 0;
        while(l<=r){
            int m = (l+r)/2;
            int f1 = (hash[i+m]-hash[i]+M)%M;
            f1=(f1*ppow[n-i+1])%M;
            int f2 = (hash[mv+m]-hash[mv]+M)%M;
            f2=(f2*ppow[n-mv+1])%M;
            if(f1==f2){
                a_m = max(a_m, m);
                l=m+1;
            }else{
                r=m-1;
            }
        }
        if(a_m<n && s[mv+a_m]>s[i+a_m]) mv = i;
    }
    for(int i = 0;i<n;i++) cout<<s[i+mv];
    // VI sp(n);
    // for(int i = 0;i<n;i++) sp[i]=i;
    // int l = 0;
    // while(sp.size()>1 && l<n){
    //     VI np;
    //     char mnc = s[sp[0]+l];
    //     set<char> ncc;
    //     for(auto &i: sp){ mnc = min(mnc, s[i+l]); ncc.insert(s[i+l]);}
    //     // if(ncc.size()==1) break;
    //     for(auto &i: sp) if(s[i+l]==mnc) np.PB(i); 
    //     sp=np;
    //     l++;
    // }
    // for(int i = 0;i<n;i++) cout<<s[i+sp[0]];

    return 0;
}