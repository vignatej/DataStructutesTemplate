#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class node{public:
    char v;
    node *l{nullptr}, *r{nullptr};
    int prio, siz{1};
    bool rev{false};
    node(char v):v(v){
        prio = rand();
    }
};

void push(node* n){
    if(!n->rev) return;
    swap(n->l, n->r);
    if(n->l) n->l->rev^=1; 
    if(n->r) n->r->rev^=1;
    n->rev=0;
}

int get_sz(node* n){
    return n ? n->siz:0;
}
void re_calc_siz(node* n){
    if(!n) return;
    n->siz = 1+get_sz(n->l)+get_sz(n->r);
}

node* merge(node *l, node *r){
    if(!l || !r) return l?l:r;
    push(l); push(r);
    if(l->prio>=r->prio){
        l->r=merge(l->r, r);
        re_calc_siz(l);
        return l;
    }else{
        r->l=merge(l, r->l);
        re_calc_siz(r);
        return r;
    }
}

void split(node* n, int k, node* &l, node* &r){
    if(!n){l=nullptr; r=nullptr; return;}
    push(n);
    if(get_sz(n->l)>=k){
        split(n->l, k, l, n->l);
        r=n;
        re_calc_siz(r); 
        // re_calc_siz(l);
    }else{
        split(n->r, k-get_sz(n->l)-1, n->r, r);
        l=n;
        // re_calc_siz(r); 
        re_calc_siz(l);
    }
}

void output(node* n){
    if(!n) return;
    push(n);
    output(n->l);
    cout<<n->v;
    output(n->r);
}

signed main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int n, m; cin>>n>>m;
    string s; cin>>s;
    node* root{nullptr};
    for(auto &i: s){
        root = merge(root, new node(i));
    }
    while(m--){
        int a, b; cin>>a>>b;
        node *l, *m1, *mid, *r;
        split(root, a-1, l, m1);
        split(m1, b-a+1, mid, r);
        mid->rev=1;
        root = merge(l, mid);
        root = merge(root, r);
    }
    output(root);
    return 0;
}