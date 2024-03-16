#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class TrieNode{
    public:
        map<char, TrieNode*> m;
        bool is_end;
        TrieNode(bool tr){this->is_end = tr;};
        TrieNode(){is_end = false;};
        TrieNode* insert(char c){
            auto it = m.find(c);
            if(it == m.end()){
                m[c] = new TrieNode();
                return m[c];
            }return m[c];
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){root = new TrieNode();}
        bool insert(string s){
            auto curr = root;
            for(char i:s){
                auto nxt = curr->insert(i);
                curr = nxt;
            }
            curr->is_end = true;
            return true;
        }
        bool search(string s){
            auto curr = root;
            for(auto i:s){
                auto it = curr->m.find(i);
                if(it == curr->m.end()){return false;}
                curr = it->second;
            }if(curr->is_end) return true;
            return false;
        }
};

int main()
{
    Trie t;
    t.insert("helo");
    t.insert("nair");
    cout<<t.search("nair");    
}
