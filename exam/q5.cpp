#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;


using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back




const int MN = 998244353;

int powl(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    int ans = powl(a, b/2);
    ans = (ans*ans)%MN;
    if(b%2) ans=(ans*a)%MN;
    return ans;
}

int calc_inv(int a){
    return powl(a, MN-2);
}

class node{public:
    int v;
    node *l{nullptr}, *r{nullptr};
    int prio; int siz{1};
    int sum{0};
    bool rev{false};
    node(int v):v(v), sum(v){
        prio=rand();
    }
};
void push(node* n){
    if(!n) return;
    if(!(n->rev)) return;
    swap(n->l, n->r);
    if(n->l) n->l->rev^=1;
    if(n->r) n->r->rev^=1;
    n->rev=0;
}
int get_sz(node* n){
    return n? n->siz:0;
}
void re_calc_size(node *n){
    if(!n) return;
    n->siz = 1 + get_sz(n->l) + get_sz(n->r);
}
void sum_re_calc(node *n){
    if(!n) return;
    n->sum = n->v + (n->l ? n->l->sum:0) + (n->r ? n->r->sum:0);
}
node *merge(node *l, node *r){
    if(!l || !r) return l?l:r;
    push(l); push(r);
    if(l->prio>=r->prio){
        l->r = merge(l->r, r);
        re_calc_size(l);
        sum_re_calc(l);
        return l;
    }else{
        r->l = merge(l, r->l);
        re_calc_size(r);
        sum_re_calc(r);
        return r;
    }
}
void split(node* curr, int k, node* &l, node* &r){
    if(!curr){l=nullptr; r=nullptr; return;}
    push(curr);
    if(get_sz(curr->l)>=k){
        split(curr->l, k, l, curr->l);
        r=curr;
        re_calc_size(r);
        sum_re_calc(r); 
        sum_re_calc(l);
    }else{
        split(curr->r, k-get_sz(curr->l)-1, curr->r, r);
        l=curr;
        re_calc_size(l); 
        sum_re_calc(l);
        sum_re_calc(r);
    }
}




int solve(int ap, node*root, ordered_set<int> &os){
    int bp = ap+1;
    int ns = 0; 
    // for(int i = bp+1;i<v.size();i++) ns+=v[i];
    node *l, *r;
    split(root, bp+1, l, r);
    if(r) ns = r->sum;
    root = merge(l, r);
    int vbp = *os.find_by_order(bp);
    int ans1 = ns-(os.size()-bp-1)*vbp;

    bp = ap-1;
    ns=0;
    // for(int i = 0;i<bp;i++) ns+=v[i];
    split(root, bp, l, r);
    if(l) ns = l->sum;
    root = merge(l, r);
    vbp = *os.find_by_order(bp);
    int ans2 = bp*vbp-ns;
    return max(ans1, ans2);
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n; cin>>n;
    ordered_set<int> os;
    vector<int> v(2);
    cin>>v[0]>>v[1]; sort(v.begin(), v.end()); 
    os.insert(v[0]); os.insert(v[1]);

    node* root = nullptr;
    for(auto i: v) root = merge(root, new node(i));

    vector<int> ans;
    for(int i = 2;i<n;i++){
        int cv; cin>>cv;
        // int d = distance(v.begin(), lower_bound(v.begin(), v.end(), cv));
        // v.insert(next(v.begin(), d), cv);
        
        int d = os.order_of_key(cv);
        os.insert(cv);
        
        node *ln, *rn;
        split(root, d, ln, rn);
        root = merge(ln, new node(cv));
        root = merge(root, rn);

        int l{1}, r{i-1};
        int mv = 1e18;
        while(l<=r){
            int m1 = l+(r-l)/3;
            int m2 = r-(r-l)/3;

            int m1v = solve(m1, root, os);
            int m2v = solve(m2, root, os);
            if(m1v<=m2v){
                r=m2-1;
                mv = min(mv, m1v);
            }else{
                l=m1+1;
                mv=min(mv, m2v);
            }
        }
        int invv = calc_inv(i-1);
        int cans = ((mv%MN)*(invv%MN))%MN;
        ans.push_back(cans);

    }
    for(auto i: ans) cout<<i<<'\n';
    return 0;
}