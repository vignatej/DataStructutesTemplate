#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <deque>
#include <queue>
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
#define vi vector<int>
#define ll long long

pair<bool, ll> solve(vector<ll> &v, int k, ll m){
    ll cs = 0;int i = 0;int n = v.size();ll mcs{0};int ck=1;
    while(i<n){
        if(cs+v[i]<=m){cs+=v[i];mcs=max(cs, mcs);}
        else{cs=v[i]; ck++;mcs=max(mcs, cs);}
        i++;
    }
    if(ck<=k) return {true, mcs};
    return {false, 0};
}

int main(int argc, char const *argv[])
{
    int T; cin>>T;
    while(T--){
        int n, m;cin>>n>>m;
        vector<ll> v(n, 0); for(int i = 0;i<n;i++) cin>>v[i];
        auto cmp = [](const ll &i,const ll &j){
            ll a=i; ll b=j;
            int c1 = 0; while(a!=0 && a%10==0){a/=10;c1++;}
            int c2 = 0; while(b!=0 && b%10==0){b/=10;c2++;}
            return c1<c2;
        };
        
        priority_queue<ll, vector<ll>, decltype(cmp)> pq(cmp);
        vector<int> nonzeros_len;
        for(auto i: v){
            string j = to_string(i);
            if(j[j.length()-1]=='0') pq.push(i);
            else nonzeros_len.push_back(j.length());
        }
        int c = 0;
        while(pq.size() || nonzeros_len.size()){
            int pqs = pq.size(); int nz = nonzeros_len.size();
            if(pqs==0 && nz==1){
                int l = nonzeros_len.back();
                if(!(l>m))cout<<"Anna";
                else cout<<"Sasha";
                cout<<"\n";
                break;
            }
            if(c%2==0){
                if(pq.size()==0){c++; continue;}
                int a = pq.top(); pq.pop();
                while(a%10==0){a/=10;}
                nonzeros_len.push_back(to_string(a).length());
            }else{
                if(pq.size()){
                    int a = pq.top(); pq.pop();
                    if(nonzeros_len.size()==0) 
                        nonzeros_len.push_back(to_string(a).length());
                    else nonzeros_len.back()+=to_string(a).length();
                }else{
                    int a = nonzeros_len.back();nonzeros_len.pop_back();
                    nonzeros_len.back()+=a;
                }
            }
            c++;
        }
        // cout<<(nonzeros>=m ? "Sasha":"anna")<<"\n";
    }
}
