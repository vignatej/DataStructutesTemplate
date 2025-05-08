#include <bits/stdc++.h>
using namespace std;
#define ll long long
class node{public:
    int par{-1}; int cc{-1};
    vector<node*> child;
    node(){}
    node(int x): par(x){}
    int child_count(){
        if(cc!=-1) return cc;
        int ans{0};
        for(auto i: child) ans+=1+i->child_count();
        return cc=ans;
    }
};
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n; cin>>n;
    vector<node*> v(n+1, nullptr);
    for(int i=1;i<=n;i++) v[i] = new node();
    for(int i = 2;i<=n;i++){
        int curr_par;
        cin>>curr_par;
        v[i]->par=curr_par;
        v[curr_par]->child.push_back(v[i]);
    }
    for(int i = 1;i<=n;i++) cout<<v[i]->child_count()<<' ';

    return 0;
}