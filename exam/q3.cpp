#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        string s; cin>>s;
        bool ans = true;
        if((s[0]=='0' && s[1]=='1')||(s[n-2]=='1' && s[n-1]=='0'))
            ans = false;
        for(int i = 1;i<n-1;i++)
            if(s[i-1]=='1' && s[i]=='0' && s[i+1]=='1') ans = false;
        if(!ans){
            cout<<"NO\n"; continue;
        }
        vector<int> v(n, 0);
        int i = 0;
        while(i<n){
            if(s[i]=='1') {
                v[i]=i; i++; continue;
            }
            int j = i+1;
            while(j<n && s[j]=='0') j++;
            for(int k = i;k<j;k++){
                v[k]=j-(k-i)-1;
            }
            i=j;
        }
        cout<<"YES\n";
        for(auto i: v) cout<<i+1<<' ';
        cout<<'\n';
    }

    return 0;
}