#include <bits/stdc++.h>
using namespace std;
#define ll long long
class node{ public:
    int val{0};
    vector<node*> children;
    node(int x): val(x){}
    node(){}
    int a{-1}, b{-1}; 
    int get_hts(int par){
        if(a!=-1) return a;
        priority_queue<int> pq;
        for(auto &i: children){
            if(i->val==par) continue;
            int ch = i->get_hts(val);
            pq.push(-1-ch);
            if(pq.size()>2) pq.pop();
        }
        if(pq.size()==0){a=0;b=0;}
        else if(pq.size()==1){
            a = -1*pq.top(); pq.pop(); 
            b=0;
        }else{
            b=-1*pq.top(); pq.pop();
            a = -1*pq.top(); pq.pop();
        }
        return a;
    }
    pair<int, int> get_last(int par){
        pair<int, int> ans = {-1, val};
        for(auto i: children){
            if(i->val==par) continue;
            auto curr = i->get_last(val);
            if(ans.first<curr.first) ans=curr;
        }
        ans.first+=1;
        return ans;
    }
};
signed main(){
    int n; cin>>n;
    vector<node*> v(n+1, nullptr);
    for(int i =1;i<=n;i++) v[i] = new node(i);
    for(int i =1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a]->children.push_back(v[b]);
        v[b]->children.push_back(v[a]);
    }
    // v[1]->get_hts(-1);
    // int ans{0};
    // for(int i=1;i<=n;i++) ans=max(ans, v[i]->a+v[i]->b);
    // cout<<ans<<'\n';
    pair<int, int> a = v[1]->get_last(-1);
    a = v[a.second]->get_last(-1);
    cout<<a.first<<'\n';
    return 0;
}