#include <bits/stdc++.h>
using namespace std;

#define LL long long
class Solution {
public:
    LL solve(int i, int es, int os, string s, bool t){
        int n = s.size();
        if(i==n){
            return es==os?1:0;
        }
        LL ans{0};
        if(!t){
            for(int j = 0;j<=9;j++){
                if(i%2==0) {
                    es+=j; 
                    ans+=solve(i, es, os, s, t);
                }else{
                    os+=j;
                    ans+=solve(i, es, os, s, t);
                }
            }
        }else{
            for(int j = 0;j<=s[i]-'0';j++){
                if(i%2==0) {
                    es+=j; 
                    ans+=solve(i, es, os, s, j==s[i]-'0');
                }else{
                    os+=j;
                    ans+=solve(i, es, os, s, j==s[i]-'0');
                }
            }
        }

        return ans;
    }
    long long countBalanced(long long low, long long high) {
        string cs = ""; 
        string hs = to_string(high);
        LL ans = solve(0, 0,0,hs, 1);
        string ls = to_string(low);
        ans -= solve(0,0,0, ls, 1);
        return ans;
    }
};

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif
    Solution s;
    vector<int> v{73,32,54};
    cout<<s.minAllOneMultiple(15);


    return 0;
}