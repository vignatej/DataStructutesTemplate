#include <iostream>
#include <string>
#include <algorithm>
std::string bin(int num){
    if (num==0) return "";
    std::string ans = std::to_string(num%2) ;
    return bin(num/2)+ans;
};
void parse(std::string &s, int n){
    int l = s.length();
    if (l<n){
        std::string ss (n-l, '0'); 
        s = ss + s;
    }
};
int minFlips(int a, int b, int c) {
    std::string a1, b1, c1;
    a1 = bin(a);b1 = bin(b); c1 = bin(c);
    int l1,l2, l3;

    l1=a1.size();l2=b1.size();l3=c1.size();
    
    int m = std::max({l1, l2, l3});
    
    parse(a1, m);parse(b1, m);parse(c1, m);
    l1=a1.length();l2=b1.length();l3=c1.length();
    if(l1 != l2 || l2 !=l3){
        std::cout<<"noo"<<std::endl;
    }
    std::cout<<a1<<std::endl;
    std::cout<<b1<<std::endl;
    std::cout<<c1<<std::endl;
    int ans = 0;
    for(auto i1 = a1.rbegin(), i2 = b1.rbegin(), i3 = c1.rbegin();
        i1!=a1.rend(), i2!=b1.rend(), i3!=c1.rend();
            i1++,i2++,i3++){
        
        if(*i3=='0'){
            if(*i1=='1') ans++;
            if(*i2=='1') ans++;
        }else{
            if(*i1 == '0' && *i2=='0') ans++;
        }
    }
    return ans;
};

int main(int argc, char const *argv[])
{
    std::cout<<minFlips(9874, 1439, 2953)<<std::endl;
    return 0;
    // std::string s {"ffff"};
    // parse(s, 7);
    // std::cout<<s;
}
