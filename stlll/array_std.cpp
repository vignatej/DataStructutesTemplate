#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

int main(int argc, char const *argv[])
{
    std::array<int, 7> arr {1,5,6,55, 20,8,5};
    std::cout<<arr.at(1)<<std::endl;
    std::cout<<arr.size()<<std::endl;
    std::cout<<arr.front()<<std::endl;
    std::cout<<arr.back()<<std::endl;
    arr.at(0) = 50;
    std::cout<<arr.front()<<std::endl;
    std::cout<<arr.back()<<std::endl;
    std::cout<<arr.data()<<std::endl;
    std::array<int, 7> arr3 {1,2,3,4,5,6,7};
    // arr.swap(arr3);
    // std::cout<<arr.front()<<std::endl;
    // std::cout<<arr.back()<<std::endl;
    // std::cout<<arr.data()<<std::endl;

    std::sort(arr.begin(), arr.end());
    std::cout<<arr.front()<<std::endl;
    std::cout<<arr.back()<<std::endl;
    std::cout<<arr.data()<<std::endl;


    int a = *(std::min_element(arr.begin(), arr.end()));        
    std::cout<<"min is: "<< a <<std::endl;
    std::cout<<"sum is: "<< std::accumulate(arr.begin(), arr.end(), 0) <<std::endl;
    
    std::cout<<"count of 1's is: "<<std::count(arr.begin(), arr.end(), 1)<<std::endl;

    std::cout<<"count of elem btw 5 and 25 is: "<<std::count_if(arr.begin(), arr.end(), [](int a) {return 5<=a && a<=25;})<<std::endl;
    for(auto x:arr){
        std::cout<<x<<", ";
    }
    

}
