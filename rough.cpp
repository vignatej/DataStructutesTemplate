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

const long long M = 1e9+7;
class Solution {
public:
    bool isp(string &s){
        int n = s.length();
        int i = 0; int j = n-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return 1;
    }
    // vector<long long> ppow{1};
    int get_hv(string &cs){
        long long p = 31; long long ppow=1;
        long long hv = 0;
        for(auto &i: cs){
            hv=(hv+((i-'a'+1)*ppow)%M)%M;
            ppow*=p;
        }
        return hv;
    }
    vector<map<int, int>> dp;
    int dfs(int curr, string &cs , int &visited, 
                vector<vector<int>> &g, string &label){
        // visited.insert(curr);
        visited|=(1<<curr);
        cs.push_back(label[curr]);
        int hv = get_hv(cs);
        if(dp[curr][hv]){ 
            visited^=(1<<curr);
            cs.pop_back();
            return dp[curr][hv];
        }
        int ans{0};
        if(isp(cs)) ans = cs.size();
        // if(ans==5) cout<<cs<<' ';
        for(auto i: g[curr]){
            if(visited & (1<<i)) continue;
            int cans = dfs(i, cs, visited, g, label);
            ans = max(ans, cans);
        }
        // visited.erase(curr);
        visited^=(1<<curr);
        cs.pop_back();
        dp[curr][hv]=ans;
        return ans;
    }
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<vector<int>> g(n);
        for(auto &i: edges){
            int a = i[0]; int b = i[1];
            g[a].push_back(b);g[b].push_back(a);
        }
        int ans{0};
        int visited{0};
        string cs;
        dp.resize(n);
        for(int i = 0;i<n;i++) 
            ans = max(ans, dfs(i, cs, visited, g, label));
        return ans;


    }
};

int main() {
    // cout<<StringChallenge("**+*{2} mmmrrrkbb");
    // string st = "bbbab";
    Solution s;
    // vector<string> d {"a","b","ba","bca","bda","bdca"};
    vector<int> v1 {1,2,3}; // = {3,1,5,3,1,1};
    vector<int> v2{2,4};
    vector<vector<int>> v{{0,1},{0,4},{0,5},{1,7},{2,3},{2,4},{2,5},{3,6},{4,6},{4,7},{6,8},{7,8}};
    
    vector<string> s1{"SAVE20","","PHARMA5","SAVE@20"};
    vector<string> s2{"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isA {1,1,1,1};
    vector<char> c1{'a','a','c','d','d','d','g','o','o'};
    vector<vector<int>> v12 {{2,0},{4,0},{4,1},{4,2},{1,2},{0,3},{2,3},{3,4}};
    vector<vector<int>> v13 {{0,1,2},{1,2,4}};
    vector<vector<char>> vc {{'1', '0', '1', '0', '0'},{'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<string>> vs{{"a","0549"},{"b","0457"},{"a","0532"},{"a","0621"},{"b","0540"}};
    // cout<<"Hello";
    // for(auto i: s.validateCoupons(s1, s2, isA)) {
    //     cout<<i;
    // }
    cout<<s.maxLen(5, v12, "jjggj");
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
