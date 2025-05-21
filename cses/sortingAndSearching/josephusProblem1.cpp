#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    vector<bool> comp(n+1, false);
    vector<int> next(n+1, 0);
    for(int i =0;i<n;i++)next[i]=(i+1)%n;
    int cs{0}; int cp=0;
    while(cs<n){
        comp[next[cp]]=1;
        cout<<next[cp]+1<<' ';
        next[cp]=next[next[cp]];
        cp=next[cp];
        cs++;
    }

    return 0;
}