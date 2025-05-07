#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;


signed main() {
    int T; cin>>T;
    while(T){T--;
        int q; cin>>q;
        vector<deque<int>> lis(2);
        int ci{0};
        int cs{0};
        int ts{0};
        int ans1{0}, ans2{0};
        vector<int> ans{ans1, ans2};
        while(q--){
            int s; cin>>s;
            if(s==1){
                // ans1-=v.back()*cs;
                ans[ci]-=lis[ci].back()*cs;
                // ans1+=ts;
                ans[ci]+=ts;
                // ans2-=ts;
                ans[1-ci]-=ts;
                // ans2+=rv.front()*cs;
                ans[1-ci]+=lis[1-ci].front()*cs;
                // v.push_front(v.back()); v.pop_back();
                lis[ci].push_front(lis[ci].back()); lis[ci].pop_back();
                // rv.push_back(v.front()); rv.pop_front();
                lis[1-ci].push_back(lis[ci].front()); lis[1-ci].pop_front();
            }else if(s==2){
                // deque<int> temp=v;
                // v=rv; rv=temp;
                // int temp1 = ans1;
                // ans1=ans2; ans2=temp1;
                ci=1-ci;
            }else if(s==3){
                int new_val; cin>>new_val;
                cs++;
                // v.push_back(new_val);
                lis[ci].push_back(new_val);
                // ans1+=new_val*(cs);
                ans[ci]+=new_val*cs;
                // rv.push_front(new_val);
                lis[1-ci].push_front(new_val);
                // ans2+=ts; ans2+=new_val;
                ans[1-ci]+=ts; ans[1-ci]+=new_val;
                ts+=new_val;
            }
            // int c_a{0};
            // for(int i = 0;i<lis[0].size();i++) c_a+=lis[0][i]*(i+1);
            // if(c_a!=ans[0]){cout<<"not matching1"<<'\n';}
            // int c_b{0};
            // for(int i = 0;i<lis[1].size();i++) c_b+=lis[1][i]*(i+1);
            // if(c_b!=ans[1]){cout<<"not matching2"<<'\n';}
            
            cout<<ans[ci]<<'\n';
        }
    }
}
