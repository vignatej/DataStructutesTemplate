#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node{public:
    int val; node* par;
    vector<node*> child;
    node(int x): val(x){}
    node(){}
    int depth{-1};
    void calc_depth(){
        depth = par->depth + 1;
        for(auto &i: child) i->calc_depth();
    }
};

void dfs(node* root, vector<int> &ids, vector<int> &depths, vector<int> &first_app){
    if(!root) return;
    ids.push_back(root->val);
    depths.push_back(root->depth);
    if(first_app[root->val]==0) first_app[root->val]=ids.size()-1;
    for(auto i: root->child){
        dfs(i, ids, depths, first_app);
        ids.push_back(root->val);
        depths.push_back(root->depth);        
    }
}

class segment_tree{public:
    int n;
    vector<pair<int, int>> arr;
    segment_tree(vector<int> &arr){
        int n = arr.size();
        int nn=1;
        while(nn<n) nn=nn<<1;
        this->n = nn;
        this->arr.resize(nn*2, {INT_MAX, 0});
        for(int i = nn;i<nn+n;i++) this->arr[i]={arr[i-nn], i-nn};
        for(int i = nn-1;i>0;i--){
            int c1 = this->arr[2*i].first; int p1 = this->arr[2*i].second;
            int c2 = this->arr[2*i+1].first; int p2 = this->arr[2*i+1].second;
            if(c1<c2){this->arr[i]=this->arr[2*i];}
            else{this->arr[i]=this->arr[2*i+1];}
        }
    }
    #define F first
    #define S second
    int find_min_ind(int a, int b){
        if(a>b){int t=a; a=b; b=t;}
        a+=n; b+=n;
        int ans_val = INT_MAX; int ans_ind = -1;
        while(a<=b){
            if(a%2==1){
                if(ans_val>arr[a].F){ans_val=arr[a].F; ans_ind=arr[a].S;}
                a++;
            }if(b%2==0){
                if(ans_val>arr[b].F){ans_val=arr[b].F; ans_ind=arr[b].S;}
                b--;
            }
            a/=2; b/=2;
        }
        return ans_ind;
    }
    #undef F
    #undef S
};

signed main(){
    int n, q; cin>>n>>q;
    vector<node*> v(n+1, nullptr);
    for(int i = 1;i<=n;i++) v[i] = new node(i);
    for(int i = 2;i<=n;i++){
        int par; cin>>par;
        v[par]->child.push_back(v[i]);
        v[i]->par = v[par];
    }
    v[1]->depth = 0;
    for(auto i: v[1]->child) i->calc_depth();
    vector<int> ids, depths;
    vector<int> first_app(n+1, 0);
    dfs(v[1], ids, depths, first_app);
    segment_tree S(depths);
    while(q--){
        int a, b; cin>>a>>b;
        int d1 = first_app[a];
        int d2 = first_app[b];
        // int min_dep_id = d1;
        // for(int i = min(d1, d2); i<=max(d1, d2);i++)
        //     if(depths[min_dep_id]>depths[i]) min_dep_id=i;
        // cout<<ids[min_dep_id]<<' ';
        int ind = S.find_min_ind(d1, d2);
        cout<<ids[ind]<<' ';

    }
    

    return 0;
}

// int ancestor(int x, int k, vector<vector<int>> table){
//     int ans = x;
//     for(int i=0;i<32;i++){
//         if(!(k&(1<<i))) continue;
//         ans = table[ans][i];
//         if(ans==0) continue;
//     }
//     return ans;
// }

// signed main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("in.txt", "r", stdin);
//         freopen("out.txt", "w", stdout);
//     #endif
//     int n, q; cin>>n>>q;
//     vector<vector<int>> v(n+1, vector<int>(32, 0));
//     map<int, vector<int>> childs;
//     for(int i =2;i<=n;i++){
//         int i_p; cin>>i_p;
//         v[i][0]=i_p;
//         childs[i_p].push_back(i);
//     }
//     for(int j=1;j<30;j++){
//         for(int i=1;i<=n;i++){
//             int by2 = v[i][j-1];
//             if(by2==0) continue;
//             v[i][j] = v[by2][j-1];
//         }
//     }
//     vector<int> curr{1}; int ch{1};
//     vector<int> hts(n+1, INT_MAX);
//     while(curr.size()){
//         vector<int> next;
//         for(auto &i: curr){
//             hts[i]=ch;
//             copy(childs[i].begin(), childs[i].end(), back_inserter(next));
//         }
//         ch++; curr=next;
//     }
//     while(q--){
//         int a, b; cin>>a>>b;
//         int ha = hts[a]; int hb = hts[b];
//         if(hts[a]!=hts[b]){
//             if(hts[a]<hts[b]){
//                 b = ancestor(b, hts[b]-hts[a], v);
//             }else{
//                 a = ancestor(a, hts[a]-hts[b], v);
//             }
//         }
//         int s{0}, e{min(ha, hb)-1};
//         int ans{1}; 
//         while(s<=e){
//             int m = (s+e)/2;
//             int aa = ancestor(a, m, v);
//             int ba = ancestor(b, m, v);
//             if(aa==ba){
//                 if(hts[ans]<hts[aa]) ans=aa;
//                 e=m-1;
//             }else{
//                 s=m+1;
//             }
//         }
//         cout<<ans<<'\n';
//     }


//     return 0;
// }