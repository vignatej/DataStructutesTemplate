#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class segment_tree_min_index{ public:
    VVI arr; int n;
    segment_tree_min_index(VI &v){
        int vs = v.size();
        n=1; while(n<vs) n=n<<1;
        arr.resize(2*n, {INT_MAX,0});
        for(int i = 0;i<vs;i++) arr[n+i]={v[i], i};
        for(int i = n-1;i>0;i--){
            arr[i]=min(arr[2*i], arr[2*i+1]);
        }
    }
    int get_min_index(int a, int b){
        a+=n; b+=n;
        int ans_v = INT_MAX; int ans_ind = -1;
        while(a<=b){
            if(a%2==1){
                if(ans_v>arr[a][0]){ans_v = arr[a][0]; ans_ind = arr[a][1];}
                a++;
            }if(b%2==0){
                if(ans_v>arr[b][0]){ans_v = arr[b][0]; ans_ind = arr[b][1];}
                b--;
            }
            a/=2; b/=2;
        }
        return ans_ind;
    }
};

class segment_tree_max_index{ public:
    VVI arr; int n;
    segment_tree_max_index(VI &v){
        int vs = v.size();
        n=1; while(n<vs) n=n<<1;
        arr.resize(2*n, {-1,0});
        for(int i = 0;i<vs;i++) arr[n+i]={v[i], i};
        for(int i = n-1;i>0;i--){
            arr[i]=max(arr[2*i], arr[2*i+1]);
        }
    }
    int get_max_index(int a, int b){
        a+=n; b+=n;
        int ans_v = -1; int ans_ind = -1;
        while(a<=b){
            if(a%2==1){
                if(ans_v<arr[a][0]){ans_v = arr[a][0]; ans_ind = arr[a][1];}
                a++;
            }if(b%2==0){
                if(ans_v<arr[b][0]){ans_v = arr[b][0]; ans_ind = arr[b][1];}
                b--;
            }
            a/=2; b/=2;
        }
        return ans_ind;
    }
};

signed main(){
    int n; cin>>n;
    VI v(n); for(int i = 0;i<n;i++) cin>>v[i];
    VI inc(n, 0), dec(n, 0);
    for(int i = 1;i<n;i++){
        if(v[i-1]<=v[i]) inc[i]=inc[i-1]+1;
        if(v[i-1]>=v[i]) dec[i]=dec[i-1]+1;
    }
    segment_tree_min_index s_min(v);
    segment_tree_max_index s_max(v);
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        l--; r--;
        if(v[l]>v[r]){
            int ma_i = s_max.get_max_index(l, r);
            int mi_i = s_min.get_min_index(l, r);
            if(
                ma_i-l == inc[ma_i]-inc[l] && 
                mi_i-ma_i==dec[mi_i]-dec[ma_i] && 
                r-mi_i==inc[r]-inc[mi_i]
            ){cout<<"YES\n";}
            else{cout<<"NO\n";}
        }else{
            int ma_i = s_max.get_max_index(l, r);
            int mi_i = s_min.get_min_index(l, r);
            if(
                mi_i-l == dec[mi_i]-dec[l] && 
                ma_i-mi_i==inc[ma_i]-inc[mi_i] && 
                r-ma_i==dec[r]-dec[ma_i]
            ){cout<<"YES\n";}
            else{cout<<"NO\n";}
        }
    }
    return 0;
}