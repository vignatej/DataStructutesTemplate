#include <bits/stdc++.h>
using namespace std;


void gen_perm(int i, vector<int> &v, vector<vector<int>> &p){
    int n = v.size();
    if(i==n){
        p.push_back(v);
    }else{
        gen_perm(i+1, v, p);
        for(int j = i+1;j<n;j++){
            swap(v[i], v[j]);
            gen_perm(i+1, v, p);
            swap(v[i], v[j]);
        }
    }
}


int main(){
    vector<vector<int>> p;
    vector<int> v{1, 2, 3, 4};
    gen_perm(0, v, p);
    for(auto i: p){
        for(auto j: i) cout<<j<<' ';
        cout<<'\n';
    }

    // h is linked list
}