#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
class node{ public:
    int id; int val;
    node* parent{nullptr};
    vector<node*> child;
    node(int id, int val): id(id), val(val){}
    void resolve(node* par){
        this->parent = par;
        if(par!=nullptr)
            child.erase(find(child.begin(), child.end(), parent));
        for(auto i: child) 
            i->resolve(this);
    }
    int ps{0};
    void calc_path_sum(){
        ps=val;
        if(parent!=nullptr) ps+=parent->ps;
        for(auto i: child) i->calc_path_sum();
    }
    int siz{1}; bool s_c{false};
    void calc_size(){
        if(s_c) return;
        for(auto &i: child){
            i->calc_size();
            siz+=i->siz;
        }
        s_c=true;
    }

};

void dfs(node* root, vector<int> &ids, vector<int> &sizes, vector<int> &ps, vector<int> &r_id, vector<int> &vals){
    ids.push_back(root->id);
    sizes.push_back(root->siz);
    vals.push_back(root->val);
    ps.push_back(root->ps);
    r_id[root->id] = ids.size()-1;
    for(auto &i: root->child) dfs(i, ids, sizes, ps, r_id, vals);
}

class segment_tree{public:
    int n; vector<int> v;
    segment_tree(vector<int> arr){
        int n = arr.size();
        int nn=1;
        while(nn<n) nn=(nn<<1);
        this->n = nn;
        v.resize(2*nn, 0);
        for(int i = 0;i<n;i++) v[i+nn]=arr[i];
        for(int i = nn-1;i>0;i--) v[i]=v[2*i]+v[2*i+1];
    }
    int calc_sum(int a, int b){
        if(a>b) swap(a, b);
        a+=n; b+=n;
        int ans{0};
        while(a<=b){
            if(a%2==1){ans+=v[a]; a++;}
            if(b%2==0){ans+=v[b]; b--;}
            a/=2; b/=2;
        }
        return ans;
    }
    void inc_element(int posn, int x){
        posn+=n; v[posn]+=x; posn/=2;
        while(posn>0){
            v[posn]=v[2*posn]+v[2*posn+1];
            posn/=2;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, q; cin>>n>>q;
    vector<node*> v(n+1, nullptr);
    for(int i =1;i<=n;i++){
        int val; cin>>val;
        v[i] = new node(i, val);
    }
    for(int i =1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    v[1]->resolve(nullptr);
    v[1]->calc_path_sum();
    v[1]->calc_size();
    vector<int> ids, sizes, paths_sums, r_ids(n+1, 0), vals;
    dfs(v[1], ids, sizes, paths_sums, r_ids, vals);
    vector<int> d_a;
    int stn = 0;
    for(auto i: paths_sums){
        d_a.push_back(i-stn);
        stn=i;
    }
    d_a.push_back(0);
    segment_tree S(d_a);
    while(q--){
        int z1; cin>>z1;
        if(z1==1){
            int x, v; cin>>x>>v;
            int posn = r_ids[x];
            int inc = v-vals[posn];
            // for(int i = posn;i<posn+sizes[posn];i++)
            //     paths_sums[i]+=inc;
            vals[posn]+=inc;
            S.inc_element(posn, inc);
            S.inc_element(posn+sizes[posn], -1*inc);

        }else{
            int x; cin>>x;
            int posn = r_ids[x];
            // cout<<paths_sums[posn]<<'\n';
            cout<<S.calc_sum(0, posn)<<'\n';
        }
    }



    return 0;
}