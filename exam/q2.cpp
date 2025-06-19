#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        string s; cin>>s;
        map<char, int> m;
        m[s[0]]++; bool ans_f{false};
        for(int i = 1;i<n;i++){
            if(i==n-1){
                // do_it
                if(m[s[i]]){
                    if(m[s[i]]==1 && s[i]==s[0]){}
                    else{ans_f = true;}
                }
                continue;
            }
            if(m[s[i]]>0) ans_f = 1;
            m[s[i]]++;
        }
        if(ans_f) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}