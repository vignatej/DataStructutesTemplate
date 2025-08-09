#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        vector<int> v1(n), v2(n);
        for(int i = 0;i<n;i++) cin>>v1[i];
        for(int i = 0;i<n;i++) cin>>v2[i];
        int ans{0};
        for(int i = 0;i<n;i++){
            int a=v1[i]; int b = v2[i];
            v1[i]=min(a, b);
            v2[i]=max(a, b);
            ans+=abs(a-b);
        }
        int oans{INT_MAX};
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int a = v1[i]; int b = v2[i];
                int c = v1[j]; int d = v2[j];
                int cans{ans};
                cans -= abs(a-b)+abs(c-d);
                vector<int> v{a, b, c, d};
                sort(v.begin(), v.end());
                cans += abs(v[0]-v[3])+abs(v[1]-v[2]);
                oans=min(oans, cans);
            }
        }
        cout<<oans<<'\n';
    }

    return 0;
}