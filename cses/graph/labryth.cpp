#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin>>v[i][j];
    int ax, ay, bx, by;
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) 
        if(v[i][j]=='A'){ax=i;ay=j;}
        else if(v[i][j]=='B'){bx=i;by=j;}
    vector<vector<int>> len(n, vector<int>(m, -1));
    
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {ax, ay}}); bool comp=false;
    while(pq.size()){
        int cl = pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();
        if(!(0<=cx && cx<n && 0<=cy && cy<m && 
                len[cx][cy]==-1 && v[cx][cy]!='#')) continue;
        len[cx][cy]=cl*(-1);
        if(cx==bx && cy==by) comp=1;
        vector<vector<int>> np{{-1, 0},{1, 0},{0,1},{0,-1}};
        for(auto &j: np){
            int nx=cx+j[0]; int ny=cy+j[1];
            if(0<=nx && nx<n && 0<=ny && ny<m && 
                len[nx][ny]==-1 && v[nx][ny]!='#')
                pq.push({cl-1, {nx, ny}});
        }
        if(comp) break;
    }
    // int cl{0};
    // vector<vector<int>> curr{{ax, ay}};
    // bool comp = false;
    // while(curr.size()){
    //     vector<vector<int>> next;
    //     for(auto &i: curr){
    //         len[i[0]][i[1]]=cl;
    //         if(i[0]==bx && i[1]==by) comp=1;
    //         vector<vector<int>> np{{-1, 0},{1, 0},{0,1},{0,-1}};
    //         for(auto &j: np){
    //             int nx=i[0]+j[0]; int ny=i[1]+j[1];
    //             if(0<=nx && nx<n && 0<=ny && ny<m && 
    //                 len[nx][ny]==-1 && v[nx][ny]!='#')
    //                 next.push_back({nx, ny});
    //         }
    //     }    
    //     if(comp) break;
    //     cl++;
    //     curr=next;
    // }
    if(!comp){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<len[bx][by]<<'\n';
    int cl={len[bx][by]};
    int cx=bx; int cy=by; string ans;
    while(cl!=0){
        vector<vector<int>> np{{-1, 0, 'D'},{1, 0,'U'},{0,1,'L'},{0,-1,'R'}};
            for(auto &j: np){
                int nx=cx+j[0]; int ny=cy+j[1];
                if(0<=nx && nx<n && 0<=ny && ny<m && 
                    len[nx][ny]==cl-1 && v[nx][ny]!='#'){
                        cx=nx; cy=ny; cl--; 
                        ans.push_back(j[2]);
                        break;
                    }
            }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;

    return 0;
}