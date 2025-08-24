#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        vector<int> rem;
        while(n>0){
            rem.push_back(n%3);
            n/=3;
        }
        int ck{0};
        for(auto i: rem) ck+=i;
        if(ck>k){ cout<<-1<<'\n'; continue;}
        int cp = max(0LL, (int)rem.size() - 2);

        while(cp >= 0 && cp+1 < rem.size() && ck + 2 <= k) {
            // while(rem[cp+1] && ck + 2 <= k) {
            //     rem[cp+1]--;
            //     rem[cp] += 3;
            //     ck += 2;
            // }
            int tf = (k-ck)/2;
            tf = min(tf, rem[cp+1]);
            rem[cp+1]-=tf; rem[cp]+=3*tf;
            ck+=2*tf;
            if(rem[cp+1] == 0) cp--;
        }

        
        int ans{0};
        for(int i = 0;i<rem.size();i++){
            int cv{0};
            if(i==0) cv = 3;
            else cv = powl(3, i-1)*(9+i);
            ans+=rem[i]*cv;
        }
        cout<<ans<<'\n';
    }

    return 0;
}