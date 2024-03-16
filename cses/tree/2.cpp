#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    class node{
    public:
        int n; vector<node*> child;
        node(int n){this->n=n;}
    };
    int n{0};vector<node*> nodes;
    graph(int k){n=k;for(int i = 0;i<=n;i++) nodes.push_back(new node(i));}
    void add_edge(int a, int b){
        nodes[a]->child.push_back(nodes[b]);
        nodes[b]->child.push_back(nodes[a]);
    }
    pair<int, int> calc(node* n, node* p){
        vector<pair<int, int>> v;
        for(auto i: n->child) {
            if(i==p) continue;
            v.push_back(calc(i, n));
        }
        int not_have{0}, can_have{0};
        for(auto i: v) not_have+=i.first;
        int ci = 0;
        for(auto i: n->child){
            if(i==p) continue;
            int cans = 1+v[ci].second + not_have - v[ci].first;
            can_have = max(can_have, cans);
            ci++;
        }
        can_have = max(can_have, not_have);
        return {can_have, not_have};
    }
};


int main(){
    int n; cin>>n; graph g(n);
    for(int i = 1;i<n;i++) {
        int a, b; 
        cin>>a>>b;
        g.add_edge(a, b);
    }
    auto ans = g.calc(g.nodes[1], 0x0);
    cout<<max(ans.first, ans.second);
}