#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int eval(vector<int> &l, int x){
    return l[0]*x+l[1];
}

void add_line(
    vector<int> cl, int idx, int l, int r,
    vector<vector<int>> &lines
){
    // if(lines[idx]==vector<long double>{-1, -1}){
    if(lines[idx][0]==-1 && lines[idx][1]==-1){
        lines[idx]=cl;
        return;
    }
    int m = (l+r)/2;
    bool mbv = eval(cl, m) < eval(lines[idx], m);
    bool lbv = eval(cl, l) < eval(lines[idx], l);
    if(mbv) swap(lines[idx], cl);
    if(l==r) return;
    if(lbv != mbv) add_line(cl, idx*2, l, m, lines);
    else add_line(cl, idx*2+1, m+1, r, lines);
}

int query(vector<vector<int>> &lines, int x, int idx, int l, int r){
    // if(lines[idx]==vector<long double> {-1, -1}){
    if(lines[idx][0]==-1 && lines[idx][1]==-1){
        return 1e18;
    }
    int res = eval(lines[idx], x);
    if(l==r) return res;
    int m = (l+r)/2;
    if(x<=m) return min(res, query(lines, x, idx*2, l, m));
    else return min(res, query(lines, x, idx*2+1, m+1, r));
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, x; cin>>n>>x;
    vector<int> s(n), f(n);
    for(int i = 0;i<n;i++) cin>>s[i];
    for(int i = 0;i<n;i++) cin>>f[i];
    int maxS{0};
    for(int i = 0;i<n;i++) maxS = max(maxS, s[i]);
    vector<vector<int>> st(4*maxS+10, {-1, -1});
    add_line(vector<int>{x, 0}, 1, 0, maxS, st);
    vector<int> dp(n, 0);
    for(int i = 0;i<n;i++){
        dp[i]=query(st, s[i], 1, 0, maxS);
        add_line({f[i], dp[i]}, 1, 0,maxS,st);
    }
    cout<<dp[n-1];
    return 0;
}