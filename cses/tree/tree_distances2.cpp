#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

class node{ public:
    int val; node* par{nullptr};
    vector<node*> child;
    node(int n):val(n){}
    void set_parent(node* par){
        this->par = par;
        if(par!=nullptr)
            child.erase(find(child.begin(), child.end(), par));
        for(auto i: child) i->set_parent(this);
    }
    vector<int> sub_tree_sizes;
    int tsiz{1};
    int get_sizes(){
        for(auto &i: child) sub_tree_sizes.push_back(i->get_sizes());
        for(auto i: sub_tree_sizes) tsiz+=i;
        return tsiz;
    }
    vector<int> sub_tree_sum;
    int tsum{0};
    void first(){

        for(auto &i: child){
            i->first();
            sub_tree_sum.push_back(i->tsum);
        }
        tsum=accumulate(sub_tree_sum.begin(), sub_tree_sum.end(), (ll)0ll);
        tsum+=tsiz-1;
    }
    int second(int n){
        if(par==nullptr){
            for(auto i: child) i->second(n);
            return tsum;
        }
        tsum = tsum+par->tsum-tsum-tsiz+n-tsiz;
        for(auto i: child) i->second(n);
        return tsum;
    }    
    

};


signed main(){
    int n; cin>>n;
    vector<node*> v(n+1, nullptr);
    for(int i = 1;i<=n;i++) v[i]=new node(i);
    for(int i=1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    v[1]->set_parent(nullptr);
    v[1]->get_sizes();
    v[1]->first();
    v[1]->second(n);
    for(int i=1;i<=n;i++) cout<<v[i]->tsum<<' ';
    return 0;
}