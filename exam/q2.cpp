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
        deque<int> q;
        while(n>0){
            if(n%2) q.push_back(n);
            else q.push_front(n);
            n--;
        }
        for(auto &i: q) cout<<i<<' ';
        cout<<'\n';
    }

    return 0;
}