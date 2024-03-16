#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 20;
    for(int k = 31;k>=0;k--){
        if(a&(1<<k)) cout<<1;
        else cout<<0;
    }
}
