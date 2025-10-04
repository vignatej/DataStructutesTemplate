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
#include <queue>
#include <stdint.h>
#include <stack>
using namespace std;
#define vi vector<int>
#define pb push_back
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define pii pair<int, int>
#define X first
#define Y second
#define ll long long
#define VI vector<int>
#define VVI vector<VI>
#define int long long
#define LL long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        map<LL, LL> m;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int ma = nums[i]; int mi = nums[i];
            for(int j = i;j<n;j++){
                ma=max(ma, nums[j]);
                mi=min(mi, nums[j]);
                m[ma-mi]++;
            }
        }
        LL ans{0};
        for(auto it = m.rbegin();it!=m.rend() && k>0;it++){
            LL f = it->first; LL s = it->second;
            if(s<=k) ans += f*s;
            else ans += f*k;
            k-=f;
        }
        return ans;
    }
};

signed main() {

    Solution s;
    vector<int> v1{18,36,6}, v2{5,4,3,2,1,1};
    cout<<s.maxTotalValue(v1, 3);

};
