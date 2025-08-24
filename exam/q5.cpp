#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define int LL

int dp[18][2][2];
pair<int, int> do_it(int n, string &cn, int i, bool tight){
    if(i==n){
        return {1, 0};
    }
    if(dp[i][tight][0]!=-1 && dp[i][tight][1]!=-1) 
        return {dp[i][tight][0], dp[i][tight][1]};
    int ans{0}; int times{0};
    for(int j = 0;j<(tight ? cn[i]-'0'+1:10);j++){
        pair<int, int> cans = do_it(n, cn, i+1, tight && j==cn[i]-'0');
        ans += cans.second + cans.first*j;
        times += cans.first;
    }
    dp[i][tight][0]=times; dp[i][tight][1]=ans;
    return {times,ans};
}

vector<int> v{1};
int powl(int a, int b){
    return v[b];
}
signed main(){
    int T; cin>>T;
    for(int i = 0;i<18;i++){
        v.push_back(v.back()*10);
    }
    while(T--){
        int n; cin>>n;
        int cn = n;
        int d{1};
        for(; d<=18; d++){
            int cdn = 1LL*9*powl(10, d-1)*d;
            if(cn>=cdn) cn-=cdn;
            else break;
        }
        string ln;
        ln.push_back('0'+1+cn/(d*powl(10, d-1)));
        cn = cn % (LL)(d*powl(10, d-1));
        int cd = d-1;
        while(cd>0){
            ln.push_back('0'+cn/(d*powl(10, cd-1)));
            cn = cn % (LL)(d*powl(10, cd-1));
            cd--;
        }
        int fans = stoll(ln);
        fans--;
        int s{0};
        for(int i = 0;i<cn;i++) s+=ln[i]-'0';
        string rs = to_string(fans);
        memset(dp, -1, sizeof(dp));
        s += do_it(rs.size(), rs, 0, 1).second;
        cout<<s<<' '<<'\n';
    }
}