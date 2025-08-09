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
class Solution {
public:
    vector<vector<int>> points;
    double dist(int p1, int p2){
        double x1{points[p1][0]};
        double y1{points[p1][1]}; 
        double x2{points[p2][0]}; 
        double y2{points[p2][1]};
        return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    double slope(int x1, int y1, int x2, int y2){
        if(x1==x2) return 1e9;
        return (double)(y2-y1)/(x2-x1);
    }
    bool ist(int a, int b, int c){
        bool ya = 1;
        double ab = dist(a, b);
        double bc = dist(c, b);
        double ca = dist(a, c);
        vector<double> q{ab, bc, ca};
        sort(q.begin(), q.end());
        if(q[2]==q[0]+q[1]) ya = 0;
        return ya;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        this->points = points;
        map<double, vector<pair<int, int>>> m;
        map<double, map<int, int>> ma;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                double cs = slope(points[i][0],points[i][1],points[j][0],points[j][1]);
                m[cs].push_back({i, j});
                ma[cs][i]++;ma[cs][j]++;
            }
        }
        set<set<int>> ss;
        for(auto &q: m){
            int cans{0};
            double cs = q.first;
            vector<pair<int, int>> &cv = q.second;
            int cvs = cv.size();
            for(int i = 0;i<cvs;i++){
                for(int j = i+1;j<cvs;j++){
                    int a = cv[i].first;
                    int b = cv[i].second;
                    int c = cv[j].first;
                    int d = cv[j].second;
                    if(!(dist(a,c) && dist(a, d) && dist(b, c) && dist(b, d))){continue;}
                    if(ist(a, b, c) && ist(a, b, d)) 
                        ss.insert({a, b, c, d});
                    // if(ist(a, b, d) && ist(a, b, d)) ss.insert({a, b, c, d});
                    
                }
            }
        }
        return ss.size();
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
    vector<vector<int>> v12 {{82,7},{82,-9},{82,-52},{82,78}};
    vector<vector<int>> v13 {{0,1,2},{1,2,4}};
    vector<vector<char>> vc {{'1', '0', '1', '0', '0'},{'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<string>> vs{{"a","0549"},{"b","0457"},{"a","0532"},{"a","0621"},{"b","0540"}};
    // cout<<"Hello";
    // for(auto i: s.validateCoupons(s1, s2, isA)) {
    //     cout<<i;
    // }
    cout<<s.countTrapezoids(v12);
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
