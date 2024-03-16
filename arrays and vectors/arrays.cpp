#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // char a[5] {'a','e','i','o','u'};
    // cout<<"first"<<a[0];
    // cout<<"first"<<a[5];
    // // cin>>a[3];
    // for(int i=0;i<5;i++){
    //     cout<<a[i]<<endl;
    // }
    // double b[5] {0};
    // cout<<b[2];
    // for(int i=0;i<5;i++){
    //     cin>>b[i];
    // };
    // for(int i=0;i<5;i++){
    //     cout<<b[i]<<endl;
    // };
    // cout<<sizeof(int);
    int rat[3][4] {0};
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<rat[i][j];
        }
    }cout<<endl;
    cout<<rat[2][1];

    int arr[5] = {1,5,6,3,2};
    cout<<arr[4];

}
