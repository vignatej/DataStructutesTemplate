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
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long
class xornode{
public:
    int v;
    xornode* child[2];
    xornode(){
        v=0;child[0]=nullptr; child[1]=nullptr;
    };
};
class xortrie{
public:
    xornode *root;
    xortrie(){root=new xornode();}
    void insert(int val){
        xornode* curr = root;
        for(int i = 31;i>=0;i--){
            int bit = (val>>i) & 1;
            if(!curr->child[bit]) 
                curr->child[bit] = new xornode();
            curr = curr->child[bit];
            curr->v++;
        }
    }void remove(int val){
        xornode* curr = root;
        for(int i = 31;i>=0;i--){
            int bit = (val>>i) & 1;
            if(!curr->child[bit]) return;
            curr=curr->child[bit];
            curr->v--;
        }
    }int max_xor(int val){
        int ans{0};
        xornode* curr = root;
        for(int i = 31;i>=0;i--){
            int bit = (val>>i)&1;
            if(curr->child[1-bit] && curr->child[1-bit]->v>0){
                ans += (1<<i);
                curr=curr->child[1-bit];
            }else{
                curr=curr->child[bit];
            }
        }return ans;
    }
};
