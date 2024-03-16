#include <iostream>
#include <vector>
#include <algorithm>

template <class t>
void print(std::vector<t>& a){
    for(auto it = a.begin();it!= a.end(); it++){
        std::cout<<*it<<", ";
    }std::cout<<std::endl;
}


int main(int argc, char const *argv[])
{
    std::vector<int> v {1,2,3,4,5};
    std::cout<<v.capacity()<<std::endl;
    v.push_back(1000);
    std::cout<<v.capacity()<<std::endl;
    v.pop_back();
    std::cout<<v.capacity()<<std::endl;
    std::cout<<v.size()<<std::endl;
    std::vector<int> v1 {5,6,2,3,0,4,1,2225};
    print<int>(v1);
    v1.erase(std::begin(v1)+2, std::begin(v1)+5);
    print<int>(v1);
    v1.erase(std::begin(v1)+3);
    print<int>(v1);
    v1.insert(std::begin(v1), 200);
    print<int>(v1);
    v1.insert(std::begin(v1)+3, 200);
    print<int>(v1);
    std::vector<int> v2 {v1};
    v2.erase(v2.begin());
    print<int>(v1);
    print<int>(v2);
    std::sort(v1.begin(), v1.end());
    std::sort(v2.rbegin(), v2.rend());
    print<int>(v1);
    print<int>(v2);
    std::vector<int> vb;
    std::copy(v1.begin(), v1.end(), std::back_inserter(vb));
    std::copy(v2.begin(), v2.end(), std::back_inserter(vb));
    print(vb);
    std::copy_if(v1.begin(), v1.end(), std::back_inserter(vb), 
        [](int a) {return a>100;});
    print(vb);
    std::vector<int> va {1,3,0,5,4};
    std::vector<int> vq {3,0,5,4, 8};
    std::vector<int> vc;
    std::transform(va.begin(), va.end(), vq.begin(),
        std::back_inserter(vc),
        [](int a, int b){return a*2 + b*2;});
    print(vc);

}
