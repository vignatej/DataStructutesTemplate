#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back


class node{public:
    int val;
    vector<node*> children;
    node(int v):val(v){};
    node(){};
    char col;
    bool colored{false};
};

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif
    string csm; cin>>csm;
    if(csm=="first"){
        int T; cin>>T;
        while(T--){
            int n, m; cin>>n>>m;
            vector<node*> v(n+1);
            for(int i = 1;i<=n;i++) v[i]=new node(i);
            for(int i = 0;i<m;i++){
                int a, b; cin>>a>>b;
                v[a]->children.push_back(v[b]);
                v[b]->children.push_back(v[a]);
            }
            vector<node*> curr{v[1]}; char cc = 'r';
            map<char, char> nc; nc['r']='g';nc['g']='b';nc['b']='r';
            while(curr.size()){
                vector<node*> next;
                for(auto i: curr){
                    if(i->colored) continue;
                    i->col=cc; i->colored=1;
                    for(auto j: i->children) next.push_back(j);
                }
                cc=nc[cc];
                curr=next;
            }
            for(int i =1;i<=n;i++) cout<<v[i]->col;
            cout<<'\n';
        }
    }else if(csm=="second"){
        int T; cin>>T;
        while(T--){
            int q; cin>>q;
            while(q--){
                int cur_nei; cin>>cur_nei;
                vector<char> v(cur_nei+1); 
                for(int i =1;i<=cur_nei;i++) cin>>v[i];
                set<char> cc; 
                for(int i =1;i<=cur_nei;i++) cc.insert(v[i]);
                auto it_r = find(v.begin(), v.end(), 'r');
                auto it_b = find(v.begin(), v.end(), 'b');
                auto it_g = find(v.begin(), v.end(), 'g');
                if(cc.size()==2){
                    char c1 = *cc.begin(); char c2 = *cc.rbegin();
                    if(c1=='b' && c2=='r'){cout<<distance(v.begin(), it_r)<<'\n';}
                    if(c1=='g' && c2=='r'){cout<<distance(v.begin(), it_g)<<'\n';}
                    if(c1=='b' && c2=='g'){cout<<distance(v.begin(), it_b)<<'\n';}
                }else if(cc.size()==1){
                    char c1 = *cc.begin();
                    if(c1=='r'){cout<<distance(v.begin(), it_r)<<'\n';}
                    if(c1=='g'){cout<<distance(v.begin(), it_g)<<'\n';}
                    if(c1=='b'){cout<<distance(v.begin(), it_b)<<'\n';}
                }
            }
        }
    }

    return 0;
}