#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using multi_ordered_set = tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
#include <vector>
#include <set>

#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int n; cin>>n;
    VVI v(n);
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        v[i] = VI ({a, b, i});
    }
    sort(v.begin(), v.end(), [](VI &a, VI &b){
        return (a[1]!=b[1] ? a[1]<b[1]: a[0]>b[0]);
    });
    multi_ordered_set<int> os;
    VI ans1(n), ans2(n);
    os.insert(v[0][0]);
    for(int i =1;i<n;i++){
        int a{v[i][0]},b{v[i][1]}, c{v[i][2]};
        int index = os.order_of_key(a);
        int od = i-index;
        ans1[c]=od;
        os.insert(a);
    }
    for(auto i: ans1) cout<<i<<' '; cout<<'\n';
    sort(v.begin(), v.end(), [](VI &a, VI &b){
        return (a[1]!=b[1] ? a[1]>b[1]: a[0]<b[0]);
    });
    os.clear();
    // s.insert(v[0][0]);
    os.insert(v[0][0]);
    for(int i =1;i<n;i++){
        int a{v[i][0]},b{v[i][1]}, c{v[i][2]};
        // auto it = s.upper_bound(a);
        // int d = distance(s.begin(), it);
        // ans2[c]=d;
        // s.insert(a);
        int ca = os.order_of_key(a+1);
        ans2[c] = ca;
        os.insert(a);
    }
    for(auto i: ans2) cout<<i<<' '; cout<<'\n';
    
    return 0;
}