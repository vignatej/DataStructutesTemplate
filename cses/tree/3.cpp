#include <bits/stdc++.h>
using namespace std;
class node;
int gh(node* n, node* p);
class node{public:
    int ht{0};
    int n; vector<node*> child;
    node(int nn){n=nn;}
};
class graph{public:
    int n; vector<node*> nodes;
    graph(int nn){
        this->n = nn; 
        for(int i = 0;i<=n;i++) nodes.push_back(new node(i));
    }
    void add_edge(int a, int b){
        nodes[a]->child.push_back(nodes[b]);
        nodes[b]->child.push_back(nodes[a]);
    }
    
    int get_diam(node* n, node* p){
        vector<int> v; int mcd = 0;
        for(auto i: n->child){if(i==p) continue;
            v.push_back(gh(i, n));
            mcd = max(mcd , get_diam(i, n));
        }
        sort(v.rbegin(), v.rend());
        int ans = 0; 
        if(v.size()==0) ans=0; else if(v.size()==1) ans=v[0];
        else ans=v[0]+v[1];
        return max(ans, mcd);
    }
};
int gh(node* n, node* p){
        if(n->ht!=0) return n->ht;
        int ht{0};
        for(auto i: n->child){if(i==p) continue;
            int ch = gh(i, n);
            ht=max(ht, ch);
        }
        ht++; n->ht=ht;
        return ht;
    }

int main(){
    int n; cin>>n; 
    graph g(n);
    for(int i = 1;i<n;i++){int a, b; cin>>a>>b;g.add_edge(a, b);}
    for(int i = 1;i<=n;i++) gh(g.nodes[1], 0x0);
    cout<<g.get_diam(g.nodes[1], 0x0);
}