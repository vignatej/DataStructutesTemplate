#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(){
    int n, k; cin>>n>>k;
    if(k==0){
        for(int i =1;i<=n;i++) cout<<i<<' ';
        return 0;
    }
    ordered_set<int> s;
    for(int i =1;i<=n;i++) s.insert(i);
    int cp = -1;int cs = s.size();
    while(s.size()>0){
        cp+=k; cs=s.size(); cp%=cs;
        auto it = s.find_by_order(cp);
        cout<<(*it)%n+1<<' ';
        s.erase(it);
    }

    return 0;
}