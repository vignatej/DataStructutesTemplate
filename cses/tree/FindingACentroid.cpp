#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node{public:
    int id; node* par{nullptr};
    node(int x):id(x){}
    vector<node*> child;
    void resolve(node* parent){
        this->par = parent;
        if(par!=nullptr) child.erase(find(child.begin(), child.end(), parent));
        for(auto i: child) i->resolve(this);
    }
    int siz{0};
    void get_siz(){
        if(siz!=0) return;
        for(auto i: child){
            i->get_siz();
            siz+=i->siz;
        }
        siz++;
    }
};

bool calculate(int n, node* root){
    int max_permit = n/2;
    bool ya = true;
    for(auto i: root->child){
        if(i->siz>max_permit) ya=false;
    }
    if(n-(root->siz) > max_permit) ya=false;
    return ya;
}

signed main(){
    int n; cin>>n;
    vector<node*> v(n+1, nullptr);
    for(int i =1;i<=n;i++) v[i] = new node(i);
    for(int i = 1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    v[1]->resolve(nullptr);
    v[1]->get_siz();
    for(int i = 1;i<=n;i++){
        if(calculate(n, v[i])){
            cout<<i; break;
        }
    }


    return 0;
}