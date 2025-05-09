#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

class node{public:
    int id; int val; node* par{nullptr};
    vector<node*> child;
    node(){}
    node(int x, int y):id(x), val(y){}
    void resolve(node* par){
        if(par!=nullptr)
            child.erase(find(child.begin(), child.end(), par));
        this->par = par;
        for(auto i: child) i->resolve(this);
    }
    int size{1}; bool size_c{false};
    void calc_size(){
        if(size_c) return;
        for(auto i: child){
            i->calc_size();
            size+=i->size;
        }
        size_c=true;
    }
    int ts{val}; bool sum_c{false};
    void calc_sum(){
        if(sum_c) return;
        for(auto i: child){
            i->calc_sum();
            ts+=i->ts;
        }
        sum_c = 1;
    }

};

void dfs(node* root, vector<int> &ids, vector<int> &size, vector<int> &vals, vector<int> &r_id){
    ids.push_back(root->id);
    size.push_back(root->size);
    vals.push_back(root->val);
    r_id[root->id] = ids.size()-1;
    for(auto i: root->child) dfs(i, ids, size, vals, r_id);
}

class segment_tree{ public:
    int n; vector<int> arr;
    segment_tree(vector<int> &v){
        int n=v.size();
        int nn =1;
        while(nn<n) nn=nn<<1;
        this->n = nn;
        arr.resize(2*nn, 0);
        for(int i=0;i<n;i++) arr[i+nn]=v[i];
        for(int i = nn-1;i>0;i--) arr[i]=arr[2*i]+arr[2*i+1];
    }
    int calc_sum(int a, int b){
        if(a>b){int t= a; a=b; b=t;}
        a+=n; b+=n;
        int ans{0};
        while(a<=b){
            if(a%2==1){ans+=arr[a]; a++;}
            if(b%2==0){ans+=arr[b]; b--;}
            a/=2; b/=2;
        }
        return ans;
    }
    void cng_val(int posn, int val){
        posn+=n; arr[posn]=val; posn/=2;
        while(posn>0){
            arr[posn]=arr[2*posn]+arr[2*posn+1];
            posn/=2;
        }
    }
};

signed main(){
    int n, q; cin>>n>>q;
    vector<node*> v(n+1, nullptr);
    for(int i = 1;i<=n;i++){
        int val; cin>>val;
        v[i] = new node(i, val);
    }
    for(int i = 1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    v[1]->resolve(nullptr);
    v[1]->calc_size();
    vector<int> ids;
    vector<int> size;
    vector<int> vals;
    vector<int> r_id(n+1, 0);
    dfs(v[1], ids, size, vals, r_id);
    // vector<int> d_ts;
    // int stn{0};
    // for(auto &i: ts){
    //     d_ts.push_back(i-stn);
    //     stn=i;
    // }
    segment_tree S(vals);
    while(q--){
        int z1; cin>>z1;
        if(z1==1){
            int id; int val; cin>>id>>val;
            int posn = r_id[id];
            S.cng_val(posn, val);

        }else{
            int cn; cin>>cn;
            int posn = r_id[cn];
            int siz = size[posn];
            int ans = S.calc_sum(posn, posn+siz-1);
            cout<<ans<<'\n';
        }
    }




    return 0;
}