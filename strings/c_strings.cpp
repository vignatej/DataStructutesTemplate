#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    char a[10]={"helloba"};
    for(int i=0;i<10;i++){
        cout<<a[i];
    }
    cout<<endl;
    strcpy(a, "vooriney");
    for(int i=0;i<10;i++){
        cout<<a[i];
    }
    cout<<endl;
    //strcpy()->copy_str, strlen()->get_len, strcmp()->compare, strcat()->concat
    // char va[50]{};
    // cout<<va;
    // cout<<"enter ur first name";
    // cin>>va;
    // cout<<"your first name is: "<<va<<" it has "<<strlen(va)<<" chars"<<endl;
    char fullname[50]={};
    strcpy(fullname, "nvnvbvjhvjva");
    cout<<fullname<<endl;
    cout<<"enter your full name";
    cin.getline(fullname,50);
    cout<<fullname;


    return 0;
}
