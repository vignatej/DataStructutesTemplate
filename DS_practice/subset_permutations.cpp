#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> all_s;
void gen_subset(int i, int n, vector<int> &cs, vector<int> &all){
    if(i==n){
        all_s.push_back(cs);
    }
    if(i<n){
        cs.push_back(all[i]);
        gen_subset(i+1, n, cs, all);
        cs.pop_back();
        gen_subset(i+1, n, cs, all);
    }
}

void gen_permutations(int i, int n, vector<int> &curr, vector<vector<int>> &all){
    if(i==n){
        all.push_back(curr);
    }
    if(i<n){
        gen_permutations(i+1, n, curr, all);
        for(int j = i+1;j<n;j++){
            swap(curr[j], curr[i]);
            gen_permutations(i+1, n, curr, all);
            swap(curr[j], curr[i]);
        }
    }
}

signed main(){
    vector<int> v{1,2,3,4,5};
    // vector<int> t;
    // gen_subset(0, v.size(), t, v);
    // for(auto i: all_s){
    //     for(auto j: i) cout<<j<<' ';
    //     cout<<'\n';
    // }
    
    gen_permutations(0, 4, v, all_s);
    for(auto i: all_s){
        for(auto j: i) cout<<j<<' ';
        cout<<'\n';
    }
    cout<<all_s.size();
    
    return 0;
}