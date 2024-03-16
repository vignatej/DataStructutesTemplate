#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n; cin>>n; vector<pair<ll, ll>> v(n);
    for(int i = 0;i<n;i++) cin>>v[i].first>>v[i].second;
    ll res{0};
    for(int i = 0;i<n;i++){
        auto p = v[i]; auto q = v[(i+1)%n];
        res+=(p.first-q.first)*(p.second+q.second);
    }
    cout<<abs(res);
}