#include <iostream>
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
// #include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    int T; cin>>T;
    while(T>0){T--;
        int n; cin>>n;vector<int> v(n, 0);
        for(int i = 0;i<n;i++) cin>>v[i];
        vector<int> orig = v;
        sort(v.begin(), v.end());
        if(v[0]!=0){cout<<n<<"\n";for(int i = 1;i<=n;i++)cout<<i<<" "<<i<<"\n"; continue;}
        int p = 0;
        for(auto i: v) if(i==p ||i==p+1){p=i;} else{p++; break;}
        if(p==v.back()) p++;
        map<int, pair<int, int>> m;
        for(int i = 0;i<p;i++) m[i]={-1, -1};
        for(int i = 0;i<n;i++){
            if(orig[i]>=p) continue;
            if(m[orig[i]].first==-1) m[orig[i]].first=i;
            else m[orig[i]].second=i;
        }
        int fl{m.begin()->second.first};
        int fm{m.begin()->second.first};
        int sl{m.begin()->second.second};
        int sm{m.begin()->second.second};
        for(auto i: m){
            fl=min(fl, i.second.first);fm=max(fm, i.second.first);
            sl=min(sl, i.second.second); sm=max(fm, i.second.second);
        }
        if(fl==-1 || sl==-1 || fm==-1 || sm==-1){ cout<<-1<<"\n";}
        else if(fm<sl){
            cout<<2<<"\n";
            cout<<1<<" "<<fm+1<<"\n";
            cout<<fm+2<<" "<<n<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}
