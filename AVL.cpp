#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode *t){
    if(!t) return 0;
    int l = depth(t->left);
    int r = depth(t->right);
    return 1+max(l, r);
}

int bal_fac(TreeNode *t){
    if(!t) return 0;
    return abs(depth(t->left)- depth(t->right));
}

TreeNode* insert(TreeNode* root, int v){
    if(!root) return new TreeNode(v);
    if(v < root->val){ 
        root->left = insert(root->left, v);
        
    }if(v > root->val){ 
        root->right = insert(root->right, v);
    }
    if(bal_fac(root)<2) return root;
    int lh = depth(root->left);
    int rh = depth(root->right);
    
}

int main() {

}
