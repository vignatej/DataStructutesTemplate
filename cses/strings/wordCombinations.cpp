#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;
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
        TrieNode* root{nullptr};
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

ll calc(string &s, int i, TrieNode* root, TrieNode* curr, vector<int> &dp){
    if(!root || !curr) return 0;
    if(curr==root && dp[i]!=-1) return dp[i];
    int n = s.length();
    if(i==n) return 1;
    ll ans = 0;
    if(curr!=root && curr->is_end) ans = calc(s, i, root, root, dp);
    ans%=M;
    if(curr->m.find(s[i])!=curr->m.end()) 
        ans+=calc(s, i+1, root, curr->m[s[i]], dp);
    ans%=M;
    if(curr==root) dp[i]=ans;
    return ans;
}

signed main(){
    Trie t;
    string s; cin>>s; 
    int n; cin>>n;
    vector<string> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    for(auto &i: v) t.insert(i);
    vector<int> dp(s.length(), -1);
    cout<<calc(s, 0, t.root, t.root, dp);

    return 0;
}