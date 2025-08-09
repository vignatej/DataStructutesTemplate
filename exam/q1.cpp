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
        set<int> v;
        for(int i = 0;i<n;i++){
            int curr; cin>>curr;
            v.insert(curr);
        }
        bool ans{1};
        if(v.size()==1){
            if(*v.begin()==0) ans=0;
            else ans=1; 
        }else if(v.size()==2){
            int v1 = *v.begin();
            int v2 = *v.rbegin();
            if(v1==-1 && v2>0) ans=1;
            else ans=0;
        }else{
            ans=0;
        }
        cout<<(ans?"YES":"NO")<<'\n';
    }

    return 0;
}