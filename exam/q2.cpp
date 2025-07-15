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
    int n; cin>>n;
    string s;
    for(int i = 0;i<n;i++){
        char x; int l; cin>>x>>l;
        if(s.length()+l>100){
            cout<<"Too Long";
            return 0;
        }
        for(int j = 0;j<l;j++) s.push_back(x);
    }
    cout<<s;
    return 0;
}