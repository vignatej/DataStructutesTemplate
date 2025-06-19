#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int solve(string &s1, string &s2, string &cs){
    int pos = cs.size();
    int n = s1.size();
    if(pos==n){
        int ans{0};
        for(int i = 0;i<n;i++) if(s1[i]==cs[i]) ans++;
        for(int i = 0;i<n;i++) if(s2[i]==cs[i]) ans++;
        return ans;
    }
    if(s1.substr(0, pos)==cs && s2.substr(0, pos)==cs){
        int ans = 100;
        char c1{s1[pos]}, c2{s2[pos]};
        if(c1>c2) swap(c1, c2);
        if(c1==c2){
            cs.push_back(c1);
            ans = min(ans, solve(s1, s2, cs));
            cs.pop_back();
            return ans;
        }
        cs.push_back(c1+1);
        ans = min(ans, solve(s1, s2, cs));
        cs.pop_back();
        cs.push_back(c1);
        ans = min(ans, solve(s1, s2, cs));
        cs.pop_back();
        return ans;
    }else if(s1.substr(0, pos)==cs){
        int ans = 100;
        char c1{s1[pos]};
        while(c1<='9' && (c1==s1[pos] || c1==s2[pos])) c1++;
        c1 = min(c1, '9');
        cs.push_back(c1);
        ans = min(ans, solve(s1, s2, cs));
        cs.pop_back();
        return ans;
    }else if(s2.substr(0, pos)==cs){
        int ans = 100;
        char c1{s2[pos]};
        while(c1>='0' && (c1==s1[pos] || c1==s2[pos])) c1--;
        c1 = max(c1, '0');
        cs.push_back(c1);
        ans = min(ans, solve(s1, s2, cs));
        cs.pop_back();
        return ans;
    }else{
        int ans = 100;
        char c1{'0'};
        while(c1<='9' && (c1==s1[pos] || c1==s2[pos])) c1++;
        c1 = min(c1, '9');
        cs.push_back(c1);
        ans = min(ans, solve(s1, s2, cs));
        cs.pop_back();
        return ans;
    }
}

signed main(){
    int T; cin>>T;
    while(T--){
        string s1, s2; cin>>s1>>s2;
        if(s1.size() > s2.size()) swap(s1, s2);
        while(s1.size() < s2.size()) s1='0'+s1;
        if(s1>s2) swap(s1, s2);
        string cs;
        int ans = solve(s1, s2, cs);
        cout<<ans<<'\n';
    }

    return 0;
}