#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node{public:
    int val; node* parent{nullptr};
    vector<node*> child;
    node(){}
    node(int x):val(x){}
    void resolve(node* par){
        child.erase(find(child.begin(), child.end(), par));
        parent=par;
        for(auto &i: child) i->resolve(this);
    }
    int depth{-1};
    void get_depth(){
        if(parent==nullptr) depth=0;
        else depth = parent->depth+1;
        for(auto i: child) i->get_depth();
    }
    int contrib{0}; bool f_c{false};
    void final(){
        if(f_c) return;
        for(auto i: child){
            i->final();
            contrib+=i->contrib;
        }
        f_c=true;
    }

};

void dfs(node* root, vector<int> &ids, vector<int> &depths, vector<int>& first_ooc){
    ids.push_back(root->val);
    depths.push_back(root->depth);
    if(first_ooc[root->val]==-1) first_ooc[root->val]=ids.size()-1;
    for(auto &i: root->child){
        dfs(i, ids, depths, first_ooc);
        ids.push_back(root->val);
        depths.push_back(root->depth);
    }
}

class segment_tree{public:
    int n; vector<pair<int, int>> arr;
    segment_tree(vector<int> &v){
        int n = v.size();
        int nn=1; 
        while(nn<n) nn=(nn<<1);
        this->n = nn;
        this->arr.resize(nn*2,{INT_MAX, 0});
        for(int i = 0;i<n;i++){
            this->arr[i+nn] = {v[i],i};
        }
        for(int i = nn-1;i>0;i--){
            int v1 = this->arr[2*i].first;
            int v2 = this->arr[2*i+1].first;
            if(v1<v2) arr[i]=arr[2*i];
            else arr[i]=arr[2*i+1];
        }
    }
    int get_min_ind(int a, int b){
        if(a>b){int t=a; a=b; b=t;}
        a+=n; b+=n;
        int ans_val=arr[a].first; int ans_ind=arr[a].second;
        while(a<=b){
            if(a%2==1){
                if(arr[a].first<ans_val){tie(ans_val, ans_ind)=arr[a];}
                a++;
            }
            if(b%2==0){
                if(arr[b].first<ans_val){tie(ans_val, ans_ind)=arr[b];}
                b--;
            }
            a/=2; b/=2;
        }
        return ans_ind;
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m; cin>>n>>m;
    vector<node*> v(n+1, nullptr);
    for(int i =1;i<=n;i++) v[i]= new node(i);
    for(int i =1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    for(auto i: v[1]->child) i->resolve(v[1]);
    v[1]->get_depth();

    vector<int> ids, depth, first_posn(n+1, -1);
    dfs(v[1], ids, depth, first_posn);

    segment_tree S(depth);
    while(m--){
        int a, b; cin>>a>>b;
        int ap = first_posn[a];
        int bp = first_posn[b];
        int lca_i = ap; 
        // for(int i =min(ap, bp);i<=max(ap, bp);i++){
        //     if(depth[lca_i]>depth[i]) lca_i=i;
        // }
        // int lca_b = S.get_min_ind(ap, bp);
        // if(lca_i!=lca_b) 
        //     cout<<"asdfg";
        lca_i = S.get_min_ind(ap, bp);
        int lca = ids[lca_i];
        v[a]->contrib++;
        v[b]->contrib++;
        v[lca]->contrib--;
        if(v[lca]->parent!=nullptr) v[lca]->parent->contrib--;
    }

    v[1]->final();
    for(int i =1;i<=n;i++){
        cout<<v[i]->contrib<<' ';
    }

    return 0;
}