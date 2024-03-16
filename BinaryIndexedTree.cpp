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
using namespace std;

class binaryIndexedTree{
public:
    vector<int> arr;
    binaryIndexedTree(vector<int> & nums){
        int n = nums.size();
        arr.resize(n+1, 0);
        for(int i=0;i<n;i++){
            add_to_tree(nums[i], i+1);
        }

    }
    void add_to_tree(int num, int posn){
        int n = arr.size();
        while(posn<n){
            arr[posn]+=num;
            posn += posn&(-posn);
        }
    }
    int get_sum(int posn){
        int s{0};
        while(posn>0){
            s+=arr[posn];
            posn-= (posn & (-posn));
        }
        return s;
    }
    int sum_range(int i, int j){
        int a = get_sum(i);
        int b = get_sum(j+1);
        return b-a;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v {1,3,4,8,6,1,4,2};
    auto a = binaryIndexedTree(v);
    for(int i=1;i<a.arr.size();i++) cout<<a.arr[i]<<"-";
    cout<<endl;
    cout<<a.sum_range(0,6 );
}
