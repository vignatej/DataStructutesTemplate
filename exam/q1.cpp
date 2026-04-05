#include <bits/stdc++.h>
using namespace std;


#define LL long long
class Solution {
public:
    long long g1(LL fc, LL ec, int i, int j, vector<LL> &ps){
        LL c1 = ps[j+1]-ps[i];
        if(c1==0) return fc;
        return 1LL*(j-i+1)*(c1)*(ec);
    }
    long long solve(LL fc, LL ec, int i, int j, vector<LL> &ps){
        if(i>j) return 0;
        pair<LL, int> ans = {g1(fc, ec, i, j, ps), -1*((j-i+1)%2==0)}; int ans_i = j;
        if((j-i+1)%2) return ans.first;
        int l = i, r=j-1;
        while(l<=r){
            int m1 = l+(r-l)/3;
            int m2 = r-(r-l)/3;
            pair<LL, int> a1 = {g1(fc, ec, i, m1, ps)+g1(fc, ec, m1+1, j, ps), 
                                 -1*((m1-i+1)%2==0)-((j-m1)%2==0)};
            pair<LL, int> a2 = {g1(fc, ec, i, m2, ps)+g1(fc, ec, m2+1, j, ps),
                               -1*((m2-i+1)%2==0)-((j-m2)%2==0)};
            if(a1<=a2){
                r=m2-1;
                if(ans>a1){ans=a1; ans_i=m1;}
            }else{
                l=m1+1;
                if(ans>a2){ans=a2; ans_i=m2;}
            }
        }
        if(ans_i==j ||(j-i)%2==0) return ans.first;
        ans.first=solve(fc, ec, i, ans_i, ps)+solve(fc, ec, ans_i+1, j, ps);
        return ans.first;
    }
    long long minCost(string s, int encCost , int flatCost ) {
        int n = s.length();
        LL ec = encCost; LL fc = flatCost;
        // if(fc<=ec){
        //     LL ans{0};
        //     for(auto i: s) if(i=='1') ans+=ec;
        //     for(int i =1;i<n;i++) if(s[i-1]=='0' && s[i]=='1') ans+=fc;
        //     if(s[n-1]=='0') ans+=fc;
        //     return ans;
        // }
        vector<LL> ps(n+1, 0);
        for(int i = 0;i<n;i++){
            ps[i+1]=ps[i];
            if(s[i]=='1') ps[i+1]++;
        }
        return solve(fc,ec, 0, n-1, ps);
    }
};

signed main(){
    Solution s;
    vector<int> v{1,1,2,2};
    // vector<int> ans = s.makeParityAlternating(v);
    // cout<<ans[0]<<' '<<ans[1];
    vector<vector<int>> g{{7,8,9}};
    cout<<s.minCost("010", 22, 8);
    return 0;
}