#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool iswin(int a1, int a2, int b1, int b2){
    int ans{0};
    if(a1>b1) ans++;
    else if(a1<b1) ans--;
    if(a2>b2) ans++;
    else if(a2<b2) ans--;
    return (ans>0);
}

signed main(){
    int T; cin>>T;
    while(T>0){T--;
        int n; cin>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) cin>>v[i][j];
        vector<int> ans;
        vector<bool> comp(2*n+1, false);
        for(int i = 0;i<n;i++){
            ans.push_back(v[0][i]);
            comp[v[0][i]]=1;
        }
        for(int i = 1;i<n;i++){
            ans.push_back(v[i][n-1]);
            comp[v[i][n-1]]=1;
        }
        for(int i =1;i<=2*n;i++)
            if(!comp[i]) ans.insert(ans.begin(), i);
        for(auto &i: ans) cout<<i<<' ';
        cout<<'\n';

    }
}
