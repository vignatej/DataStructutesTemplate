#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    string s; getline(cin, s);
    stringstream ss{s};
    int bc{0};
    for(auto i: s) if(i==' ') bc++;
    bool po = true;
    vector<int> v;
    while((bc--)+1>0){
            int n; ss>>n;
            v.push_back(n);
    }
    for(auto i: v) cout<<i<<'\n';
    return 0;
}