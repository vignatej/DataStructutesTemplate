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
    int n, k; cin>>n>>k;
    vector<string> v(n);
    set<string> m;
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    int ans{0};
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            string req = "";
            for(int l = 0;l<k;l++){
                if(v[i][l]==v[j][l]) req.push_back(v[i][l]);
                else{
                    vector<char> al{'S', 'E', 'T'};
                    al.erase(find(al.begin(), al.end(), v[i][l]));
                    al.erase(find(al.begin(), al.end(), v[j][l]));
                    req.push_back(al.front());
                }
            }
            if(req!=v[j]) ans+=m.count(req);
        }
        m.insert(v[i]);
    }
    cout<<ans/2<<'\n';

    return 0;
}