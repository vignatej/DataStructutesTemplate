#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int M = 1e9+7;

signed main(){
    int n; cin>>n;
    map<int, int> m;
    for(int i =1;i<=n;i++){
        int a; cin>>a; m[a]++;
    }
    int ans{0};
    for(auto i: m){
        int ct{i.second};
        ans=ans+ans*ct+ct;
        ans%=M;
    }
    cout<<ans;
    return 0;
}