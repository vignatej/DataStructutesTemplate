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
#define ll long long
#define ll long long

//implementation of multiset with AVL tree
// solution for leetcode Q: 3072. Distribute Elements Into Two Arrays II


class ds{
public:
    ds *l{nullptr}, *r{nullptr};
    int m; int oc{1}; int tc{1};
    // m: curr element; 
    // oc: overall count: (no of elements down the tree including curr_element)
    //    this is updated for every inserting every 
    // tc: this count (count of elements with value=m)
    ds(int v){
        m=v;
    }
    void insert(int i){
        oc++;
        if(i==m){tc++; return;}
        else if(i<m){
            if(!l){l=new ds(i);}
            else l->insert(i);
        }else{
            if(!r){r=new ds(i);}
            else r->insert(i);
        }
        if(l && l->hd()>1){
            l = rotateRight(l);
        }else if(l && l->hd()<-1){
            l = rotateLeft(l);
        }
        if(r && r->hd()>1){
            r = rotateRight(r);
        }else if(r && r->hd()<-1){
            r = rotateLeft(r);
        }
    
    }
    // finds count greater_than i
    int find_count(int i){
        if(i==m) {return tc+(l?l->oc:0);}
        else if(i<m){return (l?l->find_count(i):0);}
        else{return (l?l->oc:0) + tc+(r?r->find_count(i):0);}
    }
    // finds height difference
    int hd(){
        int lh = l ? l->oc : 0; int rh = r ? r->oc:0;
        return lh-rh;
    }
    ds* rotateLeft(ds* x){
        ds* y = x->r;
        int oyc = y->oc; int oxc = x->oc;
        oxc -= oyc;
        int bc = y->l ? y->l->oc:0;
        oyc -= bc; oxc+=bc; oyc+=oxc;
        x->oc = oxc; y->oc = oyc;
        x->r=y->l; y->l=x;
        return y;
    }

    ds* rotateRight(ds* x){
        ds* y = x->l; 
        int oyc = y->oc; int oxc = x->oc;
        oxc-=oyc;
        int bc = y->r ? y->r->oc : 0;
        oyc-=bc; oxc+=bc; oyc+=oxc;
        x->oc = oxc; y->oc = oyc;
        x->l = y->r; y->r=x;
        return y;
    }
};


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        // vector<int> fv{nums[0]}, sv{nums[1]};multiset<int> fs{nums[0]}, ss{nums[1]};
        ds* f = new ds(nums[0]);
        ds* s = new ds(nums[1]);
        vector<int> fv{nums[0]}, sv{nums[1]};
        for(int i = 2;i<n;i++){
            int gc1 = f->oc - f->find_count(nums[i]);
            int gc2 = s->oc - s->find_count(nums[i]);
            if(gc1>gc2){
                f->insert(nums[i]);fv.push_back(nums[i]);
            }else if(gc1<gc2){
                s->insert(nums[i]);sv.push_back(nums[i]);
            }else if(f->oc<s->oc) {
                f->insert(nums[i]);fv.push_back(nums[i]);
            }else if(f->oc > s->oc){
                s->insert(nums[i]);sv.push_back(nums[i]);
            }else{
                f->insert(nums[i]);fv.push_back(nums[i]);
            }
        }
        copy(sv.begin(), sv.end(), back_inserter(fv));
        return fv;
    
    }
};

int main() {
    Solution s;
    vector<int> v1 {2,1,3,3}; // = {3,1,5,3,1,1};
    for(auto i: s.resultArray(v1)) cout<<i<<" ";
};
