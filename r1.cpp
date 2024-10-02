#include <bits/stdc++.h>
using namespace std;


class treenode{
public:
    int val; 
    treenode* l{nullptr}; 
    treenode *r{nullptr};
};
class node{public:
    int v; node* next{nullptr}; 
    node(int val){
        this->v = val;
    }
};
node* preorder(treenode* t){
    if(!t) return nullptr;
    node* n = new node(t->val);
    n->next = preorder(t->l);
    node* temp = n;
    while(temp->next!=nullptr) temp=temp->next;
    temp->next = preorder(t->r);
};


int main(){
    treenode *t; // create tree
    vector<int> v;
    node* ans = preorder(t);
    // node* h = new node(v[0]);
    // node* temp = h;
    // for(int i = 1;i<v.size();i++){
    //     temp->next = new node(v[i]);
    //     temp=temp->next;
    // }
    // h is linked list
}