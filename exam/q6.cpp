#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

class node{public:
    vector<node*> child;
    int a{0}; bool comp{false};
    node(int a):a(a){}
    int get_ans1{-1}, get_ans2{-1};
    void get(){
        if(comp) {get_ans1=0; get_ans2=0;}
        if(get_ans1!=-1) return;
        vector<int> ca;
        for(auto i: child){
            i->get();
            ca.push_back(i->get_ans1);
        }
        sort(ca.rbegin(), ca.rend());
        get_ans1=0; get_ans2=0;
        for(int i = 0;i<ca.size() && i<1;i++) get_ans1+=ca[i];
        for(int i = 0;i<ca.size() && i<2;i++) get_ans2+=ca[i];
        get_ans1+=a;get_ans2+=a;
        return;
    }
    void make_black(){
        comp=1;
        vector<pair<int, node*>> ca;
        for(auto i: child){
            ca.push_back({i->get_ans1, i});
        }
        sort(ca.rbegin(), ca.rend());
        for(int i = 0;i<ca.size() && i<1;i++) 
            ca[i].second->make_black();
    }
};
void resolve(node* curr, node* par){
    curr->child.erase(find(curr->child.begin(), curr->child.end(), par));
    for(auto i: curr->child) resolve(i, curr);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, k; cin>>n>>k;
    vector<node*> v;
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v.push_back(new node(a));
    }  
    for(int i = 1;i<n;i++){
        int a, b; cin>>a>>b; 
        a--; b--;
        v[a]->child.push_back(v[b]);
        v[b]->child.push_back(v[a]);
    }
    for(auto i: v[0]->child) resolve(i, v[0]);
    int ans{0};
    while(k--){
        int ans_i = 0;
        for(int i = 0;i<n;i++){
            v[i]->get();
            if(v[i]->get_ans2>v[ans_i]->get_ans2) ans_i = i;
        }
        if(v[ans_i]->get_ans2<=0) break;
        ans += v[ans_i]->get_ans2;

        v[ans_i]->comp=1;
        for(auto &j: v[ans_i]->child) j->make_black();
        for(int i = 0;i<n;i++) v[i]->get_ans1=-1;
        for(int i = 0;i<n;i++) v[i]->get_ans2=-1;
    }
    cout<<ans;

    return 0;
}