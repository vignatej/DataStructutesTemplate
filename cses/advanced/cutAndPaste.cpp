#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class node{ public:
    char v;
    node* l{nullptr}; node* r{nullptr};
    int priority, size{1};
    node(char c){
        v=c;
        priority=rand();
    }
};

int get_size(node* n){
    if(!n) return 0;
    return n->size;
}
void update_size(node* n){
    if(!n) return;
    n->size = 1 + get_size(n->l) + get_size(n->r);
}

node* merge(node* l, node* r){
    if(!l || !r) return l?l:r;
    if(l->priority >= r->priority){
        l->r = merge(l->r, r);
        update_size(l);
        return l;
    }else{
        r->l = merge(l, r->l);
        update_size(r);
        return r;
    }
}

void split(node* curr, node* &l, node* &r, int k){
    if(!curr){l=nullptr; r=nullptr; return;}
    if(get_size(curr->l)>=k){
        split(curr->l, l, curr->l, k);
        r=curr;
        update_size(r);
    }else{
        split(curr->r, curr->r, r, k-get_size(curr->l)-1);
        l=curr;
        update_size(l);
    }

}

void print_node(node* n){
    if(!n) return;
    print_node(n->l);
    cout<<n->v;
    print_node(n->r);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    string s; cin>>s;

    node* root = nullptr;
    for(auto &i: s){
        root = merge(root, new node(i));
    }

    while(m--){
        int a, b; cin>>a>>b;
        node *l, *mr1, *mr2, *r;
        split(root, l, mr1, a-1);
        split(mr1, mr2, r, b-a+1); 
        root = merge(l, r);
        root = merge(root, mr2);
    }
    print_node(root);

    return 0;
}