#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool has_comm(VI &a, VI &b){
    int a1{a[0]}, a2{a[1]}, b1{b[0]}, b2{b[1]};
    if(a1<=b1 && b1<=a2) return 1;
    if(a1<=b2 && b2<=a2) return 1;
    if(b1<=a1 && a1<=b2) return 1;
    if(b1<=a2 && a2<=b2) return 1;
    return 0;
}

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        VI d(n); for(int i = 0;i<n;i++) cin>>d[i];
        VVI lim(n, VI(2));bool ans{true};
        for(int i = 0;i<n;i++){
            int a, b; 
            cin>>a>>b; 
            lim[i]={a, b};
            if(i>0) lim[i][0]=max(lim[i][0], lim[i-1][0]);
            if(lim[i][0]>lim[i][1]) ans=false;
        }
        VVI pr;
        if(d[0]==0) pr.push_back({0,0});
        else if(d[0]==1) pr.push_back({1,1});
        else pr.push_back({0,1});
        
        if(!has_comm(lim[0], pr[0])) ans=false;
        pr[0][0]=max(pr[0][0], lim[0][0]);
        pr[0][1]=min(pr[0][1], lim[0][1]);
        int i = 1;
        while(ans && i<n){
            int l = pr.back()[0]; int r=pr.back()[1];
            if(d[i]==0) pr.PB({l, r});
            else if(d[i]==1) pr.PB({l+1, r+1});
            else pr.PB({l, r+1});
            
            if(!has_comm(pr[i], lim[i])){ ans=false; break;}
            pr[i][0]=max(pr[i][0], lim[i][0]);
            pr[i][1]=min(pr[i][1], lim[i][1]);
            i++;
        }
        if(!ans){
            cout<<"-1\n";
            continue;
        }
        VI nd = d;
        int leh = pr[n-1][0];
        for(int i = n-1;i>0;i--){
            if(d[i]==0 || d[i]==1){
                leh-=d[i]; continue;
            }
            int pr_l = pr[i-1][0]; int pr_r = pr[i-1][1];
            if(pr_l<=leh && leh<=pr_r){
                nd[i]=0;
            }else{
                nd[i]=1; 
            }
            leh-=nd[i];
        }
        // do_for 0th index
        if(d[0]==-1){
            if(leh==0) nd[0]=0;
            else if(leh==1) nd[0]=1;
            else ans=false;
        }
        if(!ans){
            cout<<"-1\n";
            continue;
        }
        for(auto &i: nd) cout<<i<<' ';
        cout<<'\n';
    }

    return 0;
}