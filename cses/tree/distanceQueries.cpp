#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node{public:
    int val; node* parent{nullptr};
    vector<node*> child;
    node(int x):val(x){}
    node(){}
    void resolve(node* par){
        child.erase(find(child.begin(), child.end(), par));
        this->parent = par;
        for(auto &i: child) i->resolve(this);
    }
    int depth{-1};
    void get_depth(){
        if(parent!=nullptr) depth = parent->depth+1;
        else depth=0;
        for(auto &i: child) i->get_depth();
    }
};

void dfs(node* root, vector<int> &ids, vector<int> &depths, vector<int> &first_ind){
    ids.push_back(root->val);
    depths.push_back(root->depth);
    if(first_ind[root->val]==0) first_ind[root->val]=ids.size()-1;
    for(auto i: root->child){
        dfs(i, ids, depths, first_ind);
        ids.push_back(root->val);
        depths.push_back(root->depth);
    }
};

class segment_tree{public:
    int n; vector<pair<int, int>> arr;
    segment_tree(vector<int> &arr){
        int n = arr.size();
        int nn = 1;
        while(nn<n) nn=nn<<1;
        this->n = nn; 
        this->arr.resize(2*nn, {INT_MAX, 0});
        for(int i = 0;i<n;i++) this->arr[i+nn]={arr[i], i};
        for(int i = nn-1;i>0;i--){
            int v1 = this->arr[2*i].first;
            int v2 = this->arr[2*i+1].first;
            if(v1<v2) this->arr[i]=this->arr[2*i];
            else this->arr[i]=this->arr[2*i+1];
        }
    }
    int get_min_ind(int a, int b){
        if(a>=b){int t = b; b=a;a=t;}
        a+=n; b+=n;
        int ans_val = arr[a].first; int ans_ind=arr[a].second;
        while(a<=b){
            if(a%2==1){
                if(ans_val>arr[a].first){
                    ans_val=arr[a].first; ans_ind=arr[a].second;
                }
                a++;
            }
            if(b%2==0){
                if(ans_val>arr[b].first){
                    ans_val=arr[b].first;
                    ans_ind=arr[b].second;
                }
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
    int n, q; cin>>n>>q;
    vector<node*> v(n+1, nullptr);
    for(int i = 1;i<=n;i++) v[i]=new node(i);
    for(int i =1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    for(auto &i: v[1]->child) i->resolve(v[1]);
    v[1]->get_depth();
    vector<int> ids, depths, first_ind(n+1, 0);
    dfs(v[1], ids, depths, first_ind);
    segment_tree S(depths);
    while(q--){
        int a, b; cin>>a>>b;
        int a_i = first_ind[a];
        int b_i = first_ind[b];
        int min_dep_ind = a_i;
        min_dep_ind=S.get_min_ind(a_i, b_i);
        // for(int i = min(a_i, b_i);i<=max(a_i, b_i);i++)
        //     if(depths[min_dep_ind]>depths[i]) min_dep_ind = i;
        cout<<(depths[a_i]+depths[b_i]-2*depths[min_dep_ind])<<'\n';

    }

    return 0;
}