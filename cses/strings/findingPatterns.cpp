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
    string s; cin>>s;
    int n = s.length();
    int k; cin>>k;
    vector<string> vs(k);
    vector<int> vss(k, 0);
    for(int i = 0;i<k;i++) vss[i]=i;
    for(int i = 0;i<k;i++) cin>>vs[i];
    sort(vss.begin(), vss.end(), [&vs](int a, int b){
        return vs[a].length()<vs[b].length();
    });
    vector<int> hash(n+1, 0);
    VI ppow(n+1, 1);
    for(int i = 0 ;i<n;i++){
        hash[i+1]=(hash[i]+(s[i]-'a'+1)*ppow[i])%M;
        ppow[i+1]=(ppow[i]*P)%M;
    }
    set<int> vls; int cs{0};

    vector<bool> ans(k, 0);
    for(auto &q: vss){
        string &curr = vs[q];
        int cn = curr.length();
        if(cn>n){
            // cout<<"NO\n";
            ans[q]=0;
            continue;
        }
        int chv = 0;
        for(int i = 0;i<cn;i++){
            chv = (chv+(curr[i]-'a'+1)*ppow[i])%M;
        }
        chv = (chv*ppow[n])%M;
        if(cs!=cn){
            vls.clear(); cs=cn;
            for(int i = 0;i<=n-cs;i++){
                int csh = (hash[i+cs]-hash[i]+M)%M;
                csh = (csh*ppow[n-i])%M;
                vls.insert(csh);
            }
        }
        if(vls.find(chv)==vls.end()) ans[q]=0;
        else ans[q]=1;

    }
    for(int i = 0;i<k;i++) cout<<(ans[i] ? "YES":"NO")<<'\n';

    return 0;
}