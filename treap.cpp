#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class node{public:
    int v;
    node *l{nullptr}, *r{nullptr};
    int prio; int siz{1};
    int sum{0};
    bool rev{false};
    node(int v):v(v), sum(v){
        prio=rand();
    }
};
void push(node* n){
    if(!n) return;
    if(!(n->rev)) return;
    swap(n->l, n->r);
    if(n->l) n->l->rev^=1;
    if(n->r) n->r->rev^=1;
    n->rev=0;
}
int get_sz(node* n){
    return n? n->siz:0;
}
void re_calc_size(node *n){
    if(!n) return;
    n->siz = 1 + get_sz(n->l) + get_sz(n->r);
}
void sum_re_calc(node *n){
    if(!n) return;
    n->sum = n->v + (n->l ? n->l->sum:0) + (n->r ? n->r->sum:0);
}
node *merge(node *l, node *r){
    if(!l || !r) return l?l:r;
    push(l); push(r);
    if(l->prio>=r->prio){
        l->r = merge(l->r, r);
        re_calc_size(l);
        sum_re_calc(l);
        return l;
    }else{
        r->l = merge(l, r->l);
        re_calc_size(r);
        sum_re_calc(r);
        return r;
    }
}
void split(node* curr, int k, node* &l, node* &r){
    if(!curr){l=nullptr; r=nullptr; return;}
    push(curr);
    if(get_sz(curr->l)>=k){
        split(curr->l, k, l, curr->l);
        r=curr;
        re_calc_size(r);
        sum_re_calc(r); 
        sum_re_calc(l);
    }else{
        split(curr->r, k-get_sz(curr->l)-1, curr->r, r);
        l=curr;
        re_calc_size(l); 
        sum_re_calc(l);
        sum_re_calc(r);
    }

}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    node* root = nullptr;
    for(int i = 1;i<=n;i++){ 
        int c; cin>>c;
        root = merge(root, new node(c));
    }
    while(m--){
        int t, a, b; cin>>t>>a>>b;
        if(t==1){
            node *l, *m1, *m, *r;
            split(root, a-1, l, m1);
            split(m1, b-a+1, m, r);
            m->rev=1;
            root = merge(l, m);
            root = merge(root, r);
        }else{
            node *l, *m1, *m, *r;
            split(root, a-1, l, m1);
            split(m1, b-a+1, m, r);
            cout<<m->sum<<' ';
            root = merge(l, m);
            root = merge(root, r);
        }
    }



    return 0;
}