#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

VI dp;
int get_2(VI &squares, int req){
    if(dp[req]!=-2) return dp[req];
    int n = squares.size();
    int i = 0; int j = n-1;
    while(i<=j){
        int cs = squares[i]+squares[j];
        if(cs==req) break;
        if(cs<req){
            i++;
        }else if(cs>req){
            j--;
        }
    }
    if(squares[i]+squares[j]==req) 
        return dp[req] = ((i<<32) + j);
    return dp[req] = -1;
}

signed main(){

    map<int, int> two_s;
    VI squares; VI si;
    for(int i = 0;i*i<=1e7;i++){ 
        squares.PB(i*i);
        si.PB(i);
    }
    int n = squares.size();
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(squares[i]+squares[j]>1e7) continue;
            two_s[squares[i]+squares[j]] = (i<<32)+j;
        }
    }
    int T; cin>>T;
    while(T--){
        int req; cin>>req;
        for(auto &i: two_s){
            int s1 = i.first;
            auto it = two_s.find(req-s1);
            if(it==two_s.end()) continue;
            int p1 = i.second>>32;
            int p2 = i.second - (p1<<32);
            int p3 = (it->second)>>32;
            int p4 = (it->second) - (p3<<32);
            cout<<si[p1]<<' '<<si[p2]<<' '<<si[p3]<<' '<<si[p4]<<'\n';
            break;
        }
    }
    
    // int n = squares.size();
    // dp.resize(1e7+1, -2);
    // int T; cin>>T;
    // while(T--){
    //     int req; cin>>req;
    //     bool comp = 0;
    //     for(int i = 0;i<n && !comp;i++){
    //         for(int j = i;j<n && !comp;j++){
    //             int cs = squares[i]+squares[j];
    //             if(req<cs) break;
    //             int nex = get_2(squares, req-cs);
    //             if(nex==-1) continue;
    //             int v1 = sqrt(squares[i]);
    //             int v2 = sqrt(squares[j]);
    //             int p3 = nex>>32;
    //             int p4 = nex-(p3<<32);
    //             int v3 = sqrt(squares[p3]);
    //             int v4 = sqrt(squares[p4]);
    //             cout<<v1<<' '<<v2<<' '<<v3<<' '<<v4<<'\n';
    //             comp=1;
    //         }
    //     }
    // }

    return 0;
}