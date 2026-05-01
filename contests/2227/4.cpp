#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool check_pall(vector<int> &s, int a, int b){
    if(a>=b) return 1;
    while(a<b){
        if(s[a]!=s[b]) return 0;
        a++; b--;
    }
    return 1;
}
pair<int, int> exp(vector<int> &v, int a, int b){
    int n = v.size();
    while(a>=0 && b<n){
        if(v[a]!=v[b]) break;
        a--; b++;
    }
    return {a+1, b-1};
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v(2*n); for(auto &i: v) cin>>i;
        int a{-1}, b{-1};
        for(int i = 0;i<2*n;i++){
            if(v[i]!=0) continue;
            if(a!=-1) b=i;
            else a=i;
        }
        bool pa = check_pall(v, a, b);
        int ans1 = 1;
        if(pa){
            int x, y; tie(x, y) = exp(v, a, b);
            set<int> s; for(int i = x;i<=y;i++) s.insert(v[i]);
            for(int i = 0;;i++){
                if(s.find(i)==s.end()){
                    // if(i==0) break;
                    ans1 = i;
                    break;
                }
            }    
        }
        int ans2 = 1;
        {
            int x, y; tie(x, y) = exp(v, a, a);
            set<int> s; for(int i = x;i<=y;i++) s.insert(v[i]);
            for(int i = 0;;i++){
                if(s.find(i)==s.end()){
                    // if(i==0) break;
                    ans2 = i;
                    break;
                }
            }
        }
        int ans3 = 1;
        {
            int x, y; tie(x, y) = exp(v, b, b);
            set<int> s; for(int i = x;i<=y;i++) s.insert(v[i]);
            for(int i = 0;;i++){
                if(s.find(i)==s.end()){
                    // if(i==0) break;
                    ans3 = i;
                    break;
                }
            }
        }
        cout<<max({ans1, ans2, ans3})<<'\n';


    }

    return 0;
}