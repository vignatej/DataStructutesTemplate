#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int P = 31;
const int M = 1e9+7;
#define max_char 'Z'
#define min_char 'A'
int powl(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    int ans = powl(a, b/2);
    ans*=ans; ans%=M;
    if(b%2) ans*=a;
    ans%=M;
    return ans;
}
vector<int> ppow{1};
vector<int> ph{0};
int n, m;

bool match(int cl, deque<int> &hash){
    int f1 = (ph[m]-ph[0]+M)%M;
    f1 = (f1*ppow[n-m])%M;
    int f2 = (hash.back()-hash.front()+M)%M;
    f2 = (f2*ppow[n-cl])%M;
    return f1==f2;
}

int solve(int cl, deque<char> &cs, deque<int> &chash){
    if(match(cl, chash)){
        return powl(26, n-cl);
    }
    if(cl==n) return 0;
    if(cl>m){
        cs.pop_back();
        chash.pop_back();
    }
    int ans = 0;
    for(char i = min_char;i<=max_char;i++){
        cs.push_back(i);
        chash.PB(chash.back()+(i-min_char+1)*ppow[cl]);
        ans = (ans+solve(cl+1, cs, chash))%M;
        chash.pop_back();
        cs.pop_back();
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    cin>>n;
    string p; cin>>p; m = p.length();
    for(int i = 1;i<=n*m+1;i++) ppow.PB((ppow.back()*31)%M);
    ph.resize(n+1);
    for(int i = 0;i<m;i++){
        ph[i+1]=(ph[i]+(p[i]-min_char+1)*ppow[i])%M;
    }
    deque<char> cs;
    deque<int> chash{0};
    int ans = solve(0, cs, chash);
    cout<<ans;
    
    return 0;
}