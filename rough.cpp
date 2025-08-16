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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        // for(int i = n-2;i>=0;i--){
        //     if(nums[i]<nums[i+1]){
        //         swap(nums[i], nums[i+1]);
        //         return;
        //     }
        // }
        // bool a = next_permutation(nums.begin(), nums.end());
        // if(a) return; 
        // reverse(nums.begin(), nums.end());
        // if(nums[n-2]<nums[n-1]){
        //     swap(nums[n-2], nums[n-1]);
        //     return;
        // }
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                int j = i+1;
                while(j<n-1 && nums[j]>nums[j+1]) j++;
                int mn = nums[i+1]; int kp = i+1;
                for(int k = i+1;k<=j;k++){
                    if(nums[k]<mn && nums[k]>nums[i]){
                        mn=nums[k]; kp=k;
                    }
                }
                cout<<i<<' '<<j<<' '<<kp;
                swap(nums[i], nums[kp]);
                sort(next(nums.begin(), i+1), next(nums.begin(), j+1));
                return;
            }
        }
        int c = n-2;
        while(c>0 && nums[c-1]>nums[c]) c--;
        reverse(next(nums.begin(), c), nums.end());
    }
};

int main() {
    // cout<<StringChallenge("**+*{2} mmmrrrkbb");
    // string st = "bbbab";
    Solution s;
    // vector<string> d {"a","b","ba","bca","bda","bdca"};
    vector<int> v1 {1,3, 2}; // = {3,1,5,3,1,1};
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
    s.nextPermutation(v1);
    for(auto i: v1) {
        cout<<i<<' ';
    }
    // cout<<s.nextPermutation(v1);
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
