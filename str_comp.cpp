#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

class Solution {
public:
    auto ins(vector<char>& chars, vector<char>::iterator it, int num){
        string a = to_string(num);
        for(auto i:a){
            chars.insert(it, (char) i);
            it++;
        }  return it;
    }
    int compress(vector<char>& chars) {
        auto i = chars.begin();int curr=0;
        while(i<chars.end()){
            int j = 0;
            while(i+j<chars.end() && *i == *(i+j)) j++;
            if(j==1){i++;curr++;continue;}
            chars.erase(i+1, i+j);
            i = ins(chars, i+1, j);
        }return chars.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<char> v {'b','b','a','a','a','a','a','a','a','a','a','a','a','b'};
    cout<<s.compress(v)<<endl;
    for(auto i: v){
        std::cout<<i<<", ";
    }
}
