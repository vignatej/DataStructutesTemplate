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
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
int main(int argc, char const *argv[])
{
    int T;cin>>T;
    while(T>0){T--;
        ll n, c; cin>>n>>c;
        vector<ll> s(n, 0);
        for(auto &i: s) cin>>i;
        ll o{0}, e{0};
        ll ans{0};
        ans+=((c+1)*(c+2))/2;
        for(auto &i: s) if(i%2==1) o++; else e++;
        for(auto i: s) ans-=i/2+1;
        for(auto i: s) ans-=(c-i+1);
        ans+=(o*(o+1))/2;
        ans+=(e*(e+1))/2;
        cout<<ans<<"\n";
    }        
}
