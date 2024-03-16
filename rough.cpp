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
#define ll long long
#define ll long long
class Solution {
public:
    vector<ll> ps{0};
    int n; map<pair<ll, ll>, pair<bool, ll>> m;
    vector<vector<pair<bool, ll>>> maaa;
    pair<bool, ll> fin(int s, int k){
        if(k==0) return {true, 0};
        if(s>=n){return {false, 0};}
        // if(m.find({s, k})!=m.end()) return m[{s, k}];
        if(maaa[s][k].first!=false || maaa[s][k].second!=-1) return maaa[s][k];
        if(k%2==1){
            ll min_e = ps[s];
            ll ans = -1ll*1e15;
            for(int i = s;i<n;i++){
                ll curr = ps[i+1]-min_e;
                pair<bool, ll> next = fin(i+1, k-1);
                if(next.first) ans = max(ans, curr*k+next.second);
                min_e = min(min_e, ps[i+1]);
            }
            
            if(ans!=-1ll*1e15){
                // m[{s, k}] = {true, ans};
                maaa[s][k]={true, ans};
                return {true, ans};}
            // m[{s, k}] = {false, 0};
            maaa[s][k]={false, 0};
            return {false, 0};
        }else{
            ll max_e = ps[s];
            ll ans = -1ll*1e15;
            for(int i = s;i<n;i++){
                ll curr = ps[i+1]-max_e;
                pair<bool, ll> next = fin(i+1, k-1);
                if(next.first) ans=max(ans, next.second - curr*k);
                max_e = max(max_e, ps[i+1]);
            }
            if(ans!=-1ll*1e15){
                // m[{s, k}] = {true, ans};
                maaa[s][k]={true, ans};
                return {true, ans};
            }
            // m[{s, k}] = {false, 0};
            maaa[s][k]={false, 0};
            return {false, 0};
        }
    }    
    ll maximumStrength(vector<int>& nums, int k) {
        for(auto i: nums) ps.push_back(ps.back()+i);
        n = nums.size();
        maaa.resize(n+1, vector<pair<bool, ll>>(k+1, {false, -1}));
        return fin(0, k).second;
    }
};

int main() {
    // cout<<StringChallenge("**+*{2} mmmrrrkbb");
    // string st = "bbbab";
    Solution s;
    // vector<string> d {"a","b","ba","bca","bda","bdca"};
    vector<int> v1 {-431289354,-444830975,-464870607,-524498730,-555271103,-639213035,-665454754,-741322734,-860863672,-914046082,-996157908}; // = {3,1,5,3,1,1};
    vector<int> v2{2,2,2,2,2,2,3,1};
    vector<vector<int>> v{{1,20},{2, 10},{3, 5},{4, 9},{6, 8}};
    vector<string> c1{"abc","bcd","abcd"};
    vector<string> c2{"abbb","ba","aa"};
    vector<vector<int>> v12 {{7,6,3},{6,6,1}};
    vector<vector<int>> v13 {{3,4},{5,5}};
    vector<vector<string>> vs{{"a","0549"},{"b","0457"},{"a","0532"},{"a","0621"},{"b","0540"}};
    cout<<s.maximumStrength(v1, 11);
    // for(auto i: s.shortestSubstrings(c1)) cout<<i<<"-";
    // vector<bool> ans = s.canMakePalindromeQueries("hykkyh",v12);
    // for(auto i: ans) cout<<i<<" ";
    // string a = "aaaa";
    // cout<<(2<((INT_MAX<<3)&8));
    // cout<<((ll) 3.0020);
    // for(auto i: s.leftmostBuildingQueries(v1, v))cout<<i<<" ";
    // cout<<0b010010;
    // string ss; getline(cin, ss);
    // stringstream sss(ss);
    // int aaa;
    // while(sss>>aaa){
    //     cout<<aaa<<"---";
    // }
    // for(auto &i: s.maxNumber(v1, v2, 3)) cout<<i;
    // cout<<s.constrainedSubsetSum(v1, 1);
    // cout<<("0000">"0001");
    // string st;
    // getline(cin, st);
    // cout<<st<<endl;
    // stringstream ss(st); vector<int> vww;
    // int n;while(ss>>n) vww.emplace_back(n);
    // for(auto i: vww) cout<<i<<endl;

    // for(auto i: s.getPermutation(4,9))cout<<i;
    // int a; cin>>a;
    // string ss;
    // getline(cin, ss); getline(cin, ss);
    // cout<<"\n"<<"--"<<a<<"--"<<ss<<"--"<<endl;
    // cout<<"uff";
    // for(auto i: s.countVisitedNodes(v1))cout<<i<<" ";
    // vector<int> ans = s.maxNumber(v1, v2, 3);
    // for(auto i: ans) cout<<i<<endl;
    // cout<<s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    // vector<vector<char>> vv {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    // cout<<s.removeDuplicateLetters("wmxkuuoordmnpnebikzzujdpscpedcrsjphcaykjsmobturjjxxpoxvvrynmapegvtlasmyuddgxygkaztmbpkrnukbxityz");
    // cout<<(1 and 1)<<(1 & 1);
    // cout<<(0 and 1)<<(1 and 1)<<(0 and 0);
    // sort(v.rbegin(), v.rend());
    // for(auto i: v) cout<<i;
    // vector<int> v1 = {0,0};
    // int a = 50;
    // const int *b = &a;
    // a = 500;
    // cout<<*b;
    // cout<<s.isMatch("bbbba", ".*a*a");
    // int a = pow(2, 31);
    // s.t = 9191;
    // cout<<s.calc("3456237490");
    // for(auto i: s.addOperators("3456237490", 9191)) cout<<i<<endl;
    // vector<int> v2 = {1,2,3};
    // vector<double> vvv {3.0,4,5,6};
    // vector<vector<string>> vvvv {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};
    // for(auto &i: s.maxSlidingWindow(v, 3)){
    //     cout<<i<<" -";
    // };
    // vector<int> ans = s.findRedundantDirectedConnection(vv);
    // cout<<ans[0]<<"--"<<ans[1];
    // for(auto [i, j]: vv){
    //     cout<<i<<j;
    // }
    // for(auto &i: s.findMinHeightTrees(6, vv)) cout<<i;

    // for(auto &i: s.calcEquation(vv, vvv, vvvv))cout<<i<<" ";

};
