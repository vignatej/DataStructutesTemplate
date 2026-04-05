#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n; cin>>n;
    vector<int> v(n); for(auto &i: v) cin>>i;
    int f{0}, l{0};
    for(int i = 0;i<n;i++){
        if(f==0) f=v[i];
        if(v[i]!=0) l=v[i];
    }
    // v.insert(v.begin(), f);
    // v.insert(v.end(), l);
    int i = 0; int j = 1;
    map<char, vector<int>> m;
    while(i<n){
        if(v[i]==0){i++; continue;}
        if(j<=i) j=i+1;
        while(j<n && v[j]==0) j++;
        if(j-i>1){
            if(v[i]%2==0 && v[j]%2==0) m['e'].push_back(j-i-1);
            else if(v[i]%2!=0 && v[j]%2!=0) m['o'].push_back(j-i-1);
            else m['b'].push_back(j-i-1);
        }
        i=j;
    }
    set<int> rem; for(int i=1;i<=n;i++) rem.insert(i);
    for(int i = 0;i<n;i++){
        if(v[i]!=0) rem.erase(v[i]);
    }
    int ans{0};
    for(int i =1;i<n;i++) if(v[i]!=0 && v[i+1]!=0 && v[i]%2!=v[i+1]%2)
        ans++;
    vector<int> e, o;
    for(auto i: rem) if(i%2==0) e.push_back(i); else o.push_back(i);
    sort(m['e'].rbegin(), m['e'].rend());
    while(e.size() && m['e'].size()){
        int bs = m['e'].back(); m['e'].pop_back();
        int es = e.size();
        int ms = min(bs, es);
        bs-=es;
        while(ms>0){e.pop_back(); ms--;}
        if(bs>0) m['e'].push_back(bs);
    }    

    sort(m['o'].rbegin(), m['o'].rend());
    while(o.size() && m['o'].size()){
        int bs = m['o'].back(); m['o'].pop_back();
        int os = o.size();
        int ms = min(bs, os);
        bs-=os;
        while(ms>0){o.pop_back(); ms--;}
        if(bs>0) m['o'].push_back(bs);
    }  

    
    
    ans+=m['b'].size();
    ans+=2*m['e'].size(); 
    if(m['e'].size()){
        if(v[1]!=0 && v.front()%2==0) ans--;
        if(v[n]!=0 && v.back()%2==0) ans--; 
    }
    ans+=2*m['o'].size();
    if(m['o'].size()){
        if(v[1]!=0 && v.front()%2!=0) ans--;
        if(v[n]!=0 && v.back()%2!=0) ans--; 
    }
    cout<<ans<<'\n';
    
    return 0;
}