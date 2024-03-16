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

int pow2_max(int n){
    for(int i = 0;i<30;i++){
        int a = pow(2, i);
        if(a>=n) return a;
    }
    return pow(2, 30);
}

class segment_tree_for_sum{
public:
    vector<int> arr;
    segment_tree_for_sum(vector<int> nums){
        int n = nums.size();
        n=pow2_max(n);
        arr.resize(2*n, 0);
        for(int i = 0;i<nums.size();i++){
            arr[i+n]=nums[i];
        }
        for(int i = n-1;i>0;i--){
            arr[i] = arr[2*i]+arr[2*i+1];
        }
    }
    int sum(int a, int b){
        int n = arr.size()/2;
        a+=n; b+=n;
        int s = 0;
        while(a<=b){
            if(a%2 == 1) {s += arr[a];a++;}
            if(b%2==0){s += arr[b]; b--;}
            a/=2;b/=2;
        }
        return s;
    }
    void add_element(int posn, int elem){ // it will only add, not change
        int n = arr.size()/2;
        posn+=n;
        while(posn>0){
            arr[posn]+=elem;
            posn/=2;
        }
    }
    void change_element(int posn, int elem){
        int n = arr.size()/2;
        int p = posn+n;
        int diff = -arr[p]+elem;
        add_element(posn, diff);
    }
};
class segment_tre_for_max{
public:
    vector<int> arr;
    segment_tre_for_max(vector<int> &nums){
        int n = nums.size();
        n=pow2_max(n);
        arr.resize(2*n, numeric_limits<int>::min());
        for(int i = 0;i<nums.size();i++){
            arr[i+n] = nums[i];
        }
        for(int i = n-1;i>0;i--){
            arr[i] = max(arr[2*i], arr[2*i+1]);
        }
    }
    int find_max(int a, int b){
        int  n = arr.size()/2;
        a+=n; b+=n;
        int m = numeric_limits<int>::min();
        while(a<=b){
            if(a%2==1){m=max(m, arr[a]);a++;}
            if(b%2==0){m=max(m, arr[b]); b--;}
            a/=2; b/=2;
        }
        return m;
    }
};
class min_seg_tree{
public:
    vector<int> arr;
    min_seg_tree(vector<int>& v){
        int n = v.size();
        int j = 0;
        while(pow(2, j)<n) j++;
        int nn = pow(2, j)*2;
        arr.resize(nn, INT_MAX);
        for(int i = 0;i<n;i++){
            arr[(nn/2)+i] = v[i];
        }n = nn/2;
        for(int i = n-1;i>0;i--) arr[i] = min(arr[2*i], arr[2*i +1]);
    }
    int get_min(int i, int j){
        int n = arr.size()/2;
        i+=n;j+=n;
        int ans = INT_MAX;
        while(i<=j){
            if(i%2==1){ans = min(ans, arr[i]);i++;}
            else if(j%2==0){ans=min(ans, arr[j]);j--;}
            i/=2;j/=2;
        }return ans;
    }
};
class max_seg_tree{
public:
    vector<int> arr;
    max_seg_tree(vector<int>& v){
        int n = v.size();
        int j = 0;
        while(pow(2, j)<n) j++;
        int nn = pow(2, j)*2;
        arr.resize(nn, -1);
        for(int i = 0;i<n;i++){
            arr[(nn/2)+i] = v[i];
        }n = nn/2;
        for(int i = n-1;i>0;i--) arr[i] = max(arr[2*i], arr[2*i +1]);
    }
    int get_max(int i, int j){
        int n = arr.size()/2;
        i+=n;j+=n;
        int ans = -1;  
        while(i<=j){
            if(i%2==1){ans = max(ans, arr[i]);i++;}
            else if(j%2==0){ans=max(ans, arr[j]);j--;}
            i/=2;j/=2;
        }return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,55,3,4,};
    // auto a = segment_tree_for_sum(nums);
    // cout<<a.sum(1,3)<<endl;
    // a.add_element(2,8);
    // a.change_element(2,3);
    // cout<<a.sum(1,3);
    auto b = segment_tre_for_max(nums);
    // for(auto i: b.arr) cout<<i<<endl;
    cout<<b.find_max(2,3);
}

#define pii pair<int, int>
class max_for_first_greater{
public:
    vector<pii> arr;
    int nn;
    max_for_first_greater(vector<int> nums){
        int n = nums.size();
        int i = 1;
        while(pow(2, i)<n) i++;
        nn = pow(2, i);
        arr.resize(nn*2,{0,nn*2});
        for(int i = 0;i<n;i++) arr[nn+i]={nums[i],i};
        for(int i = nn-1;i>0;i--){
            if(arr[2*i].first>=arr[2*i+1].first){arr[i]=arr[2*i];}
            else{arr[i]=arr[2*i+1];}
        };
    };
    int next_max_index(int req, int start_index){
        int  i = start_index + nn;
        while(arr[i].first<req){
            if(i%2==1){
                i++;
                if(__builtin_clz(i)+__builtin_ctz(i)+1==32) return -1;
            }
            else {i/=2;} 
            if(i==0) break;
        } 
        if(i==0) return -1;
        // while(i<nn && arr[i].second<start_index) i=2*i+1;
        while(i<nn){
            if(arr[2*i].first>=req) i=2*i;
            else i=2*i+1;
        }
        return arr[i].second;
    }
};