#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    int n; cin>>n;
    if(n==1) {cout<<"10"; return 0;};
    vector<vector<int>> g((1<<(n-1))+1);
    for(int i =0;i<(1<<(n-1));i++){
        int curr = (i<<1);
        curr&=(~(1<<(n-1)));
        int zero = curr;
        // if(curr & (1<<n)){
        //     curr&=(~(1<<n));
        // }
        g[i].push_back(zero);
        zero|=1;
        g[i].push_back(zero);
    }   
    vector<vector<bool>> comp((1<<(n-1))+1, vector<bool> (2, false));

    vector<int> ans;
    vector<vector<int>> stack{{0, 0}};
    while(stack.size()){
        auto top = stack.back();
        int t = top[0]; int e=top[1];
        if(!comp[t][0]){
            stack.push_back({g[t][0], 0});
            comp[t][0] = 1;
        }else if(!comp[t][1]){
            stack.push_back({g[t][1], 1});
            comp[t][1] = 1;
        }else{
            stack.pop_back();
            ans.push_back(e);
        }
    }
    for(int i = n;i>2;i--) ans.push_back(0);
    reverse(ans.begin(), ans.end());
    // ans.pop_back();
    for(auto i: ans) cout<<i;

    return 0;
}