#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> f;deque<int> b;
        int m1, m2;m1=1;m2=1;
        auto fi = nums.begin();auto bi = nums.rbegin();
        for(;fi!=nums.end() && bi!=nums.rend();fi++, bi++){
            m1 *= *fi; m2 *= *bi;
            f.push_back(m1);b.push_front(m2);
        };
        vector<int> ans;
        int curr = 0;
        int l = nums.size();
        while(curr < l){
            if(curr == 0){
                ans.push_back(b.at(1));
            }else if(curr == l-1){
                ans.push_back(f.at(l-2));
            }else{
                ans.push_back(f.at(curr-1)*b.at(curr+1));
            }

            curr++;
        }return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v {-1,1,0,-3,3};
    Solution s;
    s.productExceptSelf(v);
    return 0;
}
