#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets;
vector<int> curr_s;
void gen_sub(int k, int n){
    if(k==n){
        subsets.push_back(curr_s);
    }else{
        curr_s.push_back(k);
        gen_sub(k+1, n);
        curr_s.pop_back();
        gen_sub(k+1, n);
    }
}

vector<vector<int>> permu;
vector<int> curr_p;
void gen_perm(int i, int n){
    if(i==0){
        curr_p.resize(n, 0);
        for(int i = 0;i<n;i++) curr_p[i]=i;
    }if(i==n){
        permu.push_back(curr_p);
    }else{
        gen_perm(i+1,n);
        for(int j=i+1;j<n;j++){
            int t = curr_p[j];curr_p[j]=curr_p[i];curr_p[i]=t;
            gen_perm(i+1, n);
            t = curr_p[j];curr_p[j]=curr_p[i];curr_p[i]=t;
        }
    }
}


int main()
{
    // gen_sub(0, 3);
    // for(auto &i: subsets){
    //     for(auto j: i) cout<<j<<"--";
    //     cout<<"comp\n";
    // }    
    gen_perm(0, 5);
    for(auto &i: permu){
        for(auto j: i) cout<<j<<"--";
        cout<<"comp\n";
    }    
    cout<<permu.size();



    return 0;
}
