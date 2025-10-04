#include <bits/stdc++.h>
using namespace std;
class Two_Dim_2dSegmentTree{ public:
    #define ll long long
    #define int ll
    #define VVI vector<vector<int>>
    #define VI vector<int>
    #define PB push_back
    VVI arr; int n, m;
    Two_Dim_2dSegmentTree(VVI v){
        int vr=v.size(); int vc = v[0].size();
        int nn = 1; while(nn<vr) nn=nn<<1;
        n=nn;
        int mm=1; while(mm<vc) mm=mm<<1;
        m=mm;
        arr.resize(2*n, VI(2*m, 0));
        for(int i = 0;i<vr;i++){
            for(int j = 0;j<vc;j++) arr[i+nn][j+mm]=v[i][j];
            for(int j = mm-1;j>0;j--) 
                arr[i+nn][j]=arr[i+nn][2*j]+arr[i+nn][2*j+1];
        }
        for(int i = nn-1;i>0;i--){
            for(int j = 1;j<2*mm;j++) 
                arr[i][j]=arr[2*i][j]+arr[2*i+1][j];
        }
    }
    Two_Dim_2dSegmentTree() = default;
    Two_Dim_2dSegmentTree(Two_Dim_2dSegmentTree&&) = default;
    Two_Dim_2dSegmentTree& operator=(Two_Dim_2dSegmentTree&&) = default;
    int get_on_single(int x, int y1, int y2){
        y1+=m; y2+=m;
        int ans{0};
        while(y1<=y2){
            if(y1%2==1){ans+=arr[x][y1]; y1++;}
            if(y2%2==0){ans+=arr[x][y2]; y2--;}
            y1/=2; y2/=2;
        }
        return ans;
    }
    int get_count(int x1, int y1, int x2, int y2){
        x1+=n; x2+=n;
        int ans{0};
        while(x1<=x2){
            if(x1%2==1){
                ans+=get_on_single(x1, y1, y2);
                x1++;
            }
            if(x2%2==0){
                ans+=get_on_single(x2, y1, y2);
                x2--;
            }
            x1/=2; x2/=2;
        }
        return ans;
    }
    void update(int x, int y, int val){
        x+=n; y+=m;
        // cout<<x<<' '<<y<<' '<<n<<' '<<m<<'\n';
        arr[x][y]=val;
        int ny=y/2;
        while(ny>0){ 
            arr[x][ny]=arr[x][2*ny]+arr[x][2*ny+1];
            ny/=2;
        }
        x/=2;
        while(x>0){
            int ny = y;
            while(ny>0){
                arr[x][ny]=arr[2*x][ny]+arr[2*x+1][ny];
                ny/=2;
            }
            x/=2;
        }
    }
    #undef ll
    #undef int
    #undef VVI 
    #undef VI 
    #undef PB 
};

class Solution {
public:
    #define LL long long
    LL M = 1e9+7;
    int n, l, r;
    Two_Dim_2dSegmentTree *st1, *st1_bool, *st2, *st2_bool;
    int do_it(int i, bool less, int prev){
        if(i==n) return 1;
        if(less && st1_bool->get_count(i, l, i, prev-1)==prev-l){
            return st1->get_count(i, l, i, prev-1);
        }
        if(!less && st2_bool->get_count(i, prev+1, i, r)==r-prev){
            return st2->get_count(i, prev+1, i, r);
        }
        
        LL ans{0};
        for(int j = (less ? l : prev+1);j<=r;j++){
            if(less && prev<j) break;
            if(prev==j) continue;
            ans+=do_it(i+1, prev<j, j);
            ans%=M;
        }
        if(less){st1->update(i, prev, ans); st1_bool->update(i, prev, 1);}
        else{st2->update(i, prev, ans); st2_bool->update(i, prev, 1);}
        return ans;
    }
    int zigZagArrays(int n, int l, int r) {
        this->n = n; this->l=l; this->r=r;
        vector<vector<LL>> v(n, vector<LL>(r+2, 0));
        this->st1 = new Two_Dim_2dSegmentTree(v);
        this->st1_bool = new Two_Dim_2dSegmentTree(v);
        this->st2 = new Two_Dim_2dSegmentTree(v);
        this->st2_bool = new  Two_Dim_2dSegmentTree(v);


        LL ans = do_it(0, 0, l-1);

        this->st1 = new Two_Dim_2dSegmentTree(v);
        this->st1_bool = new Two_Dim_2dSegmentTree(v);
        this->st2 = new Two_Dim_2dSegmentTree(v);
        this->st2_bool = new Two_Dim_2dSegmentTree(v);

        
        ans += do_it(0, 1, r+1);
        ans%=M;
        return ans;
    }
};

int solve(vector<int> cost, vector<int> capacity, int budgetLimit){
    int n = cost.size();
    vector<pair<int, int>> v;
    for(int i = 0;i<n;i++) v.push_back({cost[i],capacity[i]});
    sort(v.begin(), v.end());
    vector<int> ps_cap(n, v[0].second);
    for(int i = 1;i<n;i++) ps_cap[i]=max(ps_cap[i-1], v[i].second);
    int ans = 0; // may need to change his
    for(int i = n-1;i>=0;i--){
        int rem_bud = budgetLimit-v[i].first;
        if(rem_bud<0) continue;
        auto it1 = upper_bound(
            v.begin(), next(v.begin(), i), pair<int, int>{rem_bud, INT_MAX}
        );
        if(it1 == v.begin()){ ans = max(ans, v[i].second); continue;}
        it1--;
        int j = distance(v.begin(), it1);
        ans = max(ans, v[i].second+ps_cap[j]);
    }
    return ans;
}

signed main(){
    vector<int> nums1{1,2,3,4,6}, nums2{1,2,3,5,4};
    cout<<solve(nums2, nums1, 8);

    return 0;
}