#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class Two_Dim_2dSegmentTree{ public:
    VVI arr; int n, m;
    Two_Dim_2dSegmentTree(VVI &v){
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
            for(int j = 1;j<=2*mm;j++) 
                arr[i][j]=arr[2*i][j]+arr[2*i+1][j];
        }
    }
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
};

signed main(){
    int n, q; cin>>n>>q;
    VVI v(n, VI(n, 0));
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++){
        char c; cin>>c;
        if(c=='*') v[i][j]=1;
    }
    Two_Dim_2dSegmentTree seg(v);
    // cout<<seg.get_count(0,0,1,1)<<'\n';
    
    // cout<<seg.get_count(1,1,3,2)<<'\n';
    while(q--){
        int t; cin>>t;
        if(t==1){
            int x, y; cin>>x>>y;
            x--; y--;
            v[x][y]=!v[x][y];
            seg.update(x, y, v[x][y]);
        }else{
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            x1--; y1--; x2--; y2--;
            cout<<seg.get_count(x1, y1, x2, y2)<<'\n';
        }
    }

    return 0;
}