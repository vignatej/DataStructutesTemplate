#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, q; cin>>n>>q;
    VI v(n); for(int i =0;i<n;i++) cin>>v[i];
    int bs = sqrt(n)+1; int nb = n/bs+1;
    VVI quer(q, VI(2)); VVI qb(nb);
    VI ans(q, -1);
    for(int i = 0;i<q;i++){
        cin>>quer[i][0]; quer[i][0]--;
        cin>>quer[i][1]; quer[i][1]--;
        qb[quer[i][0]/bs].PB(i);
    }
    for(auto &qiv: qb){
        sort(qiv.begin(), qiv.end(), [&quer](int a, int b){
            return quer[a][1]<quer[b][1];
        });
        int s{-1}, e{-1}, oc{0};
        unordered_map<int, int> fc;
        for(auto &ind: qiv){
            int qs{quer[ind][0]}, qe{quer[ind][1]};
            if(s==-1){
                for(int i = qs;i<=qe;i++){ 
                    fc[v[i]]++;
                    if(fc[v[i]]==1) oc++;
                }
                s=qs; e=qe;
                ans[ind] = oc;
                continue;
            }
            while(e<qe){e++; fc[v[e]]++; if(fc[v[e]]==1) oc++;}
            while(s<qs){
                fc[v[s]]--;
                if(fc[v[s]]==0) oc--;
                s++;
            }
            while(s>qs){
                s--;
                fc[v[s]]++;
                if(fc[v[s]]==1) oc++;;
            }
            ans[ind]=oc;
        }

    }
    for(auto i: ans) cout<<i<<' ';
    return 0;
}