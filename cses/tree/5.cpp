#include <bits/stdc++.h>
using namespace std;
class node{public: 
    int n; vector<node*> child;
    int bs{0};
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
    int calc_bs(node* n, node* p){
        int ans{0};
        for(auto i: n->child){
            ans += 1+calc_bs(i, n);
        }
        return ans;
    }

}

int main(){

}