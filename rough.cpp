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
#define X first
#define Y second
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int> ps(n+1, 0);
        map<int, deque<int>> m;
        for(int i = 0;i<n;i++){
            ps[i+1]=ps[i]+nums[i];
            ps[i+1]%=p;
            m[ps[i+1]].push_back(i);
        }
        // {
        //     int ts = accumulate(nums.begin(), nums.end(), 0);
        //     int cas{n}; int ii{-1}; int ij{-1};
        //     for(int i = 0;i<n;i++){
        //         int cs{0};
        //         for(int j = i;j<n;j++){
        //             cs+=nums[j];
        //             if((ts-cs)%p==0 && cas>j-i+1){cas=j-i+1; ii=i; ij=j;}
        //         }
        //     }
        //     cout<<cas<<' '<<ii<<' '<<ij<<'\n';
        // }
        int ans = n; int rtr = ps.back();
        if(rtr==0) return 0;
        if(m[rtr].size()) ans = m[rtr].front()+1;
        for(int i = 0;i<n;i++){
            int c = ps[i+1];
            m[c].pop_front();
            int rem = c+rtr; rem+=p; rem%=p;
            if(m[rem].size()==0) continue;
            int t = m[rem].front();
            ans = min(ans, t-i);
        }
        if(ans==n) return -1;
        return ans;
    }
};

int main() {
    // cout<<StringChallenge("**+*{2} mmmrrrkbb");
    // string st = "bbbab";
    Solution s;
    // vector<string> d {"a","b","ba","bca","bda","bdca"};
    vector<int> v1 {8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2}; // = {3,1,5,3,1,1};
    vector<int> v2{2,4};
    vector<vector<int>> v{{1,20},{2, 10},{3, 5},{4, 9},{6, 8}};
    vector<string> s1{"dog","cat","dad","good"};
    vector<string> s2{"a","b","c"};
    vector<char> c1{'a','a','c','d','d','d','g','o','o'};
    vector<vector<int>> v12 {{2,3,9},{1,0,2},{1,3,3}};
    vector<vector<int>> v13 {{3,4},{5,5}};
    vector<vector<char>> vc {{'1', '0', '1', '0', '0'},{'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<string>> vs{{"a","0549"},{"b","0457"},{"a","0532"},{"a","0621"},{"b","0540"}};
    // cout<<"Hello";
    cout<<s.minSubarray(v1, 148);
    // cout<<s.maximumTotalDamage(v1);
    // for(auto i: s.arrayRankTransform(v1)) cout<<i<<"-";
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
