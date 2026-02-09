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
    vector<int> minD(1e5+5, 1);
    for(int i =2;i<minD.size();i+=2) minD[i]=2;
    for(int i =3;i<minD.size();i+=2){
        if(minD[i]==1){
            for(int j = i;j<minD.size();j+=i) minD[j]=i;
        }
    }
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        // vector<char> v1(n); for(auto &i: v1) cin>>i;
        // vector<char> v2(n); for(auto &i: v2) cin>>i;
        vector<vector<char>> v(k, vector<char>(n));
        for(auto &i: v) for(auto &j: i) cin>>j;
        vector<int> pf;
        int cn = n;
        while(cn!=1){
            pf.push_back(minD[cn]);
            cn/=minD[cn];
        }
        int pfs = pf.size();
        set<int> all_f;
        for(int i = 0;i<(1<<pfs);i++){
            int cv{1};
            for(int j = 0;j<pfs;j++) if(i&(1<<j)) cv*=pf[j];
            all_f.insert(cv);
        }
        // for(auto i: all_f) cout<<i<<' ';
        // cout<<'\n';
        for(auto &cans: all_f){
            bool poss = 1;
            string cs;
            for(int i = 0;i<cans;i++){
                set<char> inf;
                for(int j = 0;j<k;j++) inf.insert(v[j][i]);
                for(int p = i;p<n && inf.size();p+=cans){
                    set<char> inthis;
                    for(int j = 0;j<k;j++) inthis.insert(v[j][p]);
                    vector<int> ntbe;
                    for(auto &j: inf) 
                        if(inthis.find(j)==inthis.end()) ntbe.push_back(j);
                    for(auto j:ntbe) inf.erase(j); 
                }
                if(inf.size()==0){poss=0; break;}
                cs.push_back(*inf.begin());
            }
            if(!poss) continue;
            string fans = cs;
            while(fans.size()<n) 
                copy(cs.begin(), cs.end(), back_inserter(fans));
            cout<<fans<<'\n';
            break;
        }
    }

    return 0;
}