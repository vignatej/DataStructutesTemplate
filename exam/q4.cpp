#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class numTrie{ public:
    class node{ public:
        bool end{false};
        int count{0};
        vector<node*> child{nullptr, nullptr};
    };
    node* root{nullptr};
    int mb = 30;
    numTrie(){
        root = new node();
    }
    void insert(int n){
        node* curr = root;
        for(int i = mb;i>=0;i--){
            bool bit = (n>>i)&1;
            if(curr->child[bit]==nullptr) curr->child[bit]=new node();
            curr->child[bit]->count+=1;
            curr = curr->child[bit];
        }
        curr->end=true;
    }
    void remove(int n){
        node* curr = root;
        for(int i = mb;i>=0;i--){
            bool bit = (n>>i)&1;
            curr->child[bit]->count-=1;
            curr = curr->child[bit];
        }
    }
    int get_max_or(int n){
        int cn{0};
        node* curr = root;
        for(int i = mb;i>=0;i--){
            bool bit = (n>>i)&1;
            if(curr->child[1-bit]!=nullptr && curr->child[1-bit]->count>0){
                cn |= ((1-bit)<<i);
                curr = curr->child[1-bit];
            }else{
                cn |= ((bit)<<i);
                curr = curr->child[bit];   
            }
        }
        return cn;
    }

};

void solve(){
    int l, r; cin>>l>>r;
    numTrie t;
    for(int i = l;i<=r;i++) t.insert(i);
    int ans{0}; vector<int> arr;
    for(int i=l;i<=r;i++){
        int j = t.get_max_or(i);
        ans += i|j;
        t.remove(j);
        arr.push_back(j);
    }
    cout<<ans<<'\n';
    for(auto i: arr) cout<<i<<' ';
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        solve();
    }

    return 0;
}