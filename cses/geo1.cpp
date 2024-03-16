#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int T;cin>>T;
    while(T--){
        ll x1, y1, x2, y2, x3, y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
        double m = (double)(y2-y1)/(double)(x2-x1);
        double c = y1-m*x1;
        double yp = m*x3+c;
        if(x1<=x2 && y1<=y2){
            if(y3>yp) cout<<"LEFT";
            else if(y3==yp) cout<<"TOUCH";
            else cout<<"RIGHT";
        }else if(x1<=x2 && y1>=y2){
            if(y3>yp) cout<<"LEFT";
            else if(y3==yp) cout<<"TOUCH";
            else cout<<"RIGHT";
        }else if(x1>=x2 && y1<=y2){
            if(y3>yp) cout<<"RIGHT";
            else if(y3==yp) cout<<"TOUCH";
            else cout<<"LEFT";
        }else{
            if(y3<yp) cout<<"LEFT";
            else if(y3==yp) cout<<"TOUCH";
            else cout<<"RIGHT";
        }
        cout<<"\n";
    }
}