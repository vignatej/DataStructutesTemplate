#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;

#include <vector>
#include <set>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using multi_ordered_set = tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


signed main(){
    int n, x; cin>>n>>x;
    VI v(n), ps(n+1);
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v[i]=a; ps[i+1]=ps[i]+a;
    }
    multiset<int> s{ps[n]};
    multi_ordered_set<int> mos;
    mos.insert(ps[n]);
    int ans{0};
    for(int i =n-1;i>=0;i--){
        int rs = ps[i]+x;
        // int d = distance(s.lower_bound(rs), s.upper_bound(rs));
        // ans+=d;
        // s.insert(ps[i]);
        int d = mos.order_of_key(rs+1)-mos.order_of_key(rs);
        ans+=d;
        mos.insert(ps[i]);
    }
    cout<<ans;

    return 0;
}