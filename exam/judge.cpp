#include <bits/stdc++.h>
using namespace std;


signed main(){
    int T; T = 1;
    cout<<T<<'\n'<<flush;
    while(T--){
        int n; n = 4;
        cout<<n<<'\n'<<flush;
        vector<int> v{0, 2, 1, 2, 1};
        int quer{0};
        while(true){
            if(quer>ceil((3*n)/2)){
                // cout<<"MAny quer\n";
                return 1;
            }
            quer++;
            string curr;
            if(!(cin>>curr)) return 1;
            if(curr=="swap"){
                int x; cin>>x;
                if(x<1 || x>n-1) return 1;
                swap(v[x], v[x+1]);
            }else if(curr=="throw"){
                int x; cin>>x;
                if(x<1 || x>n) return 1;
                int jmps = 0;
                int c = x;
                while(c<=n){
                    c+=v[c];
                    jmps++;
                }
                cout<<jmps<<'\n'<<flush;
            }else if(curr=="!"){
                vector<int> ans(n+1, 0);
                for(int i = 1;i<=n;i++) cin>>ans[i];
                for(int i = 1;i<=n;i++) if(ans[i]!=v[i]){
                    // cout<<"WA\n";
                    return 1;
                }
                // cout<<"YAY! Test case passed\n"<<flush;
                break;
            }
        }
    }
    // cout<<"All tests passed\n"<<flush;

    return 0;
}