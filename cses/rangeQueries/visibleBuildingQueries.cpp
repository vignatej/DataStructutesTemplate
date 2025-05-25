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
        int nn = 1; while(nn<vs) nn=nn<<1;
        n=nn; arr.resize(2*n, VI(2, -1));
        for(int i =0;i<vs;i++){
            arr[i+n][0]=v[i]; arr[i+n][1]=i;
        }
        for(int i =n-1;i>0;i--){
            if(arr[2*i][0]>arr[2*i+1][0]) arr[i]=arr[2*i];
            else arr[i]=arr[2*i+1];
        }
    }
    VI get_max_index(int a, int b, int k, int x, int y){
        if(y<a || b<x) return {0, 0};
        if(a<=x && y<=b) return arr[k];
        int d = (x+y)/2;
        auto a1 = get_max_index(a, b, 2*k, x, d);
        auto a2 = get_max_index(a, b, 2*k+1, d+1, y);
        if(a1[0]>a2[0]) return a1;
        return a2;
    }
    VI maxIndex(int a, int b){
        return get_max_index(a, b, 1, 0, n-1);
    }
};

signed main(){
    int n, q; cin>>n>>q;
    VI v(n+1), ans(n+1, 0);
    for(int i = 0;i<n;i++) cin>>v[i]; v[n]=INT_MAX;
    vector<int> st{n};
    for(int i =n-1;i>=0;i--){
        while(st.back() && v[st.back()]<=v[i]) st.pop_back();
        ans[i]=ans[st.back()]+1;
        st.push_back(i);
    }
    v.pop_back(); ans.pop_back();
    segmentTree s(v);
    while(q--){
        int a, b; cin>>a>>b;
        int w = s.maxIndex(a-1, b-1)[1];
        cout<<ans[a-1]-ans[w]+1<<'\n';
    }

    return 0;
}