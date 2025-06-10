#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;
int powl(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(a==0) return a;
    int ans = powl(a, b/2);
    ans*=ans; ans%=M;
    if(b%2){ ans*=a; ans%=M;}
    return ans;
}

void resolve(VVI &g){
    int n = g.size();
    queue<int> q; q.push(1);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(auto &i: g[t]){
            auto it = find(g[i].begin(), g[i].end(), t);
            if(it != g[i].end()) g[i].erase(it);
            q.push(i);
        }
    }
}

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        map<int, int> m;
        VVI g(n+1);
        for(int i = 0;i<n-1;i++){
            int p, c; cin>>p>>c;
            m[p]++; m[c]++;
            g[p].PB(c);
            g[c].PB(p);
        }
        resolve(g);
        int lc{0};
        for(int i =2;i<=n;i++) if(g[i].size()==0) lc++;
        if(lc>=3){
            cout<<0<<'\n';
        }else if(lc==2){
            int pe = -1;
            for(int i = 1;i<=n;i++) 
                if(g[i].size()==2) pe = i;
            int l1{1}, l2{1};
            int c1{g[pe][0]}, c2{g[pe][1]};
            while(g[c1].size()>0){c1=g[c1][0]; l1++;}
            while(g[c2].size()>0){c2=g[c2][0]; l2++;}
            int curr = 1; int pl{1};
            while(curr!=pe){curr=g[curr][0]; pl++;}
            int ans;
            if(l1==l2){
                ans=powl(2, pl+1);
            }else{
                int ed = max(l1, l2)-min(l1, l2);
                ans = powl(2, pl+ed); 
                ans+=powl(2, pl+ed-1);
                ans%=M;
            }
            cout<<ans<<'\n';

        }else if(lc==1){
            int ans = powl(2, n);
            cout<<ans<<'\n';
        }
    }

    return 0;
}