#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
class segment_tree{ public:
    VVI arr; int n;
    segment_tree(VI &v){
        int vs=v.size();
        int nn=1; while(nn<vs) nn=nn<<1;
        n=nn;
        arr.resize(2*nn, VI(2, 0));
        for(int i = 0;i<vs;i++){
            arr[i+nn][0]=v[i];
            arr[i+nn][1]=i;
        }
        for(int i=nn-1;i>0;i--){
            if(arr[2*i][0]<=arr[2*i+1][0]) arr[i]=arr[2*i+1];
            else arr[i]=arr[2*i];
        }
    }
    int get_max_ind(int a, int b){
        a+=n; b+=n;
        int ans = 0; int ans_i = -1;
        while(a<=b){
            if(a%2==1){
                if(ans<arr[a][0]){ans=arr[a][0]; ans_i = arr[a][1];}
                a++;
            }
            if(b%2==0){
                if(ans<=arr[b][0]){ans=arr[b][0]; ans_i = arr[b][1];}
                b--;
            }
            a/=2; b/=2;
        }
        return ans_i;
    }
};
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, q; cin>>n>>q;
    VI arr(n), v(n+1, 0), ps(n+1, 0);
    for(int i = 0;i<n;i++){ cin>>arr[i];ps[i+1]=ps[i]+arr[i];}
    arr.PB(INT_MAX); VI s{n};
    for(int i = n-1;i>=0;i--){
        while(arr[s.back()]<arr[i]) s.pop_back();
        v[i]=v[s.back()]+(s.back()-i)*arr[i]-(ps[s.back()]-ps[i]);
        s.PB(i);
    }
    arr.pop_back();
    segment_tree st(arr);
    while(q--){
        int a, b; cin>>a>>b; a--; b--;
        int mi = st.get_max_ind(a, b);
        int ans = v[a]-v[mi]+(b-mi+1)*arr[mi]-(ps[b+1]-ps[mi]);
        cout<<ans<<'\n';
    }

    return 0;
}