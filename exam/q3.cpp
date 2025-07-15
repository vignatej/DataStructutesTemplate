#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

bool isp(int num){
    string s = to_string(num);
    string rs = s; reverse(rs.begin(), rs.end());
    return s==rs;
}

bool checkBaseApall(int num, int b){
    int og = num;
    string s;
    while(num){
        s.push_back('0'+(num%b));
        num/=b;
    }
    string rs = s; reverse(rs.begin(), rs.end());
    if(s==rs){
        // cout<<og<<'\n';
    }

    return s==rs;
}

int solve(int n, int a, int mp){
    int ans{0};
    for(int i = pow(10, n/2 -1);i<pow(10, n/2);i++){
        string s = to_string(i);
        if(s.length() < n/2)
            s = string(n/2 - s.length(), '0') + s;
        if(n%2){
            for(int e = '0';e<='9';e++){
                s.push_back(e);
                int j = (n/2) -1;
                while(j>=0){
                    s.push_back(s[j]);
                    j--;
                }
                int num = stoll(s);
                if(num<=mp && checkBaseApall(num, a)) ans+=num;
                j = (n/2) -1;
                while(j>=0){
                    s.pop_back();
                    j--;
                }
                s.pop_back();
            }
            continue;
        }
        int j = (n/2) -1;
        while(j>=0){
            s.push_back(s[j]);
            j--;
        }
        int num = stoll(s);
        if(num<=mp && checkBaseApall(num, a)) ans+=num;
    }
    return ans;
}

int do_it1(int a, int n){
    int ans{0};
    // vector<int> vv{1,2,3,4,5,6,7,8,9};
    // for(auto i: vv) if(checkBaseApall(i, a)) ans+=i;

    for(int i = 1;i<=to_string(n).length();i++) ans+=solve(i, a, n);
    return ans;
}
int do_it2(int a, int n){
    int ans{0};
    for(int i = 1;i<=n;i++){
        if(isp(i) && checkBaseApall(i, a)){ 
            ans+=i;
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int a; int n; cin>>a>>n;
    // cout<<"First\n";
    // int ans1 = do_it1(a, n);
    // cout<<"Second\n";
    // int ans2 = do_it2(a, n);
    // cout<<ans1<<' '<<ans2<<'\n';
    // if(ans1==ans2) cout<<"YES";
    // else cout<<"NO";


    cout<<do_it1(a, n);
    return 0;
}