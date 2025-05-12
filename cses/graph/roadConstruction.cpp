#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Sol{
    public:
    vector<int> head, siz;
    int getHead(int n){
        if(head[n]==n) return n;
        return head[n] = getHead(head[n]);
    }
    void union_(int a, int b){
        a=getHead(a); b=getHead(b);
        if(a==b) return;
        if(siz[a]<siz[b]) swap(a, b);
        head[b]=a;
        siz[a]+=siz[b];
    }
};

signed main(){
    int n, m; cin>>n>>m;
    Sol S; 
    S.head.resize(n+1, 0);
    S.siz.resize(n+1, 1);
    for(int i = 1;i<=n;i++) S.head[i]=i;
    int cc{n};int ms{1}; int msi{1};
    for(int i = 1;i<=m;i++){
        int a, b; cin>>a>>b;
        if(S.getHead(a)!=S.getHead(b)){
            // do stg
            S.union_(a, b);
            int new_h = S.getHead(a);
            if(S.siz[new_h]>ms){
                ms=S.siz[new_h];
                msi=new_h;
            }
            cc--;
        }
        cout<<cc<<' '<<ms<<'\n';
    }

    return 0;
}