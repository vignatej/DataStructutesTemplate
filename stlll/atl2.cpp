#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::vector<int> v1 {1,4,3,6};
    std::for_each(v1.begin(), v1.end(), 
        [](int a){std::cout<<a*a<<std::endl;});
    std::string asd = "hellOsd sajkvhKJKJY kgjb";
    std::transform(asd.begin(), asd.end(), asd.begin(), ::toupper);
    std::cout<<asd<<std::endl;

}
