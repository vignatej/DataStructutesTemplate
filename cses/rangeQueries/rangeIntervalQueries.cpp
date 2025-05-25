#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using multi_ordered_set = tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, q; cin>>n>>q;
    VI v(n); for(int i =0;i<n;i++) cin>>v[i];
    // cout<<v[2];
    int bs = sqrt(n);
    if(bs*bs<n) bs++;
    vector<multi_ordered_set<int>> v_mos(bs+1);
    for(int i =0;i<n;i++){
        v_mos[i/bs].insert(v[i]);
    }
    while(q--){
        int a, b, c, d; cin>>a>>b>>c>>d;
        a--; b--;
        int ab = a/bs;
        int bb = b/bs;
        int ans{0};
        for(int i = a;i<bs*(ab+1) && i<=b;i++) 
            if(c<=v[i] && v[i]<=d) ans++;
        for(int i = ab+1;i<bb;i++){
            int it1 = v_mos[i].order_of_key(c);
            int it2 = v_mos[i].order_of_key(d+1);
            ans+=it2-it1;
        }
        for(int i = bb*bs;bb>ab && i<=b;i++) 
            if(c<=v[i] && v[i]<=d) ans++;
        cout<<ans<<'\n';
    }

    return 0;
}