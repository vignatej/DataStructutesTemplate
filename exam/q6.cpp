#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using multi_ordered_set = tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

void solve(int n, int s, int x, VI &v){
    VI pme(n+1, 0), nm(n+1, n+1);
    vector<int> st{0};
    for(int i = 1;i<=n;i++){
        while(v[st.back()]<v[i]) st.pop_back();
        pme[i]=st.back();
        st.PB(i);
    }
    st.clear();
    st.PB(n+1);
    for(int i = n;i>0;i--){
        while(v[st.back()]<=v[i]) st.pop_back();
        nm[i]=st.back();
        st.PB(i);
    }
    VI ps{0};
    for(int i = 1;i<=n;i++) ps.PB(ps.back()+v[i]);
    // multi_ordered_set<pair<int, int>> np;
    set<int> np; map<int, int> fc;
    int nps{-1}, npe{-1};
    int ans{0};
    for(int i =1;i<=n;i++){
        if(v[i]!=x) continue;
        if(npe<i){
            np.clear(); fc.clear();
            for(int j = i;j<nm[i];j++){ 
                np.insert(ps[j]); fc[ps[j]]++;
            }
            nps=i; npe=nm[i]-1;
        }else{
            while(nps<i){
                // np.erase(np.find({ps[nps], nps}));
                fc[ps[nps]]--;
                if(fc[ps[nps]]==0) np.erase(ps[nps]); 
                nps++;
            }
            for(int j = npe+1;j<nm[i];j++) {
                np.insert(ps[j]); fc[ps[j]]++;
                // np.insert({ps[j], j});
            }
            npe=nm[i]-1;
        }
        for(int j = pme[i]+1;j<=i;j++){
            int cs = ps[i]-ps[j-1];
            int rs = s-cs;
            rs+=ps[i];
            // int rsp = np.order_of_key({rs, -1});
            // // if(rsp<np.size() && (*np.find_by_order(rsp))[0]==rs) {
            //     ans += np.order_of_key({rs+1, -1}) - np.order_of_key({rs, -1});
            // // }
            ans+=fc[rs];
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    int T; cin>>T;
    while(T--){
        int n, s, x; cin>>n>>s>>x;
        VI v(n+1, LLONG_MAX);
        for(int i =1;i<=n;i++) cin>>v[i];
        v.PB(LLONG_MAX);
        solve(n, s, x, v);

    }

    return 0;
}