#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int get_val(vector<vector<int>> &ps, int x, int y){
        int n = ps.size()-1; int m = ps[0].size()-1;
        if(x<0 || y<0) return 0;
        if(x>=n) x=n-1; if(y>m-1) y=m-1;
        return ps[x][y+1];
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int oans{0}; int n = matrix.size(); int m = matrix[0].size();
        set<int> all_v; for(auto i: matrix) for(auto j: i) all_v.insert(j);
        for(auto cv: all_v){
            if(cv==0) continue;
            vector<vector<int>> ps(n+1, vector<int>(m+1, 0));
            for(int i = 0;i<m;i++){
                ps[0][i+1]=ps[0][i]+(matrix[0][i]>cv ? 1:0);
            }
            for(int i = 1;i<n;i++){
                for(int j = 0;j<m;j++){
                    ps[i][j+1]=ps[i][j]+(matrix[i][j]>cv ? 1:0);  
                }  
                for(int j = 0;j<=m;j++) ps[i][j]+=ps[i-1][j];
            }
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(matrix[i][j]!=cv) continue;
                    int ans = get_val(ps, i+cv, j+cv) - get_val(ps, i-cv-1, j+cv) - get_val(ps, i+cv, j-cv-1) + get_val(ps, i-cv-1, j-cv-1);
                    if(i-cv>=0 && j-cv>=0 && matrix[i-cv][j-cv]>cv) ans--;
                    if(i-cv>=0 && j+cv<m && matrix[i-cv][j+cv]>cv) ans--;
                    if(i+cv<n && j-cv>=0 && matrix[i+cv][j-cv]>cv) ans--;
                    if(i+cv<n && j+cv<m && matrix[i+cv][j+cv]>cv) ans--;
                    if(ans==0) oans++;
                }
            }
        }
        return oans;
        
        
        
        
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         int cv = matrix[i][j];
        //         if(cv==0) continue;
        //         bool poss = 1;
        //         for(int k = max(0, i-cv);k<=min(i+cv, n-1) && poss;k++){
        //             for(int l = max(0, j-cv);l<=min(j+cv, m-1) && poss;l++){
        //                 if((k==i-cv || k==i+cv) && (l==(j-cv) || l==(j+cv))) continue;
        //                 if(matrix[k][l]>cv) poss=0;
        //             }
        //         }
        //         if(poss) ans++;
        //     }
        // }
        // return ans;
        
    }
};

signed main() {
    Solution s;
    vector<vector<int>> mat{{1,1}};
    cout<<s.countLocalMaximums(mat);
};
