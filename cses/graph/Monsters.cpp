#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif
    int n,m; cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin>>v[i][j];
    vector<pair<pair<int, int>, string>> A;
    set<pair<int, int>> M;
    vector<vector<char>> MP = v;
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) 
        if(v[i][j]=='A'){MP[i][j]='.';A.push_back({{i, j}, ""});}
        else if(v[i][j]=='M'){
            M.insert({i, j});
        }
    vector<vector<char>> prev=v;
    vector<vector<int>> ne{{-1, 0, 'U'},{1, 0,'D'},{0,1,'R'},{0,-1,'L'}};
    while(A.size()){
        // for(auto i: MP){
        //     for(auto j: i) cout<<j;
        //     cout<<'\n';
        // }

        // cout<<"---------------------\n";
        for(auto i: A){
            int cx = i.first.first; int cy = i.first.second;
            if(!(cx==0 || cx==n-1 || cy==0 || cy==m-1)) continue;
            // cout<<"YES\n"<<i.second.length()<<'\n'<<i.second;
            // cout<<prev[cx][cy];
            vector<char> ans;
            while(v[cx][cy]!='A'){
                // cout<<prev[cx][cy];
                ans.push_back(prev[cx][cy]);
                for(auto j: ne){
                    if(j[2]==prev[cx][cy]){cx-=j[0]; cy-=j[1]; break;}
                }
            }
            // cout<<prev[cx][cy];
            cout<<"YES\n"<<ans.size()<<'\n';
            reverse(ans.begin(), ans.end());
            for(auto &i: ans) cout<<i;
            return 0;
        }
        decltype(M) nmp;
        for(auto i: M){
            int mx=i.first; int my=i.second;
            for(auto j: ne){
                int nmx=mx+j[0]; int nmy=my+j[1];
                if(0<=nmx && nmx<n && 0<=nmy && nmy<m && v[nmx][nmy]!='#' && MP[nmx][nmy]!='M'){
                    nmp.insert({nmx, nmy});
                }
            }
            // MP[mx][my]='.';
        }
        M=nmp;
        for(auto i: M) MP[i.first][i.second]='M';
        decltype(A) nap;
        set<pair<int, int>> a_s;
        for(auto &i: A){
            int cx = i.first.first; int cy = i.first.second;
            // string cs = i.second;
            for(auto &j: ne){
                int nax=i.first.first+j[0]; int nay=i.first.second+j[1];
                if(!(0<=nax && nax<n && 0<=nay && nay<m)) continue;
                if(MP[nax][nay]=='M' || v[nax][nay]=='#') continue;
                // cs+=j[2];
                if(a_s.find({nax, nay})!=a_s.end()) continue;
                a_s.insert({nax, nay});
                nap.push_back({{nax, nay},i.second});
                if(prev[nax][nay]=='.') prev[nax][nay]=j[2];
            }
        }
        A=nap;
    }
    cout<<"NO";
    

    return 0;
}