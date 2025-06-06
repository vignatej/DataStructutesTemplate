#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;
signed main(){
    int n, m; cin>>n>>m;
    vector<vector<double>> eqss(n, vector<double>(m+1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=m;j++){
            double c; cin>>c;
            eqss[i][j]=c;
        }
    }
    auto eqs = eqss;
    bool is_a = 1;
    // for(int i = 0;i<n && i<m;i++){
    //     if(eqs[i][i]) continue;
    //     int j = i+1;
    //     while(j<n){
    //         if(eqs[j][i]) break;
    //         j++;
    //     }
    //     if(j==n){is_a=0; break;}
    //     swap(eqs[i], eqs[j]);
    // }

    for(int i = 0;i<n && i<m;i++){
        if(eqs[i][i]==0){
            int j = i+1;
            while(j<n){
                if(eqs[j][i]) break;
                j++;
            }
            if(j==n){is_a=0; break;}
            swap(eqs[i], eqs[j]);
        }
        if(!is_a) break;
        double prev_v = eqs[i][i];
        for(int j = 0;j<=m;j++) 
            eqs[i][j]/=prev_v;
        for(int a = 0;a<n;a++){
            if(a==i) continue;
            double prev = eqs[a][i];
            for(int b = 0;b<=m;b++){
                eqs[a][b]-=eqs[i][b]*prev;
            }
        }
    }
    // for(auto &i: eqs){
    //     for(auto &j: i){
    //         cout<<j<<' ';
            
    //     }cout<<'\n';
    // }
    if(!is_a){
        cout<<-1;
        return 0;
    }
    for(auto &i: eqs){
        int lv = i.back();
        cout<<(lv+M)%M<<' ';
    }

    return 0;
}