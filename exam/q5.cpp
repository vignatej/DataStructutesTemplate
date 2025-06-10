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
        VI v1(n), v2(n);
        for(int i = 0;i<n;i++) cin>>v1[i];
        for(int i = 0;i<n;i++) cin>>v2[i];
        if(v1[n-1]==v2[n-1]){ 
            cout<<n<<'\n';
            continue;
        }
        map<int, int> m;
        bool comp = false;
        for(int i = n-1;i>=0 && !comp;i--){
            if(m[v1[i]]){
                if(m[v1[i]]==1 && v2[i+1]==v1[i]){

                }else{
                    cout<<i+1<<'\n';
                    comp=1;
                    break;
                }
            } 
            m[v1[i]]++;
            if(m[v2[i]]){
                if(m[v2[i]]==1 && v1[i+1]==v2[i]){

                }else{
                    cout<<i+1<<'\n';
                    comp=1;
                    break;
                }
            } 
            m[v2[i]]++;
        }
        if(comp) continue;
        cout<<0<<'\n';

    }

    return 0;
}