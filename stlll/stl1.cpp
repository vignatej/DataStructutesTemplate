#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

#include <algorithm>


int main(int argc, char const *argv[])
{
    std::vector<int> v1 {1,2,3,4};
    
    auto loc = std::find(v1.begin(), v1.end(), 1);
    if(loc != v1.end()){
        std::cout<<"loc"<<*loc<<"- - " <<loc - v1.begin()<<std::endl;
    }
    
    std::vector<int>::iterator it1 = v1.begin();
    while(it1 != v1.end()){
        std::cout<< *it1 <<std::endl;
        ++it1;
    }
     
    std::vector<int>::reverse_iterator it3ww = v1.rbegin();
    while(it3ww != v1.rend()){
        std::cout<< *it3ww <<std::endl;
        ++it3ww;
    }
    
    
    std::set<char> suits {'C','A','H','R'};
    auto it2 = suits.begin();
    while (it2 != suits.end()){
        std::cout<< *it2 <<std::endl;
        ++it2;
    }



    std::map<std::string, std::string> m {{"q", "e"},{"w", "v"}, {"a", "n"}};
    auto it3 = m.begin();
    while (it3 != m.end()){
        std::cout<<it3->first<<" -- "<<it3->second<<std::endl;
        it3++;
    }
}
