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
    int n, m; cin>>n>>m;
    VI v(n);
    multi_ordered_set<int> mos;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        mos.insert(v[i]);
    }
    while(m--){
        char c; cin>>c;
        if(c=='!'){
            int p, x; cin>>p>>x;
            auto it = mos.find_by_order(mos.order_of_key(v[p-1]));
            mos.erase(it);
            mos.insert(x);
            v[p-1]=x;
        }else{
            int a, b; cin>>a>>b;
            int ans = mos.order_of_key(b+1)-mos.order_of_key(a);
            cout<<ans<<'\n';
        }
        // for(auto i: mos) cout<<i<<' ';cout<<'\n';
    }

    return 0;
}