#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        VI v(n+1, 1);
        vector<bool> comp(n+1, 0);
        vector<int> not_in2;
        for(int i =2;i<=n;i+=2) comp[i]=1;
        for(int i = 3;i<=n;i+=2){
            if(comp[i]) continue;
            vector<int> allp;
            for(int j = i;j<=n;j+=i){
                if(comp[j]) continue;
                allp.push_back(j);
                comp[j]=1;
            }
            if(allp.size()==1 && i*2<=n){
                not_in2.push_back(i*2);
                allp.push_back(i*2);
            }
            int cn = allp.size();
            for(int j = 0;j<cn;j++){
                v[allp[j]]=allp[(j+1)%cn];
            }
        }
        vector<int> two;
        int j = 0;
        for(int i = 2;i<=n;i+=2){
            if(j<not_in2.size() && not_in2[j]==i){
                j++;
                continue;
            }
            two.push_back(i);
        }
        int c2n = two.size();
        for(int i = 0;i<c2n;i++){
            v[two[i]]=two[(i+1)%c2n];
        }
        for(int i =1;i<=n;i++) cout<<v[i]<<' ';
        cout<<'\n';
    }

    return 0;
}