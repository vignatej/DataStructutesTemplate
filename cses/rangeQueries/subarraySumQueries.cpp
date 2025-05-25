#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class segmentTree{ public:
    VVI arr; int n;
    segmentTree(VI &v){
        int vs = v.size();
        int nn=1; while(nn<vs) nn=nn<<1;
        n=nn; arr.resize(2*nn, VI (4, 0));
        for(int i =0;i<vs;i++){
            arr[i+nn][0]=v[i];
            arr[i+nn][1]=v[i];
            arr[i+nn][2]=v[i];
            arr[i+nn][3]=v[i];
        }
        // 0->sum, 1->max, 2->suffix, 3->prefix
        for(int i =nn-1;i>0;i--){
            arr[i][0]=arr[2*i][0]+arr[2*i+1][0];
            arr[i][1]=max({arr[2*i][1], arr[2*i+1][1], arr[2*i][2]+arr[2*i+1][3]});
            arr[i][2]=max(arr[2*i+1][2], arr[2*i][2]+arr[2*i+1][0]);
            arr[i][3]=max(arr[2*i][3], arr[2*i][0]+arr[2*i+1][3]);
        }
    }
    void update(int posn, int val){
        posn+=n;
        arr[posn][0]=val;arr[posn][1]=val;arr[posn][2]=val;arr[posn][3]=val;
        posn/=2;
        while(posn){
            int i = posn;
            arr[i][0]=arr[2*i][0]+arr[2*i+1][0];
            arr[i][1]=max({arr[2*i][1], arr[2*i+1][1], arr[2*i][2]+arr[2*i+1][3]});
            arr[i][2]=max(arr[2*i+1][2], arr[2*i][2]+arr[2*i+1][0]);
            arr[i][3]=max(arr[2*i][3], arr[2*i][0]+arr[2*i+1][3]);
            posn/=2;
        }
    }

};

signed main(){
    int n, q; cin>>n>>q;
    VI v(n); for(int i =0;i<n;i++) cin>>v[i];
    segmentTree s(v);
    while(q--){
        int posn; int val; cin>>posn>>val;
        posn--;
        s.update(posn, val);
        cout<<max(s.arr[1][1], 1ll*0)<<'\n';
    }
    return 0;
}