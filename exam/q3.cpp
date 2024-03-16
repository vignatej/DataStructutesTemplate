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
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int, int>

int main(int argc, char const *argv[])
{
    int T; cin>>T;
    while(T--){
        int n, l;cin>>n>>l;
        vector<pair<ll, ll>> v(n);
        for(int i = 0;i<n;i++){ll a, b; cin>>a>>b; v[i]={b, a};}
        int ml = 0;
        sort(v.begin(), v.end());
        for(int i = 0;i<n;i++){
            priority_queue<int> pq; int as = 0;
            pq.push(v[i].second); as+=pq.top();
            if(as<=l) ml=max(ml, 1);
            for(int j = i+1;j<n;j++){
                int nl = l-v[j].first+v[i].first;
                if(as+v[j].second<=nl){
                    as+=v[j].second; pq.push(v[j].second); 
                }
                else if(pq.top()>v[j].second){
                    as-=pq.top(); pq.pop(); 
                    pq.push(v[j].second);as+=v[j].second;
                }
                if(as<=l) ml=max(ml, (int)pq.size());
            }
        }
        cout<<ml<<"\n";
    }
}
