#include <bits/stdc++.h>
using namespace std;
class node{public:
    int n; vector<node*> child;
    int root_dist{-1};
    int ht{-1};
    int md{-1};
    node(int nn){
        this->n = nn;
    }
};
class graph{public:
    int n; vector<node*> nodes;
    graph(int n){
        this->n = n;
        for(int i = 0;i<=n;i++) nodes.push_back(new node(i));
    }
    void addEdge(int a, int b){
        nodes[a]->child.push_back(nodes[b]);
        nodes[b]->child.push_back(nodes[a]);
    }

};

int get_ht(node* n, node* p){
    if(n->ht != -1) return n->ht;
    int h = 0;
    for(auto i: n->child){if(i==p) continue;
        h = max(1+get_ht(i, n), h);
    }
    n->ht = h;n->md = max(n->md, n->ht);
    return h;
}
void get_rd(node* n, node* p, int h){
    n->root_dist = h;
    n->md = max(n->md, n->root_dist);
    for(auto i: n->child){ if(i==p) continue;
        get_rd(i, n, h+1);
    }
}
void md(node* n, node* p, int d){
    vector<pair<int, int>> v;
    int ci = 0;
    for(auto i: n->child){if(i==p) continue;
        v.push_back({i->ht, ci});
        ci++;
    }
    sort(v.rbegin(), v.rend());
    int fmax = v.size() ? v[0].first:-1;
    int smax = v.size()>1 ? v[1].first : -1;
    ci = 0; 
    for(auto i: n->child){if(i==p) continue;
        int nex = fmax;
        if(ci==v[0].second) nex = smax;
        md(i, n, max(d, nex+1)+1);
        ci++; 
    }
    n->md = max(n->md, d);
}
int main(){
    int n; cin>>n;
    graph g(n);
    for(int i=1;i<n;i++) {int a, b; cin>>a>>b; g.addEdge(a, b);}
    get_ht(g.nodes[1], 0x0);
    get_rd(g.nodes[1], 0x0, 0);
    md(g.nodes[1], 0x0, 0);
    // for(int i = 0;i<=n;i++) ans[i]=max(g.nodes[i]->ht, g.nodes[i]->root_dist);
    for(int i = 1;i<=n;i++) cout<<g.nodes[i]->md<<"\n";


}