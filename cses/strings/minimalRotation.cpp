#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    string s; cin>>s; int n = s.length();
    vector<int> curr;
    char nmc = 'z';
    for(auto &i: s) nmc = min(nmc, i);
    for(int i = 0;i<n;i++) if(s[i]==nmc) curr.push_back(i);
    int times{0};
    while(curr.size()>1 && times<n){
        vector<int> next;
        char nmc = 'z';
        for(auto &i: curr) nmc = min(nmc, s[(i+1)%n]);
        for(auto &i: curr) if(s[(i+1)%n]==nmc) next.push_back((i+1)%n);
        times++;
        curr=next;
    }
    int sp = (curr[0]+n-times)%n;
    for(int i = sp;i<n;i++) cout<<s[i];
    for(int i = 0;i<sp;i++) cout<<s[i];

    return 0;
}