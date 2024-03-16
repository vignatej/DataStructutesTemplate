#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int st {0}, en{0};
        string ans;
        int l=s.length();
        vector<string> v;
        while(st<l && en<l){
            while(s[st]==' ' && st<l){
                st++;
            }if (st == l) break;
            en=0;
            while(s[st+en]!=' ' && st+en<l){
                en++;
            };
            v.push_back(s.substr(st, en));
            st+=en;
        };
        // std::copy(v.rbegin(), v.rend(), std::back_inserter(ans));
        for(auto i = v.rbegin(); i!=v.rend();++i){
            ans+=*i;
            if(i != v.rend()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string ans = s.reverseWords("    hello world   ");
    // string s = "ghsj";
    cout<<"--"<<ans<<"--"<<std::endl;
    
    return 0;
}
