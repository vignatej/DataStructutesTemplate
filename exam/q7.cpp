#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

void dfs(vector<vector<int>> &g, int cn, int p, vector<int> &st){
    st.push_back(cn);
    for(auto i: g[cn]){
        if(i==p) continue;
        dfs(g, i, cn, st);
    }
}


signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<vector<int>> g(n+1);
        for(int i = 1;i<n;i++){
            int a, b; cin>>a>>b;
            g[a].push_back(b); g[b].push_back(a);
        }
        vector<int> st;
        dfs(g, 1, 0, st);
        bool ans = 0;
        for(int i = 0;i+1<st.size() && !ans;i+=2){
            cout<<"? "<<st[i]<<" "<<st[i+1]<<'\n';
            int cv; cin>>cv;
            if(cv==1){
                ans=1;
                cout<<"? "<<st[i]<<" "<<st[i]<<'\n';
                cin>>cv;
                if(cv){cout<<"! "<<st[i]<<'\n';}
                else{cout<<"! "<<st[i+1]<<'\n';}
            }
        }
        if(!ans){
            cout<<"! "<<st[st.size()-1]<<'\n';
        }

    }

    return 0;
}