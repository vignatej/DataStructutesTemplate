#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node{ public:
    int val; node* par{nullptr};
    vector<node*> child;
    node(int x): val(x){}
    int a{-1}, b{-1};
    void get_hts(int par){
        if(a!=-1) return;
        priority_queue<int> pq;
        for(auto &i: child){
            if(i->val==par){this->par=i;continue;}
            i->get_hts(val);
            pq.push(-1*(i->a)-1);
            if(pq.size()>2) pq.pop();
        }
        if(pq.size()==0){a=0; b=0;}
        else if(pq.size()==1){a=-1*pq.top(); b=0;}
        else{b=-1*pq.top(); pq.pop(); a=-1*pq.top();}
    }
    int get_ans(){
        if(par==nullptr){
            for(auto i: child) if(i!=par) i->get_ans();
            return a;
        }
        int par_side_ans{0};
        if(par->a==a+1){
            par_side_ans=par->b+1;
        }else{
            par_side_ans=par->a+1;
        }
        if(par_side_ans>=a){b=a; a=par_side_ans;}
        else if(par_side_ans>=b){b=par_side_ans;}
        for(auto i: child) if(i!=par) i->get_ans();
        return a;
    }

};

signed main(){
    int n; cin>>n;
    vector<node*> v(n+1, nullptr);
    for(int i = 1; i<=n;i++) v[i]=new node(i);
    for(int i = 1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    v[1]->get_hts(-1);
    v[1]->get_ans();
    for(int i=1;i<=n;i++) cout<<v[i]->a<<' ';

    return 0;
}