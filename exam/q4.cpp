#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v(n+1), ans(n+1, 0);
        for(int i =1;i<=n;i++) cin>>v[i];
        ans[1]=1;
        ans[2]=2;
        if(v[1]>v[2]) ans[2]+=1;
        for(int i = 3;i<=n;i++){
            int a = v[i-2]; int b = v[i-1]; int c= v[i];
            if(a>b && b>c){
                ans[i]=ans[i-1]+i;
            }else if(a>c && c>b){
                ans[i]=max(ans[i-1], ans[i-2]+i-2+2);
            }else if(b>a && a>c){
                ans[i]=max(ans[i-1]+i, ans[i-2]+i-2+3);
            }else if(b>c && c>a){
                ans[i]=ans[i-1]+i;
            }
        }
        int fa{0};
        for(auto i: ans) fa+=i;
        cout<<fa<<'\n';
    }

    return 0;
}