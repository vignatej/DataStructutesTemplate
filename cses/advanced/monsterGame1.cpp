#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

int get(vector<vector<long double>> &lines, int cp, int &ptr){
    if(ptr>=lines.size()) ptr=lines.size()-1;
    if(ptr+1<lines.size() && lines[ptr+1][2]<=cp) ptr++;
    return lines[ptr][0]*cp+lines[ptr][1];
}
void add(vector<vector<long double>> &lines, int m, int c){
    if(lines.size() && lines.back()[0]==m){
        if(lines.back()[1]<=c) return;
        lines.pop_back();
    }
    long double intersectX;
    while(lines.size()){
        intersectX = (c-lines.back()[1])/(lines.back()[0]-m);
        if(lines.back()[2]<intersectX) break;
        lines.pop_back();
    }
    lines.push_back({(long double)m, (long double)c, intersectX});

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
    vector<vector<long double>> lines{{(long double)x, 0, -1e18}};
    vector<int> dp(n);
    int ptr = 0;
    for(int i = 0;i<n;i++){
        dp[i]=get(lines, s[i], ptr);
        add(lines, f[i], dp[i]);
    }
    cout<<dp[n-1];
    return 0;
}