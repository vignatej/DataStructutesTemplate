#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main() {

    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif

    vector<int> v{1,3,-5,2,3,-7,6,5};
    int best{0}, tn{0};
    for(auto &i: v){
        tn = max(tn+i, i);
        best = max(best, tn);
    }
    cout<<best;
    map<int, string> m;
    m[0]="0"; m[1]="1";
    if(m[2]==""){
        cout<<"yaa";
    }
    for(auto &i:m) cout<<i.first<<'-'<<i.second<<'-';
    return 0;
}