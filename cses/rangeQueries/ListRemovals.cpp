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
    int n; cin>>n;
    VI v(n); for(int i =0;i<n;i++) cin>>v[i];
    multi_ordered_set<pair<int, int>> mos;
    for(int i =0;i<n;i++){
        mos.insert({i, v[i]});
    }
    for(int i = 0;i<n;i++){
        int p; cin>>p;
        auto it = mos.find_by_order(p-1);
        cout<<(*it).second<<' ';
        mos.erase(it);
    }

    return 0;
}