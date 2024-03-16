#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <map>
#include <limits>
#include <utility>
#include <cmath>
#include <list>
#include <sstream>
#include <set>
#include <numeric>
#include <bitset>
#include <chrono>
#define pii pair<int, int>
using namespace std;
#define ll long long
#define vi vector<int>

class graph{
public: 
    class node{public:
        int v{0}; vector<int> c;
    };
    vector<node> nodes; int n;
    graph(int n){
        nodes.resize(n+1); this->n=n;
        for(int i = 1;i<=n;i++) nodes[i].v = i;
    }
    void insert(vector<int> &v){
        for(int i = 1;i<n-1;i++) nodes[v[i]].c.push_back(v[i+1]);
    }
    bool check(){
        vector<int> innode(n+1, 0);
        for(auto &i: nodes) for(auto &j: i.c) innode[j]++;
        deque<int> q;
        for(int i = 1;i<=n;i++) if(innode[i]==0) q.push_back(i);
        bool ans = false;
        int visited = 0;
        while(q.size()){
            visited++;
            int a = q.front();q.pop_front();
            for(auto &c: nodes[a].c){
                innode[c]--;
                if(innode[c]==0)q.push_back(c);
            } 
        }
        return visited==n;
    }
};

int main(int argc, char const *argv[]){
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        vector<vector<int>> v;
        for(int k1 = 0; k1<k;k1++){
            v.push_back({});
            for(int i = 0;i<n;i++){
                int val; cin>>val;
                v.back().push_back(val);
            }
        }
        graph g(n);
        for(auto &i: v){g.insert(i);}
        cout<<(g.check() ? "Yes":"No")<<"\n";
    }
}
