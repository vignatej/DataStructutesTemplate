#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    set<int> s;
    for(int i = 0;i<n;i++){int a; cin>>a; s.insert(a);}
    cout<<s.size();
    return 0;
}