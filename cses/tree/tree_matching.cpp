#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node{ public:
    int val{0};
    vector<node*> child;
    node(int x):val(x){}
    pair<int, int> calc_v{-1, -1};
    pair<int, int> calc(int parent){
        if(calc_v!=pair<int, int>{-1, -1}) return calc_v;
        vector<pair<int, int>> v;
        for(auto &i: child){
            if(i->val==parent) continue;
            v.push_back(i->calc(val));
        }
        int sec = 0;
        for(auto &i: v) sec+=max(i.first, i.second);
        int first = sec;
        for(auto &i: v){
            int cf = sec;
            cf+=1; 
            if(i.first>i.second){cf-=i.first; cf+=i.second;}
            first=max(first, cf);
        }
        calc_v = {first, sec};
        return calc_v;
    }

};

signed main(){
    int n; cin>>n;
    vector<node*> v(n+1, nullptr);
    for(int i =1;i<=n;i++) v[i]=new node(i);
    for(int i =1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    cout<<v[1]->calc(-1).first;

    return 0;
}